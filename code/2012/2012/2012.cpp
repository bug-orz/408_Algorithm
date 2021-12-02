#include <iostream>
using namespace std;
struct node {
    char data;
    node* next;
};

node* find_suffix(node* p1, node* p2) {
    node *h1=p1,*h2=p2;
    int l0 = 0, l1 = 0;
    while (h1) {
        h1 = h1->next;
        l0++;
    }
    while (h2) {
        h2 = h2->next;
        l1++;
    }
    h1 = p1; h2 = p2;
    if (l0 > l1) {
        for (int i = 0; i < l0 - l1; i++) {
            h1 = h1->next;
        }
    }
    if (l0 < l1) {
        for (int i = 0; i < l1 - l0; i++) {
            h2 = h2->next;
        }
    }
    while (h1!=h2) {
        h2 = h2->next;
        h1 = h1->next;
    }
    return h1;
}

int main()
{
    // /////////////////////////
    node* n0 = new node();
    n0->data = 'l';
    node* temp = n0;
    node* n1 = new node();
    n1->data = 'o';
    temp->next = n1;
    temp = n1;
    node* n2 = new node();
    n2->data = 'a';
    temp->next = n2;
    temp = n2;
    node* n3 = new node();
    n3->data = 'd';
    temp->next = n3;
    temp = n3;
    node* n4 = new node();
    n4->data = 'i';
    temp->next = n4;
    temp = n4;
    node* n5 = new node();
    n5->data = 'n';
    temp->next = n5;
    temp = n5;
    node* n6 = new node();
    n6->data = 'g';
    temp->next = n6;
    temp = n6;

    node* m0 = new node();
    m0->data = 'b';
    temp = m0;
    node* m1 = new node();
    m1->data = 'e';
    temp->next = m1;
    temp = m1;
    temp->next = n4;
    // ////////////////////////
    node* p = find_suffix(n0, m0);

    while (p) {
        cout << p->data;
        p = p->next;
    }
    return 0;
}
