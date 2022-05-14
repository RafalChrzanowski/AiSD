Skip to content
RafalChrzanowski
/
AiSD
Public
Code
Issues
Pull requests
Actions
Projects
More
AiSD / Zadania AiSD / ConsoleApplication1 / ConsoleApplication1.cpp
@RafalChrzanowski
RafalChrzanowski Update ConsoleApplication1.cpp
…
History
1 contributor
306 lines(285 sloc)  4.03 KB
#include "stdafx.h"
#include <iostream>
using namespace std;
struct node
{
	int val;
	node* next;
};

void ADD(node*& H, int x) {
	node* p = new node;
	p->val = x;
	p->next = H;
	H = p;
}

void SHOW(node* H) {
	cout << "H->";
	node* p = H;
	while (p != NULL) {

		cout << p->val << "->";
		p = p->next;

	}
	cout << "END";
	cout << endl;
}
void DEL(node*& H) {
	if (H != NULL) {
		node* p = H;
		H = H->next;
		delete p;
	}
}
void DEL_X(node*& H, int x) {
	if (H != NULL) {
		if (H->val == x) {
			DEL(H);
		}
		else
		{
			node* p = H;
			while (p->next != NULL && p->next->val != x)
				p = p->next;
			DEL(p->next);
		}
	}
}

void COPY(node* H) {
	if (H != NULL) {
		node* p = H;
		while (p != NULL) {
			ADD(p->next, p->val);
			p = p->next->next;
		}

	}
}

void zad1(node* H) {
	cout << "H->";
	node* p = H;
	while (p != NULL) {
		int x = p->val;
		cout << p->val << "->";
		for (int i = 1; i < x; i++) {
			cout << p->val << "->";
		}
		p = p->next;
	}
	cout << "END";
}

void zad2(node*& H, int x) {
	if (H == NULL || H->next == NULL)
		return;

	int y = H->next->val;
	if (x == y)
	{
		DEL(H);
		zad2(H, x);
	}
	else
	{
		zad2(H->next, x);
	}
}

void zad3(node*& H) {
	node* p = H;
	node* q = NULL;
	while (p != NULL) {
		ADD(q, p->val);
		p = p->next;

	}
	cout << "Q"; SHOW(q);
	cout << endl;
	SHOW(H);
	cout << endl;
	p = H;
	if (p != NULL) {//pobietanie ostaniego miejsca w liscie i dodanie tam drugiej listy
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = q;
	}
	SHOW(H);
}
node* Ostatni(node* H) {
	if (H == NULL)
		return NULL;
	if (H->next == NULL) {
		return H;
	};
	Ostatni(H->next);
}

void kopia_do_listy(node*& H, node*& H2) {
	if (H == NULL)
		return;

	kopia_do_listy(H->next, H2);
	ADD(H2, H->val);
}

void zad4(node*& H) {
	node* p = NULL;
	kopia_do_listy(H, p);
	//SHOW(p);
	node* ostatni = Ostatni(H);
	if (ostatni != NULL) {
		ostatni->next = p;
	}
	SHOW(H);
}
void zad5(node* H) {
	node* r = H;
	H = r->next;
	r->next = H->next;
	H->next = r;
	SHOW(H);
}
void zad6(node* H) {
	node* p = Ostatni(H);
	node* r = H;
	int pp = r->val;
	H->val = p->val;
	p->val = pp;
	SHOW(H);
}
//________________
//09.09

void insertSortedList(node*& H, int x) {
	if (H == NULL)
		ADD(H, x);
	else
	{
		if (H->val > x)
			ADD(H, x);
		else
		{
			node* p = H;
			while (p->next != NULL && p->next->val < x)
				p = p->next;
			ADD(p->next, x);
		}
	}
}
void Enqueu(node*& Q, node*& T, int x) {
	node* p = new node;
	p->val = x;
	p->next = NULL;
	if (Q == NULL) {
		Q = p;
		T = p;
	}
	else {
		T->next = p;
		T = p;
	}

}
int LENGHT(node* H) {
	int i = 0;
	while (H != NULL) {
		H = H->next;
		i++;
	}
	return i;
}

void SPLIT(node*& H, node*& H1, node*& H2) {
	node* p = H;
	H1 = H;
	if (H != NULL && H->next == NULL) {
		H1 = H;
		H = NULL;
	}
	else
		for (int x = 0; x < (LENGHT(H) / 2) - 1; x++) {
			p = p->next;
		}

	H2 = p->next;
	p->next = NULL;
	H = NULL;

	SHOW(H); cout << endl;
	SHOW(H1); cout << endl;
	SHOW(H2); cout << endl;
}
void MERGE(node*& H, node*& H1, node*& H2) {
	if (H1 == NULL && H2 != NULL) {
		H = H2;
		H2 = NULL;
	}
	if (H1 != NULL && H2 == NULL) {
		H = H1;
		H1 = NULL;
	}
	if (H1 != NULL && H2 != NULL) {
		node* T = NULL;
		node* p = NULL;
		while (H1 && H2) {
			if (H1->val < H2->val) {
				p = H1;
				H1 = H1->next;
				if (H == NULL) {
					H = p;
					T = p;
				}
				else {
					T->next = p;
					T = p;
				}
			}
			else {
				p = H2;
				H2 = H2->next;
				if (H == NULL) {
					H = p;
					T = p;
				}
				else {
					T->next = p;
					T = p;
				}
			}
		}
		if (H1 == NULL) {
			T->next = H2;
			H2 = NULL;
		}
		else {
			T->next = H1;
			H1 = NULL;
		}


	}
}
int main()
{
	node* H = NULL;
	node* p = new node;
	//ADD(H, 5);
	//ADD(H, 3);
	//ADD(H, 2);
	//ADD(H, 1);
	// SHOW(H);
	//zad2(H, 3);
	//SHOW(H);
	//zad3(H);
	//zad4(H);
	//zad5(H);
	//zad6(H);
	// SHOW(H);
	//insertSortedList(H, 7);
	//SHOW(H);
	//LENGHT(H);
	//SHOW(H);
	node* H1 = NULL;
	ADD(H1, 22);
	ADD(H1, 18);
	ADD(H1, 3);
	node* H2 = NULL;
	ADD(H2, 16);
	ADD(H2, 7);
	ADD(H2, 3);
	ADD(H2, -6);
	//SPLIT(H, H1, H2);
	SHOW(H);
	SHOW(H1);
	SHOW(H2);
	MERGE(H, H1, H2);
	cout << "______________" << endl;
	SHOW(H);
	SHOW(H1);
	SHOW(H2);
	return 0;
}
© 2022 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
