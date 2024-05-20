
#include <iostream>
using namespace std;
#define size 10
int queue[size], front = -1, rear = -1, i, x;
void enqueue()
{
  if (rear == size - 1)
  {
    cout << "Queue is full\n";
    return;
  }

  rear++;
  cout << "Enter new item: ";
  cin >> x;
  queue[rear] = x;
  if (front == -1)
    front++;
}
void dequeue()
{
  if (front == -1)
    cout << "Q is empty\n";

  cout << "The first item: " << queue[front] << '\n';
  if (rear == front)
    front = rear = -1;
  else 
    front++;
}
bool isempty()
{
  if (front == -1)
  {
    cout << "Q is empty \n";
    return true;
  }
  else
    return false;
}
bool isfull()
{
  if (rear == size - 1)
  {
    cout << "Q is full\n";
    return true;
  }
  else
    return false;
}
void print()
{
  if (front == -1)
  {
    cout << "Q is empty\n";
  }
  for (i = front; i <= rear; i++)
  {
    cout << "queue[" << i << "]= " << queue[i] << '\n';
  }
  cout << "\n";
}
int main()
{
  enqueue();
  enqueue();
  enqueue();
  dequeue();
  print();
  cout << "Is Empty? " << isempty();
  dequeue();
  print();
}