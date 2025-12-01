//
//
//顺序栈
//
//SqStack

//定义（顺序）栈

#define MAX 10

typedef struct 
{
    int *top;
    int *base;
    int maxsize;
}SqStack;
//初始化
void InitStack(SqStack &S){
    S.base = new int[MAX];
    S.top = S.base;
    S.maxsize = MAX;
}
//入栈Push
bool Push(int e, SqStack &S){
    //栈满，入栈失败
    if (S.top - S.base == S.maxsize)
        return false;
    *S.top = e;
    S.top++;
    return true;
}
//出栈Pop
bool Pop(SqStack &S, int &e){
    //栈空，出栈失败
    if (S.top == S.base)
        return false;
    S.top--;
    e = *S.top;
    return true;
}
// 取栈顶元素GetTop
int GetTop(SqStack &S){
    //栈空
    if (S.top == S.base)
        return false;
    return *(S.top-1);
}