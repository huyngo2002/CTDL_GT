#include<bits/stdc++.h>
using namespace std;
void bubbleSort(string arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
        for(int j = n - 1; j > i; j--)
            if(arr[j - 1] > arr[j])
            {
                string temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
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
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}
