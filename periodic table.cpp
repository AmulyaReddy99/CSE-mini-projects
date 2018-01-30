#include <iostream>
#include <fstream>
using namespace std;

string elements[]={"H","He","Li","Be","B","C","N","O","Fe","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","H","He","Li","Be","B","C","N","O","Fe","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","H","He","Li","Be","B","C","N","O","Fe","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","H","He","Li","Be","B","C","N","O","Fe","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","H","He","Li","Be","B","C","N","O","Fe","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","H","He","Li","Be","B","C","N","O","Fe","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","H","He","Li","Be","B","C","N","O","Fe","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","H","He","Li","Be","B","C","N","O","Fe","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca"};

int main(){
	int i,n; string str,x;
	cout<<"Enter the atomic number: ";
	cin>>i;
	cout<<elements[i-1];
	fstream fp;
	string elementdetails=elements[i-1]+".txt";
	fp.open(elementdetails);
	while(fp>>x)
		str+=x+" ";
	cout<<str;

	//list all elements below this atomic no
	cout<<"Enter the atomic below which all elements to be listed: \n";
	cin>>n;
	for (int i = 0; i < n; ++i)
		cout<<elements[i]<<" ";

	//list all elements below this atomic weight
	cout<<"Enter the atomic below which all elements to be listed: \n";
	cin>>n;
	for (int i = 0; i < n/2; ++i)
		cout<<elements[i]<<" ";
	cout<<"\n";

	/*list of lanthanoids, actinoids, alkali, alkaline, transition, post-transion, //metals
	metalloids, 
	non-metals, noble gases //non-metals
	*/
	

	//display entire
	cout<<"\n"<<elements[0]<<"\t\t\t\t\t\t"<<elements[1];
	int k=2;
	for (int i = 1; i < 7; ++i){
		for (int j = 0; j < 18; ++j){
			cout<<elements[k++]<<" | ";
		}
		cout<<"\n";
	}

	//show elements in group #
	cout<<"Enter the group number whose elements to be listed: \n";
	cin>>n;
	for (int i = 0; i < n; ++i)
		cout<<elements[i]<<" ";
	cout<<"\n";

	//show elements in period #
	cout<<"Enter the period number whose elements to be listed: \n";
	cin>>n;
	for (int i = 0; i < n; ++i)
		cout<<elements[i]<<" ";
	cout<<"\n";
}