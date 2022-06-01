#include <bits/stdc++.h> 

using namespace std;
#define ll long long
int a, n;
ll power(int a, int n)
{
    if (n == 0) return 1;
    if (n == 1)	return a;
    int x = power(a, n / 2);
    if(n % 2 == 0)	return x * x;
    else return x * x * a;
}
int main()
{
    cout << "Nhap so mu: ";
    cin >> n;
    if (n > 0)
    {
        cout << "Nhap co so: ";
        cin >> a;
        cout << a << "^" << n << " = ";
        cout << power(a, n);
    }
    if (n == 0)
    {
        do
        {
            cout << "Nhap co so a khac 0: ";
            cin >> a;
            if (a == 0) cout << "Ban nhap sai. Moi nhap lai:\n";
        }
        while(a == 0);
        cout << a << "^" << n << " = ";
        cout << power(a, n);
    }
    return 0;
}
