/*
Bài 2: Cho dãy số nguyên x = {04, 14, 24, 34, 54, 64, 74, 84, 94}
Mô tả quá trình tìm kiếm số nguyên k1 = 34, k2 = 60 trên dãy số nguyên x bằng phương pháp tìm kiếm nhị phân.
*/
#include <bits/stdc++.h>
using namespace std;
int binarySearch(int x[], int l, int r, int key)
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
int main ()
{
    int a[] = {04, 14, 24, 34, 54, 64, 74, 84, 94};
    int n = sizeof(a)/sizeof(a[0]);
    int k1 = 34, k2 = 60;
    if(binarySearch(a, 0, n - 1, k1) == -1)
        cout << "Khong tim thay " << k1 << " trong mang";
    else
        cout << "Tim thay " << k1 << " tai vi tri thu " << binarySearch(a, 0, n - 1, k1);
    cout << endl;
    if(binarySearch(a, 0, n - 1, k2) == -1)
        cout << "Khong tim thay " << k2 << " trong mang";
    else
        cout << "Tim thay " << k2 << " tai vi tri thu " << binarySearch(a, 0, n - 1, k2);
    return 0;
}
