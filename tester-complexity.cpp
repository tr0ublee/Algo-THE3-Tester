#include <iostream>
#include <vector>
#include <dirent.h>
#include <fstream>
#include <string>
#include <istream>
#include <cstring>
#include <ctime>
#include "the3.h"
#define YOUPATH "./your_outputs/output"
#define INPATH "./inputs/input"
#define OUTPATH "./outputs/output"
#define ASYMPPATH "./comp_inputs/input"
#define DIFF "diff -q "

using namespace std;

static int fileNum = 1;

void readWriteParams(ifstream& file,int& n, int** edgelist,double* scores, double& clock_duration){
	std::string size;
	getline(file,size);
	n=stoi(size);
	edgelist=(int**)malloc(sizeof(int*)*n);
	int j;
	int i=0;
	long val;
	while(getline(file,size)&& i<n){
		std::string append="";
		j=0;
		int* row=new int[n];
		for(char i:size){	
			
			if(i==' ' && j<n){
				row[j]=stoi(append);
				j++;	
				append="";
				continue;
			}
			append+=i;
				
				
		}
		row[j]=stoi(append);
		edgelist[i]=row;
		i++;
	}	

	std::string num=to_string(fileNum);	
	scores= new double[n];
	clock_t begin;
  	clock_t end;
  				
  	if ((begin = clock ()) == -1) cerr << "clock err" << endl;
	int retVal=Important(n,edgelist,scores);
	if ((end = clock()) == -1) cerr << "clock err" << endl;
	clock_duration = ((double)end-begin);
				
				
			
	delete scores;
	for(int i=0;i<n;i++) delete [] edgelist[i];
	free(edgelist);
}

int main(){
	ofstream comp_file("./asym-teststimes.txt");
	int fileNum=1;
	if (comp_file) {
		comp_file << N << endl;
	}
	while(fileNum<N){
		std::string num=to_string(fileNum);
		ifstream file(ASYMPPATH+num);
		if(file){
			int n=0;
			int** edgelist;
			double* scores;
			double duration;
			
			readWriteParams(file,n,edgelist,scores,duration);
			comp_file << duration << endl;
			file.close();
		}
		else{
			cerr<<"Fail"<<endl;
		}
		fileNum++;

	}
	comp_file.close();
	
	
	return 0;
}
