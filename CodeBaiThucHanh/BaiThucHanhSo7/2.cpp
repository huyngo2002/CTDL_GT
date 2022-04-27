#include <bits/stdc++.h>
using namespace std;
#define MAX 100
struct Stack
{
    char a[MAX];
    int top;
};
Stack S;
void createStack(Stack &S)
{
    S.top = -1;
}
bool isEmpty(Stack S)
{
    return (S.top == -1);
}
bool isFull(Stack S)
{
    return (S.top == MAX - 1);
}
int push(Stack &S, char x)
{
    if (isFull(S))
        return 0;
    else
    {
        S.top++;
        S.a[S.top] = x;
        return 1;
    }
}

int pop(Stack &S, char &x)
{
    if (isEmpty(S))
        return 0;
    else
    {
        x = S.a[S.top];
        S.top--;
        return 1;
    }
}

void check(Stack S, char *s, int count)
{
    createStack(S);
    bool flag = true;
    for (int i = 0; i <= count; i++)
    {
        if (s[i] == '(' && push(S, s[i]))
        {
            flag = true;
        }
        else if (s[i] == ')')
        {
            if (pop(S, s[i]))
                flag = true;
            else
            {
                flag = false;
                break;
            }
        }
    }
    if (isEmpty(S) and flag == true)
        cout << "\nDay ngoac hop le";
    else
    {
        cout << "\nDay ngoac ko hop le";
    }
}

int main()
{
    cout << "Moi ban nhap day cac dau ngoac:\n";
    char s[MAX];
    fflush(stdin);
    gets(s);
    int count = 0;
    while (true)
    {
        if (s[count] == '(' or s[count] == ')')
            count++;
        else
            break;
    }
    cout << "Day dau ngoac ban vua nhap:\n";
    for (int i = 0; i <= count; i++)
        cout << s[i];
    check(S, s, count);
    return 0;
}

