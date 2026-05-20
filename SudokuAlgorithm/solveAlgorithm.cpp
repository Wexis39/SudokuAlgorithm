#include <iostream>
#include <ctime>
#include "header.h"
using namespace std;

int table[9][9];

void inOrderInput(){
	int num;
	printTable(table);
	for(int i=0; i<9; i++){
		for(int j=0; j<9;){
			cout<<"Enter -1 to exit if you are done entering numbers."<<endl;
			cout<<"Enter 0 for unknown cells"<<endl;
			cout<<"Number: ";
			cin>>num;
			if(num==-1){
				return;
			}
			cout << "\033[2J\033[1;1H";
			if(num<=9 && num>=0){
				table[i][j]=num;
				j++;
			}else{
				cout<<"Enter only numbers between 1 and 9"<<endl;
			}
			cout<<"***SUDOKU BOARD***"<<endl;
			printTable(table);
		}
	}
	cout << "\033[2J\033[1;1H";
}

void indexOrderInput(){
	printTable(table);
	int x,y,num,flag=false;
	do{
		cout<<"row[x] column[y]"<<endl;
		while(true){
			cout<<"(1-9) x: ";
			cin>>x;
			if(x<=9&&x>=1){
				break;
			}
			if(x==-1&&flag){
				return;
			}
			cout << "\033[2J\033[1;1H";
			cout<<"row[x] column[y]"<<endl;
			cout<<"Enter only numbers between 1 and 9"<<endl;
		}
		while(true){
			cout<<"(1-9) y: ";
			cin>>y;
			if(y<=9&&y>=1){
				break;
			}
			if(y==-1&&flag){
				return;
			}
			cout << "\033[2J\033[1;1H";
			cout<<"row[x] column[y]"<<endl;
			cout<<"Enter only numbers between 1 and 9"<<endl;
		}
		while(true){
			cout<<"(1-9) Number: ";
			cin>>num;
			if(num<=9&&num>=0){
				break;
			}
			if(num==-1&&flag){
				return;
			}
			cout << "\033[2J\033[1;1H";
			cout<<"row[x] column[y]"<<endl;
			cout<<"Enter only numbers between 1 and 9"<<endl;
		}
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				if(i==x-1&&j==y-1){
					table[i][j]=num;
				}
			}
		}
		flag=true;
		cout << "\033[2J\033[1;1H";
		cout<<"***SUDOKU BOARD***"<<endl;
		printTable(table);
		cout<<"Enter -1 to exit if you are done entering numbers."<<endl;
	}while(num!=-1);
}

void solveSudoku(){
    int original[9][9];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            original[i][j] = table[i][j];
        }
    }

    int rowResets=0;
    const int MAX_ROW_RESETS=5000;

    restart_puzzle:
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            table[i][j] = original[i][j];
        }
    }
    rowResets=0;
    int i=0;
    while(i<9){
        int j=0;
        while(j<9){
            if(original[i][j]!=0){
                j++;
                continue;
            }

            bool found=false;
            int tryCount=0;

            do{
                int randNum=(rand()%9)+1;
                bool conflict=false;
                for(int k=0; k<9; k++){
                    if(randNum == table[i][k]){
                        conflict=true;
                        break;
                    }
                }
                if(!conflict){
                    for(int k=0; k<9; k++){
                        if(randNum == table[k][j]){
                            conflict = true;
                            break;
                        }
                    }
                }
                if(!conflict){
                    int rowStart=(i/3)*3;
                    int colStart=(j/3)*3;
                    for(int k = rowStart; k < rowStart + 3; k++){
                        for(int p = colStart; p < colStart + 3; p++){
                            if(randNum==table[k][p]){
                                conflict=true;
                                break;
                            }
                        }
                        if(conflict) break;
                    }
                }
                if(!conflict){
                    table[i][j] = randNum;
                    found=true;
                    break;
                }
                tryCount++;
            }while(tryCount<250);
            if(found){
                j++;
            } else {
                for(int c=0; c<9; c++){
                    if(original[i][c] == 0) table[i][c] = 0;
                }
                if(i>0){
                    i--;
                    for(int c=0; c<9; c++){
                        if(original[i][c]==0) table[i][c]=0;
                    }
                } else {
                    goto restart_puzzle;
                }

                rowResets++;
                if(rowResets>MAX_ROW_RESETS){
                    goto restart_puzzle;
                }
                break;
            }
        }
        if(j==9){
            i++;
        }
    }
    cout<<endl;
}

int main(){
	srand(time(0));
	initTable(table);
	int num;
	do{
		cout<<"1 - Fill the entire board sequentially"<<endl;
		cout<<"2 - Enter by row and column index (Recommended)"<<endl;
		cout<<"3 - Exit"<<endl;
		cout<<"Choice: ";
		cin>>num;
		switch(num){
			case 1:
				cout<<"\033[2J\033[1;1H";
				inOrderInput();
				break;
			case 2:
				cout<<"\033[2J\033[1;1H";
				indexOrderInput();
				break;
			case 3:
				return 0;
			default:
				cout<<"\033[2J\033[1;1H";
				cout<<"-----Invalid selection. Please try again-----"<<endl;
		}
		if(num==1||num==2){
			break;
		}
	}while(true);
	cout<<"\033[2J\033[1;1H";
	cout<<"The sudoku board you created"<<endl;
	printTable(table);
	cout<<"Solving Sudoku, please wait."<<endl;
	cout<<"If it takes too long, the puzzle might be unsolvable,"<<endl;
	cout<<"or the brute-force algorithm is still searching for a solution."<<endl;
	solveSudoku();
	cout<<"***Solution***"<<endl;
	printTable(table);
	return 0;
}
