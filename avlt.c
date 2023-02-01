#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
    int ht;
};
struct node *root,*temp,*fresh,*rightchild,*leftchild,*succ;
int balancefactor(struct node *root)
{
    int lh,rh;
    if(root==NULL)
    {
        return 0;
    }
    else if(root->left==NULL)
    {
        lh=0;
    }
    else
    {
        lh=1+root->left->ht;
    }
    if(root->right==NULL)
    {
        rh=0;
    }
    else
    {
        rh=1+root->right->ht;
    }
    return lh-rh;
}
int height(struct node *root)
{
    int lh,rh;
    if(root==NULL)
    {
        return 0;
    }
    else if(root->left==NULL)
    {
        lh=0;
    }
    else
    {
        lh=1+root->left->ht;
    }
    if(root->right==NULL)
    {
        rh=0;
    }
    else
    {
        rh=1+root->right->ht;
    }
    if(rh>lh)
    {
        return rh;
    }
    return lh;
}
struct node *rotateleft(struct node *root)
{
    rightchild=malloc(sizeof(struct node));
    rightchild=root->right;
    root->right=rightchild->left;
    rightchild->left=root;
    root->ht=height(root);
    rightchild->ht=height(rightchild);
    return rightchild;
}
struct node *rotateright(struct node *root)
{
    leftchild=malloc(sizeof(struct node));
    leftchild=root->left;
    root->left=leftchild->right;
    leftchild->right=root;
    root->ht=height(root);
    leftchild->ht=height(leftchild);
    return leftchild;
}
struct node *create(int data)
{
    fresh=malloc(sizeof(struct node));
    fresh->data=data;
    fresh->left=NULL;
    fresh->right=NULL;
    return fresh;
}
struct node *insert(struct node *root,int data)
{
    fresh=create(data);
    if(root==NULL)
    {
        if(fresh==NULL)
        {
            return NULL;
        }
        root=fresh;
    }
    if(data>root->data)
    {
        root->right=insert(root->right,data);
        if(balancefactor(root)==-2)
        {
            if(data>root->right->data)
            {
                root=rotateleft(root);
            }
            else
            {
                root=rotateleft(root);
                root->right=rotateright(root->right);
            }
            
        }
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
        if(balancefactor(root)==2)
        {
            if(data<root->left->data)
            {
                root=rotateright(root);
            }
            else
            {
                root=rotateright(root);
                root->left=rotateleft(root);
            }
        }
    }
    root->ht = height(root);
    return root;

}
struct node *delete(struct node *root,int key)
{
    if(root==NULL)
    {
        printf("\nKey not found");
    }
    else if(key<root->data)
    {
        root->left=delete(root->left,key);
        if(balancefactor(root)==2)
        {
            if(key<root->left->data)
            {
                root=rotateright(root);
            }
            else
            {
                root=rotateright(root);
                root->left=rotateleft(root); 
            }
        }
    }
    else if(key>root->data)
    {
        root->right=delete(root->right,key);
        if(balancefactor(root)==-2)
        {
            if(key>root->right->data)
            {
                root=rotateleft(root);
            }
            else
            {
                root=rotateleft(root);
                root->right=rotateright(root->right);
            }
            
        }
    }
    else
    {
        if(root->left!=NULL && root->right!=NULL)
        {
            succ=root->right;
            while(succ->left)
            succ=succ->left;
            root->data=succ->data;
            root->left=delete(root->left,succ->data);
        }
        else
        {
            temp=root;
            if(root->left!=NULL)
            {
                root=root->left;
            }
            else if(root->right!=NULL)
            {
                root=root->right;
            }
            else
            {
                root=NULL;
            }
            free(temp);
        }
    }
    return root;
}
int print(struct node *root,int space)
{
    if(root==NULL)
    {
        return 0;
    }
    space+=10;
    print(root->right,space);
    printf("\n");
    for(int j=0;j<space;j++)
    {
        printf(" ");

    }
    printf("%d-->%d",root->data,balancefactor(root));
    print(root->left,space);
}

void inorder(struct node *root)
{
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

int main()
{
    root = insert(root,15);
    root = insert(root,16);
    root = insert(root,17);
    root = insert(root,18);
    root = insert(root,19);
    root = insert(root,20);
    root = insert(root,21);
    print(root,0);
    root=delete(root,15);
    root=delete(root,18);
    printf("\n\nAfter deletion of 15 and 18\n\n");
    print(root,0);
    inorder(root);
    
}


