all: build run

build: gcd linear quadrate

gcd: gcd.cpp
	g++ -o gcd gcd.cpp

linear: linear.cpp
	g++ -o linear linear.cpp

quadrate: quadrate.cpp
	g++ -o quadrate quadrate.cpp

run:
	./gcd
	./linear
	./quadrate
