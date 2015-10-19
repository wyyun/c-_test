#include <iostream>
using namespace std;

class PNode{
    char data;
    PNode *lchild;
    PNode *rchild;
    int lflag;
    int rflag;

    public:
    void Create_tree(PNode *);
    void Create_threadtree(PNode *);
};

/*建树*/
void PNode::Create_tree(PNode *p)
{
    char c;
    cin >> c;
    if(c == '#')
        return;
    p = (PNode *)malloc(sizeof(PNode));
    p->data = c;
    Create_tree(p->lchild);
    if(p->lchild)
        p->lflag = 1;
    else
        p->lflag = 0;

    Create_tree(p->rchild);
    if(p->rflag)
        p->rflag = 1;
    else
        p->lflag = 0;
}

/*利用中序遍历线索二叉树*/
PNode *pre;
void PNode::Create_threadtree(PNode *p)
{
    if(!p)
        return;

  //  PNode *pre = p;
    Create_threadtree(p->lchild);
    if(!p->lchild)
    {
        p->lflag = 0;
        if(!pre)
            p->lchild = NULL;
        else
            p->lchild = pre;
    }
    if(!pre->rchild)
    {
        pre->rflag = 0;
        pre->rchild = p;
    }
    pre = p;

    Create_threadtree(p->rchild);
}

int  main()
{
    PNode *ptree;
    string s = "ABDG##H###CE#I##F##";
    cout << s << endl;

    ptree->Create_tree(ptree);
    ptree->Create_threadtree(ptree);

    return 0;
}

