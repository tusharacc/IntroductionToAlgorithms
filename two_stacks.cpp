/*
	Explain how to implement two stacks in one array A[1 : : n] in such a way that
	neither stack overflows unless the total number of elements in both stacks together
	is n. The PUSH and POP operations should run in O(1) time.

	Since the underlying structure is Array, Push and Pop will always be O(1)

*/
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
using namespace std;

#define MAX_SIZE 100

class TwoStacks {
	
	public:
		void addData(int stackNumber, int value);
		void removeData(int stackNumber );
		void viewStack(int stackNumber);
	
	private:
		int array[MAX_SIZE];
		int stackOneIndex_ = 0;
		int stackTwoIndex_ = MAX_SIZE - 1;
		void viewStackOne();
		void viewStackTwo();
};

void TwoStacks::viewStackOne(){

	for (int i = 0; i < stackOneIndex_; i++){
		cout << "The value at position " << i << " is :" << array[i] << endl;
	}

}

void TwoStacks::viewStackTwo(){

	for (int i = MAX_SIZE - 1; i > stackTwoIndex_; i--){
		cout << "The value at position " << i << " is :" << array[i] << endl;
	}
	
}

void TwoStacks::viewStack(int stackNumber){

	switch (stackNumber){
		case 1:
			viewStackOne();
			break;
		case 2:
			viewStackTwo();
			break;
	}
	
}

void TwoStacks::addData(int stackNumber, int value){
	if (stackOneIndex_ == stackTwoIndex_){
		cout << "Stack Overflow occurred" << endl;
		throw 99;
	}
	switch (stackNumber){
		case 1:
			array[stackOneIndex_] = value;
			stackOneIndex_++;
			cout << "Added Value : " << value << " to Stack # 1" << endl;
			cout << "stackOneIndex_ Value : " << stackOneIndex_ << endl;
			cout << "stackTwoIndex_ Value : " << stackTwoIndex_ << endl;
			viewStack(1);
			break;
		case 2:
			array[stackTwoIndex_] = value;
			stackTwoIndex_--;
			cout << "Added Value : " << value << " to Stack # 2" << endl;
			cout << "stackOneIndex_ Value : " << stackOneIndex_ << endl;
			cout << "stackTwoIndex_ Value : " << stackTwoIndex_ << endl;
			viewStack(2);
			break;
	}
}

void TwoStacks::removeData(int stackNumber ){
	if (stackOneIndex_ == 0 || stackTwoIndex_ == MAX_SIZE){
		cout << "Stack Underflow occurred";
		throw 99;
	}
	switch (stackNumber){
		case 1:
			cout << "Removing Value : " << array[stackOneIndex_] << " to Stack # 1" << endl;
			stackOneIndex_--;
			cout << "Removed value from Stack # 1" << endl;
			break;
		case 2:
			cout << "Removing Value : " << array[stackTwoIndex_] << " to Stack # 2" << endl;
			stackTwoIndex_++;
			cout << "Removed value from Stack # 2" << endl;
			break;
	}
}



int main() {
	srand (time(NULL));
	TwoStacks s;
	int stackNumber, value;
	for (int i = 0; i < MAX_SIZE; i++){
		stackNumber = i%2+1;
		value =  rand() % 10 + 1;
		cout << "The Stack Number chosen : " << stackNumber <<". The value is : " << value << endl;
		s.addData(stackNumber,value);	
	}
	

	return 0;
}