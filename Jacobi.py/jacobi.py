
def calc(mat, curr, prev, count):
    for i in range(count):
        curr[i] = mat[i][count]
        for j in range(count):
            if (i != j):
                curr[i] -= prev[j]*mat[i][j]
        try:
            curr[i] /= mat[i][i]
        except:
            out.write("SMTHNG WENT WRONG, CHECK THE INPUT FILE\n")
            return False
    return curr, prev


out = open('exit.txt', 'w')
def iterat(matrix,var_count):    
    EPSYLON = 1/ 1000
    cycle = True
    curr = [0 for i in range(var_count)]
    prev = [0 for i in range(var_count)]
    iteration = 0
    abslut = 0
    while (cycle):
        try:
            curr, prev =  calc(matrix, curr, prev,  var_count)
        except:
            out.write("SMTHNG WENT WRONG, CHECK THE INPUT MATRIX\n")
        iteration +=1
        count = 0
        for i in range(var_count):
            abslut = curr[i] - prev[i]
            if (abs(abslut) <= EPSYLON):
                count +=1
            if (count >= var_count):
                cycle = False
            elif(iteration >=30):
                inf = "There is no solution"
                cycle = False
                return inf
            prev[i] = curr[i]
        
        for i in range(var_count):
            out.write(f"X{i+1} = "+str(round(prev[i], 4)))
            out.write('\t')
        out.write('\n')
    out.write('\n')    
   
def call():
    matrix = []
    a = 0
    with open('input.txt', 'r') as inpt:
        for line in inpt:
            if line != "\n" :
                t = len(line.split())-1
                matrix.append(list(map(int, line.split())))
            else:
                iterat (matrix, t)
                matrix = []


call()    

