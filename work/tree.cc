#include <iostream>
using namespace std;
#define MAXSIZE 40

class PNode{
    char data;
    struct PNode *lchild,*rchild;
    int flag;

    public:
    PNode *Create_Ptree(PNode *);

    void PreOrderTraverse_R(PNode *);
    void PreOrderTraverse_NR(PNode *);

    void InOrderTraverse_R(PNode *);
    void InOrderTraverse_NR(PNode *);

    void PostOrderTraverse_R(PNode *);
    void PostOrderTraverse_NR(PNode *);
    friend class stack;
};

class stack{
    PNode* data[MAXSIZE];
    int top = -1;

    public:
    void push_stack(PNode *);
    void pop_stack(PNode *);

    friend void PNode::PreOrderTraverse_NR(PNode *);
    friend void PNode::InOrderTraverse_NR(PNode *);
    friend void PNode::PostOrderTraverse_NR(PNode *);
};

void stack::push_stack(PNode *p)
{
    if(top == MAXSIZE)
    {
        cout << "The Stack is upto its MAXSIZE!" << endl;
        return;
    }
    top++;
    data[top] = p;
}

void stack::pop_stack(PNode *p)
{
    if(top == -1)
    {
        cout << "The stack is empty!" << endl;
        return ;
    }
    top--;
}

PNode *PNode::Create_Ptree(PNode *p)
{
    char c;
    cin >> c;
    if(c == '#')
        p = NULL;
    else
    {
        p = (PNode *)malloc(sizeof(PNode));
        p->data = c;
        p->flag = 0;
        p->lchild = Create_Ptree(p->lchild);
        p->rchild = Create_Ptree(p->rchild);
    }
    return p;
}

void PNode::PreOrderTraverse_R(PNode *p)//递归先序
{
    if(p)
    {
        cout << p->data;
        PreOrderTraverse_R(p->lchild);
        PreOrderTraverse_R(p->rchild);
    }
}

void PNode::PreOrderTraverse_NR(PNode *p)//非递归先序
{
    if(!p)
        cout << "This tree is empty!" << endl;

    stack s1;
    s1.push_stack(p);
    while(s1.top != -1)
    {
        p = s1.data[s1.top];
        s1.pop_stack(p);
        cout << p->data;

        if(p->rchild)
            s1.push_stack(p->rchild);
        if(p->lchild)
            s1.push_stack(p->lchild);

    }
}

void PNode::InOrderTraverse_R(PNode *p)
{
    if(!p)
        return;
    InOrderTraverse_R(p->lchild);
    cout << p->data;
    InOrderTraverse_R(p->rchild);
}

void PNode::InOrderTraverse_NR(PNode *p)
{
    if(!p)
        cout << "The tree is empty!" << endl;

    stack s1;
    s1.push_stack(p);

    while(s1.top != -1)
    {
        if(s1.data[s1.top]->flag == 0)
        {
            s1.data[s1.top]->flag = 1;
            if(s1.data[s1.top]->lchild)
            {
                s1.push_stack(s1.data[s1.top]->lchild);
            }
        }
        else
        {
            cout << s1.data[s1.top]->data;
            p = s1.data[s1.top];
            s1.pop_stack(s1.data[s1.top]);
            if(p->rchild)
                s1.push_stack(p->rchild);
        }
    }
}

void PNode::PostOrderTraverse_R(PNode *p)
{
    if(!p)
        return;
    PostOrderTraverse_R(p->lchild);
    PostOrderTraverse_R(p->rchild);
    cout << p->data;
}

void PNode::PostOrderTraverse_NR(PNode *p)
{
    if(!p)
        cout << "The tree is empty!" << endl;
    stack s1;
    s1.push_stack(p);

    while(s1.top != -1)
    {
        if(s1.data[s1.top]->flag == 0)
        {
            s1.data[s1.top]->flag = 1;
            if(s1.data[s1.top]->lchild)
                s1.push_stack(s1.data[s1.top]->lchild);
        }
        else if(s1.data[s1.top]->flag == 1)
        {
            s1.data[s1.top]->flag = 2;
            if(s1.data[s1.top]->rchild)
                s1.push_stack(s1.data[s1.top]->rchild);
        }
        else
        {
                cout << s1.data[s1.top]->data;
                s1.pop_stack(s1.data[s1.top]);
        }
    }
}

int main()
{
    PNode *Ptree;
    string s = "ABDG##H###CE#I##F##";
    cout << s << endl;

    /*建二叉树*/
    Ptree = (*Ptree).Create_Ptree(Ptree);

    /*先序遍历二叉树*/
    cout <<"\nPreOrderTraverse" << endl;
    (*Ptree).PreOrderTraverse_R(Ptree);
    cout << endl;
    (*Ptree).PreOrderTraverse_NR(Ptree);
    cout << endl;

    /*中序遍历二叉树*/
    cout << "\nInOrderTraverse" << endl;
    (*Ptree).InOrderTraverse_R(Ptree);
    cout << endl;
 //   (*Ptree).InOrderTraverse_NR(Ptree);
    cout << endl;

    /*后序遍历二叉树*/
    cout << "\nPostOrderTraverse" << endl;
    (*Ptree).PostOrderTraverse_R(Ptree);
    cout << endl;
    (*Ptree).PostOrderTraverse_NR(Ptree);
    cout << endl;

    return 0;
}
