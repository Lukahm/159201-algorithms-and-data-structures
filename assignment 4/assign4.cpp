//Haomin Liu 12109377

////////////////   159201   ///////////////////////////////////
//SAMPLE CODE FOR ASSIGNMENT 4 - Big Numbers
//2012 
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <list>

using namespace std;

/////// PART A

//copy the template class List here



template <class T>
class List {
private:
  struct Node {
    T data;
    Node *next;
  };
  int size;
  Node *front, *current;

public:
  List();
  ~List();
  void AddtoFront(T newthing);
  bool FirstItem(T & item);
  bool NextItem(T & item);
  void Reverse();
  int Size();
};

template <class T>
List<T>::List() {
  front = NULL;  current = NULL;
	size=0;
}

template <class T>
List<T>::~List() {

}

template <class T>
void List<T>::AddtoFront(T newthing) {
Node *temp;
  temp = new Node;
  temp->data = newthing;
  temp->next = front;
  front = temp;
	++size;
}

template <class T>
bool List<T>::FirstItem(T & item) {
  if (front == NULL) { return false; }
  item = front->data;
  current = front;
  return true;
}

template <class T>
bool List<T>::NextItem(T & item) {
  current = current->next;
  if (current == NULL) { return false; }
  item = current->data;
  return true;
}

template<class T>
int List<T>::Size(){
	return size;
}


template<class T>
void List<T>::Reverse(){
	Node *temp1, *temp2;
	current = front->next;
	temp2 = front;
	while(current != NULL){
		temp1 = current->next;
		current->next = front;
		front = current;
		current = temp1;
	}
	temp2->next = NULL;
}


/////// PART B
class BigNumber: public List<int> {
private:
//complete here...
//include here a List of integers, or shorts etc
List<int> L;

public:
//complete here...
//what methods do you need?  
  BigNumber();
  ~BigNumber();
  void ReadFromString (string decstring );
  void PrintBigNumber ();
  void AddBigNumbers(BigNumber B1,BigNumber B2);
};

BigNumber::BigNumber(){

}

BigNumber::~BigNumber(){
//you can keep that empty
}

void BigNumber::ReadFromString (string decstring ) {
  //cout<< "testing string passing: "<< decstring << endl;
	//read a string, adding a new node per digit of the decimal string
	// To translate 'digits' to integers: myinteger=decstring[index]-48
	
  for(int i = 0; i < decstring.size(); i++) {
      int temp=decstring[i]-48;
      cout << "Digit " << i << " is " << temp << endl;  //Comment this out for your final version
      //You need to use the AddtoFront() 
	  //////////////////////////////////////////////////////////////////
	  L.AddtoFront(temp);
  }
}

void BigNumber::PrintBigNumber () {
//complete here, print the list (i.e., use FirstItem() and NextItem() )
//remember that the print out may be inverted, depending on the order you enter the 'digits'

	/////////////////////////////////////////////////////////////////
	int item;
	bool temp=L.FirstItem(item);
	while(temp){
		cout<<item;
		temp=L.NextItem(item);
		}
	
	}

void BigNumber::AddBigNumbers(BigNumber B1,BigNumber B2){
//complete here.
//use FirstItem(), NextItem() and AddNode()
//to add two big numbers, what do you have to do? Be careful about the carry
//Remember to add the last carry, the resulting number can have one more digit than B1 or B2
   int carry =0;
	int sum=0;
	int item1=0;
	int item2 =0;
	bool temp1= B1.FirstItem(item1),temp2= B2.FirstItem(item2);
	int sumSize;
	
	
	if(B1.Size()>=B2.Size()){
		sumSize = B1.Size();
	}
	else{
		sumSize = B2.Size();
	}
	
	for(int i = 0;i<sumSize;i++){

		if(temp1=0){
			sum = item2+carry;
			 temp2= B2.NextItem(item2);
		}
		else if(item2=0){
			sum =item1+carry;
			temp1 = B1.NextItem(item1);
		}
		else{
			sum = item1+item2+carry;
			temp1 = B1.NextItem(item1);
			temp2 = B2.NextItem(item2);
		}

		
		L.AddtoFront(sum %10);
		carry = sum/10;
	}
	 if(carry)                                         
        L.AddtoFront(carry);

	
	
	}

/////// PART C

BigNumber B1,B2,RES;

main (int argc, char ** argv) {
  string numberstring;
  int stringseq=0;
  ifstream input_file;
  if(argc==2) input_file.open(argv[1]);
  else { cout<< "cannot read the file " << argv[1] << endl; exit(0);}
  while(!input_file.eof()){
    getline(input_file,numberstring);
    if(!input_file.eof()){
      cout << "reading a big number from file:" << numberstring << endl;//Comment this out for your final version
      if(stringseq==0){
        B1.ReadFromString(numberstring);
        stringseq=1;
      }
      else B2.ReadFromString(numberstring);
    }
  }
  //Reverse
  	B1.Reverse();
  //print
  B1.PrintBigNumber();//PROBLEM: Is the printing inverted? How can you solve this problem? Before or after using AddBigNumbers()?
  cout << "+" << endl;
  B2.Reverse();
  B2.PrintBigNumber();
  cout << "=" << endl;
  //compute the addition
  B1.Reverse();
  B2.Reverse();
  RES.AddBigNumbers(B1,B2);
  //print the result
  RES.PrintBigNumber();
}