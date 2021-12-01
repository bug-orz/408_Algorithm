#include <iostream>
using namespace std;

struct node {
    double data;
    node* link;
};

class linked_list {
    node* list;
    
public:
    linked_list(int len = 50);
    double find_k(int k=5);
    void test();
};

linked_list::linked_list(int len) {
    node* temp;
    list = new node();
    list->data = 0.0;
    temp = list;
    for (int i = 1; i <= len; i++) {
        node* p = new node();
        p->data = i;
        temp->link = p;
        temp = temp->link;
    }
}

double linked_list::find_k(int k) {
    node* p1, *p2;
    p1 = list;
    p2 = list;
    for (int i = 0; i < k; i++) {
        p2 = p2->link;
    }
    while (p2) {
        p1 = p1->link;
        p2 = p2->link;
    }
    return p1->data;
}

void linked_list::test() {
    cout << list->data;
    node* p = list;
    for (int i = 0; i < 10; i++) {
        cout << p->data;
        p = p->link;
    }
    
}

int main()
{
    //linked_list().test();
    double ans = linked_list().find_k();
    cout << ans;
    return 0;
}
