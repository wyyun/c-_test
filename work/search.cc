#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(int *a, int n)
{
    for(int i = 1; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

/*顺序查找，利用a[0]为查找元素，且为哨兵*/
void Sequence_search(int *a, int size)
{
    int i = size;
    while(a[i] != a[0])
    {
        i--;
    }
    cout << a[0] << " is " << (i > 0 ? "find":"not find") << endl;
}

/*折半查找，本身有序*/
int Binary_search(int *a, int size,int &count)
{
    int mid;
    int beg = 1, end = size;

    while(beg <= end)
    {
        mid = beg + (end - beg) / 2;
        count++;
        if(a[mid] > a[0])
            end = mid -1;
        else if(a[mid] < a[0])
            beg = mid + 1;
        else
            return mid;
    }
    return 0;
}

/*插值查找：对于表较长，关键字分布均匀，该算法比折半查找性能好，比较次数少*/
int InsertBinary_search(int *a, int size,int &count)
{
    int mid;
    int beg = 1,end = size;
    while(beg <= end)
    {
        mid = beg + ((a[0] - a[beg])/(a[end] - a[beg])) * (end - beg);
        count++;
        if(a[mid] > a[0])
            end = mid - 1;
        else if(a[mid] < a[0])
            beg = mid + 1;
        else
            return mid;
    }
    return 0;
}

/*Fibonacci数列保存查找范围个数
 * 当key = a[mid] 查找成功；
 * key < a[mid],新范围为beg~mid-1,个数为F[k-1]-1
 * key > a[mid],新范围为mid+1~end,个数为F[k-2]-1*/
int F[10] = {0,1,1,2,3,5,8,13,21,34};
void  Fibonacci_search(int *a, int size)
{
    int mid,k = 0, i = 0;
    int beg = 1, end = size;
    while(size > F[k] - 1)//查找数组长度对应的Fibonacci序列位置k
        k++;
    for(i = size; i < F[k]-1; i++)//补全数组对应Fibonacci序列缺少的元素，用最后一个元素补全
        a[i] = a[size];

    while(beg < end)
    {
        mid =beg + F[k-1] -1;
        if(a[0] < a[mid])
        {
            end = mid -1;
            k--;
        }
        else if(a[0] > a[mid])
        {
            beg = mid + 1;
            k -= 2;
        }
        else
        {
            if(mid <= size)
            {
                cout << a[0] << " is find" << endl;
                return;
            }
            else
            {
                cout << " 补全数组对应的元素" << endl;
                return;
            }
        }
    }
    cout << a[0] << " is not find!" << endl;
    return;
}

struct BitNode{
    int data;
    struct BitNode *lchild,*rchild;
};

/*在二叉排序树中查找节点*/
bool SearchBST(BitNode *btree, int ele, BitNode *parrent, BitNode **pre)
{
    if(!btree)
    {
        *pre = parrent;
        return false;
    }
    else if(btree->data == ele)
    {
        *pre = btree;
        return true;
    }
    else if(btree->data > ele)
        return SearchBST(btree->lchild, ele, btree, pre);
    else return SearchBST(btree->rchild,ele,btree,pre);
}


/*在二叉排序树中插入节点*/
void InsertBST(BitNode **btree, int ele)
{
    BitNode *p;
    if(!SearchBST(*btree,ele,NULL,&p))
    {
        BitNode *s = (BitNode *)malloc(sizeof(BitNode));
        s->data = ele;
        s->lchild = s->rchild = NULL;

        if(!p)
            *btree = s;
        else if(s->data > p->data)
            p->rchild = s;
        else
            p->lchild = s;
        return;
    }
    return;
}

/*创建二叉排序树*/
void CreatBST(BitNode **btree,int *a,int size)
{
    *btree = NULL;
    for(auto i = 1; i <= size; i++)
        InsertBST(btree,a[i]);
}

void IndexBST(BitNode *btree)
{
    if(!btree)
        return;
    IndexBST(btree->lchild);
    cout << btree->data << " ";
    IndexBST(btree->rchild);
}

void delete_key(BitNode *btree)
{
    BitNode *p;
    if(!btree->lchild)//删除节点的左孩子为空
    {
        p = btree;
        btree = btree->rchild;
        free(p);
        return;
    }

    if(!btree->rchild)//删除节点的右孩子为空
    {
        p = btree;
        btree = btree->lchild;
        free(p);
        return;
    }

    //左右孩子均不为空
    BitNode *s;
    s = btree->rchild;
    p = s;
    while(s->lchild)
    {
        s = s->lchild;
    }
    btree->data = s->data;
    if(p == s)
        btree->rchild = s->rchild;
    else
        btree->rchild = s;
    free(s);
}

void delete_BST(BitNode *btree, int key)
{
    if(!btree)
        return;
    if(btree->data == key)
    {
        delete_key(btree);
    }
    else if(btree->data < key)
        delete_BST(btree->rchild,key);
    else
        delete_BST(btree->lchild,key);
}

#define EH 0
#define LH  1
#define RH -1

struct AVLtree{
    int data;
    AVLtree *lchild,*rchild;
    int bf;
};

/*对以atree为根的二叉树左平衡处理*/
void LeftBalance(AVLtree *atree)//atree->bf = 2
{
    AVLtree *L = atree->lchild;
    switch(L->bf)
    {
        case LH://与atree->bf同号
            atree->bf = L->bf = EH;
            R_Rotate(atree);
            break;
        case RH:
            AVLtree *Lr = L->rchild;
            switch(Lr->bf)//先置换L和Lr的位置
            {
                case LH:
                    L->bf = EH;
                    atree->bf = RH;
                    break;
                case EH:
                    atree->bf = L->bf = EH;
                    break;
                case RH:
                    L->bf = LH;
                    atree->bf = EH;
                    break;
            }
            Lr->bf = EH;
            L_Rotate(atree->lchild);
            R_Rotate(atree);
    }
}

void RightBalance(AVLtree *atree)//atree->bf = 2
{
    AVLtree *R = atree->rchild;
    switch(R->bf)
    {
        case LH://与atree->bf同号
            atree->bf = R->bf = EH;
            L_Rotate(atree);
            break;
        case RH:
            AVLtree *Rl = R->lchild;
            switch(Lr->bf)//先置换R和Rl的位置
            {
                case LH:
                    R->bf = EH;
                    atree->bf = RH;
                    break;
                case EH:
                    atree->bf = R->bf = EH;
                    break;
                case RH:
                    R->bf = LH;
                    atree->bf = EH;
                    break;
            }
            Rl->bf = EH;
            R_Rotate(atree->rchild);
            L_Rotate(atree);
    }
}

bool InsertAVL(AVLtree *atree, int key, int *taller)
{
    if(!atree)
    {
        atree = (AVLtree *)malloc(sizeof(AVLtree));
        atree->data = key;
        atree->bf = EH;
        atree->lchild = atree->rchild = NULL;
        *taller = true;
    }
    else
    {
        if(key == atree->data)//AVL树中已有该节点
        {
            *taller = false;
            return false;
        }
        if(key < atree->data)//在AVL左子树中查找
        {
            if(!InsertAVL(atree->lchild,key,taller))//未插入该节点到AVL左子树中
                return false;
            if(taller)//插入成功，且树长高
            {
                switch(atree->bf)//检查原树的高度
                {
                    case EH:
                        atree->bf = LH;
                        *taller = true;
                        break;
                    case LH:
                        LeftBalance(atree);
                        *taller = false;
                        break;
                    case RH:
                        atree->bf = EH;
                        *taller = false;
                        break;
                }
            }

        }
        else//在AVL右子树中查找
        {
            if(!IndexAVL(atree->rchild,key,taller))
                return false;
            if(taller)
            {
                switch(atree->bf)
                {
                    case EH:
                        atree ->bf = RH;
                        *taller = true;
                        break;
                    case LH:
                        atree->bf = EH;
                        *taller = false;
                        break;
                    case RH:
                        RightBalance(atree);
                        *taller = false;
                        break;
                }
            }
        }
    }
    return true;
}

void CreatAVL(AVLtree *atree, int *a, int size)
{
    atree = NULL;
    int taller;
    for(int i = 1; i <= size; i++)
        InsertAVL(atree,a[i],&taller);
}

void IndexAVL(AVLtree *atree)
{
    if(!atree)
        return;
    IndexAVL(atree->lchild);
    cout << atree->data << " ";
    IndexAVL(atree->rchild);
}
int main()
{
    int key[20] = {62,99,16,1,24,59,35,88,73,62,47};
    int key_binary[20] = {62,1,16,24,35,47,59,62,73,88,99};
   // int key_binary[11] = {10,2,4,5,7,8,9,10,11,14,15};
    int count = 0;

    cout << "****顺序查找****" << endl;
    print(key,10);
    Sequence_search(key,10);

    cout << "\n****折半查找****" << endl;
    int result = Binary_search(key_binary,10,count);
    print(key_binary,10);
    cout << key_binary[0] << (result > 0? " is find!":" is not find") << " count = " << count << endl;

    cout << "\n****插值查找*****" << endl;
    count = 0;
    result = InsertBinary_search(key_binary,10,count);
    print(key_binary,10);
    cout << key_binary[0] << (result > 0? " is find!":" is not find") << " count = " << count << endl;

    cout << "\n****Fibonacci查找*****" << endl;
    print(key_binary,10);
    Fibonacci_search(key_binary,10);

    cout << "\n****二叉排序树****" << endl;
    BitNode *Btree;
    CreatBST(&Btree,key,10);
    IndexBST(Btree);
    int keynum = 62;
    cout << "\ndelete the number of " << keynum << " in BST!" << endl;
    delete_BST(Btree,keynum);
    IndexBST(Btree);

    cout << "\n****AVL平衡二叉树****" << endl;
    AVLtree *Atree;
    CreatAVL(Atree,key,10);
    IndexAVL(Atree);
    cout << endl;
    return 0;
}
