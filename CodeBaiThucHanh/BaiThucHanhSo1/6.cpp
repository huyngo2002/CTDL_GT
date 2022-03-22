#include<bits/stdc++.h>
using namespace std;
int count(int arr[], int left, int right, int x){
	if (left == right){
		if (arr[left] == x) return 1;
		else return 0;
	}
	int mid = (left + right) / 2;
		return count(arr, left, mid, x) + count(arr, mid + 1, right, x);
}
int main(){
    int n, x;
    do
    {
        cout << "Nhap so phan tu cua mang n (n > 0): ";
        cin >> n;
        if (n <= 0) cout << "Ban nhap sai. Moi nhap lai:\n";
    }while(n <= 0);
    int a[n];
    cout << "Nhap mang gom " << n << " phan tu: \n";
	for (int &k : a)    cin >> k;
	cout << "Nhap so x: ";
	cin >> x;
	cout << x << " xuat hien " << count(a, 0, n-1, x) << " lan trong mang";
	return 0;
}
