#include <iostream>
#include <string>
using namespace std;


class A
{
    public:
        virtual void func(int val = 1)
        { std::cout<<"A->"<<val <<std::endl;}
        virtual void test()
        { func();}
};
class B : public A
{
    public:
        void func(int val=0)
        {std::cout<<"B->"<<val <<std::endl;}
};


int fun(unsigned int x)
{
    int n=0;
    while((x+1))
    {
        n++;
        x=x|(x+1);
    }
    return n;
}
void funcc(char str_arg[100])
{
    cout<<sizeof(str_arg)<<endl;
}

int main()
{
    cout << fun(2014) <<endl;
    int a[5]={1,2,3,4,5};
    int *ptr=(int*)(&a+1);
    printf("%d,%d\n",*(a+1),*(ptr-1));;
    char str[]="Hello";
    char *p=str;
    cout<<sizeof(str)<<endl;
    cout<<sizeof(p)<<endl;
    funcc("test");
    int (*p1)[5] = &a;
    int *p2[3];
    /* p2[0] =  &a; */
    p2[0] = a;
    p2[1] = &a[0];
    /* int (*p2)[5] = a;地址虽然相同，但是类型不匹配 */
    printf("%p %p\n",a,&a);
    cout << "(*p)[5] = &a: (p1+1)  " <<*(p1+1) << "   (*p)[5] = &a: *(&a+1)   " << *(&a+1) << endl;
    cout << "(*p)[5] = &a: (a+1)  " <<*(a+1) << endl;
    cout <<" *p[3]: *(p)= " <<*(p2)<<"  *(p+1)= "<<  *(p2+1) << "  *(*p+1)= " << *(*p2+1)<< "  *p[1]= " << *p2[1] << endl;


    B *bp = new B;
    bp->test();
    return 0;
}
