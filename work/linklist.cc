#include <iostream>
// #include <vector>

using namespace std;
#define MAXSIZE 20

typedef struct Linklist{
    int data;
    Linklist *next;
} Linklist;//单链表

Linklist *linklist_create()
{
    Linklist *s;

    s = (Linklist *) malloc(sizeof(*s));
    s->data = 0;
    s->next = NULL;
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

void Linklist_InsertElement(Linklist *l, int data)
{
    Linklist *p = l;
    Linklist *s;

    if (l == NULL) {
        return;
    }

    while (p->next) {
        p = p->next;
    }

    s = (Linklist *) malloc(sizeof(Linklist));
    s->data = data;
    s->next = NULL;

    p->next = s;
    l->data++;
}

void Linklist_Insert(Linklist *list, int num, int des)
{
    Linklist *s = (Linklist *)malloc(sizeof(Linklist));
    s->data = des;
    s->next = NULL;

    Linklist *L = list, *q;
    L = L->next;

    while (L)
    {
        if(L->data == num)
            break;
        q = L;
        L = L->next;
    }

    if (L) {
        s->next = q->next;
        q->next = s;
        list->data++;
    }
}

void Linklist_Delete(Linklist *list, int des)
{
    Linklist *p = l->next;
    Linklist *q = l;

    while (p) {
        if (p->data == des)
            break;
        q = p;  // q = q->next;
        p = p->next;
    }

    if (p) {
        q->next = p->next;
        free(p);
        l->data--;
    }
}

void Linklist_Dump(Linklist *l)
{
    if (l == NULL)
        return;
    cout << "[" << l->data << "] ";
    l = l->next;

    while (l) {
        cout << l->data << "->";
        l = l->next;
    }

    cout << "Nil" << endl;
}

int main()
{
    Linklist *l;

    l = linklist_create();

    Linklist_InsertElement(l, 1);
    Linklist_InsertElement(l, 2);
    Linklist_InsertElement(l, 3);
    Linklist_InsertElement(l, 4);
    Linklist_Dump(l);

    Linklist_Delete(l, 3);
    Linklist_Dump(l);
/*
    Linklist_Delete(l, 4);
    Linklist_Dump(l);

    Linklist_Delete(l, 1);
    Linklist_Dump(l);

    Linklist_Delete(l, 2);
    Linklist_Dump(l);
*/
    return 0;
}

