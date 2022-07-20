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



