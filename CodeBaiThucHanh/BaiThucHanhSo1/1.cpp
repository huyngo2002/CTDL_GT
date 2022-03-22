// Code này sử dụng quy hoạch động để tính số fibonaci. ĐPT: O(n)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f[1005]; // khai báo 1 mảng để chứa các số fibonaci
int n;
ll fib(int n) {
	if(f[n] != -1)	return f[n]; // nếu f[n] đã được tính thì trả về giá trị f[n]
	if (n == 1 || n == 2)	return f[n] = 1; // điểm dừng đệ quy n = 1 và n = 2
	return f[n] = fib(n - 1) + fib(n - 2); // công thức truy hồi
}
int main() {
    do
    {
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
        if (n <= 0) cout << "Ban nhap sai. Moi nhap lai:\n";
    }while(n <= 0);
	for (int i = 1; i <= 1000; i++)	f[i] = -1; // đánh dấu các số trong mảng chưa được tính
	cout << "So fibonaci thu " << n << " la: " << fib(n);
	cout << "\nDay " << n << " so fibonaci dau tien la:\n";
	for (int i = 1; i <= n; i++)
        cout << fib(i) << "  ";
	return 0;
}
