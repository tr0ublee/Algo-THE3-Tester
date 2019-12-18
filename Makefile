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


N_MAX = 128

installation:
	pip install matplotlib

comp_clean:
	rm -rf ./comp_inputs
	rm -f matrcomplexity
	rm -f testcomplexity
	rm -f plot.png
comp_build:
	mkdir comp_inputs
	g++ matrcomplexity.cpp -Wall -std=c++11 -DN=$(N_MAX) -o matrcomplexity
	./matrcomplexity
	g++ the3.cpp tester-complexity.cpp -Wall -std=c++11 -DN=$(N_MAX) -o testcomplexity
comp_run:
	./testcomplexity
	python plot.py
	xdg-open plot.png

complexity:
	make comp_clean
	make comp_build
	make comp_run
	
	
