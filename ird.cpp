#include <iostream>
using namespace std;
#define max 5
class ird
{
public:
    int item[max], right, left;
    void create(ird *p);
    void isempty(ird *);
    void isfull(ird *);
    void insert(ird *, int);
    int rem_left(ird *);
    int rem_right(ird *);
    void display(ird *);
};
void ird::create(ird *p)
{
    p->right = p->left = -1;
    cout << "Ird is created\n";
}
void ird::insert(ird *p, int element)
{
    if (p->right == max - 1)
    {
        cout << "Ird is overflow...\n";
    }
    else
    {
        ++p->right;
        p->item[p->right] = element;
    }
}
int ird::rem_left(ird *p)
{
    if (p->right == p->left)
    {
        cout << "Ird is underflow...\n";
    }
    else
    {
        ++p->left;
        cout << p->item[p->left] << " is removed from the so called ird\n";
        return (p->item[p->left]);
    }
}
int ird::rem_right(ird *p)
{
    if (p->right == p->left)
    {
        cout << "Ird is underflow...\n";
    }
    else
    {
        cout << p->item[p->right] << " is removed from so called ird\n";
        return (p->item[p->right--]);
    }
}
void ird::display(ird *p)
{
    for (int i = p->left + 1; i <= p->right; i++)
    {
        cout << p->item[i] << " ";
    }
}
void ird::isempty(ird *p)
{
    if (p->right == p->left)
    {
        cout << "Ird is empty\n";
    }
    else
    {
        cout << "Ird is not empty\n";
    }
}
void ird::isfull(ird *p)
{
    if (p->right == max - 1)
    {
        cout << "Ird is full\n";
    }
    else
    {
        cout << "Ird is not full\n";
    }
}

int main()
{
    int ch, x, y, n;
    ird obj, q, *p = &q;
    do
    {
        cout << "Enter your choise\n";
        cout << "\n1.create\n2.isempty\n.isfull\n4.insert\n5.rem_left\n6.rem_right\n7.display\n8.exit\n";
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
            cout << "Enter any elment\n";
            cin >> n;
            obj.insert(p, n);
            break;
        case 5:
            x=obj.rem_left(p);
            break;
        case 6:
            y=obj.rem_right(p);
            break;
        case 7:
            obj.display(p);
            break;
        case 8:
            exit(1);
        }
    } while (ch != 8);

    return 0;
}