
def str_to_int(lin):
    lst = lin.split(" ")
    int_list = [int(i) for i in lst]
    return int_list


def create_list(inpt):
    for i in range (3):
        k = inpt.readline()
        j = k.strip()
        print(str_to_int(j))
    


with open ('input.txt','r') as inpt:
    lines = int(len(inpt.readlines()))
    print(lines)
   # create_list(inpt)

