#amenamec bajanairar python
def bajanarar(a,b):   
    if (b==0):
        return a
    else:
        return bajanarar(b,a%b)

with open('exit3.txt','w') as q:
 with open('test3.txt', 'r') as pt:
   #crrlne = [line.split() for line in pt]
   x = pt.readlines()
   for i in x:
       k = eval(i.strip())
       v,b = k
       h = bajanarar(v,b)
       q.write(str(h))
       q.write('\n')
       #print(h)

#a = int(input("greq arajin tivy "))
#b = int(input("greq erkrord tivy "))

#num = bajanarar(a,b)
#print(num)
