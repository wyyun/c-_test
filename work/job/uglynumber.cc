#include <string>
#include <bitset>
#include <set>
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> vec)
{
    for(auto i:vec)
        cout << i << " ";
    cout << endl;
}

int min(int l,int m,int r)
{
    if(l <= m && l <= r)
        return l;
    else if(m <= l && m <= r)
        return m;
    else return r;
}

class Ugly{
    public:
        bool isUgly(int n)
        {
            if(n<7)
                return true;
            else
            {
                if(!(n%2)||!(n%3)||!(n%5))
                {
                    if(!(n%2))
                        return isUgly(n/2);
                    else if(!(n%3))
                        return isUgly(n/3);
                    else return isUgly(n/5);
                }
                else return false;
            }
        }
        int getUgly(int n)
        {
            if(n < 1) return 0;
            int id2 = 0,id3 = 0,id5 = 0;//记录3个2，3，5倍数的位置
            vector<int> ugly_vec;
            int small = 1;
            int d2,d3,d5;
            while(n--)
            {
                ugly_vec.push_back(small);
                d2 = 2*(ugly_vec[id2]);
                d3 = 3*(ugly_vec[id3]);
                d5 = 5*(ugly_vec[id5]);
                small = min(d2,d3,d5);

                id2 += (small == d2);
                id3 += (small == d3);
                id5 += (small == d5);
            }
            print(ugly_vec);
            return 1;
        }
};

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL) {}
    TreeNode * Mid_creat();
    void Mid_print(TreeNode *);
};

TreeNode * TreeNode::Mid_creat()
{
    TreeNode *tree = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    cin >> i;
    if(!i)
        tree = NULL;
    else
    {
        tree->left = Mid_creat();
        tree->val = i;
        tree->right = Mid_creat();
    }
    return tree;

}
void TreeNode::Mid_print(TreeNode *t)
{
    if(t)
    {
        Mid_print(t->left);
        cout << t->val << " ";
        Mid_print(t->right);
    }
}

void print(vector<string> vec)
{
    for(auto i:vec)
    {
        cout << i << endl;
    }
}

class Binary{
    public:
        vector<string> Str_vec;
        vector<string> binaryTreePaths( TreeNode *root)
        {
            Add_binaryPaths(root,"");
            print(Str_vec);
            return Str_vec;
        }
        void Add_binaryPaths(TreeNode *t,string s);
};

void Binary::Add_binaryPaths(TreeNode *t,string s)
{
    s += s.empty()? to_string(t->val):"->"+to_string(t->val);
    if(!(t->left)&&!(t->right))
    {
        Str_vec.push_back(s);
        return;
    }
    if(t->left != NULL) Add_binaryPaths(t->left,s);
    if(t->right != NULL) Add_binaryPaths(t->right,s);
}

vector<int> get_single(vector<int> &nums)
{
    multiset<int> setnum;
    vector<int> result;
    for(int i = 0; i < nums.size(); i++)
        setnum.insert(nums[i]);

    for(auto i:setnum)
        cout << i << "  ";
    cout << "   setnum " << endl;
    for(int i = 0; i < nums.size(); i++)
        if(setnum.count(nums[i]) == 1)
            result.push_back(nums[i]);
    print(result);
    return result;
}

int get_Maxnum(vector<int> &nums)
{
    int i;
    int count = 0;
    int max;
    for(i = 0; i<nums.size(); i++)
    {
        if(count == 0)
        {
            count = 1;
            max = nums[i];
        }
        else if(max != nums[i])
                count--;
             else count++;
    }
    return max;
}

int single_int(int *arr,int n)
{
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        result ^= arr[i];
    }
    cout << "the single_int is " << result << endl;
    return result;
}

int main()
{
/*质数？只能是2，3，5的倍数，最小从1开始；isUgly(n)函数判断给定值n是否是,getUgly(n)函数求出n个最小的质数  */
    Ugly ugly;
    cout << "8:" << ugly.isUgly(8) << endl;
    cout << "7:" << ugly.isUgly(7) << endl;
    cout << "16:" << ugly.isUgly(16) << endl;
    cout << "14:" << ugly.isUgly(14) << endl;
    int flag = ugly.getUgly(10);

/*打印出二叉树中从根节点到叶子节点的路径，包括创建二叉树，打印二叉树路径函数*/
    /* vector<int> Ivec = {1,2,0,5,0,0,3,0,0};
    print(Ivec);
    TreeNode *treenode;
    treenode = treenode->Mid_creat();
    treenode->Mid_print(treenode);
    cout << endl;
    Binary Path_binary;
    Path_binary.binaryTreePaths(treenode); */

/*判断数组中只出现一次的数*/
    vector<int> single_vec;
    vector<int> nums = {1,2,1,3,2,5};
    single_vec = get_single(nums);

/*求出一列整数中个数超出一半的整数  */
    nums = {4,2,6,8,2,2,2,2,0};
    print(nums);
    int number = get_Maxnum(nums);
    cout << "上面数列中出现的最大的数: " << number << endl;

    int Iarr[] = {2,8,4,9,23,45,8,45,2,4,9};
    int Iresult = single_int(Iarr,11);
    return 0;
}
