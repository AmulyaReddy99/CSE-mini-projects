#include <iostream>
#include<fstream>
using namespace std;

class bus{
public:
	bus();
	~bus();
};
 
int main(){ 
	ifstream fp; ofstream add; int count=0;
	//store posters and also latest informantion
	fp.open("notice board.pdf");
	
	try{
		while(fp){
			cout<<fp;
			count++;
			if(count>200)
				break;
		}
	}
	catch(...){
		cout<<"type not found...";
	}

	fp.close();


}