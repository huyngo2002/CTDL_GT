#include<bits/stdc++.h>
using namespace std;
int a, b;
int gcd(int a, int b)
{
    if (b == 0) return a;
    if (a % b == 0) return b;
    return gcd(b, a%b);
}
int main()
{
    cout << "Nhap 2 so a va b lan luot la: ";
    cin >> a >> b;
    cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: ";
    cout << gcd(a, b);
}
