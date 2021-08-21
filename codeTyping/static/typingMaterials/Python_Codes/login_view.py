from django.shortcuts import render
# from django.http import HttpResponse
from myapp import models
from django.contrib import messages
from django.http import HttpResponseRedirect


def register(request):
    c = models.Users.objects.filter(account=request.GET['account']).count()
    if c == 1:
        messages.info(request, '账号已存在.')
        return
    user = models.Users()
    user.account = request.GET['account']
    user.password = request.GET['password']
    user.save()
    messages.info(request, '注册成功.')


def login(request):
    content = {}

    if request.GET:
        if request.GET['type'] == 'register':
            # 要先对比
            register(request)

        elif request.GET['type'] == 'login':
            c = models.Users.objects.filter(
                account=request.GET['account'], password=request.GET['password']).count()
            if c == 1:
                # return render(request, "main.html")
                return HttpResponseRedirect("main/")
            else:
                messages.info(request, '账号或密码错误.')

    return render(request, "login.html", content)
