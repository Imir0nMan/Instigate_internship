# we have matrix class which is for keeping matrixes
#it have mathods to create martix in (NxN+1) sizde, to get matrix, to get specific element and to set elements in it
class Matrix:
	__size = 0
	__linecount = 0
	def __init__(self, size):
		self.__size = size
		self.__matrix = []
		for i in range(self.__size):
			self.row = [0 for i in range(self.__size+1)]
			self.__matrix.append(self.row)


	def set_line(self, line):
		if(self.__linecount < self.__size):
			self.__matrix [self.__linecount] = line
			self.__linecount +=1
		else:
			print("out of range")

	def get_matrix(self):
		return self.__matrix

	def get_elem(self, i ,j):
		return self.__matrix[i][j]


l = [[1, 2, 3], [4, 5, 6]]
k = Matrix(2)
for i in range(2):
    k.set_line(l[i])
print(k.get_matrix())
