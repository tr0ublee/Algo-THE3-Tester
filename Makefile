clean:
	rm -rf ./your_outputs
	rm -f test
	rm -f matrix
build:
	mkdir your_outputs
	g++ tester.cpp the3.cpp -Wall -std=c++11 -o test
matrix:
	g++ matrix-gen.cpp -o matrix
run:
	./test
all:
	make clean
	make build
	make run
