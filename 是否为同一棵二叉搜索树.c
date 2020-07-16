#include <stdio.h>
#include <stdlib.h>
//  搜索树的表示
typedef struct TreeNode *Tree;
struct TreeNode{
	int v;
	Tree Left,Right;
	int flag;
};
Tree MakeTree(int N);
Tree NewNode(V);
Tree Insert( Tree T, int V );
int check( Tree T,int V );
int Judge( Tree T, int N);
void ResetT( Tree T);
void FreeTree( Tree T);
// 程序框架
int main()
{
	int N,L,i;
	Tree T;
	scanf("%d", &N );
	while( N )
	{
		scanf("%d", &L );
		T = MakeTree(N);		//建立一棵树
		for( i = 0; i<L; i++)
		{
			if( Judge( T, N)) printf( "Yes\n");	//判断是否一样
			else printf( "No\n");
			ResetT(T);		//清空flag标记
		}
		FreeTree(T);	//释放这棵树的空间
		scanf( "%d",&N);	//继续输入下一组
	}
	return 0;
}

//建立搜索树
Tree MakeTree(int N)
{
	Tree T;
	int i,V;
	scanf( "%d", &V);
	T = NewNode(V);
	for( i = 1; i<N; i++)
	{
		scanf( "%d",&V);
		T = Insert( T,V);
	}
	return T;
}

Tree NewNode(V)
{
	Tree T = (Tree)malloc( sizeof(struct TreeNode));
	T ->v = V;
	T ->Left = T ->Right = NULL;
	T ->flag = 0;
	return T;
}

Tree Insert( Tree T, int V )
{
	if( !T ) T = NewNode( V );
	else{
		if( V > T ->v)
			T ->Right = Insert( T ->Right, V );
		else
			T ->Left = Insert( T ->Left, V);
	}
	return T;
}

//如何判别
//在树T中按顺序搜索序列中的每个数
//如果每次搜索所经过的结点在前面出现过，则一致、
//否则（某次搜索中遇到前面未出现的结点），则不一致


int check( Tree T,int V )
{
	if( T ->flag ){
		if( V <T ->v) return check( T ->Left, V);
		else if( V > T ->v) return check( T ->Right, V);
		else return 0;
	}
	else{
		if( V == T ->v){
			T ->flag = 1;
			return 1;
		}
		else return 0;
	}
}

int Judge( Tree T, int N)
{
	int i,V,flag = 0;	//0代表目前还一致，1代表不一致了
	scanf("%d",&V);
	if( V != T ->v)  flag = 1;
	else  T ->flag = 1;
	for( i =1; i<N; i++)
	{
		scanf("%d", &V);
		if( (!flag) && (!check( T,V )))  flag = 1;
	}
	if(flag)  return 0;
	else return 1;
}

void ResetT( Tree T)
{
	if( T ->Left ) ResetT(T ->Left);
	if(T ->Right )  ResetT(T ->Right);
	T ->flag =0 ;
}

void FreeTree( Tree T)
{
	if( T ->Left ) FreeTree( T->Left);
	if( T ->Right ) FreeTree( T->Right);
	free(T);
}
