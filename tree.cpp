#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node *newNode(int data)
{
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}
void Inorder(struct node *node)
{
  if (node == NULL)
    return;

  Inorder(node->left);
  cout << node->data;
  Inorder(node->right);
}
void Preorder(struct node *node)
{
  if (node == NULL)
    return;

  cout << node->data;
  Preorder(node->left);
  Preorder(node->right);
}
void Postorder(struct node *node)
{
  if (node == NULL)
    return;

  Postorder(node->left);
  Postorder(node->right);
  cout << node->data;
}
int main()
{
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);


  cout << "\nInorder traversal of binary tree is \n";
  Inorder(root);

  cout << "\nPreorder traversal of binary tree is \n";
  Preorder(root);

  cout << "\nPostorder traversal of binary tree is \n";
  Postorder(root);
  return 0;
}