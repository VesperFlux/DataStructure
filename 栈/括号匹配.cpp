#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define MAX 30

//定义顺序栈
typedef struct
{
    int size;
    char *top;
    char *base;
} SqStack;
//初始化栈
void InitStack(SqStack &S){
    S.base = new char[MAX];
    S.top = S.base;
    S.size = 0;
}
//进栈
void Push(SqStack &S,char ch){
    if (S.size >= MAX)
        return;
    *(S.top++) = ch;
    S.size++;
}
//出栈
char Pop(SqStack &S){
    char ch = *(--S.top);
    S.size--;
    return ch;
}
//销毁栈
void DestroyStack(SqStack &S){
    delete[] S.base;
    S.base = nullptr;
    S.top = S.base;
    S.size = 0;
}
// 匹配判断
bool isMatch(const string &str){
    SqStack S;
    InitStack(S);
    for(char ch : str){
        if (ch == '(' || ch == '[' || ch == '{') {
            Push(S,ch);
        }
        else {
            if (S.size == 0) {
                DestroyStack(S);
                return false;
            }
            char Topch = Pop(S);
            if ((ch == ')' && Topch != '(') ||
                (ch == ']' && Topch != '[') ||
                (ch == '}' && Topch != '{')) 
            {
                DestroyStack(S);
                return false;
            }
        }  
    }
    bool res = (S.size == 0);
    DestroyStack(S);
    return res;
}

int main(void)
{

    int T;
    cin >> T; // T个待测字符串
    cin.ignore();

    while (T--)
    {
        string str;
        getline(cin, str);
        if (isMatch(str))
            cout << "yes" << endl;
        else cout << "no" << endl;
    }
    
    return 0;    
}