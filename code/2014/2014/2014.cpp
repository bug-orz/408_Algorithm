#include<iostream>
using namespace std;

struct node {
	node* left, * right;
	int weight;
};

int WPL_helper(node* h, int depth) {
	
	if (h->left == NULL && h->right == NULL) {
		cout << "weight:  " << h->weight << "     depth:  " << depth << endl;
		return h->weight * depth;
	}
	else if(h->left == NULL){
		return  WPL_helper(h->right, ++depth);
	}
	else if (h->right == NULL) {
		return WPL_helper(h->left, ++depth);
	}
	else {
		return WPL_helper(h->left, ++depth) + WPL_helper(h->right, ++depth);
	}

}

int WPL(node* h) {
	return WPL_helper(h, 0);
}

int main() {
	node* n1 = new node();
	n1->weight = 1;
	node* n2 = new node();
	n2->weight = 2;
	node* n3 = new node();
	n3->weight = 3;
	node* n4 = new node();
	n4->weight = 4;
	node* n5 = new node();
	n5->weight = 5;
	node* n6 = new node();
	n6->weight = 6;
	n1->left = n2;
	n1->right = n3;
	n2->right = n4;
	n3->right = n5;
	n4->left = n6;
	// //////////////////
	cout << WPL(n1);

	return 0;
}