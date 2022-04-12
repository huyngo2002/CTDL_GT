/*
Bài 1: Cho dãy số nguyên x = {34, 14, 24, 54, 84, 64, 94, 74, 04}
Cài đặt chương trình tìm kiếm số nguyên k1 = 94, số k2 = 55 trên dãy số nguyên x bằng phương pháp tìm kiếm tuần tự
*/
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
int main ()
{
    int a[] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
    int n = sizeof(a)/sizeof(a[0]);
    int k1 = 94, k2 = 55;
    if(find(a, n, k1) == -1)
        cout << "Khong tim thay " << k1 << " trong day";
    else
        cout << "Tim thay " << k1 << " o vi tri thu " << find(a, n, k1);
    cout << endl;
    if(find(a, n, k2) == -1)
        cout << "Khong tim thay " << k2 << " trong day";
    else
        cout << "Tim thay " << k2 << " o vi tri thu " << find(a, n, k2);
    return 0;
}
