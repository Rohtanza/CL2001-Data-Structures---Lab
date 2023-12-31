#include<iostream>
using namespace std;
class Node {
	public:
		string val;
		Node *next;
		Node(string val) {
			this->val=val;
			next=NULL;
		}
};
class Stack {
	public:
		Node *top;

		Stack() {

		}
		~Stack() {

		}

		bool isEmpty() {
			if(top==NULL) {
				return true;
				cout<<"Stack is empty"<<endl;
			} else {
				return false;
			}
		}

		void push(string val) {

		}

		string pop() {

		}

};

class Queue {
		int front;
		int rear;
		int size;
		string *arr;
	public:
		Queue(int size) {
			front=-1;
			rear=-1;
			this->size=size;
			arr=new string[size];
		}
		bool isEmpty() {

		}
		bool isFull() {

		}

		void enqueue(string val) {

		}

		string dequeue() {

		}

		void getFront() {
		}
};

int main() {
	int choice;
	// Set up the stack for encounters
	Stack encounters;

	Queue mansionQueue(6);
	mansionQueue.enqueue("The Gateway to Darkness");
	mansionQueue.enqueue("The Creeping Corridor");
	mansionQueue.enqueue("The Abandoned Lounge");
	mansionQueue.enqueue("The Haunted Gallery");
	mansionQueue.enqueue("The Shadowed Library");
	mansionQueue.enqueue("The Broken Window");
	cout<<"Start exploring the mansion? "<<endl;
	cout<<"1. Yes"<<endl;
	cout<<"2. No"<<endl;
	cin>>choice;
	if(choice==1) {
		// write the rest of the logic to control the mansion exploration
	} else {
		cout<<"See you next time"<<endl;
		return 0;
	}
}