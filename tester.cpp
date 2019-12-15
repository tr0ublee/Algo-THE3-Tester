#include <iostream>
#include <vector>
#include <dirent.h>
#include <fstream>
#include <string>
#include <istream>
#include <cstring>

#include "the3.h"

#define N 25
#define YOUPATH "./your_outputs/output"
#define INPATH "./inputs/input"
#define OUTPATH "./outputs/output"
#define DIFF "diff -q "

using namespace std;

static int fileNum=1;

void readWriteParams(ifstream& file,int& n, int** edgelist,double* scores){
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
	ofstream outfile(YOUPATH+num+".txt");
		if(outfile.is_open()){
				scores= new double[n];
				int retVal=Important(n,edgelist,scores);
				outfile<<retVal<<endl;
				for(int i=0;i<n;i++){
					outfile<<scores[i];
					if(i!=n-1) outfile<<" ";
				}
				outfile.close();
			}
			else{
				cerr<<"Your out file cannot be read"<<endl;
			}
	delete scores;
	for(int i=0;i<n;i++) delete [] edgelist[i];
	free(edgelist);
}

void test(){
	int correct=0;
	std::string diff(DIFF);
	std::string yourput(YOUPATH);
	std::string output(OUTPATH);
	for(int i=1;i<N;i++){
		std::string num=to_string(i);
		std::string command(diff+yourput+num+".txt "+output+num+".txt");
		int stat=system(command.c_str());
		if(!stat){ 
			cout<<"TEST "<<num<<" PASS!"<<endl;
			correct++;
		}
		else{
			cout<<"TEST "<<num<<" FAIL."<<endl;


		}
	}

	cout<<"EXPECTED GRADE: "<<(float)correct*100/(N-1)<<endl;

}

int main(){
	while(fileNum<N){
		std::string num=to_string(fileNum);
		ifstream file(INPATH+num);
		if(file){
			int n=0;
			int** edgelist;
			double* scores;
			readWriteParams(file,n,edgelist,scores);
			file.close();
		}
		else{
			cerr<<"Fail"<<endl;
		}
		fileNum++;

	}
	test();
	return 0;
}
