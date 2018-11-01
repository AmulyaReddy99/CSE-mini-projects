#include <fstream>
#include <map>
#include "minspan.cpp"
using namespace std;

map<string, int> map1;

bool bfs(string source,string dest){

	map1["A"]=1;map1["B"]=2;map1["C"]=3;map1["D"]=4;map1["E"]=5;map1["F"]=6;map1["G"]=7;
	map1["H"]=8;map1["I"]=9;map1["J"]=10;map1["K"]=11;map1["L"]=12;map1["M"]=13;map1["N"]=14;
	map1["O"]=15;map1["P"]=16;map1["Q"]=17;map1["R"]=18;map1["S"]=19;map1["T"]=20;map1["U"]=21;
	map1["V"]=22;map1["W"]=23;map1["X"]=24;map1["Y"]=25;map1["Z"]=26;

	ifstream fp; string s, e1,e2; int count=0,i=0;
	fp.open("Bus Details.txt");
	while(getline(fp,s)){
		if(s=="EOB") break;
		size_t pos = 0;
		while ((pos = s.find(" ")) != string::npos) {
			count%=3;
		    string token = s.substr(0, pos);
		    if(count==0 || count==1) {
		    	if(count==0) e1=token;
		    	if(count==1) e2=token;
		    }
		    if(count==2){
		    	// graph.insert(pair<string,int> (e1,stoi(token)));
		    	set(map1[e1],map1[e2],stoi(token));
		    }
		    s.erase(0, pos+1);
		    count++;
		}
	}
	minspan(map1[source],map1[dest]);

	fp.close();
}

// for (auto it: graph)
// {
// 	cout<<it.first<<"\t"<<it.second<<endl;
// }
// map<string,int>::iterator i;
// for (i=graph.begin(); i!=graph.end();++i)
// {
// 	cout<<i->first<<"\t"<<i->second<<endl;
// }