#include<iostream>
using namespace std;
#define MAX 5
int stack[MAX] , top = -1;
void push(int item)
{
  if (top == MAX - 1)
  {
    cout << "Stack is full\n";
    return;
  }
  else
  {
    top++;
    stack[top] = item;
  }
}
int pop()
{
  int item;
  if (top == -1)
  {
    cout << "Stack is empty\n";
  }
  else
  {
    item = stack[top];
    top--;
  }
  return item;
}
bool isempty()
{
  return (top == -1);
}
bool isfull()
{
  return (top == MAX - 1);
}
void top_item()
{
  if (top == -1)
  {
    cout << "Stack is empty\n";
  }
  else
  {
    cout << "Top Item = " << top << '\n';
  }
}
void print ()
{
  if (top == -1)
  {
    cout << "Stack is empty\n";
    return;
  }
  else
  {
    for (int i = 0; i <= top; i++)
    {
      cout << stack[i] << ' ';
    }
    cout << endl;
  }
}
int main()
{
  cout << "is empty? " <<  isempty() << '\n';
  cout << "is full? " << isfull() << '\n';
  int x;
  for (int i = 0; i < 5; i++)
  {
    cout << "Enter X: ";
    cin >> x;
    push (x);
  }
  print();
  pop();
  print();
  cout << "is empty? " <<  isempty() << '\n';
  cout << "is full? " << isfull() << '\n';
}