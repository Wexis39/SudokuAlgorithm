#include <iostream>
#include "header.h"
using namespace std;
void printTable(int table[9][9]){
	int row=0,col=0;
	for(int i=0; i<9; i++){
		cout<<"|";
		for(int j=0; j<9; j++){
			cout<<table[i][j];
			col++;
			if(col==3){
				cout<<"|";
				col=0;
			}else{
				cout<<" ";
			}
		}
		row++;
		if(row==3&&i<8){
			cout<<endl;
			for(int k=0; k<19; k++){
				cout<<"-";
			}
			row=0;
		}
		cout<<endl;
	}
}

void initTable(int table[9][9]){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			table[i][j]=0;
		}
	}
}
