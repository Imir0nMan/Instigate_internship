def diagonal(matr, numb):
    for i in range(numb):
        for k in range(i+1, numb):
            if abs(matr[i][i]) < abs(matr[k][i]):
                for j in range(numb+1):
                    temp = matr[i][j]
                    matr[i][j] = matr[k][j]
                    matr[k][j] = temp
    for i in range (numb-1):
        for k in range(i+1, numb):
            t = matr[k][i]/matr[i][i]
            for j in range(numb+1):
                matr[k][j] -= t*a[i][j]
    return matr

def gaus(mat, count):
    x = [count]
    for i in range(count-1, -1, -1):
        x[i] = mat[i][count]
        for j in range(i+1,count):
            if j != i:
                x[i] -= mat[i][j]*x[j]
        x[i] /= mat [i][i]
    return mat



def str_to_int(lin):
    lst = lin.split(" ")
    int_list = [int(i) for i in lst]
    return int_list


def create_list(inpt, numb):
    matrix = []
    for i in range (numb):
        k = inpt.readline()
        j = k.strip()
        matrix.append(str_to_int(j))
    return matrix



#smthing like Main
try:
    with open ('input.txt', 'r') as inpt:
        line_count = int((inpt.readline()).strip())
        mat = create_list(inpt, line_count)
        inpt.close()
except:
    with open ('exit.txt', 'w') as exit:
        exit.write('There is no such file')

with open ('exit.txt', 'w') as exit:

    exit.close()

#####################################

