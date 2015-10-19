#include <iostream>
#include <vector>

using namespace std;
#define MAXSIZE 20

typedef struct Slist{
    int data[MAXSIZE];
    int length;
}Slist;//顺序表

typedef struct Linklist{
    int data;
    Linklist *next;
}Linklist;//单链表

typedef struct DLinklist{
    int data;
    DLinklist *prior;
    DLinklist *next;
}DLinklist;//双链表

int ListInsert(Slist *list, int num, int des)
{
    int i = 0;
    if((*list).length == MAXSIZE)
    {
        cout << "The Slist is upto its maxsize\n";
        return 0;
    }
    while(i < (*list).length)
    {
        if((*list).data[i] == num)
            break;
        i++;
    }
    if(i < (*list).length)
        for(int j = (*list).length-1; j >= i; j--)
            (*list).data[j+1] = (*list).data[j];
    (*list).data[i] = des;
    (*list).length++;
    return 1;
}

int ListDelete(Slist *list, int num)
{
    if((*list).length == 0)
    {
        cout << "The Slist is empty\n";
        return 0;
    }
    int i;
    for(i = 0; i < (*list).length; i++)
        if((*list).data[i] == num)
            break;
    if(i < (*list).length)
        for(int j = i+1; j < (*list).length;j++)
            (*list).data[j-1] = (*list).data[j];
    (*list).length--;
    return 1;
}

void creat_linklist(Linklist *list)
{
    list->data = 0;
    list->next = NULL;

    int size = 4;
    int i = 0;
    Linklist *L = list,*s;

    while(i < size)
    {
        s = (Linklist *)malloc(sizeof(Linklist));
        s->data = i*2;
        s->next = list->next;
        list->next = s;
        list = s;
        L->data++;
        i++;
    }
    list = L;
}

void Linklist_Insert(Linklist *list,int num, int des)
{
    Linklist *s = (Linklist *)malloc(sizeof(Linklist));
    s->data = des;
    Linklist *L=list,*q;
    L = L->next;
    while(L)
    {
        if(L->data == num)
            break;
        q=L;
        L = L->next;
    }
    if(L)
    {
        s->next = q->next;
        q->next = s;
    }
    list->data++;
}

void Linklist_Delete(Linklist *list, int des)
{

    Linklist *L = list->next,*q;
    q = L;
    while(L)
    {
        if(L->data == des)
            break;
        q = L;
        L = L->next;
    }

    if(L)
    {
        q->next = L->next;
        free(L);
        list->data--;
    }

}

void print(Slist *list1)
{
    cout << "Now the Slist length is " << (*list1).length << ".\n";
    for(int i = 0; i < (*list1).length; i++)
       cout << (*list1).data[i] << "\t";
    cout << endl;
}

void print(Linklist *list)
{
    Linklist *L = list;
    cout << "The Linklist length is " << L->data << endl;
    L = L->next;
    while(L)
    {
        cout << L->data << "->";
        L = L->next;
    }
    cout << "Nil" << endl;
}

void creat_DLinklist(DLinklist *list)
{
    list->data = 0;
    list->next = list;
    list->prior = list;

    int size = 5;
    int i = 0;
    DLinklist *L = list;
    
    for(;i < size; i++)
    {
        DLinklist *s = (DLinklist *)malloc(sizeof(DLinklist));
        s->data = i * 3;
        s->prior = L;
        s->next = s;
        L->next = s;
        L = s;
        list->data++;
    }
}

void print(DLinklist *list)
{
    DLinklist *L = list;
    cout << "The DLinklist length is " << L->data << endl;
    L = L->next;
    while(L->next != L)
    {
        cout << L->data <<"->";
        L = L->next;
    }
    cout << L->data << "->";
    cout << "Nil" << endl;
}

void DLinklist_Insert(DLinklist *list, int num, int des)
{
    DLinklist *L = list;
    L = L->next;
    while(L->data != num && L->next != L)
    {
        L = L->next;
    }

    if(L->next != L)
    {
        DLinklist *p = L->prior;
        DLinklist *s = (DLinklist *)malloc(sizeof(DLinklist));
        s->data = des;
        s->prior = p;
        s->next = L;
        L->prior = s;
        p->next = s;
        list->data++;
    }
}

void DLinklist_Delete(DLinklist *list,int des)
{
    DLinklist *L = list;
    L = L->next;
    while(L->data != des && L->next != L)
    {
        L = L->next;
    }

    if(L->next != L)
    {
        DLinklist *p = L->prior, *q = L->next;
        p->next = q;
        q->prior = q;
        free(L);
    }
}

int main()
{
    Slist list1;
    int i;
    list1.length = 5;
    cout << "The Slist length is " << list1.length << ".\n";
    for(i = 0; i < list1.length; i++)
    {
        list1.data[i] = i+1;
        cout << list1.data[i] <<"\t";
    }
    cout << endl;
    /*insert number 8 before 3*/
    int succ = ListInsert(&list1,3,8);
    cout << ((succ == 1) ? "ListInsert successfull\n" : "ListInsert unsuccessful\n");
    print(&list1);

    /*delete number 8*/
    succ = ListDelete(&list1,8);
    cout << ((succ == 1) ? "ListDelete successfull\n" : "ListDelete unsuccessful\n");
    print(&list1);

    /*单链表*/
    Linklist *linklist = (Linklist *)malloc(sizeof(Linklist));
    creat_linklist(linklist);
    print(linklist);

    /*Insert the num 7 before 2*/
    Linklist_Insert(linklist,2,7);
    print(linklist);

    /*Delete the num 7*/
    Linklist_Delete(linklist,7);
    print(linklist);

    /*双链表*/
    DLinklist *dlinklist = (DLinklist *)malloc(sizeof(DLinklist));
    creat_DLinklist(dlinklist);
    print(dlinklist);

    /*Insert the num 2 before 6*/
    DLinklist_Insert(dlinklist,6,2);
    print(dlinklist);

    /*Delete the num 2*/
    DLinklist_Delete(dlinklist,2);
    print(dlinklist);
    return 0;
}

