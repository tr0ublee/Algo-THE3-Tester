clean:
	rm -f ./your_outputs/*.txt
	rm -f test
	rm -f matrix
build:
	mkdir your_outputs
	g++ -g the3.cpp tester.cpp -o test
matrix:
	g++ matrix-gen.cpp -o matrix
run:
	./test
all:
	make clean
	make build
	make run
