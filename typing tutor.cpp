#include <iostream>
#include<fstream>
#include <ctime>
using namespace std;

int main(){ 
	string para, str, TYPED; char *typed="this";
	ifstream in;
	in.open("paragraph.txt");
	while(in>>str){
		cout<<str;
		para+=str+" ";
	}
	cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<para<<endl;
	cout<<"\nStart right now and win the challenge.\n";
	while(typed){
		cin>>typed;
		TYPED+=typed;
	}
	cout<<"You typed:\n";
	cout<<TYPED<<endl;
	if(TYPED==para)
		cout<<"\nYou Won, No mismatch";
	else cout<<"\nMismatches at few places";
}