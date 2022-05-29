#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A[5]= {10000, 5000, 2000, 1000, 500};
    int b[5]= {0, 0, 0, 0, 0};
    int m;
    cout << "Nhap so tien can quy doi: ";
    cin >> m;
    for(int i = 0; i < 5; i++)
    {
        if(m >= A[i])
        {
            b[i] = m / A[i];
            m = m - b[i] * A[i];
        }
    }
    cout << "Can so to la:\n";
    for(int i = 0; i < 5; i++)
    {
        if(b[i] != 0)
        {
            cout << "Can " << b[i] << " to " << A[i] << " dong\n";
        }
    }
    return 0;
}
