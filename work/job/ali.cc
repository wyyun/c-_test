#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Node{
    private:
        int data;
        Node *lchild,*rchild;
    public:
        Node *CreatTree(Node *);
        void print(Node *);
        int returndata() {return data;}
        friend void FindNode(Node *,int& ,int&);
};

/*先序建二叉树*/
Node* Node::CreatTree(Node *tree)
{
    int i;
    cin >> i;
    if(!i)
    {
        tree = NULL;
    }
    else
    {
        tree = (Node *)malloc(sizeof(Node));
        tree->data = i;
        tree->lchild = CreatTree(tree->lchild);
        tree->rchild = CreatTree(tree->rchild);
    }
    return tree;
}

/*先序输出二叉树*/
void Node::print(Node *tree)
{
    if(tree)
    {
        cout << tree->data << " ";
        print(tree->lchild);
        print(tree->rchild);
    }
}

void FindNode(Node *tree,int &big,int &small)
{
    if(tree)
    {
        if(tree->data > big )
            big = tree->data;
        else if(tree->data < small)
            small = tree->data;
        FindNode(tree->lchild,big,small);
        FindNode(tree->rchild,big,small);
    }
}

int main()
{
    /* int i = 1;
    //i = (i++);
    [>i = i++;<]
    printf("%d ",i);
    char *p = "hello";
    [>*(p+1) = 'E'; <]
    char ch = *p++;
    cout << i++ << " " << i-- << endl;
    printf("%d %d\n",i++,i--); */

    Node *Tree;
    Tree = (*Tree).CreatTree(Tree);
    (*Tree).print(Tree);
    cout << endl;
    /* int &big = 0,&small = 0; */
    int b = Tree->returndata();
    int &big = b;
    int s = Tree->returndata();
    int &small = s;
    FindNode(Tree,big,small);
    cout << "big = " << big << ",small = "<< small <<";big-small = "<< big-small << endl;
}
