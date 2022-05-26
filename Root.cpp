#include <iostream>
using namespace std;
struct node {
	node* R;
	node* L;
	int val;
	node* up;
	/*
	//dodac wskaznikj up, przy korzeniu jest null-done
	//node* up;-done
	min-done
	max-done

	poprzednik polaczone to z max zmiana kierunku
	nastêpnik polczone to z min
	usuñ , usuwasz jesli nie ma l i r to usuwasz, jeœli ma l lub r to ususawsz i dajewsz na to miejsce ten po lewej,a jeœli masz l i r zmieniasz element na nastêpnik
	*/
};
void insertBSR(node*& root, int x,node* prew=NULL) {
	if (root == NULL) {
		root = new node;
		root->up = prew;//prew to rodzic poprzedni
		root->val = x;
		root->R = root->L = NULL;
	}
	else {
		if (x < root->val)
			insertBSR(root->L, x, root);
		else
			insertBSR(root->R, x,root);
	}

}
void Inorder(node* root) {
	if (root != NULL) {
		Inorder(root->L);
		cout << root->val << " ";
			if (root->up != NULL)
				cout << "up " << root->up->val << endl;
		Inorder(root->R);
	}
}
node* min(node* root) {
	node* p = root;
	if (p != NULL) {
		while (p->L != NULL) {//schodzisz jak najbardziej w lewo
			p = p->L;
		}
		cout << p->val<<endl;
		return p;
	}
}
node* max(node* root) {
	node* p = root;
	if (p != NULL) {
		while (p->R != NULL) {//schodzisz jak najbardziej w prawo
			p = p->R;
		}
		cout << p->val << endl;
		return p;
	}
}
node* nastepnik(node* root) {
	node* p = root;
	node* child = NULL;
	if (p != NULL) {
		if (p->R == NULL) {
			child = p;
			p = p->up;
			while (p != NULL && p->L == child) {
				child = p;
				p = p->up;
			}
			cout << "Nastepnik: " << p->val << endl;
			return p;
		}
		else {
			cout << "Nastepnik: " << p->R->val << endl;
			return min(p->R);
		}
		
	}
}
node* poprzednik(node* root) {//do dokończenia
	node* p = root;
	node* child = NULL;
	if (p != NULL) {
		if (p->L == NULL) {
			child = p;
			p = p->up;
			while (p != NULL && p->R == child) {
				child = p;
				p = p->up;
			}
			cout << "Nastepnik: " << p->val << endl;
			return p;
		}
		else {
			cout << "Nastepnik: " << p->L->val << endl;
			return max(p->L);
		}

	}
}
void usun(node* root) {
	node* p = root;
	if (p != NULL) {
		if (p->L == NULL && p->R == NULL) {
			delete p;
		}
		else if (p->L != NULL && p->R != NULL) {
			delete p;
			p = nastepnik(p);
		}
		else if (p->L != NULL || p->R != NULL) {
			delete p;
			p = p->L;
		}

	}
}

int main()
{
	node* root = NULL;
	insertBSR(root, 22);
	insertBSR(root, 18);
	insertBSR(root, 36);
	insertBSR(root, 12);
	insertBSR(root, 8);
	insertBSR(root, -3);
	insertBSR(root, 10);
	insertBSR(root, 8);
	insertBSR(root, 13);
	//Inorder(root);
	//min(root);
	//max(root);
	//nastepnik(root);
	//poprzednik(root);
	system("PAUSE");
	return 0;
}
