# code-typing

![image](https://user-images.githubusercontent.com/39082096/149967763-a9bb56c5-6411-4d86-90d3-f1e22845e2a8.png)

A tiny web page to practice code typing.

Select different program files of different languages, then practice typing codes!

Mainly used Python Django and JavaScript. 

## Features

1. Practice typing on any customized code snippets
2. Automatically skip comment blocks
3. Highlight codes
4. Show mistakes
5. Use the right arrow key to skip code blocks as you want

## Usage

After download the codes, go to its root directory, then go to `/codeTyping`:

```sh
cd codeTyping
```

Then run below command to start the server:

```sh
python3 manage.py runserver 0.0.0.0:8000
```

Then use browser to view the webpage at http://0.0.0.0:8000/

### Tips

1. If you don't have `Django`, install it by:

```sh
pip3 install django==3.2.8
```

2. If you want to customize code files, just replace the files in `/codeTyping/static/typingMaterials`, which are code snippets files.
