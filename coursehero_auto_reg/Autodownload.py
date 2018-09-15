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


def target(target_url, driver, download_dir, pic_dir, count):

    if count > 2:  # try two times
        return False
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
            return target(target_url, driver, download_dir, pic_dir, count + 1)

        return target(target_url, driver, download_dir, pic_dir, count + 1)
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


def no_unlock_handle(username, pwd, work_dir):
    try:
        no_unlock_file = os.path.join(work_dir, "no_unlock.txt")
        accounts_file = os.path.join(work_dir, "accounts.txt")
        account = username + ' ' + pwd

        with open(no_unlock_file, 'a') as f:
            f.write(account + '\n')

        with open(accounts_file, 'r') as f:
            accounts_list = f.read().split('\n')

            try:
                idx = accounts_list.index(account)
                del accounts_list[idx]
                print("The no-unlock account removed")

            except Exception as e:
                print(e)
                print("The no-unlock account failed to removed")
                return False

        with open(accounts_file, 'w') as f:

            for account in accounts_list:
                if account == accounts_list[-1]:
                    f.write(account)
                else:
                    f.write(account + '\n')
    except Exception as e:
        print(e)
        print("no_unlock_handle failed")


def check_unlock(driver, pic_dir):
    try:
        payment_url = "https://www.coursehero.com/payment/"
        home_url = "https://www.coursehero.com/home/"

        if driver.current_url == payment_url:
            print("No unlocks remaining. Change account")
            return False
        sleep(1)
        if driver.current_url == home_url:
            elem_unlock = driver.find_element_by_xpath("//div/div/ul/li[2]/span[@class='dashboard-stats-highlight "
                                                   "ng-binding']").text
            if elem_unlock != '0':
                print(elem_unlock, "unlocks remaining")
                return True

            print(elem_unlock, "unlocks remaining. Change account")
            
        print(driver.current_url + "not home_url")
        return False
    except Exception as e:
        return exception_handle("check_unlock", e, driver, pic_dir)


def refresh(count, driver, pic_dir):
    try:
        for i in range(count):
            driver.refresh()
            print("refreshing")
    except Exception as e:
        return exception_handle("refresh", e, driver, pic_dir)


def login(username, pwd, driver, pic_dir, count):

    if count > 3:
        print("Many times login failed")
        return False

    print("The", count, "times to login")
    login_url = "https://www.coursehero.com/login/"
    home_url = "https://www.coursehero.com/home/"
    payment_url = "https://www.coursehero.com/payment/"
    # domain_url = "https://www.coursehero.com"
    try:

        driver.get(login_url)
        driver.implicitly_wait(10)

        refresh(2, driver, pic_dir)

        elem_user = driver.find_element_by_name("email")
        elem_user.send_keys(Keys.CONTROL, 'a')
        elem_user.send_keys(username)
        elem_pwd = driver.find_element_by_xpath("//input[@name='password']")
        elem_pwd.clear()
        elem_pwd.send_keys(pwd)
        elem_sub = driver.find_element_by_xpath("//a[@id='login-submit-field']")
        sleep(2)
        elem_sub.click()

        cnt = 1
        while driver.current_url == login_url:
            sleep(1)
            print("Waiting login ...", cnt, "s")
            if cnt > 3:
                return login(username, pwd, driver, pic_dir, count + 1)
            cnt = cnt + 1

        if driver.current_url == home_url or driver.current_url == payment_url:
            print("log in successfully")
            return True

        print("log in fail for some unknown reasons")
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

    if login(username, pwd, driver, pic_dir, 1):
        if check_unlock(driver, pic_dir):
            if target(target_url, driver, download_dir, pic_dir, 1):
                driver.quit()
                return True

        else:
            no_unlock_handle(username, pwd, work_dir)
        
    # logout(driver)
    driver.quit()
    print("Auto download failed")
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
