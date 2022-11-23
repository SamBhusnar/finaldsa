#include <string.h>
#include <iostream>
using namespace std;
#define max 50
class stack
{
public:
    int item[max], top;
    void create(stack *);
    void push(stack *, int);
    int pop(stack *);
};
void stack::create(stack *p)
{
    p->top = -1;
}
void stack::push(stack *p, int element)
{
    if (p->top == max - 1)
    {
        cout << "Stack is overflow...\n";
    }
    else
    {
        ++p->top;
        p->item[p->top] = element;
    }
}
int stack::pop(stack *p)
{
    if (p->top == -1)
    {
        cout << "Stack is underflow...\n";
    }
    else
    {
        return (p->item[p->top--]);
    }
}
int main()
{
    char infix[50], prefix[50], ch;
    int i, j;
    j = i = 0;
    stack *oprnd, *ops, obj, a, b;
    oprnd = &a;
    ops = &b;
    cout << "Enter any infix exp : ";
    cin >> infix;
    strrev(infix);
    obj.create(ops);
    obj.create(oprnd);
    while (infix[i] != '\0')
    {
        if (infix[i] == ')' || infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '$' || infix[i] == '^' || infix[i] == '%')
        {
            obj.push(ops, infix[i]);
        }
        else if (infix[i] == '(')
        {
            while (ops->top != -1)
            {
                ch = obj.pop(ops);
                if (ch != ')')
                {
                    obj.push(oprnd, ch);
                }
            }
        }
        else
        {
            obj.push(oprnd, infix[i]);
        }
        i++;
    }
    if (ops->top != -1)
    {
        while (ops->top != -1)
        {
            ch = obj.pop(ops);
            if (ch != ')')
            {
                obj.push(oprnd, ch);
            }
        }
    }
    while (oprnd->top != -1)
    {
        prefix[j] = obj.pop(oprnd);
        j++;
    }
    prefix[j] = '\0';
    cout << "prefix exp : " << prefix;
    return 0;
}