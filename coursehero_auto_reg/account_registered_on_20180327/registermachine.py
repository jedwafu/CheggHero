# -*- coding: utf-8 -*-
import time
import os
import random
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
        time.sleep(1)
        elem_exit = my_driver.find_element_by_class_name("shepherd-cancel-link")
        elem_exit.click()
    except Exception as e:
        return exception_handle("click", e)
def upload(my_driver, class_name, upload_url):
    try:
        my_driver.get(upload_url)
        time.sleep(3)
        elem_classname = my_driver.find_element_by_xpath("//*[@id='ch-body']/div/div[4]/div/div[2]/div[3]/popup/div/div/div/div/div/div[1]/div[2]/div[2]/div[1]/div[2]/fieldset/div/div[1]/input")
        elem_classname.click()
        elem_classname.send_keys("chi")
        print("class name sent!")
        #time.sleep(20)
        time.sleep(2)
        elem_classname.send_keys(Keys.ENTER)
        print("enter sent!")
        time.sleep(5)
        elem_upload = my_driver.find_element_by_xpath("//*[@id='ch-body']/div/div[4]/div/div[2]/div[3]/popup/div/div/div/div/div/div[1]/div[2]/div[4]/div[1]/a[1]")
        #elem_upload.click()
        elem_upload.send_keys("d:\\results6.txt")
        print("file sent!")
    except Exception as e:
        return exception_handle("upload", e)

def register(email_address, username, pwd, school, register_url, payment_url, my_driver, account_list_file_name):
    try:
        my_driver.get(register_url)
        #str = input("输入y表示你准备好了：")
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
        time.sleep(1)
        elem_enter_school.send_keys(Keys.ENTER)
        elem_sub = my_driver.find_element_by_id("signup-submit-field")
        time.sleep(0.5)
        elem_sub.click()

        cnt = 0
        while my_driver.current_url != payment_url and cnt < 20:
            time.sleep(1)
            print ("now waiting submitting, already", cnt, "s")
            cnt = cnt + 1
            
        if my_driver.current_url == payment_url:
            print("registration success")
            return True

        print("fail to register account")
        return False

    except Exception as e:
        return exception_handle("login", e)


def driver(download_dir):

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
        ch.append(random.choice(seed))
    return ''.join(ch)

if __name__ == "__main__":
    login_url = "https://www.coursehero.com/login/"
    register_url = "https://www.coursehero.com/register/"
    home_url = "https://www.coursehero.com/home/"
    payment_url = "https://www.coursehero.com/payment/"
    upload_url = "https://www.coursehero.com/upload/"

    class_name = "cs314"
    school = "university of washington"
    my_time = time.localtime(time.time())
    work_dir = os.getcwd()
    #account_list_file_name= "account_" + str(my_time.tm_year) + str(my_time.tm_mon) + str(my_time.tm_mday) + ".txt"
    #account_list_file_name = "f:\coursehero_auto_reg\coursehero_acc_lst" + str(my_time.tm_year) + str(my_time.tm_mon) + str(my_time.tm_mday) + ".txt"
    #account_list_file_name = work_dir + "coursehero_acc_lst" + str(my_time.tm_year) + str(my_time.tm_mon) + str(my_time.tm_mday) + ".txt"
    account_list_file_name = work_dir + "\\coursehero_acc_lst" + ".txt"
    print("saved in file: " + account_list_file_name)

    my_driver = driver(work_dir)
    email = "d8tl" + my_random("1234567890abcdefghijklmnopqrstuvwxyz", 8) + "@hotmail.com"
    username = "d8tl" + my_random("abcdefghijklmnopqrstuvwxyz", 4)
    pwd = my_random("1234567890", 8)
    register(email, username, pwd, school, register_url, payment_url, my_driver, account_list_file_name)
    time.sleep(4)

    #click_exit(my_driver, home_url)
    #time.sleep(4)
    my_driver.get(upload_url)
    upload(my_driver, class_name, upload_url)
    fp = open(account_list_file_name, "a")
    #fp.write("caonima")
    str = input("输入y表示你已经上传好了：")
    flag = 0
    while flag == 0:
        if str == "y" or str == "Y":
            fp.write(email+' '+ pwd + '\n')
            flag = 1
        
        if str != "n" and str != "N" and str != "Y" and str != "y":
            str = input("输入y表示你已经上传好了：")

        if str == "n" or str == "N":
            flag = -1

    if str == "y" or str =="Y":
        str = input("记录成功！按回车键退出")
    else:
        print("注册未成功 按回车键开始下一个账号注册")
    
    fp.close()
    #time.sleep(1)
    my_driver.quit()
