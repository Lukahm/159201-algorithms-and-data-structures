//159201 assignment 1 skeleton
//You need to add your own AddNode and PrintLL functions, as well as an AddMatrices function
//Name:Haomin Liu   ID:12109377
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
struct Node {  //declaration
	int row;
	int col;
	int value;
	Node *next;
};
Node *A, *B, *C; //declaration

void read_matrix(Node*&a, char *file_name);

void AddNode(Node *& listpointer, int row, int column, int value);//add nodes to the tail

void PrintMatrix(Node * listpointer,int size);

int Search(Node *listpointer, int i,int j);

void AddMatrices(Node *a, Node *b);


int c=0;

void read_matrix(Node*&a, char *file_name){//reads a matrix from a file
	int col = 0, row = 0, value = 0;
	ifstream input;
	input.open(file_name);
	if(!input.good()){
		cout << "Cannot open file " << file_name << endl;
		//Exit(0);
		return ;
	}
	string line;
	//reads the first line to get dimensions
	if(input.good()){
		//use 'getline' to scan the fist line and store it to 'line'
		getline(input,line);
		//use 'stringstream' class to create object 'sline', pass 'line' to 'sline'
		stringstream sline(line);
		//store numders to 'row' and 'col'
		sline >> row >> col;
	}
	c = row;
	//read matrix 
	for(int i = 0; i < row; ++i){
		if(input.good()) {
			getline(input,line);
			stringstream sline(line);
        	for(int j = 0; j < col; ++j){
				sline >> value;
	         //if(value == 0) continue;
				if(value != 0){AddNode(a,i,j,value);}
            //Include your own add_node(a, i, j, value); function here
				//The next line is for debbuging, it can be commented later
				//cout << "Element at (" << i << " " << j << ") is different than zero and it is: "<< value <<" " << endl;
			}
			//the next line is for debbuging purposes, it can be commented out later
			//cout << endl;
		}
	}

	input.close();
	
}

void AddNode(Node *& listpointer, int row, int column, int value){
	// add a new node to the TAIL of the list
 Node *current;
  current=listpointer;
 	if(listpointer == NULL){
		listpointer = current; 
	}else{
    while (current->next!=NULL){
      current=current->next;
    }
  }
  Node *temp;
  temp = new Node;
	temp -> row = row;
	temp -> col =column;
	temp -> value = value;
  temp->next = NULL;
  if(current!=NULL) current->next = temp;
  else listpointer=temp;
	  

 
}


void PrintMatrix(Node *listpointer, int s){
	for(int i=0; i<s; i++){
		for(int j=0; j<s; j++){
			cout << Search(listpointer,i,j) << " ";
		}
		cout << endl;
	}
}


void AddMatrices(Node *a, Node *b){

	
	for (int i=0;i<c;i++){
		for (int j=0; j<c;j++){
			int result = Search(A, i, j) + Search(B, i, j);
		if(result != 0) AddNode(C, i, j, result);
		}
	}
	
	
}



int Search(Node *listpointer, int i,int j) {
Node *current;
  current = listpointer;
  while (true) {
    if (current == NULL) { break; }
    if (current->row == i && current->col == j) {
      return current->value;
    }
    current = current->next;
  }
}


void printElements(Node *listpointer){
	Node *current;
	current = listpointer;
	int i = 0;
	while(true){
		if(current == NULL){break;}
		cout << current->value << " ";
		current = current->next;
		i++;
	}
	cout << endl;
}

int main() {
	// ALL linked-lists start empty
	A = NULL;	
	B = NULL;
	C = NULL;
	
		//if(argc!=3) {printf("needs two matrices \n"); exit(0);}
	cout << "Matrix 1: " ;
	read_matrix(A, (char*)"matrix1.txt"]); 
	printElements(A);
	PrintMatrix(A,c);
	cout <<"Matrix 2: " ;
	read_matrix(B,(char*)"matrix2.txt";
	printElements(B);
	PrintMatrix(B,c);  
	
	AddMatrices(A, B);
	cout << "Matrix Result: ";
	printElements(C);
	PrintMatrix(C,c);


}
