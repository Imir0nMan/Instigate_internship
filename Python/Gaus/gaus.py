class Matrix:
    __size = 0
    __linecount = 0
    def __init__(self):
        self.__matrix = []


    def set_line(self, line):
        if(self.__linecount < self.__size):
            self.__matrix.append (line)
            self.__linecount +=1
        else:
            print("out of range")


    def get_matrix(self):
        return self.__matrix


    def get_elem(self, i ,j):
        return self.__matrix[i][j]


    def set_size(self, size):
        self.__size = size




with open ('exit.txt', 'w') as exit:
        exit.write("")


def gaus(n, matr):
    with open ('exit.txt', 'a') as exit:
        x = [0 for i in range(n) ]
        mat = matr
        for i in range(n):
            if mat[i][i] == 0:
                exit.write("There is no solution")
                break
            for j in range(i+1, n):
                tem = mat[j][i]/mat[i][i]

                for k in range(n+1):
                    mat[j][k] = mat[j][k] - tem * mat[i][k]

        x[n-1] = mat[n-1][n]/mat[n-1][n-1]

        for i in range(n-2,-1,-1):
            x[i] = mat[i][n]

            for j in range(i+1,n):
                x[i] = x[i] - mat[i][j]*x[j]

            x[i] = x[i]/mat[i][i]

        for i in range(n):
            exit.write(f"X{i+1} = "+str(round(x[i], 4)))
            exit.write('\t')
        exit.write('\n')



def call():
    matrix = Matrix()
    with open('input.txt', 'r') as inpt:
        for line in inpt:
            if line != "\n" :
                t = len(line.split())-1
                matrix.set_size(t)
                curr = []
                k = list(map(int, line.split()))
                matrix.set_line(k)
            else:
                print(matrix.get_matrix())
                gaus(t, matrix.get_matrix())
call()

