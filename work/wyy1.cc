#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int sum_add(initializer_list<int> li);
void print_ivec(vector<int> ivec,int i);
int &get(vector<int> ivec,int index);
int main()
{
    int i = 1,j = 2.01;
    //int &b  = 2;
    int &a1  = i;
    int &a2 = i;
    int &b1 = j;
    cout << "i=" << i << ",a1=" << a1 << ",a2=" << a2 <<"\n";
    cout << "j=" << j << ",b1=" << b1 << "\n";

    i = 3;
    j = 4;
    cout << "i=" << i << ",a1=" << a1 << ",a2=" << a2 <<"\n";
    cout << "j=" << j << ",b1=" << b1 << "\n";

    a1 = 5;
    b1 = 6;
    cout << "i=" << i << ",a1=" << a1 << ",a2=" << a2 <<"\n";
    cout << "j=" << j << ",b1=" << b1 << "\n";

    a1 = j;
    cout << "i=" << i << ",a1=" << a1 << ",a2=" << a2 <<"\n";
    cout << "j=" << j << ",b1=" << b1 << "\n";
    a1 = 5;//只绑带了初始化的变量，
    cout << "i=" << i << ",a1=" << a1 << ",a2=" << a2 <<"\n";
    cout << "j=" << j << ",b1=" << b1 << "\n";

    const int &c = 1;
    cout << "const int &c = " << c << "\n";
    int s = 10;
   // const int &s1 = s;
    const int &s1 = s;
    const int &s2 = s;
    cout << "in s=" << s << ", const int &s1=" << s1 << ", const int &s2=" << s2 <<"\n";
    
    s = 13;
    cout << "in s=" << s << ",const int &s1=" << s1 << ",const int &s2=" << s2 <<"\n";
/*
    s1 = 13;//不能更改const，及其引用值
    cout << "in s=" << s << ",const int &s1=" << s1 << ",const int &s2=" << s2 <<"\n";
    s2 = i;
    cout << "in s=" << s << ",const int &s1=" << s1 << ",const int &s2=" << s2 <<"\n";*/

    auto s3 = 12;
    auto &s4 = s;
    s4 = 5;
    cout << "s3 = " << s3 << ", &s4 =" << s4 << ", s=" << s << "\n";

    string str1("hello");
    string str2 = "world",str3 = str1 + str2;
    cout << str1 << " "  << str2 << " " << str3 <<"\n";

    str3 = str1 + " Judy\n";
    cout << str3;
/*    str3 = str1 + "hi " + "Judy\n";
    cout << str3;*///不能将两个字面值string相加

    /*统计字符串中标点符号的个数*/
    str1 = "DDD1223!!4ddeoj,.?ss?!.{(oiu";
    decltype(str1.size()) punct_cnt = 0;
    for(auto c :str1)
        if(ispunct(c))
            punct_cnt++;
    cout << punct_cnt << " punctuation characters in " << str1 << endl;
    str2 = str1;

    /*改变字符串中的大小写*/
    for(auto &c:str1)//利用引用改变值
        if(!ispunct(c))
        {
            if(isupper(c))
                c = tolower(c);
            else
                c = toupper(c);
        }
    cout << str2 << "改变字符串中的大小写：" << str1 <<endl;

    /*将字符串中字符改为x*/
    i = 0;
    while(str1[i++] )
    {   
        auto &c = str1[i-1];
        c = 'x';
    }
    cout << str2 << "改变字符串中字符为x：" << str1 <<endl;

    /*去除标点符号，输出剩余字符*/
    str1 = str2;
    i = 0;
    while(str1[i])
    {
        if(ispunct(str1[i]))
            str1[i] = ' ';
        i++;
    }
    cout << str2 << "去除标点符号：" << str1 <<endl;

    /*vector*/
    vector<vector<int>> ivec1;
    vector<int> ivec2;
    str2 = "";
    vector<string> svec1{"aaa"};
    vector<string> svec2(3,"hi");
    vector<string> svec3{2,"hello"};

    for(i = 0; i < 6 ;i++)
    {
        ivec2.push_back(i);
    }
    cout << ivec2.size() << " number in the vector:";
    for(auto i:ivec2)
        cout << i << " ";
    cout << endl;
    
    for(i = 0; i<4;i++)
        svec1.push_back("hello ");
    cout << svec1.size() << " number in the vector:";
    for(auto i:svec1)
        cout << i << " ";
    cout << endl;

    /*vector 字符串改大写*/
    cout <<"转化成大写";
    for(i = 0; i<svec1.size(); i++)
    {
        for(auto &c:svec1[i])
            c = toupper(c);
        cout << svec1[i] << " ";
    }
    cout << endl;

    /*vector 数字首尾相加*/
    for(i = 0; i < ivec2.size()/2; i++)
    {
        cout << ivec2[i] + ivec2[ivec2.size() - i-1] << " ";
        if(ivec2.size()%2)
            cout << ivec2[ivec2.size()/2];
    }
    cout << endl;

    /*利用迭代器二分查找*///ivec2,svec1
    auto ib = ivec2.begin();
    auto ie = ivec2.end();
    auto imid = ivec2.begin() + (ie-ib)/2;
    decltype(ivec2.size()) sought = 4;
    cout << "sought = "<< sought;
    while(*imid != sought && imid != ie)
    {
        if(*imid < sought)
            ib = imid + 1;
        else if(*imid > sought)
            ie = imid;
        imid = ib + (ie-ib)/2;
    }
    if(imid != ie)
        cout <<" find the sought:"<< *imid << endl;
    else
        cout << " There have no sought!" << endl;

    /*数组and指针*/
    int array1[3][4];
    for(i = 0; i < 3; i++)
        for(j = 0; j < 4; j++)
            array1[i][j] = i * 10 + j;
    for(auto p1 = array1; p1 < array1+3; p1++)
    {
        for(auto p2 = *p1; p2 < *p1+4; p2++)
            cout << *p2 << " ";
        cout << endl;
    }

    int *p1 = array1[1];
    cout << ++*p1 << " ";
    cout << *p1 <<endl;

    i = 5;
    cout << ((i < 3)? "fail":"true") << endl;
    /*cout <<(i < 3)? "fail":"true" ;
    cout << endl;*/

    /*利用位运算，共32个学生，判断某个学生是否完成测试*/
    unsigned long stu = 1;
    cout << "置27位为1:" << 1UL << " ";
    stu |= 1UL << 27;//第27个学生完成测试置为1
    bool status = stu & (1UL << 27);
    cout << "判断该位值是否为1：" << status << " ";// 判断该位值是否为1
    stu &= ~(1UL << 27);//重新置为0
    status = stu &(1UL << 27);
    cout << "重新置为0：" << status << endl;

   /*try-catch异常*//*
    cout << "输入两个数，相除：\n";
        cin >> i >> j;
    int sc = i/j;
    try{
        throw exception;
    }catch(exception){
        cout << "除数为0，不合法\n";
        cin >> j;
    }
    cout << "商为：" << i/j;*/
    int i1 = 1,i2 = 2,i3 = 3,i4 = 4;
    int sum = sum_add({i1,i2,i3,i4});
    cout << i1<<"+" << i2 << "+" <<i3 <<"+"<< i4 << "=" << sum << endl;

    print_ivec(ivec2,0);
    cout << endl;

    for(i = 0; i != ivec2.size(); i++)
    {
        get(ivec2,i) = i+1;
        cout << ivec2[i] << " ";
    }

}

int sum_add(initializer_list<int> li)
{
    int sum = 0;
    for(auto i:li)
        sum += i;
    return sum;
}

void print_ivec(vector<int> ivec,int i)
{
    if(i != ivec.size())    
    {
        cout << ivec[i++] << " ";
        print_ivec(ivec,i);
    }
}

int &get(vector<int> ivec,int index)
{
    return ivec[index];
}
