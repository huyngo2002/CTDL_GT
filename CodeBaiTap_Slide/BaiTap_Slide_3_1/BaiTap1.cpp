#include <bits/stdc++.h>
using namespace std;
int find(int a[], int n, int k)
{
    int i = 0;
    while(i < n && k != a[i])
        i++;
    if(i < n)
        return i;
    return -1;
}
int main()
{
    int a[] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
    int n = sizeof(a)/sizeof(a[0]);
    int k1 = 94, k2 = 45;
    if (find(a, n, k1) == -1)
        cout << "Khong tim thay " << k1 << " trong mang" << endl;
    else
        cout << "Tim thay " << k1 << " o vi tri thu " << find(a, n, k1) << endl;
    if (find(a, n, k2) == -1)
        cout << "Khong tim thay " << k2 << " trong mang" << endl;
    else
        cout << "Tim thay " << k2 << " o vi tri thu " << find(a, n, k2) << endl;
    return 0;
}
