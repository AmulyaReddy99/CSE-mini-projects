#include <iostream>
#include <fstream>
using namespace std;

string elements[]={"H ","He","Li","Be","B ","C ","N ","O ","F ","Ne","Na","Mg","Al","Si","P ","S ","Cl","Ar","K ","Ca","Sc","Ti","V ","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y ","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I ","Xe","Cs","Ba","La","Hf","Ta","W ","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","  ","Fl","  ","Lv","  ","  "};
string l_a[]={"Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Th","Pn","U ","Np","Po","Am","Cm","Hh","Cf","Es","Fm","Md","No","Lr"};
int main(){
	// int i,n; string str,x;
	// cout<<"Enter the atomic number: ";
	// cin>>i;
	// cout<<elements[i-1];
	// fstream fp;
	// string elementdetails=elements[i-1]+".txt";
	// fp.open(elementdetails);
	// while(fp>>x)
	// 	str+=x+" ";
	// cout<<str;

	// //list all elements below this atomic no
	// cout<<"Enter the atomic below which all elements to be listed: \n";
	// cin>>n;
	// for (int i = 0; i < n; ++i)
	// 	cout<<elements[i]<<" ";

	// //list all elements below this atomic weight
	// cout<<"Enter the atomic below which all elements to be listed: \n";
	// cin>>n;
	// for (int i = 0; i < n/2; ++i)
	// 	cout<<elements[i]<<" ";
	// cout<<"\n";

	/*list of lanthanoids, actinoids, alkali, alkaline, transition, post-transion, //metals
	metalloids, 
	non-metals, noble gases //non-metals
	*/
	

	//display entire
	cout<<"1 | "<<elements[0]<<" |\t\t\t\t\t\t\t\t\t\t| "<<elements[1]<<" |\n";
	int k=2,n=0,count=0;
	for (int i = 1; i < 7; ++i){
		if(i==1||i==2) n=8;
		if(i==3||i==4||i==5||i==6) n=18;
		cout<<i+1<<" | ";
		for (int j = 0; j < n; ++j){
			if(n==8) {
				cout<<elements[k++]<<" | ";
				count++;
				if(count==2){
					cout<<"\t\t\t\t\t\t      | ";
				}
			}
			else{
				cout<<elements[k++]<<" | ";
			}
		}
		cout<<"\n";
		count=0;
	}
	cout<<"\n\n";
	for (int i = 0; i < 2; ++i){
		if (i==0) cout<<"Lanthanoids: | ";
		if (i==1) cout<<"Actinoids:   | ";
		for (int j = 0; j < 14; ++j){
			cout<<elements[k++]<<" | ";
		}
		cout<<"\n";
	}
	cout<<"Enter element: (eg.: Li) "; string el,s; cin>>el;
	ifstream fp;
	fp.open("prop.txt");
	while(getline(fp,s)){
		if(s==el) break;
	}
	while(getline(fp,s)) {
		if(s=="-") break;
		cout<<s;
	}

	//show elements in group #
	// cout<<"Enter the group number whose elements to be listed: \n";
	// cin>>n;
	// for (int i = 0; i < n; ++i)
	// 	cout<<elements[i]<<" ";
	// cout<<"\n";

	// //show elements in period #
	// cout<<"Enter the period number whose elements to be listed: \n";
	// cin>>n;
	// for (int i = 0; i < n; ++i)
	// 	cout<<elements[i]<<" ";
	// cout<<"\n";
}