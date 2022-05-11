using namespace std;
#include <iostream>
#include <stack>
#include <queue>

int main()
{
    cout << "Hello World!\n";
    stack <int> stos;
    stos.push(123);
    cout << stos.top();
    stos.pop();
    // cout << stos.top();
    if (stos.empty()==true)cout << "\nPusty";
    else cout << "\ncos jest";
    queue <int> kolejka;
}
