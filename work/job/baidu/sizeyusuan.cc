#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 100

typedef struct Stack_int{
    int data[MAXSIZE];
    int top;
}Stack_int;

typedef struct Stack_char{
    char data[MAXSIZE];
    int top;
}Stack_char;

char priority[5][5] = {'=','=','<','<','>',
                       '=','=','<','<','>',
                       '>','>','=','=','>',
                       '>','>','=','=','>',
                       '<','<','<','<','='};/*分别为 + - * / (*/

void pushstack(Stack_char *CStack, char c)
{
    if((*CStack).top == MAXSIZE)
        cout << "The Stack_char is up to its MAXSIZE!" << endl;
    else
        (*CStack).data[++(*CStack).top] = c;
}
/*优先级比较，优先级定义在数组priority中*/
char compare_priority(char c, char d)
{
    if((c == '+')||(c == '-'))
    {
        if(d == '+' || d == '-')
            return '=';
        else if(d == '(')
            return '>';
        else
            return '<';
    }
    else if(c == '*' || c == '/')
    {
        if(d == '+' || d == '-')
            return '>';
        else if(d == '(')
            return '>';
        else
            return '=';
    }
    else if(c == d)
         return '=';

}

/*如果是数字，直接保存在数字栈中，若是（，保存在字符栈中，若为计算符,则比较字符栈栈顶和该字符优先级，若优先级大于栈顶元素，则入栈字符栈，否则输出字符栈中元素，若是），则输出字符栈中元素到数字栈中，直到遇到（*/
void Transfer_MidtoLat(string s, Stack_char *CStack1, Stack_char *CStack2)
{
    char c;
    for(auto c : s)
    {
        if( c >= '0' && c <= '9')
        {
            pushstack(CStack2,c);
        }
        else if((*CStack1).top != -1)
            {
                if(c == ')')
                {
                    while((*CStack1).data[(*CStack1).top] != '(')
                    {
                        pushstack(CStack2,(*CStack1).data[(*CStack1).top]);
                        (*CStack1).top--;
                    }
                    (*CStack1).top--;
                }
                else if(c == '(')
                        pushstack(CStack1,c);
                else
                {
                    if(compare_priority(c,(*CStack1).data[(*CStack1).top]) != '<')
                        pushstack(CStack1,c);
                    else
                    {
                        while((compare_priority(c,(*CStack1).data[(*CStack1).top]) != '>') && ((*CStack1).top != -1))
                        {
                            pushstack(CStack2,(*CStack1).data[(*CStack1).top]);
                            (*CStack1).top--;
                        }
                        pushstack(CStack1,c);
                    }
                }
            }
            else
            {
                pushstack(CStack1,c);
            }
    }
    while((*CStack1).top != -1)//字符栈中剩余元素输入到数字栈中
        pushstack(CStack2,(*CStack1).data[(*CStack1).top--]);
}

void print(Stack_char CStack,char *surfix)
{
    Stack_char CStack1;
    CStack1.top = -1;
    while(CStack.top != -1)
    {
        CStack1.top++;
        CStack1.data[CStack1.top] = CStack.data[CStack.top];
        CStack.top--;
    }
    int i = 0;
    while(CStack1.top != -1)
    {
        cout << CStack1.data[CStack1.top];
        surfix[i++] = CStack1.data[CStack1.top];
        CStack1.top--;
    }
    cout << endl;
}

void pushstack(Stack_int *IStack,int a)
{
    if((*IStack).top == MAXSIZE)
    {
        cout << "The Stack_int is up to its MAXSIZE!" << endl;
        return;
    }

    (*IStack).data[++(*IStack).top] = a;
}

void Compute_expression(Stack_int *IStack,char c)
{
    int result;
    switch(c)
    {
        case '+': result = (*IStack).data[(*IStack).top-1] + (*IStack).data[(*IStack).top];
                  (*IStack).top -= 2;
                  break;
        case '-': result = (*IStack).data[(*IStack).top-1] - (*IStack).data[(*IStack).top];
                  (*IStack).top -= 2;
                  break;
        case '*': result = (*IStack).data[(*IStack).top-1] * (*IStack).data[(*IStack).top];
                  (*IStack).top -= 2;
                  break;
        case '/': result = (*IStack).data[(*IStack).top-1] / (*IStack).data[(*IStack).top];
                  (*IStack).top -= 2;
                  break;
    }
    pushstack(IStack,result);
}

/*计算后缀表达式的值，若为数字，压数字栈，若为计算符，计算数字表达式中栈顶前两个数的值，再压栈*/
int Compute_Lat(char *surfix)
{
    Stack_int IStack;
    IStack.top = -1;
    int i = 0;

    while(surfix[i])
    {
        if(surfix[i] >= '0' && surfix[i] <= '9')
            pushstack(&IStack,int(surfix[i]-'0'));
        else
            Compute_expression(&IStack,surfix[i]);
        i++;
    }
    return IStack.data[IStack.top];
}

int main()
{
    Stack_char CStack1;
    Stack_char CStack2;

    string s;
    char *surfix;
    int result,i = 0;

    while(cin >> s && i < 10)
    {
        CStack1.top = -1;
        CStack2.top = -1;
        Transfer_MidtoLat(s,&CStack1,&CStack2);
        result = Compute_Lat(surfix);
        cout  << result << endl;
        i++;
    }

    return 0;
}
