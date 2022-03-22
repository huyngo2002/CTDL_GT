#include <bits/stdc++.h>
using namespace std;
int n, M;
struct dat
{
    int w = 0, v = 0;
};
dat a[105];
int dp[110][110]; // dp[i][j] là giá trị lớn nhất khi mà chọn đến gói hàng thứ i và khối lượng tối đa có thể chứa là j
int res = 0;
void Solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (j < a[i].w)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].w] + a[i].v);
            res = max(res, dp[i][j]);
        }
    }
}
int main()
{
    cout << "Nhap so do vat: ";
    cin >> n;
    cout << "Nhap tong khoi luong balo: ";
    cin >> M;
    cout << "Nhap khoi luong va gia tri cua " << n << " do vat lan luot la:\n";
    for (int i = 1; i <= n; i++)
        cin >> a[i].w >> a[i].v;
    Solve();
    cout << "Gia tri long nhat la: " << res;
    return 0;
}
