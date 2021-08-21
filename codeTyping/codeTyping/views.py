from django.shortcuts import render
from django.contrib import messages


def mainView(request):
    content = {'p': 'Practice to type faster.'}

    return render(request, "index.html", content)
