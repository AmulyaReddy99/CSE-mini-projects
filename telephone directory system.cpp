#include <iostream>
#include<fstream>
using namespace std;

// void generateContactCard(){

// }
string& ltrim(string& str, const string& chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}
 
string& rtrim(string& str, const string& chars = "\t\n\v\f\r ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}
string& trim(string& str, const string& chars = "\t\n\v\f\r ")
{
    return ltrim(rtrim(str, chars), chars); 
}

int main(){ 
	string deleteline, line;
	ifstream fin;
	fin.open("Telephone dir.csv");
	ofstream temp;
	temp.open("temp.csv");
	cout << "Which line do you want to remove? ";
	cin >> deleteline;
	while (getline(fin,line))
	{ 
	    if(trim(line)!=deleteline){
	    	cout<<deleteline<<" "<<line<<endl;
	    	temp<<line<<endl;
	    }
	    else{
	    	cout<<deleteline<<" -- "<<line<<endl;
	    }
	}
	temp.close();
	fin.close();
	remove("Telephone dir.csv");
	rename("temp.csv","Telephone dir.csv");
}
	// ifstream fp; ofstream writef; 
	// string deleteline,name,searchName; long int number; 
	// int edit=0,Delete=0;
	// fp.open("telephone dir.csv");
	// while(fp>>name){
	// 	cout<<name<<endl;
	// }
	// fp.close();
	
	// //NOTE: use switch cases for each application
	// // This code 1)Takes new entry 2)Searches a string 3)Edits a phone no or name
	// writef.open("telephone dir.csv", ios_base::app);
	// cout<<"Enter the new entry";
	// cin>>name>>number;
	// writef<<"\n"<<name<<","<<number;
	// writef.close();

	// fstream f;
	// f.open("telephone dir.csv");
	// cout<<"Enter substring to search: "; cin>>searchName;
	// size_t pos = 0;
	// while(f>>name)
	// {
	// 	pos = name.find(",");
	// 	string token = name.substr(0, pos);
	// 	if(token==searchName){
	// 		cout<<name<<endl;
	// 		cout<<"Edit?(0/1) "; cin>>edit; 
	// 		if(edit){
	// 			cout<<"Enter the new name: ";
	// 			cin>>searchName;
	// 			f<<searchName;
	// 			cout<<"Edit successful";
	// 		}
	// 	}
	// 	name.erase(0, pos+1);
	// }
	// f.close();

	// edit phno or name of this guy also delete this contact
	// f.open("Telephone dir.csv");
	// cout<<"Delete?(0/1) "; cin>>Delete;
	// if(Delete){
	// 	cout<<"Enter line to delete ";
	// 	cin>>deleteline;
	// 	while(getline(f,name)){
	// 		cout<<searchName<<" : this is deleted!"<<endl;
	// 		name.replace(name.find(deleteline),deleteline.length(),"");
	// 		temp << name << endl;
	// 	}
	// }
	// f.close();

	//see for second mobile number if any

	//add to favourites and groups
// }