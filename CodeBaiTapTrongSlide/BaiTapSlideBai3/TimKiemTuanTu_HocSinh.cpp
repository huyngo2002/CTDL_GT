#include <bits/stdc++.h>
using namespace std;
class HOCSINH
{
    char maHS[20];
    char hoTen[35];
    int namSinh;
    float diemTB;
public:
    void nhap();
    void xuat();
    friend void timKiem(HOCSINH *a, int n);
};
void HOCSINH::nhap()
{
    cout << "Nhap ma hoc sinh: ";
    fflush(stdin);
    gets(maHS);
    cout << "Nhap ho va ten: ";
    fflush(stdin);
    gets(hoTen);
    cout << "Nhap nam sinh: ";
    cin >> namSinh;
    cout << "Nhap diem trung binh: ";
    cin >> diemTB;
}
void HOCSINH::xuat()
{
    cout << setw(20) << maHS << setw(35) << hoTen << setw(20) << namSinh << setw(20) << diemTB << endl;
}
void timKiem(HOCSINH *a, int n)
{
    char hoTenCanTim[35];
    cout << "Nhap vao ho va ten hoc sinh can tim: ";
    fflush(stdin);
    gets(hoTenCanTim);
    int i = 0;
    strcpy(a[n].hoTen, hoTenCanTim);
    while(strcmp(a[i].hoTen, hoTenCanTim) != 0)
        i++;
    if(i < n)
    {
        cout << "Co hoc sinh \"" << hoTenCanTim << "\" trong danh sach. Thong tin:\n";
        cout << setw(20) << "Ma hoc sinh" << setw(35) << "Ho va ten" << setw(20) << "Nam sinh" << setw(20) << "Diem TB" << endl;
        a[i].xuat();
    }
}
int main()
{
    int n;
    do
    {
        cout << "Nhap vao so nguyen duong n (0 < n < 100): ";
        cin >> n;
        if (n < 1 || n > 99)    cout << "Ban nhap sai. Moi nhap lai:\n";
    }
    while (n < 1 || n > 99);
    HOCSINH *a = new HOCSINH[n + 1];
    cout << "Nhap vao danh sach " << n << " hoc sinh:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":\n";
        a[i].nhap();
    }
    cout << "\nDanh sach hoc sinh vua nhap la: \n";
    cout << setw(20) << "Ma hoc sinh" << setw(35) << "Ho va ten" << setw(20) << "Nam sinh" << setw(20) << "Diem TB" << endl;
    for (int i = 0; i < n; i++)
        a[i].xuat();
    timKiem(a, n);
    return 0;
}
