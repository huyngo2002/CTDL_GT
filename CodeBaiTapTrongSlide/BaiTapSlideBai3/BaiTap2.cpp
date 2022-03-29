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
int main()
{
    int a[] = {04, 14, 24, 34, 54, 64, 74, 84, 94};
    int n = sizeof(a)/sizeof(a[0]);
    int k1 = 64, k2 = 44;
    if (binarySearch(a, 0, n - 1, k1) == -1)
        cout << "Khong tim thay " << k1 << " trong mang" << endl;
    else
        cout << "Tim thay " << k1 << " o vi tri thu " << binarySearch(a, 0, n - 1, k1) << endl;
    if (binarySearch(a, 0, n - 1, k2) == -1)
        cout << "Khong tim thay " << k2 << " trong mang" << endl;
    else
        cout << "Tim thay " << k2 << " o vi tri thu " << binarySearch(a, 0, n - 1, k2) << endl;
    return 0;
}

