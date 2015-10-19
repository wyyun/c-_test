#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

void init_Svec(vector<string> *svec,int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        svec->push_back("sssveca"+i);
        svec->push_back("wyya");
    }
}

void count_words(map<string,size_t> words)
{
    for(auto w:words)
        cout << w.first << " occurs " << w.second << ((w.second > 1)? " times":" time") << endl;
}

void init_map(map<string,size_t> *words, vector<string> svec)
{
    for(auto w = svec.begin(); w != svec.end(); w++)
    {
        if(words->find(*w) != words->end())
            ++(*words)[*w];
        else
        {
          //  words->insert({*w,1});//向map中插入元素pair
            words->insert(make_pair(*w,1));
        }
    }
}

void delete_map(map<string,size_t> *words,string s)
{
    if(words->erase(s))
        cout << "delete_map:" << s << " sucessful!" << endl;
    else
        cout << s << " is not find in delete_map" << endl;

}

void print(map<string,size_t> word)
{
    cout << "****map*****" << endl;
    for(auto i:word)
        cout << i.first << " " << i.second << ";";
    cout << endl;
}

void print(set<string> word)
{
    cout << "*****set****" << endl;
    for(auto i:word)
        cout << i << " ";
    cout << endl;
}

void init_multmap(multimap<string,size_t> *word, vector<string> svec)
{
    for(auto i : svec)
        word->insert({i,1});

    for(auto i : svec)
        word->insert({i,1});
}

void init_multset(multiset<string> *word, vector<string> svec)
{
    for(auto i:svec)
        word->insert(i);

    for(auto i:svec)
        word->insert(i);
}

void print(multimap<string,size_t> word)
{
    cout << "\n*****multimap*****" << endl;
    for(auto i : word)
    {
        cout << i.first << " " << i.second << ";";
    }
    cout << endl;
    cout << "wyya:";
    auto num = word.count("wyya");
    auto iter = word.find("wyya");
    while(num)
    {
        cout << iter->second << " ";
        iter++;
        num--;
    }
    cout << endl;

}

void print(multiset<string> word)
{
    cout << "\n*****multiset*****" << endl;
    for(auto i: word)
    {
        cout << i << " ";
    }
    cout << endl;
    auto num = word.count("wyya");
    auto iter = word.find("wyya");
    cout << "wyya:";
    while(num)
    {
        cout << *iter << " ";
        iter++;
        num--;
    }
    cout << endl;
}

map<string,string> buildMap(ifstream &mapfile)
{
    map<string,string> trans_map;
    string key;
    string value;
    while(mapfile >> key && getline(mapfile,value))
    {
        if(value.size() > 1)//是否有转化机制
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for "+ key);
    }
    return trans_map;
}

const string& transform(const string &s, const map<string,string> &m)
{
    auto map_it = m.find(s);
    if(map_it != m.cend())
        return map_it->second;
    else
        return s;
}

void word_transfrom(ifstream &mapfile, ifstream &input)
{
    auto trans_map = buildMap(mapfile);//保存转换规则
    string text;
    while(getline(input,text))//输入要转换文件中的一行，保存在text中
    {
        istringstream stream(text);
        string word;
        bool firstword = true;//控制是否打印空格
        while(stream >> word)//输出该行，以空格分断
        {
            if(firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word,trans_map);//根据转换规则，转化单词到对应的单词
        }
        cout << endl;
    }

}

int main()
{
    vector<string> Svec;
    init_Svec(&Svec,6);

    map<string,size_t> word{{"wyya",1},{"wyyb",1}};
    init_map(&word,Svec);
    count_words(word);//计数单词数
    delete_map(&word,*Svec.begin());//删除map中的元素
    delete_map(&word,"yaowj");//删除map中的元素
    print(word);

    set<string> wordset(Svec.begin(),Svec.end());
    print(wordset);

    multimap<string,size_t> wordmultmap;
    init_multmap(&wordmultmap,Svec);
    print(wordmultmap);

    multiset<string> wordmultset;
    init_multset(&wordmultset,Svec);
    print(wordmultset);

    ifstream mapfile("mapfile.txt");
    ifstream input("input.txt");
    word_transfrom(mapfile,input);

    return 0;
}
