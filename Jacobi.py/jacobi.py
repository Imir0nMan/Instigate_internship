def wr_inexit(curr_answ,answ_count):
    for i in range(answ_count):
        exit.write(str(curr_answ[i]))
        exit.write('\t\t\t')


def calc(mat,curr, prev, count):
    for i in range(count):
        curr[i] = mat[i][count]
        for j in range(count):
            if (i != j):
                curr[i] -= prev[j]*mat[i][j]
        try:
            curr[i] /= mat[i][i]
        except:
            exit.write("SMTHNG WENT WRONG, CHECK THE INPUT FILE\n")
            return False
    return curr, prev


def iterat(mat,var_count):
    EPSYLON = 1/ 1000
    cycle = True
    curr = [0 for i in range(var_count)]
    prev = [0 for i in range(var_count)]
    iteration = 0
    abslut = 0
    while (cycle):
        try:
            curr, prev =  calc(mat, curr, prev,  var_count)
        except:
            break
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
        wr_inexit(prev, var_count)
        exit.write('\n')
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

try:
    with open ('input.txt', 'r') as inpt:
        line_count = int((inpt.readline()).strip())
        mat = create_list(inpt, line_count)
        inpt.close()
except:
    with open ('exit.txt', 'w') as exit:
        exit.write('There is no such file')

with open ('exit.txt', 'w') as exit:
    answ = iterat(mat, line_count)
    exit.write('The answer is\n')
    for i in range(line_count):
        exit.write(str(answ[i]))
        exit.write('\t\t\t')
    exit.write('\n')
    exit.close()

#tetsting part
i = 0
exit = open('exit.txt', 'r')
golden = open('golden.txt', 'r')
for line1 in exit:
    i += 1

    for line2 in golden:

        # matching line1 from both files
        if line1 == line2:
            # print IDENTICAL if similar
            print("Line ", i, ": IDENTICAL")
        else:
            print("Line ", i, ":")
            # else print that line from both files
            print("\tFile 1:", type(line1), end='')
            print("\tFile 2:", type(line2), end='')
        break


