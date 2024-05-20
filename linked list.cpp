#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
  int data;
  node *ptr;
};
node *create(int n)
{
  node *head;
  head = (node *)malloc(sizeof(node));
  if (head == NULL)
  {
    cout << "No Memory Space\n";
    return 0;
  }
  else
  {
    head->data = n;
    head->ptr = NULL;
  }
  return head;
}
node *insert_first(node *p, int n)
{
  node *temp;
  temp = (node *)malloc(sizeof(node));
  if (temp == NULL)
  {
    cout << "No Memory Space\n";
    return 0;
  }
  else
  {
    temp->data = n;
    temp->ptr = p;
    p = temp;
  }
  return p;
}
node *insert_last(node *p, int n)
{
  node *temp, *current;
  temp = (node *)malloc(sizeof(node));
  if (temp == NULL)
  {
    cout << "No Memory Space\n";
    return 0;
  }
  else
  {
    current = p;
    while (current->ptr != NULL)
    {
      current = current->ptr;
    }
    temp->data = n;
    temp->ptr = NULL;
    current->ptr = temp;
  }
  return p;
}
node *delete_first(node *p)
{
  node *current = p;
  p = p->ptr;
  free(current);
  return p;
}
node *delete_last(node *p)
{
  node *prev = NULL, *current = p;
  while (current->ptr != NULL)
  {
    prev = current;
    current = current->ptr;
  }
  prev->ptr = NULL;
  free(current);
  return p;
}
int count(node *p)
{
  int counter = 0;
  while (p != NULL)
  {
    p = p->ptr;
    counter++;
  }
  return counter;
}
void print(node *p)
{
  while (p != NULL)
  {
    cout << p->data << '\n';
    p = p->ptr;
  }
}
int main()
{
  node *head = create(5);
  // 5
  head = insert_first(head, 1);
  // 1 5
  head = insert_last(head, 6);
  // 1 5 6
  head = insert_before(head, 50, 6);
  // 1 5 50 6
  head = delete_node(head, 90);
  // 1 5 50 6
  head = delete_node(head, 5);
  // 1 50 6
  head = delete_first(head);
  // 50 6
  head = delete_last(head);
  // 50

  print(head);
  cout << "Num of elements: " << count(head) << '\n';
}