#include<iostream>
using namespace std;
int find_main(int a[],int N) {
	int temp = -1, num = 0;
	for (int i = 0; i < N; i++) {
		if (temp == a[i]) {
			num++;
		}
		else {
			num--;
			if (num < 0) {
				temp = a[i];
				num = 1;
			}
		}
	}
	num = 0;
	for (int i = 0; i < N; i++) {
		if (temp == a[i]) {
			num++;
		}
	}
	if (num > N / 2) {
		return temp;
	}
	else {
		return -1;
	}
}
int main() {
	int A1[] = {0,5,5,3,5,7,5,5};
	int A2[] = {0,5,5,3,5,1,5,7};
	int N = 8;
	cout << find_main(A1,N)<<endl;
	cout << find_main(A2,N) << endl;
	//return 0;
}