#include<bits/stdc++.h>
using namespace std;

class Stack{
	int top, cap;
	int *a;

	public:
		Stack(int cap) {
			this->cap = cap;
			top = -1;
			a = new int[cap];
		}

		~Stack() {
			delete[] a;
		}

		bool push(int x){
			if(top >= cap -1) {
				cout<<"Stack overflow"<<endl;
				return false;
			}
			a[++top] = x;
			return true;
		}

		int pop(){ 
			if(top == -1){
				cout << "Stack underflow"<<endl;
				return 0;
			}
			return a[top--];
		}

		int peek(){
			if(top < 0){
				cout << "Stack is Empty"<<endl;
				return 0;
			}
			return a[top];
		}

		bool isEmpty() {
			return top < 0; 
		}

};

int main(){
	Stack s(5);

	s.push(10);
	s.push(20);
	s.push(30);

	cout<< s.pop() << "Popped from stack" << endl;

	cout<< "Top element is:" << s.peek() << endl;

	cout<< "Element present is stack are:";
	while(!s.isEmpty()){
		cout << s.peek() << " ";
		s.pop();
	}

	return 0;
}

