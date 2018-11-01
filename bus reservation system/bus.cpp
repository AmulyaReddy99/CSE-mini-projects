#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 
#include "bfs.cpp"
using namespace std;

//fixes : change the place names in txt file and in map, no of vertices in minspan

string dateDay(int k,int m,int y){
	if(m>=3) m=m-2; else m=12-m+1;
	int C = y/100,mul=0,rem=0,D = y%100;
	if(m==11 || m==12) D=D-1;
	int f = k + ((13*m-1)/5) + D + (D/4) + (C/4) - 2*C;
	if(f>=0) rem=f%7;
	else {
		if(-f>7){
			f=-f;
			while(mul<=f){
				mul*=7;
			}
			rem=mul-f;
		}
		else rem=f+7;
	}
	switch(rem){
		case 1: return "M";
		case 2: return "Tu";
		case 3: return "W";
		case 4: return "Th";
		case 5: return "F";
		case 6: return "Sat";
		case 7: return "Sun";
	}
}

int main(){
	string s, dest; int choice,exit=0,dd,mm,yy,hr,min;
	ifstream fp;
	while(exit==0){
		cout<<"\n1.BOOK NOW\n2.About\n3.Top Operators\n4.Services\n5.Exit\n6.Bill\n"; cin>>choice;
		switch(choice){
		case 1:	//BOOK NOW
			fp.open("Bus Details.txt");
			while(getline(fp,s)) if(s=="ROUTES") break;
			while(getline(fp,s)){
				if(s=="EOB") break;
				cout<<s<<endl;
			}
			while(getline(fp,s)) if(s=="CAL") break;
			cout<<"Choose the destination: ";
			cin>>dest;
			cout<<"Enter the date(DD MM YYYY) & time(HR:MIN) of boarding: ";
			cin>>dd>>mm>>yy>>hr>>min;
			while(fp>>s) 
				if(s==dest){ 
					getline(fp,s); 
					//cout<<s; //' (M,W,F) 5:30 9:30 16:10 17:07 19:40'
					size_t pos = 0,p=0,count=0,p2=0;
					while ((pos = s.find(" ")) != string::npos) {
					    string token = s.substr(0, pos);
					    count++;
					    if(count<=2){
					    	if(count==2){
					    		while((p2=token.find(","))!=string::npos){
					    			string day = token.substr(0, p2);
					    			if(day==dateDay(dd,mm,yy)){
					    				cout<<"Available on "<<day<<endl; 
					    				break;
					    			}
					    		token.erase(0, p2+1);
					    		}
					    	}
					    }
					    else{
					    	int tym = stoi(token.substr(0,token.find(":")));
					    	if(hr==tym) cout<<"Available at "<<token<<endl;
					    }
					    s.erase(0, pos+1);
					}
				}
			fp.close();
			break;
		case 2:	//ABOUT
			fp.open("Bus Details.txt");
			while(getline(fp,s)) if(s=="ABOUT") break;
			while(getline(fp,s)){
				if(s=="EOB") break;
				cout<<s<<endl;
			}
			fp.close();
			break;
		case 3:	//TOPOP
			fp.open("Bus Details.txt");
			while(getline(fp,s)) if(s=="TOPOP") break;
			while(getline(fp,s)){
				if(s=="EOB") break;	
				cout<<setw(25)<<s;
			}
			fp.close();
			break;
		case 4:	//SERVICES
			fp.open("Bus Details.txt");
			while(getline(fp,s)) if(s=="SERVICES") break;
			while(getline(fp,s)){
				if(s=="EOB") break;
				cout<<s<<endl;
			}
			fp.close();
			break;
		case 5: exit=1; break;
		case 6: //BILL
			string source;
			cout<<"Enter source: "; cin>>source;
			cout<<"\nEnter destination: "; cin>>dest;

			cout<<"Minimum bus fair: "; bfs(source,dest);
			break;
		}
	}
}