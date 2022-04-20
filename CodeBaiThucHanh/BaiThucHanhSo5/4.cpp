/*
- Tạo một danh sách học sinh, mỗi học sinh gồm các thông tin: họ và tên, giới
tính, năm sinh, điểm tổng kết.
- Sử dụng một trong các thuật toán sắp xếp phân đoạn, vun đống hoặc trộn để sắp
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
    friend void merge(HocSinh *a, int low, int high, int mid);
    friend void mergeSort(HocSinh *a, int low, int high);
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
void merge(HocSinh *a, int low, int high, int mid)
{

    int i = low, j = mid + 1, k = 0;
    HocSinh temp[high - low + 1];
    while(i <= mid && j <= high)
    {
        if (tachTen(a[i].hoTen) < tachTen(a[j].hoTen))
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i<=mid)
        temp[k++]=a[i++];

    while(j<=high)
        temp[k++]=a[j++];

    for(i=low; i<=high; i++)
        a[i]=temp[i-low];
    return;
}
void mergeSort(HocSinh *a, int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, high, mid);
    }
    return;
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
    }
    while(n < 1);
    HocSinh *a = new HocSinh[n];
    cout << "Nhap danh sach " << n << " hoc sinh:\n";
    for (int i = 0; i  < n; i++)
    {
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":\n";
        a[i].nhap();
    }
    mergeSort(a, 0, n-1);
    cout << "Danh sach hoc sinh sau khi sap xep:\n";
    cout << setw(30) << "Ho Ten" << setw(20) << "Gioi Tinh" << setw(20) << "Nam Sinh" << setw(20) << "Diem TK" << endl;
    for (int i = 0; i < n; i++)
        a[i].xuat();
    return 0;
}
