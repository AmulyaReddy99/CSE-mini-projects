#include <iostream>
#include <cstdlib>
using namespace std;

int counter;

int found(int list[], int a, int k){
	for (int i = 0; i < k; ++i)
		if (a==list[i])
			return 1;
	return 0;
}

void display(int matrix[100][100], int count){
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void counterFunction(int matrix[100][100], int I, int J, int count){
	for (int i = 0; i < count-1; ++i)
	{
		if(matrix[I][i]==matrix[I][i+1])
			counter++;
	}
	for (int i = 0; i < count-1; ++i)
	{
		if(matrix[i][J]==matrix[i+1][J])
			counter++;
	}
	if(I+J==count){
		for (int i = 0, j = 0; i < count-1 && j < count-1; ++i,++j)
		{
			if(matrix[i][j]==matrix[i+1][j+1])
				counter++;
		}
		for (int i = count, j = 0; i >= 0 && j < count-1; --i, ++j)
		{
			if(matrix[i][j]==matrix[i-1][j+1])
				counter++;
		}
	}
}

void play(int matrix[100][100], int count){
	int strikeOff,f=0;
	cout<<"Enter your choice: ";
	cin>>strikeOff;
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			if (matrix[i][j]==strikeOff)
			{
				matrix[i][j]=0;
				counterFunction(matrix,i,j,count);
				f=1;
				break;
			}
		}
		if(f==1) break;
	}
	display(matrix,count);
}

int COUNTER;

int main(){ 
	int count;
	int rand(),a,f=0, list[100], k=0, matrix[100][100];
	cin>>count;
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			while(f==0){
				a=rand()%(count*count);
				if(!found(list, a, k)){
					if(a==0) a=count*count;
					cout<<a<<" ";
					f=1;
					list[k++]=a;
					matrix[i][j]=a;
				}
			}
			f=0;
		}
		cout<<"\n";
	}
	while(COUNTER-1<=count){
		while(counter-1<=count){
			play(matrix, count);
			COUNTER++;
		}
		counter=0;
	}
}