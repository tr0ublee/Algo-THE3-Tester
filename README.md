# Algo-THE3-Tester
Algorithms THE3 Tester

How to run?
1. Place your the3.cpp file in the same directory with the tester.
2. ~$ make clean
3. ~$ make all
4. ~$ make run
(or simply, ~$ make all)

I have also added the matrix generator I have used to generate the inputs. Feel free to make it more randomized.

DISCLAIMER: You might have used a function that was not included in the original the3.h but it may work due to headers I have used in the tester. 

Basic Complexity test provided by: Ozan San
### Important: Check the original tester before you run this part!
### This part does not check if your solution is correct or not, it only measures time.
How to test the complexity of your code?

1. Place your the3.cpp file in the same directory with the tester.
2. ~$ make comp_clean
3. ~$ make comp_build
4. ~$ make comp_run
(or simply, ~$ make complexity)
You can also install the needed library (i.e. Matplotlib) using: 
~$ make installation

Basically, since we need to solve the task in O(N^3) time, we have a constant factor of c. We plot the line y=T/N^3, and check if the line has an increase or not. If you wrote the algorithm, in, say, BigTheta(N^4) time, this will be shown as an increase in the plot, otherwise, you will have a line, decaying to some constant c. 
Tl;Dr: If you wrote the code correctly, the line should not increase.

You can also edit the N_MAX variable in the Makefile to test your program for bigger inputs than 128.
