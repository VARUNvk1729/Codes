#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
struct Node
{
  struct Node *lchild;
  int data;
  struct Node *rchild;
}*root=NULL;
//Iterative insertion
void Insert(int key)
 {
    struct Node *t=root;
    struct Node *r=NULL,*p;
    if(root==NULL)
    {
     p=(struct Node *)malloc(sizeof(struct Node));
     p->data=key;
     p->lchild=p->rchild=NULL;
     root=p;
     return;
    }
    while(t!=NULL)
   {
      r=t;
      if(key<t->data)
      t=t->lchild;
      else if(key>t->data)
      t=t->rchild;
     else
     return;
    }
       p=(struct Node *)malloc(sizeof(struct Node));
       p->data=key;
       p->lchild=p->rchild=NULL;
    
    if(key<r->data) r->lchild=p;
     else r->rchild=p;
}
void Inorder(struct Node *p)
{
    if(p)
  {
    Inorder(p->lchild);
    printf("%d ",p->data);
    Inorder(p->rchild);
   }
}
//recursive insertion
struct Node *RInsert(struct Node *p,int key)
{
    struct Node *t=NULL;
    if(p==NULL)
    {
      t=(struct Node *)malloc(sizeof(struct Node));
      t->data=key;
      t->lchild=t->rchild=NULL;
      return t;
    }
    if(key < p->data)
    p->lchild=RInsert(p->lchild,key);
    else if(key > p->data)
    p->rchild=RInsert(p->rchild,key);
    return p;
}
void printLeftview(struct Node* root,int level,  int* maxi)
{
    
    if(!root)
        return;
    
    if(*maxi<level)
    {
        cout<<root->data<<" ";
        *maxi=level;
    }
    printLeftview(root->lchild,level+1,maxi);
    printLeftview(root->rchild,level+1,maxi);
}

void leftView(struct Node* root)
{
  int maxi=0;
  printLeftview(root,1,&maxi);
}


void printRightview(struct Node* root,int level,  int* maxi)
{
     if(!root)
        return;
    
    if(*maxi<level)
    {
        cout<<root->data<<" ";
        *maxi=level;
    }
    printRightview(root->rchild,level+1,maxi);
    printRightview(root->lchild,level+1,maxi);
}

void rightView(struct Node* root)
{
  int maxi=0;
  printRightview(root,1,&maxi);
}



void printBottomview(struct Node* root,int level,  int* maxi)
{
     if(!root)
        return;
    printBottomview(root->lchild,level+1,maxi);
    if(*maxi<=level)
    {
        cout<<root->data<<" ";
        *maxi=level;
    }
    printBottomview(root->rchild,level+1,maxi);
}

void bottomView(struct Node* root)
{
  int maxi=0;
  printBottomview(root,1,&maxi);
}
int main()
{
    root=RInsert(root,30);
    root=RInsert(root,20);
    root=RInsert(root,40);
    root=RInsert(root,10);
    root=RInsert(root,50);
    root=RInsert(root,35);
  //  cout<<root->lchild->data<<" ";
   // cout<<root->rchild->data<<" ";
   // Inorder(root);
   // cout<<endl;
   // cout<<root->lchild->data;
  // leftView(root);
   cout<<endl;
 //  rightView(root);
   bottomView(root);
    return 0;
}
