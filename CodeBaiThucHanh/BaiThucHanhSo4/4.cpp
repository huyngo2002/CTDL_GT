/*
- Tạo một danh sách học sinh, mỗi học sinh gồm các thông tin: họ và tên, giới
tính, năm sinh, điểm tổng kết.
- Sử dụng một trong các thuật toán sắp xếp nổi bọt, lựa chọn hoặc chèn để sắp
xếp danh sách theo tên với thứ tự từ điển.
- Hiển thị danh sách được sắp xếp.
*/
#include <bits/stdc++.h>
using namespace std;
class HocSinh
{
    string hoTen, gioiTinh;
    int namSinh;
    float diemTK;
public:
    void nhap();
    void xuat();
    friend void selectionSort(HocSinh *a, int n);
};
void HocSinh::nhap()
{
    cin.ignore();
    cout << "Nhap ho va ten: ";
    getline(cin, hoTen);
    cout << "Nhap gioi tinh: ";
    getline(cin, gioiTinh);
    cout << "Nhap nam sinh: ";
    cin >> namSinh;
    cout << "Nhap diem tong ket: ";
    cin >> diemTK;
}
void HocSinh::xuat()
{
    cout << setw(30) << hoTen << setw(20) << gioiTinh << setw(20) << namSinh << setw(20) << diemTK << endl;
}
string tachTen(string s)
{
    string res = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if(s[i] != ' ')
            res += s[i];
        else break;
    }
    reverse(res.begin(), res.end());
    return res;
}
void selectionSort(HocSinh *a, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(tachTen(a[i].hoTen) > tachTen(a[j].hoTen))
                swap(a[i], a[j]);
        }
    }
}
int main ()
{
    int n;
    do
    {
        cout << "Nhap so luong hoc sinh: ";;
        cin >> n;
        if (n < 1)
            cout << "Ban nhap sai. Moi nhap lai:\n";
    }while(n < 1);
    HocSinh *a = new HocSinh[n];
    cout << "Nhap danh sach " << n << " hoc sinh:\n";
    for (int i = 0; i  < n; i++)
    {
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":\n";
        a[i].nhap();
    }
    selectionSort(a, n);
    cout << "Danh sach hoc sinh sau khi sap xep:\n";
    cout << setw(30) << "Ho Ten" << setw(20) << "Gioi Tinh" << setw(20) << "Nam Sinh" << setw(20) << "Diem TK" << endl;
    for (int i = 0; i < n; i++)
        a[i].xuat();
    return 0;
}
