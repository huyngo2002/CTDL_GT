#include <bits/stdc++.h>
using namespace std;
#define MAX 6
// Kiểu dữ liệu biểu diễn 1 vị trí trong ma trận
// Gồm 2 thành phân (dòng, cột)
struct POS
{
    int row, col;
};

// Các biến toàn cục
// Ma trận đầu vào
int a[MAX][MAX] =
{
    {1, 0, 1, 1, 0, 0},
    {0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 0},
    {1, 0, 0, 0, 1, 1},
    {0, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 1},
};
// Mảng để đánh dấu những ô đã duyệt qua rồi (tránh lặp)
int mark[MAX][MAX];
// Cấp của ma trận
int n = 6;
// Mảng lưu đường đi
POS kq[100];
int nk = 0;

// Kiểm tra xem đã đến đích hay chưa
int check(POS cur, int dir)
{
    switch(dir)
    {
    case 0:
        if (cur.col == 0) return 1;
        break; // left
    case 1:
        if (!cur.row) return 1;
        break; // top
    case 2:
        if (cur.col == n - 1) return 1;
        break; // right
    case 3:
        if (cur.row == n - 1) return 1;
        break; // bottom
    }
    return 0;
}
// Khởi tạo toàn bộ mảng mark bằng 0
void initmark()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mark[i][j] = 0;
}
// Giải thuật đệ quy và quay lui để tìm đường đi
void findpath2(POS cur, int dir)
{
    if (check(cur, dir)) // đã đi được đến đích thì in kq
    {
        cout << "Tim duoc duong di:\n";
        for (int i = 0; i < nk; i++)
            cout << "(" << kq[i].row << "," << kq[i].col << ")-->";
        cout << "end\n";
    }
    // Thử 8 ô xung quanh ô đang đứng, xem có đi được tiếp ko
    for (int i = 1; i >= -1; i--)
        for (int j = 1; j >= -1; j--)
            if ((i || j) && cur.row + i >= 0 && cur.row + i < n
                    && cur.col + j >= 0 && cur.col + j < n)
            {
                POS p; // lưu ô tiếp theo có thể đi
                p.row = cur.row + i;
                p.col = cur.col + j;
                if (a[p.row][p.col] == a[cur.row][cur.col] &&
                        !mark[p.row][p.col]) // chưa đi và đi được
                {
                    mark[p.row][p.col] = 1; // đánh dấu là đã đi qua
                    kq[nk++] = p;
                    findpath2(p, dir);// tiếp tục tìm đường
                    nk--;// quay lui, hủy đường đi thử
                    mark[p.row][p.col] = 0; // hủy đánh dấu
                }
            }
}
int main ()
{
    initmark(); // khởi tạo ma trận đánh dấu
    POS start; // vị trí xuất phát
    start.row = 2;
    start.col = 2;
    mark[start.row][start.col] = 1; // đánh dấu đã duyệt
    kq[nk++] = start;
    findpath2(start, 2);
    return 0;
}
