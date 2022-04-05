#!/usr/bin/python
# -*- coding: UTF-8 -*-
import sys
from tkinter import ttk
from cx_Freeze import setup, Executable

# Dependencies are automatically detected, but it might need fine tuning.
# build_exe_options = {"packages": ["os"], "excludes": ["tkinter"]}
includefiles = ['1.png', '2.png', '3.png', '4.png']
includes = []
excludes = ['tkinter']
packages = ['os']


setup(name='图片传密',
      version='2.0',
      description='加密文字的传输方式',
      author='朱珈印',
      author_email='asdfg990518@163.com',
      # options={'build_exe': build_exe_options, 'include_files': includefiles},
      options={'build_exe': {'includes': includes, 'excludes': excludes,
                             'packages': packages, 'include_files': includefiles}},
      executables=[Executable('picSecret.py')])
# python3 packToExt.py build
# python3 packToExt.py bdist_dmg
