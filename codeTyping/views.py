from django.shortcuts import render
from django.contrib import messages
import os
import random

BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

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
                materials = os.listdir( os.path.join(BASE_DIR,
                    'static/typingMaterials/' + materialTypes[materialType]))
                content['typeName'] = materialType
                content['materials'] = materials
                content['display1'] = "none"
                content['display2'] = "block"
            else:
                # random choose
                pass
        elif 'material' in request.GET.keys():
            folderName = materialTypes[request.GET['typeName']]
            fileName = random.choice(os.listdir( os.path.join(BASE_DIR,
                'static/typingMaterials/' + folderName))) if request.GET['material'] == '*random' else request.GET['material']
            content['language'] = folderName.split('_')[0]

            with open(os.path.join(BASE_DIR, 'static/typingMaterials/' +
                folderName + '/' + fileName)) as f:
                lines = f.readlines()
                content['sentences'] = lines
                content['letters'] = '\\\n'.join(
                    line.strip('\n') for line in lines)
                content['display2'] = "hidden"
                content['display1'] = "block"
    return render(request, "templates/index.html", content)
