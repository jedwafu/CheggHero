from django.shortcuts import render
from cmdb import models
from unlock import Autodownload
from unlock import Autoemail
from django.views.decorators.csrf import csrf_exempt
from urllib.parse import urlparse
from random import randrange
from os import system


@csrf_exempt
def index(request):

    return render(request, "index.html")


@csrf_exempt
def unlock(request):

    if request.method == "GET":
        code = request.GET.get("code", '')
        url = request.GET.get("url", '')
        email = request.GET.get("email", '')

        if not check_url(request, url):
            return render(request, "error_url.html")
        if not check_code(request, code):
            return render(request, "error_code.html")

        models.UserInfo.objects.create(code=code, url=url, email=email)
        
        for i in range(3):
            account = get_account()
            if account and len(account) == 2:
                username = account[0]
                pwd = account[1]
            else:
                print("account info error")
                return render(request, "base.html")
            # temp = {"code": code, "url": url, "email": email}
            # with open("data.txt", 'w') as f:
            #     f.write(temp)
            
            try:
                # system("taskkill /im Chrome.exe /f")
                if Autodownload.main(code, url, username, pwd):
                    if Autoemail.main(code, url, email):
                        return render(request, "success.html")
            except Exception as e:
                print(e)
        return render(request, "base.html")


def check_code(request, code):
    """

    :param request:
    :type code: str
    """

    if not code:
        print("empty code")
        return False

    with open("codes.txt", 'r') as f:
        codelist = f.read().split()

        try:
            idx = codelist.index(code)
            del codelist[idx]
            print("activation code matches")

        except Exception as e:
            print(e)
            print("activation code NOT matches")
            return False

    with open("codes.txt", 'w') as f:

        for code in codelist:
            f.write(code + '\n')

    return True


def check_url(request, url):

    if not url:
        print('empty url')
        return False

    return check_domain_name(url)
    

# Get domain name (example.com)
def check_domain_name(url):
    try:
        result = urlparse(url).netloc.split('.')
        user_domain = result[-2] + '.' + result[-1]
        domain = 'coursehero.com'

        if user_domain == domain:
            return True
        return False
    except Exception as e:
        print(e)
        print('Error: failed to get domain name')
        return False


@csrf_exempt
def get_account():

    with open("accounts.txt", 'r') as f:
        accounts = f.readlines()

        idx = randrange(len(accounts))
        account_string = accounts[idx].strip()

        while not account_string:
            idx = randrange(len(accounts))
            account_string = accounts[idx].strip()
            
        account = account_string.split()

    return account
