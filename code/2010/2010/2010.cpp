#include <iostream>
using namespace std;

int* init_array(int len = 20) {
    int* a = new int[len];
    for (int i = 0; i < len; i++) {
        a[i] = i;
    }
    return a;
}

void reverse(int* &temp,int start,int end) {
    int m;
    while (end > start) {
        m = temp[start];
        temp[start] = temp[end];
        temp[end] = m;
        start++;
        end--;
    }
}

void reverse_k(int* &temp,int len,int k) {
    reverse(temp, 0, k - 1);
    reverse(temp, k, len - 1);
    reverse(temp, 0, len - 1);
}

int main()
{
    int N = 20, k = 10;
    int *array = init_array(N);
    reverse_k(array, N, k);
    for (int i = 0; i < N; i++) {
        cout << array[i] << endl;
    }
    return 0;
}