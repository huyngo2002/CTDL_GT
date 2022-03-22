#include<bits\stdc++.h>
using namespace std;
int sum(int *arr, int left, int right)
{
    if(left == right)	return arr[left];
    int s = 0;
    s += sum(arr, left, (left + right) / 2);
    s += sum(arr, (left + right) / 2 + 1, right);
    return s;
}
int main()
{
    int n;
    do
    {
        cout << "Nhap so phan tu cua mang n: ";
        cin >> n;
        if (n <= 0) cout << "Ban nhap sai. Moi nhap lai:\n";
    }
    while(n <= 0);
    int a[n];
    for(int &x : a) cin >> x;
    cout << "Tong cac phan tu cua mang la: " << sum(a, 0, n-1);
    return 0;
}
