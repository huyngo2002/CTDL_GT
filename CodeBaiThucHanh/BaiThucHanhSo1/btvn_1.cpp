#include<bits/stdc++.h>
using namespace std;
int countDigit (long long n)
{
    if (n / 10 == 0)	return 1;
    return 1 + countDigit (n / 10);
}
int main()
{
    int n;
    cout << "Nhap vao so nguyen n: ";
    cin >> n;
    cout << "So chu so cua " << n << " la: " << countDigit(n);
}
