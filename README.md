# code-typing

![image](https://user-images.githubusercontent.com/39082096/149967763-a9bb56c5-6411-4d86-90d3-f1e22845e2a8.png)

**Live demo now available at
[http://jyzhu.pythonanywhere.com/](http://jyzhu.pythonanywhere.com/)!!**

A tiny web page to practice code typing.

Select different program files of different languages, then practice typing codes!

Mainly used Python Django and JavaScript. 

## Features

1. Practice typing on any customized code snippets
2. Automatically skip comment blocks
3. Highlight codes
4. Show mistakes
5. Use the right arrow key to skip code blocks as you want

## Run Django server locally

After download the codes, go to its root directory. Then run the command below to start the server:

```sh
python3 manage.py runserver 0.0.0.0:8000
```

Then view the webpage at http://0.0.0.0:8000/ via browser

### Tips

1. If you don't have `Django`, install it by:

```sh
pip3 install django==3.2.8
```

2. If you want to customize code files, just replace the files in `/codeTyping/static/typingMaterials`, which are code snippets files.

---

## Note

Initially I tried to deploy this demo on Vercel.com. But it was too troublesome coz it does not support Django by default. Thankfully, I found [pythonanywhere](https://www.pythonanywhere.com/), on which each user can deploy one web app without payment. What's the best is that it is really easy to deploy: it provides access to Bash console.

Two things to be noted:

1. Every 3 months, I have to login into the pythonanywhere to extend my web app, otherwise it will be killed.
2. The bug cost most of my time is that in the `view.py` I had used relative path to the static code files. However, I should use absolute path, with adding `BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))` ahead.

## TODO

Actually, after learned the MERN frame this semester, I am now aware of how naive this project is. However, I love Python, so it doesn't matter if i still regard Django as a hobby🤨. Who knows... I haven't even spent my time on that course project...

Now that the live demo is achieved, I might think of polishing this little project a bit. 

- [ ] Fix bugs. Though i've already forgotten what those bugs are...
- [ ] Replace the stupid code snippets...
- [ ] Add the feature to compute time cost and typing speed. Also, save typing records.
- [ ] Explicitly support other kinds of typing materials, and also support uploading customize materials.
