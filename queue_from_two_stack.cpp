/*
Show how to implement a queue using two stacks. Analyze the running time of the
queue operations.
*/

#include <iostream>
#include <stack>
#include <stdlib.h> 
#include <time.h> 
using namespace std;

class QueueOnStack{

public:
	int pop();
	void add(int value);

private:
	stack<int> s1;
	stack<int> s2;
	int removeFromStack(int numberOfItems);
};

int QueueOnStack::removeFromStack(int numberOfItems){
	
	int temp;
	
	for (int i = 0; i < numberOfItems-1 ; i++){
		temp = s1.top();
		cout << "The element being removed : " << temp << endl;
		s2.push(temp);
		s1.pop();
	}
	temp = s1.top();
	for (int i = 0; i < s2.size();i++){
		s1.push(s2.top());
		s2.pop();
	}
	return temp;
}

int QueueOnStack::pop(){
	int temp;
	cout << "The size of S1 is : " << s1.size() << endl;
	int numberOfItems = s1.size();
	switch (numberOfItems){
		case 0:
			cout << "The Queue is Empty" << endl;
			throw 99;
			break;
		case 1:
			temp = s1.top();
			cout << "The value removed is : " << temp << endl;
			s1.pop();
			break;
		default:
			temp = removeFromStack(numberOfItems);
			break;
	}

	return temp;
	
}

void QueueOnStack::add(int value){
	s1.push(value);
}

int main() {
  
  	srand (time(NULL));
  	QueueOnStack q;
  
  	int valueRemoved;

  	//Removing from Empty Queue
  	try{
  		valueRemoved = q.pop();
		cout << "The value removed is : " << valueRemoved << endl;
  	} catch (int e){
  		if (e == 99){
  			cout << "The Queue is Empty "  << endl;	
  		} else {
  			cout << "Who Knows what happened " << e  << endl;
  		}
  	}
  	

	//Removing from Queue with 1 item
	q.add(2);
	valueRemoved = q.pop();
	cout << "The value removed is : " << valueRemoved << endl;
	valueRemoved = q.pop();
	cout << "The value removed is : " << valueRemoved << endl;

	//Rest of the cases
  	int value;
  	for (int i = 0; i < 10; i++){
		value =  rand() % 10 + 1;
		cout << "The Value added : " << value << endl;
		q.add(value);
	}
	
	valueRemoved = q.pop();
	cout << "The value removed is : " << valueRemoved << endl;

  	return 0;
}