
//
//
// 链栈(LinkStack)

//  定义
typedef struct StackNode
{
    int data;                 // 数据元素
    struct StackNode *next;   // 结点指针
} StackNode, *LinkStack;
// 注意：StackNode*表示结点指针，而LinkStack表示栈顶指针

//
// 不带头结点
//

// 创 （初始化）
void InitStack(LinkStack &S)
{
    S = nullptr;
}

// 增（入栈）
int Push(LinkStack &S, int e)
{
    StackNode *p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;
    return 1;
}

// 删 （出栈）
int Pop(LinkStack &S, int &e) // 注意：e需要用引用（&），否则无法把栈顶元素传出去
{
    if (S == nullptr)
        return 0;
    e = S->data;
    StackNode *p = S;
    S = S->next;
    delete p;
    return 1;
}

// 查 （获取栈顶元素）
int GetTop(LinkStack S)
{
    if (S != nullptr)
        return S->data;
    return -1;
}

// 如何判空/判满？
// 判空：
int StackEmpty(LinkStack S)
{
    if (S == nullptr)
        return 0;
    return 1;
}
// 无需判满

//
// 带头结点
//

// 创 （初始化）
void InitStack(LinkStack &S)
{
    S = new StackNode;   // 头结点
    S->next = nullptr;   // 头指针的指针域置空
}
// 增 （入栈）
int Push1(LinkStack &S, int e)
{
    StackNode *p = new StackNode;
    p->data = e;
    p->next = S->next;
    S->next = p;
    return 1;
}
// 删 （出栈）
int Pop1(LinkStack &S, int &e) // 同样的，这里的e需要用引用，才能把栈顶元素传出
{
    if (S->next == nullptr)
        return 0;
    StackNode *p=S->next;// 保存待删除结点
    e = p->data;
    S->next = p->next;
    delete p;
    return 1;
}
// 查 （读取栈顶元素）
int GetTop1(LinkStack S)
{
    if (S->next != nullptr)
        return S->next->data;
    return -1;
}
