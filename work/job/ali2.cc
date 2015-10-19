#include <iostream>
#include <vector>
/* #include <stdlib.h> */
#include <map>
#include <set>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;
/* 在text中查找query里包含的最长字串 */
int findstring(string str,string substr)
{
    int i = 0,j = substr.length();
    int len = 0;
    for( i = 0; i < substr.length();i++)
    {
        for(j = substr.length(); j != i; j--)
        {
            char *p = &substr[i];
            if(str.find(p,0,j-i) != str.npos)
            {
                if (len < j-i)
                    len = j-i;
            }
        }
    }
    cout << "text:" << str << "    query:" << substr;
    cout << "   length: " << len << endl;
    return len;
}

void init_vec(vector<string> &svec)
{
    svec = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
}

void init_vec(map<string,int> &map_vec)
{
    map_vec.insert({"A++",12});
    map_vec.insert({"B++",22});
    map_vec.insert(make_pair("C++",32));
}
void init_vec(set<string> &set_vec)
{
    set_vec.insert("Aplusplus");
    set_vec.insert("Bplusplus");
    set_vec.insert("Cplusplus");
    set_vec.insert("Bplusplus");
}

void print(map<string,int> map_vec)
{
    auto iter = map_vec.begin();
    for(;iter != map_vec.end();iter++)
        cout << (*iter).first << ":"<< (*iter).second << endl;
    /* for(auto i:map_vec)
        cout << i.first << ":"<< i.second << endl; */
    cout << endl;
}

void print(set<string> set_vec)
{
    /* for(auto i:set_vec)
        cout << i << " " ; */
    for(auto i = set_vec.begin();i != set_vec.end(); i++)
        cout << *i << " " ;
    cout << endl;
}

void print(vector<string> &svec)
{
    for(auto i = svec.begin();i != svec.end(); i++)
        cout << *i << "  ";
    cout << endl;
}

void sort_by_dic(vector<string> &svec)
{
    sort(svec.begin(),svec.end());
    auto end_unique = unique(svec.begin(),svec.end());
    svec.erase(end_unique,svec.end());
    print(svec);
    /*按长度重新排序*/
    stable_sort(svec.begin(),svec.end(),[](const string &a,const string &b) {return a.size() < b.size();});
    print(svec);
}


int main()
{
    string text("abcdaoiut");
    string query = "cda";
    int length = findstring(text,query);
    length = findstring("acaccbabb","acbac");

    string str = "as980dff+3.1415k99999";
    cout << str << "     "<< stod(str.substr(str.find_first_of("+-.0123456789"))) << endl;

/*找出字符串中所有的数字，并转化成数字输出  */
    /* size_t pos = 0;
    double yao;
    while((pos = str.find_first_of("-.0123456789",pos)) != str.npos)
    {
        string s = str.substr(str.find_first_of("-.0123456789",pos));
        char *c ;
        yao = stod(s);
        cout <<yao << endl;
        gcvt(yao,10,c);
        [>cout << strlen(c) << endl;<]
        pos = pos + strlen(c);
    } */

/*按字典序排序  */
    vector<string> svec;
    init_vec(svec);
    print(svec);
    sort_by_dic(svec);
    size_t sz = 3;
    auto wc = find_if(svec.begin(),svec.end(),[sz](const string &a) { return a.size() > sz;});
    cout <<"输出长度>" <<sz << "的单词,共" << svec.end()-wc <<"个:" ;
    for_each(wc,svec.end(),[](const string &a) {cout << a << " ";});
    cout << endl;


    /*set和map*/
    map<string,int> book_map = {{"D++",42},{"E++",52}};
    init_vec(book_map);
    print(book_map);
    set<string> book_set;
    init_vec(book_set);
    print(book_set);
    return 0;
}
