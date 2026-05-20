#include <iostream>
#include <cstdlib>
#include <ctime>
#include "header.h"
using namespace std;

int table[9][9];

void createTable(){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			bool notFound=true;
			int tryCount=0;
			do{
				notFound=false;
				int randNum=(rand()%9)+1;
				for(int k=0; k<9; k++){
					if(randNum==table[i][k]){
						notFound=true;
						break;
					}
				}
				for(int k=0; k<9; k++){
					if(randNum==table[k][j]){
						notFound=true;
						break;
					}
				}
				int colStart,colEnd;
				int rowStart,rowEnd;
				if(j<3){
					colStart=0, colEnd=3;
				}else if(j<6){
					colStart=3, colEnd=6;
				}else if(j<9){
					colStart=6, colEnd=9;
				}
				if(i<3){
					rowStart=0,rowEnd=3;
				}else if(i<6){
					rowStart=3,rowEnd=6;
				}else if(i<9){
					rowStart=6,rowEnd=9;
				}
				for(int k=rowStart; k<rowEnd; k++){
					for(int p=colStart; p<colEnd; p++){
						if(randNum==table[k][p]){
							notFound=true;
							break;
						}
					}
				}
				if(notFound==false){
					table[i][j]=randNum;
					break;
				}
				tryCount++;
				if(tryCount==150){
					initTable(table);
					i=-1;
					j=8;
					break;
				}
			}while(notFound);
		}
	}
}

int main(){
	srand(time(0));
	initTable(table);
	createTable();
	printTable(table);
	return 0;
}
