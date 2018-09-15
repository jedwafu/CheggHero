import os
import sys
import re
from time import sleep
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
def exception_handle(func, e, driver):
	print(e)
	print(func + " fail")
	return -1

def create_driver(download_dir):

	chrome_options = Options()

	# 无壳 加载
	#chrome_options.add_argument('--headless')
	#chrome_options.add_argument('--disable-gpu')

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
	#driver.maximize_window()

	return driver

def check_expiration_date(my_driver):
	upload_url = "https://www.coursehero.com/upload/"
	my_driver.get(upload_url)
	bell = my_driver.find_element_by_class_name("ch_notifications_action")
	bell.click()
	print("bell clicked")
	sleep(2)
	message = my_driver.find_element_by_xpath("//p[@class='ng-binding']")
	#print("now checking expiration")
	print(message.text)
	return message.text



def check_unlock_number(my_driver):
	#unlock_number = my_driver.find_elements_by_css_selector("#dashboard-stats")
	#print(unlock_number)
	#cnt = 0
	#for elem in unlock_number:
	#	cnt = cnt + 1
	#	print (cnt)
	#	print (elem.text)
	#	s = elem.text
	#print ("This account info: \n" + s)
	#arr = re.findall(r"\d+",s)
	#unlock_number = arr[0]
	#print (arr[0] + " unlocks detected")
	file_name = check_expiration_date(my_driver)
	print("from check_unlock_number"+file_name)
	return file_name

def login(username, pwd):
	work_dir = os.getcwd()
	my_driver = create_driver(work_dir)
	login_url = "https://www.coursehero.com/login/"
	home_url = "https://www.coursehero.com/home/"
	payment_url = "https://www.coursehero.com/payment/"
	# domain_url = "https://www.coursehero.com"
	try:
		my_driver.get(login_url)
		sleep(2)
		elem_user = my_driver.find_element_by_name("email")
		#elem_user.send_keys(Keys.CONTROL, 'a')
		elem_user.send_keys(username)
		sleep(0.5)
		elem_pwd = my_driver.find_element_by_xpath("//input[@name='password']")
		#elem_pwd.clear()
		elem_pwd.send_keys(pwd)
		elem_sub = my_driver.find_element_by_xpath("//a[@id='login-submit-field']")
		
		elem_sub.click()
		sleep(10)
		cnt = 1
		while my_driver.current_url == login_url:
			sleep(1)
			print("Waiting login ...", cnt, "s")
			if cnt > 3:
				return login(username, pwd, my_driver)
			cnt = cnt + 1

		if my_driver.current_url == home_url or my_driver.current_url == payment_url:
			print("log in successfully")
			file_name = check_unlock_number(my_driver)
			my_driver.quit()
			return file_name

		print("log in fail for some unknown reasons")
		my_driver.quit()
		return -1
	except Exception as e:
		my_driver.quit()
		return exception_handle("login", e, my_driver)
	my_driver.quit()


	#print (allWords)  