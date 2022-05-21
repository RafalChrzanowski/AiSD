// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include <iostream>
using namespace std;
struct node {
	node *R;
	node *L;
	int val;
	/*
	//dodaæ wska¿nikj up, przy korzeniu jest null
	//node* up;
	poprzednik po³aczone to z max zmiana kierunku
	nastêpnik po³¹czone to z min
	min
	max
	
	usuñ , usuwasz jesli nie ma l i r to usuwasz, jeœli ma l ub r to ususawsz i dajewsz na to miejsce ten po lewej,a jeœli masz l i r zmieniasz element na nastêpnik
	*/
};
void insertBSR(node*& root, int x) {
	if (root == NULL) {
		root = new node;
		root->val = x;
		root->R = root->L = NULL;
	}
	else {
		if (x < root->val)
			insertBSR(root->L, x);
		else
			insertBSR(root->R, x);
	}

}
void Inorder(node* root) {
	if (root != NULL) {
		Inorder(root->L);
		cout << root->val << " ";
		Inorder(root->R);
	}
}
int main()
{
	node *root = NULL;
	insertBSR(root, 22);
	insertBSR(root, 18);
	insertBSR(root, 36);
	insertBSR(root, 12);
	insertBSR(root, 8);
	insertBSR(root, -3);
	insertBSR(root, 10);
	insertBSR(root, 8);
	insertBSR(root, 13);
	Inorder(root);
	system("PAUSE");
	return 0;
}
