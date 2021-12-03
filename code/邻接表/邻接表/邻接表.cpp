#include <iostream>
using namespace std;

#define N 3

struct ArcNode {
    int adjvex;
    ArcNode* next;
};

struct Node {
    int data;
    ArcNode* first;
};

int main()
{
    Node adjList[N];
    ArcNode* n1 = new ArcNode();
    n1->adjvex = 1;
    ArcNode * n2 = new ArcNode();
    n1->adjvex = 2;
    ArcNode* n3 = new ArcNode();
    n1->adjvex = 3;
    adjList[0].first = n1;
    n1->next = n2;
    cout << "Hello World!\n";
}
