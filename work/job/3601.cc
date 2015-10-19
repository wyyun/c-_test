#include <iostream>
using namespace std;
int main()
{
    int i=0,a=1,b=2,c=3;
    i=++a||++b||++c;
    printf("%d %d %d %d\n",i,a,b,c);


    for(i=0;i<3;i++){
        switch(i){
            case 0:printf("%d",i);
            case 2:printf("%d",i);
            default:printf("%d",i);
        }
    }
    printf("\n");
    a = 3;
    cout << a/6 << endl;
    return 0;
}
