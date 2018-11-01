#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
	string s,ans; int rand(),a,exit=1,points=0;
	ifstream fp;
	while(exit){
		a=rand()%(4); //4: number of questions in text file
		fp.open("quiz.txt");
		while(getline(fp,s)){
			try{if(a==stoi(s)) break;} catch(...){}
		}
		while(getline(fp,s)) {
			if(s=="Ans") break;
			cout<<s<<endl;
		}
		cin>>ans;
		getline(fp,s);
		if(s==ans){ cout<<"Correct"; points++; }
		else{ cout<<"Answer is: "<<s; }
		fp.close();
		cout<<"\nTo continue, press any number. Enter 0 to exit.\n"; cin>>exit;
	}
	cout<<"\nYour score is: "<<points;
}
//shanti.shfla@gmail.com