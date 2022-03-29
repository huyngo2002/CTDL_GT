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
void xuatMang(int *a, int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << "\t";
    cout << endl;
}
void sapXep(int *a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if(a[i] > a[j])
                swap(a[i], a[j]);
}
int binarySearch(int *x, int l, int r, int key)
{
    if (r < l)  return -1;
    else
    {
        int m = (l + r) / 2;
        if (x[m] == key)    return m;
        else if (x[m] > key)
            return binarySearch(x, l, m - 1, key);
        else return binarySearch(x, m + 1, r, key);
    }
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
    cout << "Mang sap xep theo thu tu tang dan la:\n";
    xuatMang(a, n);
    cout << "Nhap so nguyen k: ";
    cin >> k;
    if(binarySearch(a, 0, n - 1, k) == -1)
        cout << "Khong tim thay " << k << " trong mang";
    else
        cout << "Tim thay " << k << " tai vi tri thu " << binarySearch(a, 0, n - 1, k);
    return 0;
}
