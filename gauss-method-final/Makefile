clean:
	@#rm tester.o tester jacobian.o jacobian output.txt diff.txt
	@rm *.o *.exe output.txt diff.txt


run: gauss.exe
	@./gauss.exe

gauss.exe: main.o
	@g++ main.o -o gauss.exe

main.o: main.cpp
	@g++ -c main.cpp

test: tester.exe
	@./tester.exe

tester.exe: tester.o
	@g++ tester.o -o tester.exe

tester.o: tester.cpp
	@g++ -c tester.cpp
