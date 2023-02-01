#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int getheight(struct node *root)
{
    if(root==NULL)
        return 0;
    return root->height;
}

struct node *create(int val)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}

int getbalancefactor(struct node *root)
{
    if(root==NULL)
        return 0;
    return getheight(root->left) - getheight(root->right);

}

int max(int n1, int n2)
{
    if(n1>n2)
        return n1;
    else
        return n2;
}

struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(getheight(x->left),getheight(x->right)) + 1;
    y->height = max(getheight(y->left),getheight(y->right)) + 1;

    return y;
}

struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    x->height = max(getheight(x->left),getheight(x->right)) + 1;
    y->height = max(getheight(y->left),getheight(y->right)) + 1;

    return x;
}

struct node *insert(struct node *root,int val)
{
    
    if(root == NULL)
        return create(val);
    
    if(val<root->data)
        root->left = insert(root->left,val);
    else if(val>root->data)
        root->right = insert(root->right,val);
    

    int bf = getbalancefactor(root);

    //left left case
    if(bf>1 && val < root->left->data)
    {
        rightrotate(root);
    }
    //left right case
    if(bf>1 && val > root->left->data)
    {
        root->left = leftrotate(root->left);
        rightrotate(root);
    }
    //right right case
    if(bf<-1 && val > root->right->data)
    {
        leftrotate(root);
    }
    //right left case
    if(bf<-1 && val < root->right->data)
    {
        root->right = rightrotate(root->right);
        leftrotate(root);
    }
    return root;
}



void inOrder(struct node *root)
{
    if(root != NULL)
    {
        
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct node* minValueNode(struct node *root)
{
    struct node *temp;
    temp = root;
    while(temp->left!=NULL)
        temp = temp->left;
    return temp;
}

struct node *delete(struct node *root, int val)
{
    if (root == NULL)
        return root;

    if (val < root->data)
        root->left = delete(root->left, val);
    else if (val > root->data)
        root->right = delete(root->right, val);
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct node *temp = root->left!=NULL ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            struct node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    if (root == NULL)
        return root;
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    int bf = getbalancefactor(root);
    if (bf > 1 && getbalancefactor(root->left) >= 0)
        return rightrotate(root);
    if (bf > 1 && getbalancefactor(root->left) < 0)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (bf < -1 && getbalancefactor(root->right) <= 0)
        return leftrotate(root);
    if (bf < -1 && getbalancefactor(root->right) > 0)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}

int main()
{
    struct node *root=NULL;
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,40);
    root = insert(root,50);
    root = delete(root,40);
    inOrder(root);
    return 0;
}
