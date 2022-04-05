from PIL import Image
im=Image.open('blue.jpg')
a,b=eval(input('Tell me the size a,b: '))
im=Image.resize((a,b))
im.save('blue.jpg')