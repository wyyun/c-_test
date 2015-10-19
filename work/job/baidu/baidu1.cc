#include <stdio.h>
#include <stdlib.h>

/*就是求n个坐标值中相差最大的x坐标或者y坐标的平方*/

typedef struct Locate{
    int x,y;
};
/*输入坐标*/
void input(Locate *locate,int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d",&(locate[i].x),&(locate[i].y));
    }
}

int find_max_square(Locate *locate,int n)
{
    int minx = 0,maxx = 0;//记录最小最大x坐标值
    int miny = 0,maxy = 0;//记录最小最大y坐标值

    for(int i = 0; i < n; i++)
    {
        if(locate[i].x < minx)
            minx = locate[i].x;
        else if(locate[i].x > maxx)
            maxx = locate[i].x;

        if(locate[i].y < miny)
            miny = locate[i].y;
        else if(locate[i].y > maxy)
            maxy = locate[i].y;
    }
    if((maxx - minx) > (maxy - miny))
        return (maxx-minx)*(maxx-minx);
    else
        return (maxy-miny)*(maxy-miny);
}

int main()
{
    int n;
    scanf("%d",&n);

    Locate *locate = (Locate *)malloc(sizeof(Locate));
    input(locate,n);

    int result = find_max_square(locate,n);
    printf("%d\n",result);
    return 0;
}
