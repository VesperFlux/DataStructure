
#include <iostream>
using namespace std;

#define MAXSIZE 20

typedef struct {
    int maxsize;
    int *top;
    int *base;
}SqStack;

void InitStack(SqStack &S){
    S.base = new int[MAXSIZE];
    S.top = S.base;
    S.maxsize = MAXSIZE;
}

int main() {
    
    int N;
    cin >> N;
    SqStack Stack;
    InitStack(Stack);
    
    while (N>0){
        *Stack.top = N % 8;
        ++Stack.top;
        N /= 8;
    }
    
    while (Stack.top != Stack.base) {
        cout << *--Stack.top;
    }
    
    cout << endl;
    
    return 0;
}
 
