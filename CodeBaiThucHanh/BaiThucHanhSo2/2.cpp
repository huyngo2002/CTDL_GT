#include<bits/stdc++.h>
using namespace std;
struct DoVat {
	float trongLuong, giaTri, donGia;
};
void sort(DoVat a[], int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i].donGia > a[j].donGia)
				swap(a[i], a[j]);
}
void nhap(DoVat a[], int &n, int &w) {
	cout << "Nhap so luong do vat: ";
	cin >> n;
	cout << "Nhap trong luong toi da: ";
	cin >> w;
	cout << "Nhap trong luong va gia tri cua " << n << " do vat:\n";
	for(int i=0; i<n; i++) {
		cout << "\nNhap thong tin do vat thu " << i + 1 << ":\n";
		cout << "\tTrong luong: ";
		cin >> a[i].trongLuong;
		cout << "\tGia tri: ";
		cin >> a[i].giaTri;
		a[i].donGia = a[i].giaTri / a[i].trongLuong;
	}
}
void xepbalo(DoVat a[], int n, int w) {
	sort(a, n);
	cout << "Cac do vat cho vao balo la:\n";
	for(int i=0; i<n; i++) {
		if(w >= a[i].trongLuong) {
			w -= a[i].trongLuong;
			cout << a[i].trongLuong << " " << a[i].giaTri << "\n";
		} else break;
	}
}
int main() {
	DoVat a[100];
	int n, w;
	nhap(a, n, w);
	xepbalo(a, n, w);
}
