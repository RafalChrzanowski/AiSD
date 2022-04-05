//#include "stdafx.h"
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
        ;
        cout << p->val << "->";
        p = p->next;
       
    } 
    cout << "END";
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
void zad2(node*& H,int x) {
    node* p = H;
    while (p != NULL  && p->next!= NULL) {
        int y = p->next->val;
        if (y == x) {
            // cout << endl << "kurwaaa " << x << endl;
            DEL(p);
        }
        else
            p = p->next;
       SHOW(H);

    }
}
int main()
{
    node* H = NULL;
    node* p = new node;
    ADD(H, 1);
    ADD(H, 5);
    ADD(H, 2);
    ADD(H, 1);
   // SHOW(H);
    zad2(H, 2);
    ;
    return 0;
}
