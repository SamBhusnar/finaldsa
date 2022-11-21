#include <iostream>
using namespace std;
#define max 5
class cir_queue
{
public:
    int item[max], rear, front;
    void create(cir_queue *);
    void isempty(cir_queue *);
    void isfull(cir_queue *);
    void insert(cir_queue *, int);
    int remove(cir_queue *);
    void display(cir_queue *);
};
void cir_queue::create(cir_queue *p)
{
    p->rear = p->front = -1;
    cout << "Circular queue is created\n";
}
void cir_queue::isempty(cir_queue *p)
{
    if (p->front = -1)
    {
        cout << "Circular queue is empty\n";
    }
    else
    {
        cout << "circular queue is not empty\n";
    }
}
void cir_queue::isfull(cir_queue *p)
{
    if ((p->front == 0 && p->rear == max - 1) || (p->front == p->rear + 1))
    {
        cout << "Circular queue is full\n";
    }
    else
    {
        cout << "circular queue is not full\n";
    }
}
void cir_queue::insert(cir_queue *p, int element)
{
    if ((p->front == 0 && p->rear == max - 1) || (p->rear + 1 == p->front))
    {
        cout << "Circular queue is overflow...\n";
    }
    else
    {
        if (p->front == -1)
        {
            p->front = p->rear = 0;
        }
        else
        {
            p->rear = (p->rear + 1) % max;
        }
        p->item[p->rear] = element;
    }
}
int cir_queue::remove(cir_queue *p)
{
    if (p->front == -1)
    {
        cout << "circular queue is underflow...\n";
    }
    else
    {
        int z;
        z = p->item[p->front];
        if (p->front == p->rear)
        {
            p->front = p->rear = -1;
        }
        else
        {
            p->front = (p->front + 1) % max;
        }
        cout<<z<<" is removed from the  so called circular queue\n";
        return (z);
    }
}
void cir_queue::display(cir_queue *p)
{
    for (int i = p->front; i != p->rear; i = ((i + 1) % max))
    {
        cout << p->item[i] << " ";
    }
    cout << p->item[p->rear] << " ";
}
int main()
{
    int n, z, ch;
    cir_queue obj, q, *p = &q;
    do
    {
        cout << "Enter your choise\n";
        cout << "\n1.create\n2.isemty\n3.isfull\n4.insert\n5.remove\n6.display\n7.exit\n";
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
            obj.insert(p, n);
            break;
        case 5:
            z = obj.remove(p);
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