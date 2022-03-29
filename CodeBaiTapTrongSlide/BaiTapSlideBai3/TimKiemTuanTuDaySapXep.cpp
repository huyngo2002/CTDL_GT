#include <bits/stdc++.h>
using namespace std;
void nhapMang(int *a, int n)
{
    cout << "Nhap vao mang " << n << " phan tu:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\ta[" << i << "]: ";
        cin >> a[i];
    }
}
void sapXep(int *a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if(a[i] > a[j])
                swap(a[i], a[j]);
}
int timKiem(int *a, int n, int k)
{
    int i = 0;
    while(i < n && k > a[i])
        i++;
    if(i < n && a[i] == k)
        return i;
    return -1;
}
int main()
{
    int n, k;
    do
    {
        cout << "Nhap vao so nguyen duong n (0 < n < 100): ";
        cin >> n;
        if (n < 1 || n > 99)    cout << "Ban nhap sai. Moi nhap lai:\n";
    }
    while (n < 1 || n > 99);
    int *a = new int[n];
    nhapMang(a, n);
    sapXep(a, n);
    cout << "Nhap so nguyen k: ";
    cin >> k;
    if(timKiem(a, n, k) == -1)
        cout << "Khong tim thay " << k << " trong mang";
    else
        cout << "Tim thay " << k << " tai vi tri thu " << timKiem(a, n, k);
    return 0;
}
