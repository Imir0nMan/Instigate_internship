#qarakusayin havasarman armatnery
from math import sqrt

def dkrmnt(a,b,c):
    d = b*b-4*a*c
    return d

def exprlook(a,b,c):
    if (b<0):
        l=""
    else:l="+"
    if (c<0):
        p=""
    else:p="+"
    print (f"{a}x^2{l}{b}x{p}{c}")

def gcayin1(b,c):
    print(f" ===>>trvac havasarumn e {b}X={c}")
    if(b!=0):
        x=c/b
        return x
    elif(b==0 and c==0):
        print("antiv qanaki lucumner")
        return
    else:
        print("havasarumy lucum chuni")

x1,x2 = 0, 0
def qarakusayin(a, b, c):
    exprlook(a,b,c)
    d = dkrmnt(a,b,c)
    if (a == 0):
        x1 = gcayin1(b,c)
        return x1
    elif (d>0):
        x1 = (-b-sqrt(d))/(2*a)
        x2 = (-b+sqrt(d))/(2*a)
        #print(f"x1 = {(-b-sqrt(d))/(2*a)}")
        #print(f"x2 = {(-b+sqrt(d))/(2*a)}")
        return (x1,x2)
    elif(d==0):
        x1 = -b/(2*a)
        #print(f"x = {-b/(2*a)}")
        return x1
    else:
        print("havasarumy lucum chuni")
        return

with open('exit1.txt','w') as q:
 with open('test1.txt', 'r') as pt:
   # crrlne = [line.split() for line in pt]
   x = pt.readlines()
   for i in x:
       k = eval(i.strip())
       v,b,n = k
       h = qarakusayin(v,b,n)
       q.write(str(h))
       q.write('\n')
       print(h)


#a = int(input("grel a-n "))
#b = int(input("grel b-n "))
#c = int(input("grel c-n "))

#num = qarakusayin(a,b,c)
