#include <bits/stdc++.h>
using namespace std;
int findMax(int x[], int left, int right)
{
    if (left == right)	return x[left];
    if (left == right - 1)
    {
        if (x[left] > x[right])	return x[left];
        else	return x[right];
    }
    int mid, maxLeft, maxRight;
    mid = (left + right) / 2;
    maxLeft = findMax(x, left, mid);
    maxRight = findMax(x, mid + 1, right);
    if(maxLeft > maxRight)	return maxLeft;
    else	return maxRight;
}
int main()
{
    int n;
    do
    {
        cout << "Nhap so phan tu cua mang n (n > 0): ";
        cin >> n;
        if (n <= 0) cout << "Ban nhap sai. Moi nhap lai:\n";
    }while(n <= 0);
    int a[n];
    cout << "Moi ban nhap vao mang " << n << " phan tu: \n";
    for (int &x : a)
        cin >> x;
    cout << "Phan tu lon nhat cua mang la: ";
    cout << findMax(a, 0, n - 1);
    return 0;
}
