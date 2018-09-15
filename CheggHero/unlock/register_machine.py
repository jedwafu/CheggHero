# -*- coding: utf-8 -*-
from time import sleep
import os
from random import choice
import sys
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.chrome.options import Options


def exception_handle(function, e):
    print (e)
    print(function + " fail")
    return False


def click_exit(my_driver, home_url):
    try:
        my_driver.get(home_url)
        sleep(1)
        elem_exit = my_driver.find_element_by_class_name("shepherd-cancel-link")
        elem_exit.click()
    except Exception as e:
        return exception_handle("click", e)


def upload(my_driver, class_name, upload_url):
    try:
        my_driver.get(upload_url)
        my_driver.implicitly_wait(5)
        elem_classname = my_driver.find_element_by_class_name("selectize-input")
        elem_classname.click()
        elem_classname.send_keys(class_name)
        sleep(1)
        elem_classname.send_keys(Keys.ENTER)
        sleep(1)
        elem_upload = my_driver.find_element_by_class_name("ch_uploadFromDesktop_action")
        elem_upload.send_keys('d:\\results6.txt')
    except Exception as e:
        return exception_handle("upload", e)


def register(email_address, username, pwd, school, register_url, payment_url, my_driver, account_list_file_name):
    try:
        my_driver.get(register_url)
        my_driver.implicitly_wait(5)
        elem_email = my_driver.find_element_by_name("email")
        elem_email.send_keys(Keys.CONTROL, 'a')
        elem_email.send_keys(email_address)
        elem_username = my_driver.find_element_by_name("username")
        elem_username.send_keys(Keys.CONTROL, 'a')
        elem_username.send_keys(username)
        elem_pwd = my_driver.find_element_by_name("password")
        elem_pwd.clear()
        elem_pwd.send_keys(pwd)
        elem_school = my_driver.find_element_by_id("s2id_school_name_dropdown")
        elem_school.click()
        elem_enter_school = my_driver.find_element_by_class_name("select2-input")
        elem_enter_school.send_keys(school)
        sleep(1)
        elem_enter_school.send_keys(Keys.ENTER)
        elem_sub = my_driver.find_element_by_id("signup-submit-field")
        sleep(0.5)
        elem_sub.click()
        sleep(1)

        cnt = 0
        while my_driver.current_url != payment_url and cnt < 20:
            sleep(1)
            print ("now waiting submitting, already", cnt, "s")
            cnt = cnt + 1
            
        if my_driver.current_url == payment_url:
            print("registration success")
            return True

        print("fail to register account")
        return False

    except Exception as e:
        return exception_handle("register", e)


def create_driver(download_dir):

    chrome_options = Options()
    prefs = {'download.default_directory': download_dir,
            "download.prompt_for_download": False,
            "directory_upgrade": True,
            "safebrowsing.enabled": True
            }
    chrome_options.add_experimental_option('prefs', prefs)

    driver = webdriver.Chrome(executable_path='chromedriver.exe', chrome_options=chrome_options)
    driver.maximize_window()

    return driver


def my_random(seed, len):

    ch = []
    for i in range(len):
        ch.append(choice(seed))
    return ''.join(ch)


def main(count, driver):

    login_url = "https://www.coursehero.com/login/"
    register_url = "https://www.coursehero.com/register/"
    home_url = "https://www.coursehero.com/home/"
    payment_url = "https://www.coursehero.com/payment/"
    upload_url = "https://www.coursehero.com/upload/"

    class_name = "cs314"
    school = "university of washington"

    #my_time = time.localtime(time.time())
    #account_list_file_name= "account_" + str(my_time.tm_year) + str(my_time.tm_mon) + str(my_time.tm_mday) + ".txt"
    work_dir = os.getcwd()
    filename = "new_accounts.txt"
    full_path = os.path.join(work_dir, filename)

    for i in range(count):
        email = "d8tl" + my_random("1234567890abcdefghijklmnopqrstuvwxyz", 8) + "@hotmail.com"
        username = "d8tl" + my_random("abcdefghijklmnopqrstuvwxyz", 4)
        pwd = my_random("1234567890", 8)

        if register(email, username, pwd, school, register_url, payment_url, driver, full_path):
            with open(filename, "a") as f:
                f.write(email + ' ' + pwd + '\n')
                print("new account added")
        else:
            return False
    print("register successfully")
    return True

    #click_exit(my_driver, home_url)
    #sleep(4)
    #upload(my_driver, class_name, upload_url)
    #sleep(1)

if __name__ == "__main__":
    driver = create_driver(work_dir)

    main(1, driver)

    driver.quit()
