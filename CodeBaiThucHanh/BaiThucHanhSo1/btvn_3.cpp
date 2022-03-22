#include<bits\stdc++.h>
using namespace std;
char findWord(string a[], int l, int r, string x)
{
    if(l > r)	return -1;
    int mid = (l+r)/2;
    if(a[mid] == x)	return mid;
    if(x < a[mid])	return findWord(a, l, mid-1, x);
    return findWord(a, mid+1, r, x);
}
int main()
{
    int n;
    do
    {
        cout << "Nhap so luong tu trong tu dien n: ";
        cin >> n;
        if (n <= 0) cout << "Ban nhap sai. Moi nhap lai:\n";
    }
    while(n <= 0);
    string str[n];
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap tu thu " << i + 1 << ": ";
        getline(cin, str[i]);
    }
    sort(str, str + n);
    string x;
    cout << "Nhap tu x = ";
    getline(cin, x);
    if(x == " ")
		if(findWord(str, 0, n-1, x) != -1)	cout << "Co dau cach trong tu dien";
		else 	cout << "Khong co dau cach trong tu dien";
    else if(findWord(str, 0, n-1, x) != -1)	cout << "Co tu \"" << x << "\" trong tu dien";
    else 	cout << "Khong co tu \"" << x << "\" trong tu dien";
    return 0;
}
