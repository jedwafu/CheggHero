import os
import sys
import time
from time import sleep
import check_acc
import re
import shutil
def mkdir(path):
    # 去除首位空格
    path=path.strip()
    # 去除尾部 \ 符号
    path=path.rstrip("\\")

    # 判断路径是否存在
    # 存在     True
    # 不存在   False
    isExists=os.path.exists(path)

    # 判断结果
    if not isExists:
        # 如果不存在则创建目录
        print (path+' 创建成功')
        # 创建目录操作函数
        os.makedirs(path)
        return True
    else:
        # 如果目录存在则不创建，并提示目录已存在
        shutil.rmtree(path)
        print (path+' 目录已存在')
        os.makedirs(path)
        return False

if __name__ == '__main__':

	myfile = open('coursehero_acc_lst.txt', 'r')  
	allWords = []
	line = myfile.readline()  
	os.system("taskkill /im chromedriver.exe")
	#cwd = os.getcwd()
	my_time = time.localtime(time.time())
	c = str(my_time.tm_year) + str(my_time.tm_mon) + str(my_time.tm_mday)
	dest_dir = os.path.pardir+ "\\" + "account_list " + c + "\\"
	mkdir(dest_dir)

	while line:	
		list = line.split(' ')  
		for word in list:
			if word[-1]=='\n':  
				pwd = word[:-1]  #去掉行末的'\n'  
			else:
				username = word
		this_file_name = -1
		cnt = 0
		
		while (this_file_name==-1) and (cnt < 30):
			cnt = cnt + 1
			this_file_name = check_acc.login(username, pwd)
		
		if (cnt == 30) or (this_file_name==-1):
			print("unexcept problems in call_check.py")
			sys.exit(1)

		unlock = re.search(r"(\d+ unlocks)", this_file_name)
		date = re.search(r"(\d{4}-\d{1,2}-\d{1,2})", this_file_name)
		try: 
			a = unlock.group()
			b = date.group()
		except Exception as e:
			a = "0 unlocks"
			b = ""
		fp = open(dest_dir + a+ "_" + b + ".txt", "a")
		fp.write(username+' '+ pwd + '\n')
		fp.close()
		line = myfile.readline()

	myfile.close() 