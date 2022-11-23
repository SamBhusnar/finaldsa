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
    char infix[50], postfix[50], ch;
    int i, j;
    i = 0;
    j = 0;
    stack obj, q, *p = &q;
    cout << "Enter any infix exp\n";
    cin >> infix;
    obj.create(p);
    while (infix[i] != '\0')
    {
        if (infix[i] == '(' || infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '$' || infix[i] == '^')
        {
            obj.push(p, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (p->item[p->top] != '(')
            {
                ch = obj.pop(p);
                if (ch != '(')
                {
                    postfix[j] = ch;
                    j++;
                }
            }
            ch = obj.pop(p);
        }
        else
        {
            postfix[j] = infix[i];
            j++;
        }

        i++;
    }
    if (p->top != -1)
    {
        while (p->top != -1)
        {
            ch = obj.pop(p);
            if (ch != '(')
            {
                postfix[j] = ch;
                j++;
            }
        }
    }
    postfix[j] = '\0';
    cout << "Postfix exp=" << postfix;

    return 0;
}