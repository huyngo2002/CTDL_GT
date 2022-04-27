#include<bits/stdc++.h>
using namespace std;
char kt[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
struct NODE
{
    int data;
    struct NODE *pNext;
};
struct STACK
{
    NODE *pTop;
};
void KhoiTaoStack(STACK &s)
{
    s.pTop = NULL;
}
NODE *KhoiTaoNode(int x)
{
    NODE *p = new NODE();
    if (p == NULL)
    {
        cout << "\nKhông đủ bộ nhớ để cấp phát !";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}
bool IsEmpty(STACK s)
{
    if (s.pTop == NULL)
        return false;
    return true;
}
bool Push(STACK &s, NODE *p)
{
    if (p == NULL)
    {
        return false;
    }
    if (IsEmpty(s) == false)
    {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
    return true;
}
bool Pop(STACK &s, int &x)
{
    if (IsEmpty(s) == false)
    {
        return false;
    }
    NODE *p = s.pTop;
    s.pTop = s.pTop->pNext;
    x = p->data;
    return true;
}

bool Top(STACK s, int &x)
{
    if (IsEmpty(s) == false)
    {
        return false;
    }
    x = s.pTop->data;
    return true;
}

void convertRadix(STACK &s, int radix, int decimal)
{
    while (decimal != 0)
    {
        int x = decimal % radix;
        NODE *p = KhoiTaoNode(x);
        Push(s, p);
        decimal /= radix;
    }
}

void outputStack(STACK &s)
{
    while (IsEmpty(s) == true)
    {
        int x;
        Pop(s, x);
        cout << kt[x];
    }
}

int main()
{
    STACK s;
    KhoiTaoStack(s);
    int decimal, radix;
    cout << "Nhap so can chuyen (he co so 10): ";
    cin >> decimal;
    do
    {
        cout << "Nhap co so chuyen (2, 8, 16):  ";
        cin >> radix;
        if (radix != 2 && radix != 8 && radix != 16)
            cout << "Ban nhap sai. Moi nhap lai:\n";
    }
    while(radix != 2 && radix != 8 && radix != 16);
    convertRadix(s, radix, decimal);
    cout << decimal << "(10) = ";
    outputStack(s);
    cout << "(" << radix << ")";
    cout << endl;

}
