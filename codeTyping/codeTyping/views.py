from django.shortcuts import render
from django.contrib import messages
import os


def mainView(request):
    content = {}
    materialTypes = {'C codes': 'C_Codes',
                     'Java codes': 'Java_Codes',
                     'Python codes': 'Python_Codes',
                     'English Articles': 'Articles',
                     'Randomly Mixed': 'Random'}
    if request.GET:
        if 'choose' in request.GET.keys():
            materialType = request.GET['choose']
            if materialType not in materialTypes.keys():
                content['sentence'] = 'Please select a type.'
            elif materialType != 'Randomly Mixed':
                # any type
                materials = os.listdir(
                    'static/typingMaterials/' + materialTypes[materialType])
                content['typeName'] = materialType
                content['materials'] = materials
            else:
                # random choose
                pass
        elif 'material' in request.GET.keys():
            folderName = materialTypes[request.GET['typeName']]
            content['language'] = folderName.split('_')[0]
            with open('static/typingMaterials/' + folderName + '/' + request.GET['material']) as f:
                content['sentences'] = f.readlines()
            # pass
    return render(request, "templates/index.html", content)
