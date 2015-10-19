#include "stdio.h"
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int count = 1;
    int child;
    //if(!(child = fork()))
    if(!(child = vfork()))
    {
        for(int i = 0; i < 12;i++)
        {
            printf("This is son,his count is %d, and his pid is %d\n",++count,getpid());
            if(i == 3)
                exit(1);
        }
        exit(1);
    }
    else
    {
        printf("This is father,his count is %d,and his pid is %d\n",count,getpid());
    }
    return 0;
}


