textfile=open("ren.txt","rt")
print(textfile.readline())
textfile.close()
binfile=open("ren.txt",'rb')
print(binfile.readline())
binfile.close()