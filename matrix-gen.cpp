#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#define N 25
using namespace std;
static int fileNum=1;

void matrixGen(ofstream& file){
	int size=rand()%(fileNum*5);
	file<<size<<endl;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(i==j) file<<0;
			else{
				file<<(rand()%2 ? rand()%20 : 0);
			}
			if(j!=size-1) file<<" ";
		}
		file<<endl;
	}

}





int main(){
	std::string path="./inputs/input";
	while(fileNum<N){
		std::string num=to_string(fileNum);
		ofstream file(path+num);
		if(file.is_open()){
			matrixGen(file);
			file.close();
			
		}
		else{
			cerr<<"Fail"<<endl;
		}
		fileNum++;
	}



	return 0;
}