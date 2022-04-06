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
    if (p != NULL) {
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
    int p = r->val;
    H->val = r->next->val;
    H->next->val = p;
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
int main()
{
    node* H = NULL;
    node* p = new node;
    ADD(H, 3);
    ADD(H, 2);
    ADD(H, 1);
    // SHOW(H);
    //zad2(H, 3);
    //SHOW(H);
    //zad3(H);
    //zad4(H);
    //zad5(H);
    zad6(H);
   // SHOW(H);
    return 0;
}
