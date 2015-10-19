#include <iostream>
#include <vector>
#include <string.h>
/* #include <iterator> */
using namespace std;

bool Find(vector<vector<int> > array,int target) {
        /*每行每列折半查找*/
        vector<int>::iterator low,high,mid;

        for(int i = 0; i < array.size(); i++)
        {
            low = array[i].begin();
            high = array[i].end()-1;

            while(low <= high)
            {
                mid = low + (high - low)/2;
                if(target > *mid)
                    low = mid+1;

                else if(target < *mid)
                    high = mid-1;

                else return true;
            }
        }
        return false;
    }

/*从左下角开始，若待查找数大于，则向右移，列数加；反之上移，行数减*/
bool Find1(vector<vector<int>> array,int target)
{
    int row = array.size();//行数
    int col = array[0].size();//列数

    for(int i = row-1,j = 0; i >= 0 && j < col;)
    {
        if(target == array[i][j])
            return true;
        else if(target > array[i][j])
            j++;
        else
            i--;
    }
    return false;
}

void replaceSpace(char *str,int length)
{
    int i = 0,k = 0;
    char* result = new char[length];
    for(i=0; i < length;i++)
        result[i] = str[i];
    i = 0;
    while(i < length)
    {
        if(result[i] == ' ')
        {
            str[k] = '%';
            str[k+1] = '2';
            str[k+2] = '0';
            k += 2;
        }
        else
        {
            str[k] = result[i];
        }
        i++;
        k++;
    }
    str[k] = '\0';
}

int main()
{
    vector<vector<int>> array = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    cout << boolalpha;
    cout << Find(array,7) << endl;
    cout << Find1(array,7) << endl;

    char str[] = "hello world";
    /* str = "hello world"; */
    /* cin >> str;hello world  */
    replaceSpace(str,strlen(str));
    cout << str << endl;
    return 0;
}
