using namespace std;
#include <iostream>
//#include <stack>
#include <queue>

struct node {
	int val;
	node* next;
};

class Stack {
	node* H = NULL;
	int size = 0;
public:
	void push(int x) {
		node* drugi = new node;
		drugi->val = x;
		drugi->next = H;
		H = drugi;
		//size++;
	}

	void pop() {
		if (H != NULL) {
			node* p = H;
			H = H->next;
			delete p;
			//size--;
		}
		
	}
	int top() {
		if (H != NULL) {
			cout << H->val;
			return H->val;
		}
	}
	void isEmpty(){
		if (H == NULL)cout << "\nIsEmpty";
	}
};

class Qeueu {
	node* H = NULL;
	node* R = NULL;
public:
	void isEmpty() {
		if (H == NULL)cout << "\nIsEmpty";
	}
	void Enqueue(int x) {
		node* p = new node;
		p->val = x;
		p->next = NULL;
		if (H == NULL) {
			R = p;
			H = p;
		}
		else {
			R->next = p;
			R = p;
		}
	}

	void Dequeue() {
		if (H != NULL) {
			node* p = H;
			H = H->next;
			delete p;
		}
	}
	int FrontValue() {
		if (H != NULL) {
			cout << H->val;
			return H->val;
		}
	};

};

int main()
{
	node* H = NULL;
	/*
	Stack* stos = new Stack;
	stos->push(1);
	stos->top();
	stos->pop();
	stos->isEmpty();
	*/
	Qeueu* Kolejka = new Qeueu;
	Kolejka->Enqueue(1);
	Kolejka->Enqueue(2);
	Kolejka->Enqueue(3);
	Kolejka->FrontValue();
	//Kolejka->Dequeue();
	//Kolejka->isEmpty();
	
}
