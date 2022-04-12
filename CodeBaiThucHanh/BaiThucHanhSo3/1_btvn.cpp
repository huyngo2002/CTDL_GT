/* Bài 1_Bài tập về nhà*/
#include "bits/stdc++.h"
using namespace std;
int timKiemTuanTu(string str[], int n, string x)
{
    int i = 0;
    while(i < n && x != str[i])
        i++;
    if(i < n)
        return i;
    return -1;
}
int timKiemNhiPhan(string str[], int l, int r, string x)
{
    if (r < l)  return -1;
    else
    {
        int m = (l + r) / 2;
        if (str[m] == x)    return m;
        else if (str[m] > x)
            return timKiemNhiPhan(str, l, m - 1, x);
        else return timKiemNhiPhan(str, m + 1, r, x);
    }
}
int main ()
{
    int n;
    do
    {
        cout << "Nhap so luong tu trong tu dien n (khong qua 100 tu): ";
        cin >> n;
        if (n < 1 || n > 100) cout << "Ban nhap sai. Moi nhap lai:\n";
    }
    while(n < 1 || n > 100);
    string str[n];
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap tu thu " << i + 1 << ": ";
        getline(cin, str[i]);
    }
    sort(str, str + n);
    cout << "\tTu dien sau khi sap xep:\n";
    for (int i = 0; i < n; i++)
        cout << str[i] << endl;
    string x;
    cout << "\nTIM KIEM TUAN TU:\n";
    cout << "Nhap tu x = ";
    getline(cin, x);
    if(timKiemTuanTu(str, n, x) == -1)
        cout << "Khong tim thay \"" << x << "\" trong day";
    else
        cout << "Tim thay \"" << x << "\" o vi tri thu " << timKiemTuanTu(str, n, x);
    cout << endl;
    cout << "\nTIM KIEM NHI PHAN:\n";
    cout << "Nhap tu x = ";
    getline(cin, x);
    if(timKiemNhiPhan(str, 0, n - 1, x) == -1)
        cout << "Khong tim thay \"" << x << "\" trong day";
    else
        cout << "Tim thay \"" << x << "\" o vi tri thu " << timKiemNhiPhan(str, 0, n - 1, x);
    cout << endl;
    return 0;
}
