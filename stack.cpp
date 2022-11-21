// probably this code help someone
#include <iostream>
using namespace std;
#define max 5
class stack
{
public:
    int item[max], top;
    void create(stack *);
    void isempty(stack *);
    void isfull(stack *);
    void push(stack *, int);
    int pop(stack *);
    void display(stack *);
};
void stack::create(stack *p)
{
    p->top = -1;
    cout << "Stack is created\n";
}
void stack::isempty(stack *p)
{
    if (p->top == -1)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        cout << "Stack is not empty\n";
    }
}
void stack::isfull(stack *p)
{
    if (p->top == max - 1)
    {
        cout << "Stack is full\n";
    }
    else
    {
        cout << "Stack is not full\n";
    }
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
int stack ::pop(stack *p)
{
    if (p->top == -1)
    {
        cout << "Stack is underflow...\n";
    }
    else
    {
        cout << p->item[p->top] << " is removed from so called stack ";
        return (p->item[p->top--]);
    }
}
void stack::display(stack *p)
{
    for (int i = p->top; i >= 0; i--)
    {
        cout << p->item[i] << " ";
    }
}
int main()
{
    int n, z, ch;
    stack obj, q, *p = &q;
    do
    {
        cout << "Enter your choise\n";
        cout << "\n1.create\n2.isempty\n3.isfull\n4.push\n5.pop\n6.display\n7.exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.create(p);
            break;
        case 2:
            obj.isempty(p);
            break;
        case 3:
            obj.isfull(p);
            break;
        case 4:
            cout << "Enter any element\n";
            cin >> n;
            obj.push(p, n);
            break;
        case 5:
            z = obj.pop(p);
            break;
        case 6:
            obj.display(p);
            break;
        case 7:
            exit(1);
        }
    } while (ch != 7);

    return 0;
}