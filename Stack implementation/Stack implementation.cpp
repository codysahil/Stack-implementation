#include<iostream>
using namespace std;

class stack {
private:
	int top;
	int size;
	int* s;
public:
	stack(int size);
	~stack();
	void push(int x);
	int pop();
	int peek(int index);
	int isFull();
	int isEmpty();
	void disp();
	int stackTop();
};

stack::stack(int size) {
	this->size = size;
	top = -1;
	s = new int[size];
}
stack::~stack() {
	delete[] s;
}

void stack::push(int x) {
	if (isFull()) {
		cout << "stack overflow" << endl;
	}
	else {
		top++;
		s[top] = x;
	}
}
int stack::pop() {
	int x = 1;
	if (isEmpty()) {
		cout << "stack underflow" << endl;
	}
	else {
		x = s[top];
		top--;

	}
	return x;
}

int stack::peek(int index) {
	int x = -1;
	if (top - index + 1 < 0 || top - index + 1 == size) {
		cout << "Invalid posn" << endl;
	}
	else {
		x = s[top - index + 1];
	}
	return x;
}

int stack::isFull() {
	if (top == size - 1) {
		return 1;
	}
	return 0;
}
int stack::isEmpty() {
	if (top == -1) {
		return 1;
	}
	return 0;
}
void stack::disp() {
	for (int i = top; i >= 0; i--) {
		cout << s[i] << " " << flush;
	}
	cout << endl;
}

int stack::stackTop() {
	if (isEmpty()) {
		return -1;
	}
	return s[top];
}

int main() {
	int a[] = { 1,3,5,7,9 };
	stack stk(sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		stk.push(a[i]);
	}
	stk.disp();
	stk.pop();
	stk.push(11);
	cout << endl;
	stk.disp();
}

