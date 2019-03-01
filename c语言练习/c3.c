#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//1、求素数
/*bool SuShu(int n)
{
	if(n==2)//2也是素数
		return true;

	for(int i=2;i<n;i++)
	{
		if(n%i == 0)//如果n能被除了1和他本身的其他正整数整除，那么n就不是素数
		    return false	;
	}

	return true;//如果n的约数只有1和它本身，则n是素数
}*/
//筛选法求素数		
//筛选法：首先取除掉能被2整除的数，然后被三整出的数，一次类推，直到n-1；
//步骤：1、首先申请一块动态内存，存放筛选的数据
//2、将所有的数都值1；3、将能被2—>n-1整除的数置0；4、剩下是1的数均为素数
void SuShu(int n)
{
	int *p = (int *)malloc(n*sizeof(int));//申请内存
	assert(p != NULL);
	if(p == NULL)
		return ;
	int i = 0;
	for( i=0;i<n;i++)
	{
		p[i] = 1;//将所有的数都置1
	}

	p[0] = 0;//0和1不是素数
	p[1] = 0;

	for(i=2;i<n;i++)//利用循环嵌套，将能被从2到n-1整除的数置0
	{
		for(int j=i+1;j<n;j++)
		{
			if(j%i==0)
				p[j] = 0;
		}
	}

	for(i=0;i<n;i++)
	{
		if(p[i] == 1)//没有被置0的数就是素数
			printf("%d\n",i);
	}
	free(p);//释放内存


}
	


//2、用选择发对10个整数排序
/*int PaiXu(int *arr,int len)
{
	int n,i,t;
	for(n=0;n<len;n++)
	{
		for(i=0;i<len-n;i++)
		{
			t=arr[i];
			if(arr[i]>arr[i+1])
				arr[i]=arr[i+1];
			 arr[i+1]=t;

		}
		for(i=0;i<len;i++)
		return arr[i];
	}
	
}*/

//3、求3*3的整型矩阵矩阵对角线元素之和
int Sum()
{
	
	int b[3][3]={1,2,3,4,5,6,7,8,9},i,j;
	int x,y;
	x = y = 0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
		    x += b[i][j];
			  if(i+j==2)
				y +=b[i][j];
			//else break;
		}
	}
	printf("%d\n",x+y);	
	return 0;
}



//int main()
//{
	/*for(int n=2;n<=100;n++)
	{
		if(SuShu(n))
		printf("%d\n",n);
	}*/


	/*int arr[]={2,11,8,9,7,6,4,3,1,5};
	printf("%d,",PaiXu(arr,sizeof(arr)/sizeof(arr[0])));
	printf("%d\n");*/
	//YangSan(10);
	//return 0;
//}





//6、杨辉三角
/*int main()
{
	int a[11][12],i,j;//初始化i，j
	for(i=0;i<11;i++)
		for(j=0;j<12;j++)
	a[i][j] = 0;//给二维数组赋初值
	for(i=0;i<10;i++)
	{
		for(j=0;j<i;j++)
		{
			if(j<1||i==j)//其实这里不用判断i==j
				a[i][j] = 1;//第一列和每一行的最后一个数字都是1
			else if(i==0)//如果是第一行就退出循环（因为第一行就一个元素）
				break;
			else
				a[i][j]=a[i-1][j-1]+a[i-1][j];//除了第一列元素外，其他的元素都=自身上方元素+自身上方元素的前一个元素（包括每行最后一个元素）

		}
	}
	for(i=0;i<10;i++)//表示打印前10行元素
	{
		for(j=0;j<i;j++)
	    printf("%-4d",a[i][j]);
		printf("\n");
	}
	return 0;
}*/

//7、输出“魔方阵”
/*
魔方阵第一步应将1放在第一行的最中间位置，因为魔方阵是奇数阶矩阵。
魔方阵排放规律：1、从2到n*n个数，一个元素存放的位置是前一个元素的行-1，列+1；
2、如果前一个元素的行为1的话，这个元素的行为n，然后列+1；
3、如果前一个元素的列为n的话，这个元素的列为1，然后行-1；
4、如果按上述规律，此位置已有元素或者上一个元素的位置为第1行第n列，则次元素就放在前一个元素的正下方。
*/

/*
int MoFangZhen()
{
#define H 3
#define L H
	int arr[H][L] = {0};//初始化矩阵所有元素为0；
	int h = 0;
	int l = L/2;
	arr[h][l] = 1;//定义1的位置
	for(int i=2;i<=H*L;i++)
	{
		//环形处理
		h = (h+H-1)%H;
		l = (l+1)%L;
		if(arr[h][l]!=0)//此位置已有元素，则放在上一元素的正下方
		{
			h = (h+H-1)%H;
			l = (l+L-1)%L;
		}
		arr[h][l] = i;
	}
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<L;j++)
		{
			printf("%4d",arr[i][j]);//输出魔方阵
		}
		printf("\n");
	}
	return 0;
}
*/

//8、求鞍点



//9、折半查找数字
/*int BinSearch(int *arr,int len,int key)
{
	int a = 0;//数组第一个元素的下标
	int n = len-1;//最后一个元素的下标
	int mid;
	while(a<n)
	{
		mid = (a+n)/2;//折半
		if(arr[mid] == key)//判断要查找的值的等于arr[mid]（最中间的值）
		{
			return mid;
		}
		else if(arr[mid]<key)
		{
			a = mid;
		}
		else if(arr[mid]>key)
		{
			n = mid;
		}
		//else
			//return 0;
	}
	return mid;
	

}*/


//12、译码


//13、字符串拷贝
char *Mystrcat(char *des,const char *src)
{
	assert(des != NULL&&src != NULL);//断言两个字符串均不为空
	if(des == NULL||src ==NULL)
	{
		return 0;
	}
	char *p = des; 
	while(*des !='\0')//找字符串的尾巴‘\0’
	{
		*des++;
	}
	while(*des++=*src++)//将源字符串拷贝到目标字符串
	return p;
}

//字符串比较
char Compare(const char *str1,const char *str2)
{
	int tmp;
	
	while((tmp = *str1-*str2)== 0&&*str1!='\0')//判断字符串中每个字符的大小
	{
		*str1++;
		*str2++;
	}
	return tmp;//返回字符的差值

}


int main()
{
	SuShu(100);
	//Sum();


	//MoFangZhen();


	//int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	//printf("%d\n",BinSearch(arr,sizeof(arr)/sizeof(arr[0]),12));
	//printf("%d\n",BinSearch(arr,sizeof(arr)/sizeof(arr[0]),2));


	//char des[10] = "asdf";//如何定义des字符串的长度
	//char src[] = "zx";
	//Mystrcat(des,src);
	//printf("%s\n",des);


	
	printf("%d\n",Compare("qwert","qwert"));
	printf("%d\n",Compare("qw","qwert"));
	printf("%d\n",Compare("qwert","as"));
	printf("%d\n",Compare("asd","asx"));

	
	return 0;
}
