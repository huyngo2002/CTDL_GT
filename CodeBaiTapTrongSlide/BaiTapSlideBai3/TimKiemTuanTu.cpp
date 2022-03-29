#include <bits/stdc++.h>
using namespace std;
void inputArray(int *a, int n)
{
    cout << "Moi ban nhap mang " << n << " phan tu:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\ta[" << i << "]: ";
        cin >> a[i];
    }
}
int find(int *a, int n, int k)
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
    int n, k;
    do
    {
        cout << "Nhap so nguyen duong n (0 < n < 100): ";
        cin >> n;
        if(n < 1 || n > 99) cout << "Ban nhap sai. Moi nhap lai:\n";
    }
    while(n < 1 || n > 99);
    int *a = new int[n];
    inputArray(a, n);
    cout << "Nhap so nguyen k: ";
    cin >> k;
    if(find(a, n, k) == -1)
        cout << "Khong tim thay " << k << " trong day";
    else
        cout << "Tim thay " << k << " o vi tri thu " << find(a, n, k);
    return 0;
}
