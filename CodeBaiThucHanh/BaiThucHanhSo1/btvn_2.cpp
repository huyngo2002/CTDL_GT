#include<bits/stdc++.h>
using namespace std;
void reverse(string str)
{
    if(str.size() == 0) return;
    reverse(str.substr(1));
    cout << str[0];
}
int main()
{
    string str;
    cout << "Moi ban nhap vao mot chuoi: ";
    getline(cin, str);
    cout << "Chuoi dao nguoc la: ";
    reverse(str);
}
