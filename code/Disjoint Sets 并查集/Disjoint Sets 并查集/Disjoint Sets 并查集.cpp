#include <iostream>
using namespace std;
#define NUM_of_NODES 4

class Disjoint_Sets {
    int set[NUM_of_NODES];
public:
    Disjoint_Sets();
    int find(int x);
    void union_(int i, int j);
};

Disjoint_Sets::Disjoint_Sets() {
    for (int i = 0; i < NUM_of_NODES; i++) {
        set[i] = -1;
    }
}

int Disjoint_Sets::find(int x) {
    int temp = x;
    while (set[temp] >= 0) {
        temp = set[temp];
    }
    int head = temp;
    temp = x;
    while (set[temp] >= 0) {
        set[temp] = head;
        temp = set[temp];
    }
    return temp;
}

void Disjoint_Sets::union_(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j) {
        return;
    }
    if (i > j) {
        set[j] += set[i];
        set[i] = j;
    }
    else {
        set[i] += set[j];
        set[j] = i;
    }
}
bool check_circle(int g[4][4]) { //寻找图中的环
    Disjoint_Sets d;
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            if (g[i][j] != 0) {
                if (d.find(i) == d.find(j)) {
                    return true;
                }
                else {
                    d.union_(i, j);
                }
            }
        }
    }
    return false;
}


int main()
{
    int graph1[4][4] = { { 0,1,1,0 },{1,0,0,1},{1,0,0,1},{0,1,1,0} };
    int graph2[4][4] = { { 0,1,1,0 },{1,0,0,1},{1,0,0,0},{0,1,0,0} };
    cout << check_circle(graph1) << endl;
    cout << check_circle(graph2) << endl;
    return 0;
}