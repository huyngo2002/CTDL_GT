#include <bits/stdc++.h>
using namespace std;
template <class T>
class Vector {
	private:
		int cap, n;
		T *V;
	public:
		Vector() {
			cap = n = 0;
			V = 0;
		}
		Vector(int num);
		Vector(int k, T x);
		Vector& operator=(Vector a);
		~Vector();
		int capacity();
		int size();
		bool empty();
		void pop_back();
		T& back();
		void push_back(T x);
		T& operator[](int k);
		void insert(int k, T x);
		void extend(int newcap);
};
template<class T>
Vector<T>::Vector(int num) {
	cap = n = num;
	V = new T[n];
}
template<class T>
Vector<T>::Vector(int k, T x) {
	cap = n = k;
	V = new T[k];
	for (int i = 0; i < k; i++)	V[i] = x;
}
template<class T>
Vector<T>& Vector<T>::operator=(Vector a) {
	cap = a.capacity();
	n = a.size();
	if (cap) V = new T[cap];
	for (int i = 0; i < n; i++)
		V[i] = a[i];
	return *this;
}
template<class T>
Vector<T>::~Vector() {
	if (V) delete[]V;
}
template<class T>
int Vector<T>::capacity() {
	return cap;
}
template<class T>
int Vector<T>::size() {
	return n;
}
template<class T>
bool Vector<T>::empty() {
	return n == 0;
}
template<class T>
void Vector<T>::pop_back() {
	if(n > 0) n--;
}
template<class T>
T& Vector<T>::back() {
	return V[n - 1];
}
template <class T>
void Vector<T>::push_back(T x) {
	if (n == cap)	extend(cap * 2 + 5);
	V[n++] = x;
}
template<class T>
T& Vector<T>::operator[](int k) {
	return V[k];
}
template<class T>
void Vector<T>::insert(int k, T x) {
	if (cap == n) extend(cap * 2 + 5);
	for (int i = n - 1; i >= k; i--)
		V[i + 1] = V[i];
	V[k] = x;
	n++;
}
template<class T>
void Vector<T>::extend(int newcap) {
	if (newcap < cap) 	return;
	cap = newcap;
	T *temp = new T[cap];
	for (int i = 0; i < n; i++)
		temp[i] = V[i];
	if (V) delete []V;
	V = temp;
}
struct SinhVien {
	char maSV[20], hoDem[20], ten[20], gioiTinh[10];
	int namSinh;
	float diemTK;
};
void nhap(Vector<SinhVien> &a, int &n) {
	cout << "Nhap so sinh vien: ";
	cin >> n;
	cout << "Nhap thong tin cac sinh vien:\n";
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
		SinhVien x;
		cout << "Nhap ma sinh vien: ";
		fflush(stdin);
		gets(x.maSV);
		cout << "Nhap ho dem: ";
		fflush(stdin);
		gets(x.hoDem);
		cout << "Nhap ten: ";
		fflush(stdin);
		gets(x.ten);
		cout << "Nhap gioi tinh: ";
		fflush(stdin);
		gets(x.gioiTinh);
		cout << "Nhap nam sinh: ";
		cin >> x.namSinh;
		cout << "Nhap diem tong ket: ";
		cin >> x.diemTK;
		a.push_back(x);
	}
}
void xuat_1(SinhVien x) {
	cout << setw(20) << x.maSV << setw(20) << x.hoDem << setw(20) << x.ten
	     << setw(20) << x.gioiTinh << setw(20) << x.namSinh << setw(20) << x.diemTK << endl;
}
void xuat(Vector<SinhVien> &a, int n) {
	cout << setw(20) << "STT" << setw(20) << "Ma SV" << setw(20) << "Ho dem" << setw(20) << "Ten"
	     << setw(20) << "Gioi tinh" << setw(20) << "Nam sinh" << setw(20) << "Diem TK" << endl;
	for (int i = 0; i < n; i++) {
		cout << setw(20) << i + 1;
		xuat_1(a[i]);
	}
}
void xoaPhanTuDauTien(Vector<SinhVien> &a, int &n) {
	for (int i = 0; i < n; i++) {
		a[i] = a[i + 1];
	}
	n--;
}
void chenViTriThuBa(Vector<SinhVien> &a, int &n) {
	SinhVien x;
	cout << "Nhap thong tin sinh vien can chen:\n";
	cout << "Nhap ma sinh vien: ";
	fflush(stdin);
	gets(x.maSV);
	cout << "Nhap ho dem: ";
	fflush(stdin);
	gets(x.hoDem);
	cout << "Nhap ten: ";
	fflush(stdin);
	gets(x.ten);
	cout << "Nhap gioi tinh: ";
	fflush(stdin);
	gets(x.gioiTinh);
	cout << "Nhap nam sinh: ";
	cin >> x.namSinh;
	cout << "Nhap diem tong ket: ";
	cin >> x.diemTK;
	n++;
	a.insert(2, x);
}
void sapXepTenTangDan(Vector<SinhVien> &a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(a[i].ten, a[j].ten) > 0)
				swap(a[i], a[j]);
		}
	}
}
int main () {
	int n;
	Vector<SinhVien> a;
	nhap(a, n);
	xuat(a, n);
	xoaPhanTuDauTien(a, n);
	cout << "\nDanh sach sinh vien sau khi xoa phan tu dau tien:\n";
	xuat(a, n);
	chenViTriThuBa(a, n);
	cout << "\nDanh sach sinh vien sau khi chen them phan tu vao vi tri thu ba:\n";
	xuat(a, n);
	sapXepTenTangDan(a, n);
	cout << "\nDanh sach sinh vien sau khi sap xep theo ten tang dan:\n";
	xuat(a, n);
	return 0;
}
