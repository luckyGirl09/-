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
	for(i = 0; i<n; i++){			//i���������λ��
		for( j =i; j<n; j++){		//j�������Ҷ�λ��
			ThisSum = 0;	//ThisSum�Ǵ�i��j�ĺ�
			for( k=i; k<=j; k++){
				ThisSum += a[k];
			}
			if( ThisSum >MaxSum)   
				MaxSum = ThisSum;
		}	//jѭ������	
	}	//iѭ������
	return MaxSum;
}
	
int MaxSubseqSum2(int a[], int n)
{
	int i,j;
	int ThisSum = 0,MaxSum = 0;
	for( i = 0; i<n; i++){			//i���������λ��
		ThisSum = 0;	//ThisSum�Ǵ�i��j�ĺ�
		for(j = 0; j<n;  j++){		//j�������Ҷ�λ��
			ThisSum+=a[j];
		//������ͬ��i ��ͬ��j ��ֻҪ��ѭ���Ļ������ۼ�1�Ϳ���
		if( ThisSum >MaxSum)
			MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

//�㷨��    �ֶ���֮
/*
	�����д��з�Ϊ�������������С�
	�ݹ�����������е����͡�
	���зֵ��ͷ����������ɨ�裬�ҳ�����ֽ��ߵ�������к͡�
	������������к�����һ����  
*/
int Max3( int a,int b, int c)
{
	return a > b ? a > c ? a : c : b > c ? b : c;
}
int MaxSubseqSum3(int List[], int n)
{
	return Divide( List, 0, n-1);
}
/* ���η���List[left]��List[right]��������к� */
int Divide(int List[], int left, int right)
{
	int MaxLeftSum,MaxRightSum;	/* �������������Ľ� */
	int MaxLeftBorderSum, MaxRightBorderSum;	/*��ſ�ֽ��ߵĽ��*/

	int LeftBorderSum, RightBorderSum;
	int center, i;

	if( left == right ){		/* �ݹ����ֹ����������ֻ��1������ */
		if( List[left] > 0)  return List[left];
		else return 0;
	}
	
	/* ������"��"�Ĺ��� */
	center = ( left + right) / 2;	/* �ҵ��зֵ� */
	/* �ݹ�����������е����� */
	MaxLeftSum = Divide( List, left, center );
	MaxRightSum = Divide( List, center+1, right );
	
	//�������ֽ��ߵ�������к�
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for( i = center; i>=left; i--)	/* ����������ɨ�� */
	{
		LeftBorderSum += List[i];
		if( LeftBorderSum> MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}/* ���ɨ����� */
	MaxRightBorderSum = 0; RightBorderSum = 0;
	for( i=center+1; i<=right; i++ ) /* ����������ɨ�� */
	{ 
        		RightBorderSum += List[i];
        		if( RightBorderSum > MaxRightBorderSum )
            		MaxRightBorderSum = RightBorderSum;
    	} /* �ұ�ɨ����� */
	
	/* ���淵��"��"�Ľ�� */
	 return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}



int MaxSubseqSum4(int a[], int n)	//���ߴ���
{
	int ThisSum=0 ,MaxSum = 0;
	int i;	
	for( i = 0; i<n; i++){		//�����ۼ�
		ThisSum += a[i];
		if(ThisSum > MaxSum )
			MaxSum = ThisSum;
		else if( ThisSum <0)		//�����ǰ���к�Ϊ����������������Ϊ������ʹ����ĺͱ��
			ThisSum = 0;
	}
	return MaxSum;
}

