#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//记录搬动次数
int cnt = 0;
stack<int>stkA;
stack<int>stkB;
stack<int>stkC;
//将A上唯一的圆盘直接移到C
void Move(stack<int>& A, stack<int>& C){
    int temp = A.top();   //获取A上的圆盘temp
    A.pop();              //将temp移出A
    C.push(temp);         //将temp移入C
    ++cnt;                   //移动次数加一
}
//将A上的所有(n个)圆盘移到C 中间以B作为铺垫
void Hanoi(int n, stack<int>& A, stack<int>& B, stack<int>& C){
    //若A上只有一个圆盘 直接移到C
    if (n == 1)
        Move(A, C);
    else{//若A上有n个(n>1) 先把A上面的前n-1个移到B 中间用C作辅助
        Hanoi(n-1, A, C, B);
        //再把A剩下的最后一个圆盘移到C 中间用B作辅助
        Move(A, C);
        //最后把B上的n-1个圆盘移到C 中间用A作辅助
        Hanoi(n-1, B, A, C);
    }
}
int main(){
    int n;
    cin >> n;                       //圆盘总个数
    for(int i=0; i<n; i++){
        int num;
        cin >> num;                 //依次输入圆盘编号
        stkA.push(num);             //将圆盘压入栈A中
    }
    Hanoi(n, stkA, stkB, stkC);     //调用函数移动所有圆盘
    while (n){
        cout << stkC.top() << " ";  //输出移动后C上的圆盘
        stkC.pop(); --n;
    }
    cout << endl << cnt << endl;    //输出移动总次数
    return 0;
}