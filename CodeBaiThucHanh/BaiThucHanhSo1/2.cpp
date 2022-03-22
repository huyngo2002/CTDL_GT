#include<bits/stdc++.h>
using namespace std;
int dem = 0;
void move(int n, char a, char b, int &dem) {
	cout << "Chuyen dia thu " << n << " tu cot " << a << " sang cot " << b << endl;
	dem++;
}
void thapHaNoi(int n, char a, char b, char c) {
	if(n == 1)	move(1, a, c, dem);
	else {
		thapHaNoi(n - 1, a, c, b);
		move(n, a, c, dem);
		thapHaNoi(n - 1, b, a, c);
	}
}
int main() {
    int n;
    do
    {
        cout << "Nhap so nguyen duong n: ";
        cin >> n;
        if (n <= 0) cout << "Ban nhap sai. Moi nhap lai:\n";
    }while(n <= 0);
	thapHaNoi(n, 'A', 'B', 'C');
	cout << "Co " << dem << " buoc chuyen";
}
