def calc(mat,curr, prev, count):
    for i in range(count):
        curr[i] = mat[i][count]
        for j in range(count):
            if (i != j):
                curr[i] -= prev[j]*mat[i][j]
        curr[i] /= mat[i][i]
    return curr, prev


def iterat(mat,var_count):
    EPSYLON = 1/ 1000
    cycle = True
    curr = [0 for i in range(var_count)]
    prev = [0 for i in range(var_count)]
    iteration = 0
    abslut = 0
    while (cycle):
        curr, prev =  calc(mat, curr, prev,  var_count)
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
    return prev


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


with open ('input.txt', 'r') as inpt:
    line_count = int((inpt.readline()).strip())
    mat = create_list(inpt, line_count)
    inpt.close()
answ = iterat(mat, line_count)
with open ('exit.txt', 'w') as exit:
    for i in range(line_count):
        exit.write(str(answ[i]))
        exit.write('\n')
    exit.close()
