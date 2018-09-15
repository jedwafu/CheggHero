# -*- coding: utf-8 -*-

from smtplib import SMTP_SSL
from email.mime.multipart import MIMEMultipart    
from email.mime.text import MIMEText    
import sys
import os


def send_mail(code, url, receiver, download_dir, filename):

    host_server = 'smtp.gmail.com'
    port = 465

    sender = 'chegghero.service@gmail.com'
    pwd = 'Unlock2018'
    
    subject = 'CheggHero Unlock File! (NO REPLY)'  # email subject

    # 文字内容   
    text = '''
    Dear!
    
    Here is the file you wanted. Thanks for your coming!
    '''
    text = text + "\nYour activation code is: " + code
    text = text + "\nYour file URL is: " + url

    msg = MIMEMultipart('mixed') 
    text_plain = MIMEText(text, 'plain', 'utf-8')
    msg.attach(text_plain) 

    # 构造附件
    full_dir = os.path.join(download_dir, filename)
    file_contend = open(full_dir, 'rb').read()
    text_att = MIMEText(file_contend, 'base64', 'utf-8')
    text_att["Content-Type"] = 'application/octet-stream'  
    # 以下附件可以重命名成aaa.txt
    # text_att["Content-Disposition"] = 'attachment; filename="aaa.txt"'
    # 另一种实现方式
    text_att.add_header('Content-Disposition', 'attachment', filename=filename)
    # 以下中文测试不ok
    # text_att["Content-Disposition"] = u'attachment; filename="中文附件.txt"'.decode('utf-8')
    msg.attach(text_att)   
    
    msg['Subject'] = subject
    msg["From"] = sender  # 发送者邮箱地址
    msg["To"] = receiver  # 接收者邮件地址

    smtp = SMTP_SSL(host_server, port)  # SSL 加密连接
    # smtp.set_debuglevel(0) # set_debuglevel()是用来调试的。参数值为1表示开启调试模式，参数值为0关闭调试模式
    smtp.ehlo(host_server)  # 连接服务器
    smtp.login(sender, pwd)  # 邮箱登录
    
    try:
        smtp.sendmail(sender, receiver, msg.as_string())  # 发送邮件函数
        print("Successfully Send to " + receiver)  # 输出成功标志
        smtp.quit()
        return True
    except Exception as e:
        print(e)
        print("The sever is busy, please continue later.")
        smtp.quit()
        return False


def main(code, url, receiver):
    try:
        work_dir = os.getcwd()
        download_dir = os.path.join(work_dir, "download_file", code)
        filelist = os.listdir(download_dir)

        if not filelist:
            return False

        filename = filelist[0]
        return send_mail(code, url, receiver, download_dir, filename) # 发送邮件
        # sys.exit(0)
    except Exception as e:
        print(e)
        print("Auto email failed")
        return False