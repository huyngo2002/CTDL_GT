/*
Bài 3:
- Tạo một danh sách học sinh, mỗi học sinh gồm các thông tin: họ và tên, giới
tính, năm sinh, điểm tổng kết. Danh sách được tạo sao cho điểm tổng kết của
hoc sinh trong danh sách theo thứ tự giảm dần.
- Thiết kế giải thuật tìm kiếm một học sinh theo tên và điểm tổng kết bằng
phương pháp tìm kiếm tuần tự.
- Thiết kế giải thuật tìm kiếm học sinh theo điểm tổng kết bằng phương pháp
tìm kiếm nhị phân.
*/
#include "bits/stdc++.h"
using namespace std;
class HOCSINH
{
    char hoTen[30];
    char gioiTinh[10];
    int namSinh;
    float diemTK;
public:
    void nhap();
    void xuat();
    friend void sapXep(HOCSINH *a, int n);
    friend void timKiemTuanTu(HOCSINH *a, int n);
    friend void timKiemNhiPhan(HOCSINH *a, int n);
    friend int binarySearch(HOCSINH x[], int l, int r, float key);
};
void HOCSINH::nhap()
{
    cout << "Nhap ho va ten: ";
    fflush(stdin);
    gets(hoTen);
    cout << "Nhap gioi tinh: ";
    fflush(stdin);
    gets(gioiTinh);
    cout << "Nhap nam sinh: ";
    cin >> namSinh;
    cout << "Nhap diem tong ket: ";
    cin >> diemTK;
}
void HOCSINH::xuat()
{
    cout << setw(30) << hoTen << setw(15) << gioiTinh
    << setw(15) << namSinh << setw(15) << diemTK << endl;
}
void sapXep(HOCSINH *a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].diemTK < a[j].diemTK)
                swap(a[i], a[j]);
}
void timKiemTuanTu(HOCSINH *a, int n)
{
    cout << "\nTIM KIEM BANG PHUONG PHAP TIM KIEM TUAN TU:\n";
    char hoTenCanTim[30];
    cout << "Nhap vao ho va ten hoc sinh can tim: ";
    fflush(stdin);
    gets(hoTenCanTim);
    float diem;
    cout << "Nhap vao diem tong ket cua hoc sinh can tim: ";
    cin >> diem;
    int i = 0;
    while(i < n && (strcmp(a[i].hoTen, hoTenCanTim) != 0 || diem != a[i].diemTK))
        i++;
    if(i < n)
    {
         cout << "Co hoc sinh \"" << hoTenCanTim << "\" co diem tong ket la "
         << diem << " trong danh sach. Thong tin:\n";
         cout << setw(30) << "Ho ten" << setw(15) << "Gioi tinh"
         << setw(15) << "Nam sinh" << setw(15) << "Diem TK" << endl;
         a[i].xuat();
    }
    else
        cout << "KHONG co hoc sinh \"" << hoTenCanTim
        << "\" co diem tong ket la " << diem << " trong danh sach. Thong tin:\n";
}
int binarySearch(HOCSINH x[], int l, int r, float key)
{
    if (r < l)  return -1;
    else
    {
        int m = (l + r) / 2;
        if (x[m].diemTK == key)    return m;
        else if (x[m].diemTK < key)
            return binarySearch(x, l, m - 1, key);
        else return binarySearch(x, m + 1, r, key);
    }
}
void timKiemNhiPhan(HOCSINH *a, int n)
{
    cout << "\nTIM KIEM BANG PHUONG PHAP TIM KIEM NHI PHAN:\n";
    float diem;
    cout << "Nhap vao diem tong ket cua hoc sinh can tim: ";
    cin >> diem;
    if(binarySearch(a, 0, n - 1, diem) != -1)
    {
        cout << "Co hoc sinh co diem tong ket la " << diem
        << " trong danh sach. Thong tin:\n";
        cout << setw(30) << "Ho ten" << setw(15) << "Gioi tinh"
        << setw(15) << "Nam sinh" << setw(15) << "Diem TK" << endl;
        a[binarySearch(a, 0, n - 1, diem)].xuat();
    }
    else
        cout << "Khong co hoc sinh co diem tong ket la " << diem
        << " trong danh sach.\n";
}
int main ()
{
    int n;
    do
    {
        cout << "Nhap vao so nguyen duong n (0 < n): ";
        cin >> n;
        if (n < 1)    cout << "Ban nhap sai. Moi nhap lai:\n";
    }
    while (n < 1);
    HOCSINH *a = new HOCSINH[n];
    cout << "Nhap vao danh sach " << n << " hoc sinh:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":\n";
        a[i].nhap();
    }
    sapXep(a, n);
    cout << "\nDANH SACH HOC SINH DUOC TAO LA:\n";
    cout << setw(30) << "Ho ten" << setw(15) << "Gioi tinh" << setw(15)
    << "Nam sinh" << setw(15) << "Diem TK" << endl;
    for (int i = 0; i < n; i++)
        a[i].xuat();
    timKiemTuanTu(a, n);
    timKiemNhiPhan(a, n);
    return 0;
}
