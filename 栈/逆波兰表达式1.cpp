#include <iostream>
#include <cstring>
#include <stack>
#include <cstdlib>
using namespace std;
//判断当前字符token是操作数还是运算符
bool isNumber(char *token){
    int len = strlen (token);//当前字符的长度
    //注：长度大于一表示是二位数操作数
    return (len > 1) || (token[0] >= '0' && token[0] <= '9');
}

int evalRPN(char** tokens, int len){
    //声明一个存储int型数据的栈
    stack<int> stk;
    //遍历表达式数组
    for (int i = 0; i < len; i++) {
        char* token = tokens[i];
        if (isNumber(token))
            //操作数转整数入栈
            stk.push(atoi(token));
        else {
            //取栈顶前两个元素出栈(先出栈的是右操作数)
            int b = stk.top(); stk.pop(); 
            int a = stk.top(); stk.pop();
            int val;
            switch (token[0]) {
            case '+': val = a + b; break;
            case '-': val = a - b; break;
            case '*': val = a * b; break;
            case '/': val = a / b; break;
            default : val = 0;
            }
            //把运算结果放回栈中
            stk.push(val); 
        }
    }
    return stk.top();
}

int main (){
    const char* tokens_arr[] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int len = sizeof(tokens_arr)/sizeof(tokens_arr[0]);//表达式的长度
    char** tokens = const_cast<char**>(tokens_arr);
    cout << "RPN的结果是" << evalRPN(tokens, len) << endl;   
    return 0;
}