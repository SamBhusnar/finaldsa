#include <iostream>
#define max 5
using namespace std;
class ord
{
public:
    int item[max], right, left;
    void create(ord *);
    void isempty(ord *);
    void isfull(ord *);
    int remove(ord *);
    void ins_right(ord *, int);
    void ins_left(ord *, int);
};
void ord::create(ord *p)
{
    p->right = p->left = -1;
}
void ord::isempty(ord *p)
{
    if (p->right == p->left)
    {
        cout << "Ord is empty\n";
    }
    else
    {
        cout << "Ord is not empty\n";
    }
}
void ord::isfull(ord *p)
{
    if (p->right == max - 1)
    {
        cout << "Ord is full\n";
    }
    else
    {
        cout << "Ord is not full\n";
    }
}
void ord::ins_right(ord *p, int element)
{
    if (p->right == max - 1)
    {
        cout << "Ord is oveflow...\n";
    }
    else
    {
        ++p->right;
        p->item[p->right] = element;
    }
}
int ord::remove(ord *p)
{
    if (p->left == p->right)
    {
        cout << "Ord is undeflow...\n";
    }
    else
    {
        ++p->left;
        return (p->item[p->left]);
    }
}
void ord::ins_left(ord *p, int element)
{
    if (p->right == max - 1)
    {
        cout << "Ord is overflow...\n";
    }
    else
    {
        for (int i = p->right + 2; i < p->left + 1; i--)
        {
            p->item[i] = p->item[i - 1];
        }
        ++p->right;
        p->item[p->left] = element;
    }
}
int main()
{
    int z, n, ch;
    ord obj, q, *p = &q;
    do
    {
        cout << "Enter your choise\n";
        cout << "\n1.create\n2.isemtpy\n3.isfull\n4.ins_right\n5.ins_left\n6.remove\n7.display\n8.exit\n";
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
            obj.ins_right(p, n);
            break;
        case 5:
            cout << "Enter any element\n";
            cin >> n;
            obj.ins_left(p, n);
            break;
        case 6:
            z = obj.remove(p);
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