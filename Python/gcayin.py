#python gcayin havasarum
x=0
def gcayin1(a,b):
    if(a!=0):
        x=b/a
        return x
    elif(a==0 and b==0):
        return
    else:
        return

with open('exit2.txt','w') as q:
 with open('test2.txt', 'r') as pt:
   x = pt.readlines()
   for i in x:
       k = eval(i.strip())
       v,b = k
       h = gcayin1(v,b)
       q.write(str(h))
       q.write('\n')


#a = float(input("grel havasarman a-i gorcakicy  "))
#b = float(input("grel havasarman b-i gorcakicy  "))
#gcayin1(a,b)
