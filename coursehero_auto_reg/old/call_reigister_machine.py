import time
import registermachine
import os
import random
import sys
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.chrome.options import Options



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
	school = "university of texas"
	my_time = time.localtime(time.time())
	account_list_file_name= "account_" + str(my_time.tm_year) + str(my_time.tm_mon) + str(my_time.tm_mday) + ".txt"
	print("saved in file: " + account_list_file_name)
	email = "d8tl" + my_random("1234567890abcdefghijklmnopqrstuvwxyz", 8) + "@hotmail.com"
	username = "d8tl" + my_random("abcdefghijklmnopqrstuvwxyz", 4)
	pwd = my_random("1234567890", 8)

	fp = open(account_list_file_name, "w")
	for i in range(10):
		str = input("按任意键表示你已经准备好了：");
		email = "d8tl" + my_random("1234567890abcdefghijklmnopqrstuvwxyz", 8) + "@hotmail.com"
		username = "d8tl" + my_random("abcdefghijklmnopqrstuvwxyz", 4)
		pwd = my_random("1234567890", 8)
		registermachine.main(email, username, pwd, school, class_name, account_list_file_name)
		fp.write(email+' '+ pwd + '\n')
		str = input("按任意键表示你已经上传好了，进入下一个账号：");
	fp.close()
