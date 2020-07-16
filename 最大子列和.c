#include <stdio.h>
#define MAX 10000
int main(void)
{
	int k,i;
	int a[MAX] = {0};
	scanf( "%d",&k);
	for( i = 0; i<k; i++)
		scanf("%d",&a[i]);
	printf("%d\n",MaxSubseqSum3( a,k));
	return 0;
}

int MaxSubseqSum1(int a[], int n)
{
	int i,j,k;
	int ThisSum = 0,MaxSum = 0;
	for(i = 0; i<n; i++){			//i是子列左端位置
		for( j =i; j<n; j++){		//j是子列右端位置
			ThisSum = 0;	//ThisSum是从i到j的和
			for( k=i; k<=j; k++){
				ThisSum += a[k];
			}
			if( ThisSum >MaxSum)   
				MaxSum = ThisSum;
		}	//j循环结束	
	}	//i循环结束
	return MaxSum;
}
	
int MaxSubseqSum2(int a[], int n)
{
	int i,j;
	int ThisSum = 0,MaxSum = 0;
	for( i = 0; i<n; i++){			//i是子列左端位置
		ThisSum = 0;	//ThisSum是从i到j的和
		for(j = 0; j<n;  j++){		//j是子列右端位置
			ThisSum+=a[j];
		//对于相同的i 不同的j ，只要在循环的基础上累加1就可以
		if( ThisSum >MaxSum)
			MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

//算法三    分而治之
/*
	将序列从中分为左右两个子序列。
	递归求得两个子列的最大和。
	从中分点分头向左、右两边扫描，找出跨过分界线的最大子列和。
	输出这三个子列和最大的一个。  
*/
int Max3( int a,int b, int c)
{
	return a > b ? a > c ? a : c : b > c ? b : c;
}
int MaxSubseqSum3(int List[], int n)
{
	return Divide( List, 0, n-1);
}
/* 分治法求List[left]到List[right]的最大子列和 */
int Divide(int List[], int left, int right)
{
	int MaxLeftSum,MaxRightSum;	/* 存放左右子问题的解 */
	int MaxLeftBorderSum, MaxRightBorderSum;	/*存放跨分界线的结果*/

	int LeftBorderSum, RightBorderSum;
	int center, i;

	if( left == right ){		/* 递归的终止条件，子列只有1个数字 */
		if( List[left] > 0)  return List[left];
		else return 0;
	}
	
	/* 下面是"分"的过程 */
	center = ( left + right) / 2;	/* 找到中分点 */
	/* 递归求得两边子列的最大和 */
	MaxLeftSum = Divide( List, left, center );
	MaxRightSum = Divide( List, center+1, right );
	
	//下面求跨分界线的最大子列和
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for( i = center; i>=left; i--)	/* 从中线向左扫描 */
	{
		LeftBorderSum += List[i];
		if( LeftBorderSum> MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}/* 左边扫描结束 */
	MaxRightBorderSum = 0; RightBorderSum = 0;
	for( i=center+1; i<=right; i++ ) /* 从中线向右扫描 */
	{ 
        		RightBorderSum += List[i];
        		if( RightBorderSum > MaxRightBorderSum )
            		MaxRightBorderSum = RightBorderSum;
    	} /* 右边扫描结束 */
	
	/* 下面返回"治"的结果 */
	 return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}



int MaxSubseqSum4(int a[], int n)	//在线处理
{
	int ThisSum=0 ,MaxSum = 0;
	int i;	
	for( i = 0; i<n; i++){		//向右累加
		ThisSum += a[i];
		if(ThisSum > MaxSum )
			MaxSum = ThisSum;
		else if( ThisSum <0)		//如果当前子列和为负的则抛弃他，因为他不会使后面的和变大
			ThisSum = 0;
	}
	return MaxSum;
}

