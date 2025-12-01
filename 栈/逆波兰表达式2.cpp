#include<vector>
#include<string>
#include<stack>
using namespace std;
int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (auto& token : tokens) {
        char c = token[0];
        //若token是数字 直接入栈
        if (token.size() > 1 || isdigit(c)) {
            st.push(stoi(token));
            continue;
        }
        //右操作数出栈
        int num = st.top();
        st.pop();
        //计算结果替换栈顶元素 避免左操作数出栈又入栈
        if (c == '+') st.top() += num;
        else if (c == '-') st.top() -= num;
        else if (c == '*') st.top() *= num;
        else st.top() /= num;
    }
    return st.top();
}
