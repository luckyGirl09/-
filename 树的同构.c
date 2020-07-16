// #include <iostream>
#include <stdio.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
// using namespace std;
struct TreeNode {
    ElementType Element;
    Tree Left;
    Tree Right;
} T1[MaxTree],T2[MaxTree];
Tree BuildTree(struct TreeNode T[]) {
    int N,i;
     scanf("%d\n",&N);
    //添加的代码
    int Root=Null;
    char cl,cr;
    int check[N];
    if(N) {
        for(i=0; i<N; i++)
            check[i]=0;
        for(i=0; i<N; i++) {
           // cin>>T[i].Element>>cl>>cr;
            scanf("%c %c %c\n",&T[i].Element,&cl,&cr);
            //左子树
            if(cl!='-') {
                T[i].Left=cl-'0';
                check[T[i].Left]=1;
            } else
                T[i].Left=Null;
            //右子树
            if(cr!='-') {
                T[i].Right=cr-'0';
                check[T[i].Right]=1;
            } else
                T[i].Right=Null;
        }
        for(i=0; i<N; i++)
            if(!check[i])
                break;
        Root=i;
    }
    return Root;
}
int Isomorphic(Tree R1,Tree R2) {
    //Both = Null
    if((R1==Null)&&(R2==Null))
        return 1;
    //R1,R2中有一个为Null
    if(((R1==Null)&&(R2!=Null))||((R1!=Null)&&(R2==Null)))
        return 0;
    //两棵树中根节点的元素不一样
    if(T1[R1].Element!=T2[R2].Element)
        return 0;
    //如果两颗二叉树的左子树都为空，返回判断二叉树的右子树
    if((T1[R1].Left==Null)&&T2[R2].Left==Null)
        return Isomorphic(T1[R1].Right,T2[R2].Right);
    //如果左子树都不为空且元素相同，返回判断右子树是否为空以及右子树的元素是否相同
    if(((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))
            &&((T1[T1[R1].Left].Element)==(T2[T2[R2].Left].Element)))
        return(Isomorphic(T1[R1].Left,T2[R2].Left)
               &&Isomorphic(T1[R1].Right,T2[R2].Right));
    else
        return(Isomorphic(T1[R1].Left,T2[R2].Right)
               &&Isomorphic(T1[R1].Right,T2[R2].Left));//如果两棵树左子树元素不相等还要比较左右元素是否可能相等
}
int main() {
    Tree R1,R2;
    R1=BuildTree(T1);
    R2=BuildTree(T2);
    if(Isomorphic(R1,R2))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
