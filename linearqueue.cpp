#include <iostream>
#define max 5
using namespace std;
class queue
{
public:
    int item[max], rear, front;
    void create(queue *);
    void isempty(queue *);
    void isfull(queue *);
    void insert(queue *, int);
    int remove(queue *);
    void display(queue *);
};
void queue::create(queue *p)
{
    p->rear = p->front = -1;
    cout << "Linear queue is created\n";
}
void queue::isempty(queue *p)
{
    if (p->rear == p->front)
    {
        cout << "Linear queue is empty\n";
    }
    else
    {
        cout << "Linear queue is not empty\n";
    }
}
void queue::isfull(queue *p)
{
    if (p->rear == max - 1)
    {
        cout << "Linear queue is full\n";
    }
    else
    {
        cout << "linear queue is not full\n";
    }
}
void queue::insert(queue *p, int element)
{
    if (p->rear == max - 1)
    {
        cout << "Linear queue is overflow...\n";
    }
    else
    {
        ++p->rear;
        p->item[p->rear] = element;
    }
}
int queue::remove(queue *p)
{
    if (p->front == p->rear)
    {
        cout << "Linear queue is underflow...\n";
    }
    else
    {
        ++p->front;
        cout << p->item[p->front] << "  is removed from so called Linear queue\n";
        return (p->item[p->front]);
    }
}
void queue::display(queue *p)
{
    for (int i = p->front + 1; i <= p->rear; i++)
    {
        cout << p->item[i] << " ";
    }
}
int main()
{
    int n, ch, z;
    queue obj, q, *p = &q;
    do
    {
        cout << "Enter your choise\n";
        cout << "\n1.create\n2.isempty\n3.isfull\n4.insert\n5.remove\n6.display\n7.exit\n";
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