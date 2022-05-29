#include "bits/stdc++.h"
using namespace std;
class TAISAN
{
    char maTS[20];
    char tenTS[20];
    float giaTri;
    char tinhTrang[20];
public:
    void nhap();
    void xuat();
    friend void sapXep(TAISAN *a, int n);
    friend void timKiemTuanTu(TAISAN *a, int n);
    friend int binarySearch(TAISAN *a, int l, int r, float key);
    friend void timKiemNhiPhan(TAISAN *a, int n);
};
void TAISAN::nhap()
{
    cout << "Nhap ma tai san: ";
    fflush(stdin);
    gets(maTS);
    cout << "Nhap ten tai san: ";
    fflush(stdin);
    gets(tenTS);
    cout << "Nhap gia tri: ";
    cin >> giaTri;
    cout << "Nhap tinh trang: ";
    fflush(stdin);
    gets(tinhTrang);
}
void TAISAN::xuat()
{
    cout << setw(20) << maTS << setw(20) << tenTS << setw(20) << giaTri << setw(20) << tinhTrang << endl;
}
void sapXep(TAISAN *a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].giaTri < a[j].giaTri)
                swap(a[i], a[j]);
}
void timKiemTuanTu(TAISAN *a, int n)
{
    cout << "\nTIM KIEM BANG PHUONG PHAP TIM KIEM TUAN TU:\n";
    char maTSCanTim[20];
    cout << "Nhap ma tai san can tim: ";
    fflush(stdin);
    gets(maTSCanTim);
    int i = 0;
    while (i < n && strcmp(a[i].maTS, maTSCanTim) != 0)
        i++;
    if (i < n)
    {
        cout << "Tim thay tai san co ma \"" << maTSCanTim << "\" trong danh sach. Thong tin:\n";
        cout << setw(20) << "Ma tai san" << setw(20) << "Ten tai san" << setw(20) << "Gia tri" << setw(20) << "Tinh trang" << endl;
        a[i].xuat();
    }
    else
    {
        cout << "KHONG tim thay tai san co ma \"" << maTSCanTim << "\" trong danh sach.\n";
    }
}
int binarySearch(TAISAN a[], int l, int r, float key)
{
    if (r < l)  return -1;
    else
    {
        int m = (l + r) / 2;
        if (a[m].giaTri == key)    return m;
        else if (a[m].giaTri < key)
            return binarySearch(a, l, m - 1, key);
        else return binarySearch(a, m + 1, r, key);
    }
}
void timKiemNhiPhan(TAISAN *a, int n)
{
    cout << "\nTIM KIEM BANG PHUONG PHAP TIM KIEM NHI PHAN:\n";
    float gt;
    cout << "Nhap gia tri tai san can tim: ";
    cin >> gt;
    if (binarySearch(a, 0, n -1, gt) != -1)
    {
        cout << "Tim thay tai san co gia tri " << gt << " trong danh sach. Thong tin:\n";
        cout << setw(20) << "Ma tai san" << setw(20) << "Ten tai san" << setw(20) << "Gia tri" << setw(20) << "Tinh trang" << endl;
        a[binarySearch(a, 0, n -1, gt)].xuat();
    }
    else
    {
        cout << "KHONG tim thay tai san co gia tri " << gt << " trong danh sach.\n";
    }
}
int main()
{
    int n;
    do
    {
        cout << "Nhap vao so nguyen duong n (0 < n): ";
        cin >> n;
        if (n < 1)    cout << "Ban nhap sai. Moi nhap lai:\n";
    }
    while (n < 1);
    TAISAN *a = new TAISAN[n];
    cout << "Nhap vao danh sach " << n << " tai san: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin tai san thu " << i + 1 << ":\n";
        a[i].nhap();
    }
    sapXep(a, n);
    cout << "\nDANH SACH TAI SAN SAP XEP THEO THU TU GIAM DAN LA:\n";
    cout << setw(20) << "Ma tai san" << setw(20) << "Ten tai san" << setw(20) << "Gia tri" << setw(20) << "Tinh trang" << endl;
    for (int i = 0; i < n; i++)
        a[i].xuat();
    timKiemTuanTu(a, n);
    timKiemNhiPhan(a, n);
    return 0;
}
