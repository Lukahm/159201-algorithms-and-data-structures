//Name:Haomin Liu   ID:12109377

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale>
#include <sstream>

using namespace std;

/* implement your stack here */
struct Node{
	float data;
	Node *next;
};

class Stack{
	private:
		Node *listpointer;
	public:
		Stack();
		~Stack();
		void Push(float newthing);
		void Pop();
		float Top();
		bool isEmpty();
};


Stack :: Stack(){
	//constructor
	listpointer = NULL;
	
}


Stack :: ~Stack(){
//destructor
}
	
void Stack :: Push(float newthing){
	// place the new thing on top of the stack
	Node *temp;
	temp = new Node;
	temp->data = newthing;
	temp->next = listpointer;
	listpointer = temp;
}


void Stack :: Pop(){
	// remove top item from the stack
	Node *p;
	p = listpointer;
	if(listpointer != NULL){ //        check to avoid underflow
		listpointer = listpointer->next;
		delete p; //always delete a TEMPORARY variable
	}
}

float Stack :: Top(){
	// return the value of the top item
	return listpointer->data;
}

bool Stack :: isEmpty(){

	return listpointer == NULL;
	}
	
main( int argc, char** argv ){//get arguments from command line, i.e., yourexec filename
	Stack S;
	int result, op1, op2, number,i;
	result=NULL;
	char oper;
	string expression;
	ifstream input_file;
	if(argc==2) input_file.open(argv[1]);
	else { cout<< "cannot read file " << argv[1] << endl; exit(0);}
	
	while(!input_file.eof()){
		getline(input_file,expression);
		if(isdigit(expression[0])){
		  stringstream line(expression);
		  line >> number;
		  //add elements into stack	
			//modify here to deal with the Stack
		  //PUSH number
		  S.Push(number);
		  cout << "reading number " << S.Top() << endl;
		 
		  
		}
		else{
			if(expression[0]=='+' || expression[0]=='-'|| expression[0]=='/'||expression[0]=='*') {
				stringstream line(expression);
				line >> oper;
				cout << "reading operator " << oper << endl;
				//op2 = TOP
				//POP
				//op1 = TOP 
				//POP
				//compute result
				//PUSH result
				
				if(!S.isEmpty() ){
					op2 = S.Top();
					S.Pop();
				}else{
					cout << "too many operators" << endl;
					exit(0);
				}
				if(!S.isEmpty()){
					op1 = S.Top();
					S.Pop();
				}else{
					cout << "too many operators" << endl;
					exit(0);
				}
				
				if(oper == '+'){ result = op2 + op1;}
				
				if(oper == '-'){ result = op1 - op2;}
				
				if(oper == '/'){ result = op1 / op2;}
				
				if(oper == '*'){ result = op2 * op1;}
		
				S.Push(result);
		  }
		}
	}
	
	//finalanswer = TOP
	//the last element of the stack should be the final answer...
	result = S.Top();
	S.Pop();
	if(!S.isEmpty()){
		cout << "too many numbers" << endl;
		exit(0);
	}
	cout << "The result is "<<result << endl;
	
}
