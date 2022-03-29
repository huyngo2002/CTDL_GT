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
    friend void sapXep(HOCSINH *a, int n);
    friend int binarySearch(HOCSINH *a, int l, int r, float k);
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
void sapXep(HOCSINH *a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if(a[i].diemTB < a[j].diemTB)
                swap(a[i], a[j]);
}
int binarySearch(HOCSINH *a, int l, int r, float k)
{
    if (r < l)  return -1;
    else
    {
        int m = (l + r) / 2;
        if (a[m].diemTB == k)   return m;
        else if (a[m].diemTB > k)
            return binarySearch(a, l, m - 1, k);
        else return binarySearch(a, m + 1, r, k);
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
    sapXep(a, n);
    cout << "\nDanh sach hoc sinh sap xep theo DTB giam dan la: \n";
    cout << setw(20) << "Ma hoc sinh" << setw(35) << "Ho va ten" << setw(20) << "Nam sinh" << setw(20) << "Diem TB" << endl;
    for (int i = 0; i < n; i++)
        a[i].xuat();
    float k;
    cout << "Nhap vao diem trung binh cua hoc sinh can tim: ";
    cin >> k;
    if (binarySearch(a, 0, n -1, k) == -1)
        cout << "Khong tim thay hoc sinh co diem trung binh bang " << k;
    else
    {
        cout << "Co hoc sinh co diem trung binh bang " << k << ". Thong tin:\n";
        cout << setw(20) << "Ma hoc sinh" << setw(35) << "Ho va ten" << setw(20) << "Nam sinh" << setw(20) << "Diem TB" << endl;
        a[binarySearch(a, 0, n - 1, k)].xuat();
    }
    return 0;
}

