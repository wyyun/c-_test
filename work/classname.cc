#include <iostream>
using namespace std;

class X
{
    int a;
};

int main()
{
    X x;
    X y;
    const X *x1;
    x1 = &x;
    x1 = &y;
    X const *x2;
/*  const T*和T const* 都表示指向一个const对象的指针*/
    /* x1=x2; */
    x2 = &x;
    x2 = &y;
    /* const X const *x3 = &x;不可以，const重复 */
    X *const x4 = &x;
    /* x4 = &y; 不可以，表示一个指向X 对象的const指(*/
    int a,b;
    for(a = 1, b = 1; a <= 100; a++)
    {
        if(b >= 20) break;
        b += 3;
    }
    b = b - 5;
    printf("%d\n", a);
    int k;
    for(int i = 0, k = 1; k = 0; i++, k++)
        cout << "for    " << endl;
    return 0;
}

