#include <stdio.h>
#include <stdlib.h>

 typedef struct DFS
{
    int a;
    char* s;
}DFS;
void main()
{
    DFS *var[2];
    int i = 0,j = 0;
    var[0] = (DFS *)malloc(sizeof(DFS)*4);
    var[1] = (DFS *)malloc(sizeof(DFS)*4);
    for(;i < 2;i++)
    {
        for(j = 0;j < 4;j++)
        {
            var[i]->a = j;
            var[i]->s = "as";
            printf("var[%d]=%d,%s\n",i,var[i]->a,var[i]->s);
            var[i]++;
        }
    }
    printf("over\n");


}
