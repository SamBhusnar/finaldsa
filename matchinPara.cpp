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
    char ch, infix[50];
    int t, i;
    i = 0;
    t = 0;
    stack obj, q, *p = &q;
    obj.create(p);
    cout << "Enter any infix exp : ";
    cin >> infix;
    while (infix != '\0')
    {
        if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
        {
            obj.push(p, infix[i]);
        }
        else if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
        {
            ch = obj.pop(p);
            if (((ch == '(') != (infix[i] == ')')) || ((ch == '{') != (infix[i] == '}')) || ((ch == '[') != (infix[i] == ']')))
            {
                t = 1;
                break;
            }
        }
        i++;
    }
    if (p->top != -1 || t == 1)
    {
        cout << "Expression is invalid\n";
        cout << infix;
    }
    else
    {
        cout << "Expression is valid\n";
        cout << infix;
    }
    return 0;
}