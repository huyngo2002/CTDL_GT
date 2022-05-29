#include<bits/stdc++.h>
using namespace std;
void quickSort(string arr[], int left, int right)
{
    if(left < right)
    {
        int i = left;
        int j = right;
        string t = arr[(left + right) / 2];
        while(i <= j)
        {
            while(arr[i] < t) i++;
            while(arr[j] > t) j--;
            if(i <= j)
            {
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        quickSort(arr, left, j);
        quickSort(arr, i, right);
    }
}
void printArray(string arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    string arr[] = {"John", "Try", "Thor", "Zil", "Adam", "Dany", "Milk"};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
