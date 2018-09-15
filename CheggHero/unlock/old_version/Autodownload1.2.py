# -*- coding: utf-8 -*-
# version: 1.0
import os
import sys
from time import sleep
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.chrome.options import Options


def exception_handle(func, e, driver, pic_dir):
    print(e)
    print(func + " fail")

    pic_name = func + ".png"

    if not os.path.exists(pic_dir):
        os.makedirs(pic_dir)

    download_dir = os.path.join(pic_dir, pic_name)
    driver.get_screenshot_as_file(download_dir)

    return False


def logout(driver, pic_dir):
    try:
        driver.switch_to.default_content()
        move_mouse = driver.find_element_by_xpath("//ul/li[3]/a[@class='ch_nav_action']/i[@class='fa fa-chevron-down']")
        ActionChains(driver).move_to_element(move_mouse).perform()
        elem_logout = driver.find_element_by_xpath("//ul/li[3]/div/ul/li[4]/a[@href='/logout/']")
        elem_logout.click()
        print("logout successfully")
        return True
    except Exception as e:
        return exception_handle("logout", e, driver, pic_dir)


def download(driver, pic_dir):
    try:
        driver.switch_to.frame("flash-document")
        elem_download = driver.find_element_by_id('toolbar_download_button')
        elem_download.click()
        print("download successfully")
        return True
    except Exception as e:
        return exception_handle("download", e, driver, pic_dir)


def unlock(driver, pic_dir):
    try:
        elem_unlock = driver.find_element_by_xpath("//a[@class='ldp_notification_action']")
        elem_unlock.click()
        print("unlock successfully")
        return True
    except Exception as e:
        return exception_handle("unlock", e, driver, pic_dir)


def target(target_url, driver, download_dir, pic_dir):
    # if count == 2:  # try second time
    #     return False
    try:
        driver.get(target_url)
        driver.implicitly_wait(10)

        unlock(driver, pic_dir)
        driver.implicitly_wait(10)

        if download(driver, pic_dir):  # success
            sleep(5)  # 5s to download file

            if os.path.exists(download_dir):
                print("file exist")
                return True

            print("file not exist")
            return False

        return False
        # elif login(username, pwd, login_url, target_url, driver):
        #     return target(target_url, driver, count+1)
    except Exception as e:
        return exception_handle("target", e, driver, pic_dir)

    # try:
    #     elem_help = driver.find_element_by_xpath("//a[@class='rf_helpful_button']")
    #     elem_help.click()
    # except:
    #     print("fail to click helpful")


# def check_robot(driver, pic_dir):

# 	try:
# 		elem_robot = driver.find_element_by_id("recaptcha-anchor-label")
# 		return True
# 	except Exception as e:
# 		return exception_handle("check_robot", e, driver, pic_dir)


def login(username, pwd, driver, pic_dir):

    login_url = "https://www.coursehero.com/login/"
    home_url = "https://www.coursehero.com/home/"
    domain_url = "https://www.coursehero.com"
    try:

        driver.get(login_url)
        driver.implicitly_wait(10)

        for i in range(3):
            driver.refresh()
            print("refreshing")

        elem_user = driver.find_element_by_name("email")
        elem_user.send_keys(Keys.CONTROL, 'a')
        elem_user.send_keys(username)
        elem_pwd = driver.find_element_by_xpath("//input[@name='password']")
        elem_pwd.clear()
        elem_pwd.send_keys(pwd)
        elem_sub = driver.find_element_by_xpath("//a[@id='login-submit-field']")
        sleep(2)
        elem_sub.click()

        cnt = 0
        while driver.current_url == login_url:
            sleep(1)
            print("Waiting login ...", cnt, "s")
            if cnt > 20:
                break
            cnt = cnt + 1

        if driver.current_url == home_url:
            print("log in successfully")
            return True

        if driver.current_url != login_url:
            print("no enough unlock chances in this account")
            return False
            
        print("log in fail")
        return False
    except Exception as e:
        return exception_handle("login", e, driver, pic_dir)


def create_driver(download_dir):

    chrome_options = Options()

    # 无壳 加载
    # chrome_options.add_argument('--headless')
    # chrome_options.add_argument('--disable-gpu')

    # cookie 加载
    # chrome_options.add_argument("user-data-dir="+os.path.abspath(profile_dir))  

    # download 目录
    prefs = {'download.default_directory': download_dir,
             "download.prompt_for_download": False,
             "directory_upgrade": True,
             "safebrowsing.enabled": True
             }
    chrome_options.add_experimental_option('prefs', prefs)

    driver = webdriver.Chrome(executable_path='chromedriver.exe', chrome_options=chrome_options)
    driver.maximize_window()

    return driver


def main(code, target_url, username, pwd):

    # 对应你的chrome的用户数据存放路径
    # profile_dir = r"C:\Users\Benjamin\AppData\Local\Google\Chrome\User Data"

    # file 下载地址
    work_dir = os.getcwd()
    download_dir = os.path.join(work_dir, "coursehero_file", code)
    pic_dir = os.path.join(work_dir, "error_pic", code)

    driver = create_driver(download_dir)
    if login(username, pwd, driver, pic_dir):
        if target(target_url, driver, download_dir, pic_dir):
            driver.quit()
            return True

    # logout(driver)
    driver.quit()
    return False
    # sys.exit(0)


if __name__ == '__main__':

    # cmd
    if len(sys.argv) == 5:
        target_url = sys.argv[1]
        code = sys.argv[2]
        username = sys.argv[3]
        pwd = sys.argv[4]
    # else:
    #     target_url = "https://www.coursehero.com/file/28025536/finalSol-Fall2013pdf/"
    #     code = '12345'  # 激活码
    #     # coursehero account
    #     username = "glock18@utexas.edu"
    #     pwd = "57715915"

        main(code, target_url, username, pwd)
