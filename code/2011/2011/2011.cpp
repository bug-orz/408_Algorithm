#include<iostream>
using namespace std;
int mid_search1(int a[], int b[],int L) {
	int i = -1, j = -1, k = L, ans=-1;
	while (k > 0) {
		if (a[i+1] > b[j+1]) {
			j++;
			k--;
			ans = b[j];
		}
		else {
			i++;
			k--;
			ans = a[i];
		}
	}
	return ans;
}

int mid_search2(int A[], int B[], int L) {
    int m1, m2, s1, s2, d1, d2;
    s1 = s2 = 0;
    d1 = d2 = L - 1;
    while (s1 != d1 || s2 != d2)
    {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (A[m1] == B[m2])
            return A[m1];
        if (A[m1] < B[m2])//A的中位数比B的中位数小
        {
            if ((s1 + d1) % 2 == 0)//当前比较元素为奇数
            {
                s1 = m1;//A的比较范围向后移动,保留中间点
            }
            else {
                s1 = m1 + 1;//A的比较范围向后移动,不保留中间点
            }
            d2 = m2;//B的比较范围向前移动,保留中间点
        }
        else {//A的中位数比B的中位数大
            d1 = m1;//A的比较范围向前移动,保留中间点
            if ((s2 + d2) % 2 == 0)//当前比较元素为偶数
            {
                s2 = m2;//B的比较范围向后移动,保留中间点
            }
            else {
                s2 = m2 + 1;//B的比较范围向后移动,保留中间点
            }
        }
    }
    if (A[s1] < B[s2])//取小即为中位数点
        return A[s1];
    else return B[s2];

}

int main() {
	int s1[] = { 12,13,15,17,19,20,21,22,50,51 };
	int s2[] = { 2,4,6,8,11,14,19,25,28,29 };
	int L = 10;
	int ans1 = mid_search1(s1, s2, L);
    int ans2 = mid_search2(s1, s2, L);
    if (ans1 == ans2) {
        cout << ans1;
    }
	
	return 0;
}