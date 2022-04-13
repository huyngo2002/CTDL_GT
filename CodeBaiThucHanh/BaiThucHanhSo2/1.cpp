/*Đề bài:
Cho dãy a có n số nguyên và số nguyên s. Cần lấy ít nhất bao nhiêu số trong dãy a
để được tổng p lớn hơn s.
*/
#include <bits/stdc++.h>
using namespace std;
void sortAscending(int *a, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}
int main()
{
    int n, s, p = 0, cnt = 0;
    do
    {
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
        if (n < 1)  cout << "Ban nhap sai. Moi nhap lai:\n";
    }
    while(n < 1);
    int a[n];
    cout << "Nhap day a co " << n << " phan tu:\n";
    for (int &x : a)    cin >> x;
    cout << "Nhap so nguyen s: ";
    cin >> s;
    sortAscending(a, n);
    for (int &x : a)
    {
        if(p <= s)
        {
            p += x;
            cnt++;
        }
        else break;
    }
    if (p <= s) cout << "Khong lay duoc!";
    else cout << "Can lay it nhat " << cnt << " phan tu trong day de duoc tong lon hon " << s;
    return 0;
}

