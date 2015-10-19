#include <iostream>
#include <memory>
using namespace std;

class Sort{
    private:
        /* shared_ptr<int> data; */
        int *data;
        int len;
    public:
        /* void initdata(int *); */
        Sort(int *d,int l):
            len(l)
    {
        data = (int *)malloc(sizeof(int)*l);
        for(int i = 0 ;i < l;i++)
            data[i] = d[i];
    }
        friend void show(int *,int l);
        void bubble_sort();
        void Insert_sort();
        void Select_sort();
        void Shell_sort();
        void Heap_sort();
        void HeapAdjust(int ,int);
        /*递归归并排序*/
        void Msort();
        void Merge_sort(int Mr[],int Tr[],int l,int r);
        /*合并，将Tr2[l..m]和Tr2[m+1...r]归并到Tr1数组中*/
        void Merge(int Tr2[],int Tr1[],int l,int m,int r);
        /*快速排序*/
        void Quicksort();
        void Qsort(int ,int);
        int partition(int ,int);

        ~Sort() {delete data;cout << "析构函数" << endl;};
};

void show(int *data,int len)
{
    for(int i = 0; i < len; i++)
        cout << data[i] << "  ";
    cout << endl;
}

void Sort::bubble_sort()
{
    bool flag = true;
    for(int i = 0; i < len && flag; i++)
    {
        flag = false;
        for( int j = 0; j < len-i ; j++)
        {
            if(data[j] > data[j+1])
            {
                int temp = data[j+1];
                data[j+1] = data[j];
                data[j] = temp;
                flag = true;
            }
        }
    }
    show(this->data,this->len);
}

void Sort::Insert_sort()
{
    int j;
    int temp;
    for(int i = 1; i < len; i++)
    {
        temp = data[i];
        if(data[i] < data[i-1])
        {
            for(j = i-1 ; j >= 0 && data[j] > temp; j--)
            {
                data[j+1] = data[j];
            }
            data[j+1] = temp;
        }
    }
    show(this->data,this->len);
}

void Sort::Select_sort()
{
    int min;
    for(int i = 0; i < len; i++)
    {
        min = i;
        for(int j = i+1; j < len; j++)
        {
            if(data[j] < data[min])
                min = j;
        }
        if(min != i)
        {
            int temp = data[min];
            data[min] = data[i];
            data[i] = temp;
        }
    }
    show(this->data,this->len);
}

void Sort::Shell_sort()
{
    int increment = len;
    while(increment > 1)
    {
        increment = increment/3 + 1;
        for(int i = increment; i < len;i++)
        {
            int temp = data[i];
            int j;
            if(data[i] < data[i-increment])
            {
                for(j = i-increment; j >= 0 && data[j] > temp;j -= increment)
                    data[j+increment] = data[j];
                data[j+increment] = temp;
            }
        }
    }
    show(this->data,this->len);
}

void Sort::Heap_sort()
{
    for(int i = len/2; i >= 0; i--)
        HeapAdjust(i,len);
    for(int i = len-1; i >= 0;i--)
    {
        cout << data[0] << " " ;
        int temp = data[i];
        data[i] = data[0];
        data[0] = temp;
        HeapAdjust(0,i-1);
    }
    cout << endl;
}

void Sort::HeapAdjust(int l,int r)
{
    int temp = data[l];
    for(int i = l*2+1; i<r; i = i*2+1)
    {
        if(i < r && data[i] > data[i+1])
            i++;
        if(temp < data[i])
            break;
        data[l] = data[i];
        l = i;
    }
    data[l] = temp;
}

void Sort::Msort()
{
    Merge_sort(data,data,0,len-1);
    show(this->data,this->len);
}
/*递归归并排序:将Mr[]归并排序到Tr[]*/
void Sort::Merge_sort(int Mr[],int Tr[],int l,int r)
{
    int *Tr2 = (int *)malloc(sizeof(int)*len);
    int m;
    if(l == r)
        Tr[l] = Mr[l];
    else
    {
        m = (r+l)/2;
        Merge_sort(Mr,Tr2,l,m);
        Merge_sort(Mr,Tr2,m+1,r);
        Merge(Tr2,Tr,l,m,r);
    }
}

/*合并，将Tr2[l..m]和Tr2[m+1...r]归并到Tr1数组中*/
void Sort::Merge(int Tr2[],int Tr1[],int l,int m,int r)
{
    int i = l;
    int j = m+1;
    int c = l;
    for(; i<= m&&j <= r;c++)
    {
        if(Tr2[i] < Tr2[j])
        {
            Tr1[c] = Tr2[i];
            i++;
        }
        else
        {
            Tr1[c] = Tr2[j];
            j++;
        }
    }
    while(i <= m)
        Tr1[c++] = Tr2[i++];
    while(j <= r)
        Tr1[c++] = Tr2[j++];
}

void Sort::Quicksort()
{
    Qsort(0,len-1);
    show(this->data,this->len);
}

void Sort::Qsort(int low,int high)
{
    if(low < high)
    {
        int k = partition(low,high);
        Qsort(low,k-1);
        Qsort(k+1,high);
    }
}

int Sort::partition(int low,int high)
{
    int privot = data[low];
    while(low < high)
    {
        while(data[high] > privot && low < high)
            high--;
        if(low < high)
        {
            int temp = data[low];
            data[low] = data[high];
            data[high] = temp;
        }
        while(data[low] < privot && low < high)
            low++;
        if(low < high)
        {
            int temp = data[high];
            data[high] = data[low];
            data[low] = temp;
        }
    }
    return low;
}

int main()
{
    int sort_data[] = {5,1,9,3,7,4,8,6,2};
    int sort_length = 9;
    cout << "before sort: ";
    show(sort_data,9);
    Sort sort(sort_data,sort_length);
    cout << "after sort: ";
    /* sort.bubble_sort(); */
    /* sort.Insert_sort(); */
    /* sort.Select_sort(); */
    /* sort.Shell_sort(); */
    /* sort.Heap_sort(); */
    /* sort.Msort(); */
    sort.Quicksort();


}
