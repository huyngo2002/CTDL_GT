#include <bits/stdc++.h>
using namespace std;
/*Thuật toán quickSort sắp xếp dãy giảm dần*/
void quickSort(int arr[], int left, int right)
{
    int k, t, i, j;
    if (left < right)
    {
        k = (left + right) / 2;
        t = arr[k];
        i = left;
        j = right;
        do
        {
            while (arr[i] > t) i = i + 1;
            while (arr[j] < t) j = j - 1;
            if (i <= j)
            {
                int tg = arr[i];
                arr[i] = arr[j];
                arr[j] = tg;
                i = i + 1;
                j = j - 1;
            }
        }
        while (i <= j);
        quickSort(arr, left, j);
        quickSort(arr,i,right);
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}

