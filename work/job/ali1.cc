#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
int func(unsigned int i)
{
    unsigned int temp=i;
    temp=(temp & 0x55555555)+((temp & 0xaaaaaaaa)>>1);
    temp=(temp & 0x33333333)+((temp & 0xccccccccc)>>2);
    temp=(temp & 0x0f0f0f0f)+((temp & 0xf0f0f0f0)>>4);
    temp=(temp & 0xff00ff)+((temp & 0xff00ff00)>>8);
    temp=(temp & 0xffff)+((temp & 0xffff0000)>>16);
    return temp;
}

/* template<typename T> */
#define MAXSIZE 1024
class FreeList{
    private:
        struct Freelist
        {
            int usesize;
            int *addr;
        };
        Freelist uselist[MAXSIZE];
        Freelist freelist[MAXSIZE];
        /* static int size = MAXSIZE*sizeof(int); */
        void *address = malloc(MAXSIZE*sizeof(int));
        int size = MAXSIZE;
        memset(freelist,0,MAXSIZE);
        freelist[0]= {MAXSIZE,address};
    public:
        void *operator new(size_t);
        void *operator new[](size_t);
        void operator delete(void *) noexcept;
        void operator delete[](void *) noexcept;
};

void * FreeList::operator new(size_t t)
{
    for(int i = 0; i < MAXSIZE; i++)
        if((this->(freelist[i].usesize) >= sizeof(t)) && (uselist[i+1].addr == nullptr))
        {
            usesize[i].usesize = sizeof(t);
            uselist[i+1].addr = uselist[i].addr + sizeof(t);
            return freelist[i].addr;
        }
    else
        return (std::new(t));
}

void *FreeList::operator new[](size_t t)
{
    for(int i = 0;i < MAXSIZE; i++)
        if(this->(freelist[i].usesize) >= sizeof(t))
        {
            uselist[i].addr = freelist[i].addr;
            uselist[i].usesize = freelist[i].usesize;
            return freelist[i].addr;
        }
    else
        return (std::new(t));
}

void FreeList::operator delete(void *t)
{
    for(int i = 0; i < MAXSIZE; i++)
    {
        if(i == 0)
        {
            freelist[0].addr == t;
            freelist[0].usesize = sizeof(*t);
            if(freelist[1].addr != nullptr)
            {
                freelist[1].addr == nullptr;
                freelist[0].usesize += freelist[1].usesize;
            }
            for(int j = 0; j<MAXSIZE; j++)
            {
                if(uselist[j].addr == t)
                {
                    uselist[j].addr = nullptr;
                    uselist[j].usesize = 0'
                    break;
                }

            }
        }
        else
            if(this->(freelist[i]))
    }
}


int main()
{
    printf("%u  ",func(0x11530828));
    cout << func(0x11530828) << endl;

    int i = 0;i = (i++);
    cout << i << endl;
/* 属于未定义的错误
 * 1.同一运算符多个操作数的计算顺序如x = f() + g()
 * 2.函数个参数的求职顺序，如printf("%d,%d\n",++n,power(2,n));
 * 3.通过指针直接修改const常量的值，如下*/
    char *p = "hello";
    /* string p = "hello";
    p[1] = 'E'; */
    cout << p << endl;
    char ch = *(p++);
    cout << ch  << endl;

    /*阿里笔试1：重新封装FreeList机制*/
    cout << "\n\n\n" << endl;
    return 0;
}
