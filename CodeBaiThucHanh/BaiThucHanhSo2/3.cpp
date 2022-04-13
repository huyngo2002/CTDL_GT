#include<bits/stdc++.h>
using namespace std;
#define M 5

// Khởi tạo bàn cờ rỗng (chưa đi qua ô nào cả)
void Init(int board[][M])
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            board[i][j] = 0;
}
// Kiểm tra xem vị trí (i, j) có nằm trong bàn cờ hay không
int check(int i, int j)
{
    return (i >= 0 && i < M && j >= 0 && j < M);
}
// Hiển thị kết quả đi tuần (in ma trận)
int Show(int board[][M])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%4d", board[i][j]);
        printf("\n\n");
    }
}
// Hàm quay lui để tìm đường đi cho quân mã
void Try(int step, int i, int j, int board[][M], int *I, int *J, int &OK)
{
    int m, inext, jnext;
    for (m = 0; m < 8; m++)
    {
        inext = i + I[m];
        jnext = j + J[m];
        if (check(inext, jnext) && board[inext][jnext] == 0)
        {
            board[inext][jnext] = step + 1; // thử đi tới
            if (step == M * M - 1) // hoàn tất
                OK = 1;
            else
            {
                Try(step + 1, inext, jnext, board, I, J, OK); // đi tiếp
                if (!OK)
                    board[inext][jnext] = 0;    // trả lại như cũ
            }
        }
    }
}
int main ()
{
    int board[M][M], OK = 0, i = 2, j = 0;// xuất phát tại 2, 0
    int I[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int J[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    Init(board);
    board[i][j] = 1;
    Try(1, i, j, board, I, J, OK);
    printf("\n====================\n");
    if (OK)
            Show(board);
    else
        printf("\nKhong co loi giai!");
    return 0;
}
