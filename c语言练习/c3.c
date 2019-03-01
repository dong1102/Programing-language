#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//1��������
/*bool SuShu(int n)
{
	if(n==2)//2Ҳ������
		return true;

	for(int i=2;i<n;i++)
	{
		if(n%i == 0)//���n�ܱ�����1���������������������������ôn�Ͳ�������
		    return false	;
	}

	return true;//���n��Լ��ֻ��1����������n������
}*/
//ɸѡ��������		
//ɸѡ��������ȡ�����ܱ�2����������Ȼ��������������һ�����ƣ�ֱ��n-1��
//���裺1����������һ�鶯̬�ڴ棬���ɸѡ������
//2�������е�����ֵ1��3�����ܱ�2��>n-1����������0��4��ʣ����1������Ϊ����
void SuShu(int n)
{
	int *p = (int *)malloc(n*sizeof(int));//�����ڴ�
	assert(p != NULL);
	if(p == NULL)
		return ;
	int i = 0;
	for( i=0;i<n;i++)
	{
		p[i] = 1;//�����е�������1
	}

	p[0] = 0;//0��1��������
	p[1] = 0;

	for(i=2;i<n;i++)//����ѭ��Ƕ�ף����ܱ���2��n-1����������0
	{
		for(int j=i+1;j<n;j++)
		{
			if(j%i==0)
				p[j] = 0;
		}
	}

	for(i=0;i<n;i++)
	{
		if(p[i] == 1)//û�б���0������������
			printf("%d\n",i);
	}
	free(p);//�ͷ��ڴ�


}
	


//2����ѡ�񷢶�10����������
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

//3����3*3�����;������Խ���Ԫ��֮��
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





//6���������
/*int main()
{
	int a[11][12],i,j;//��ʼ��i��j
	for(i=0;i<11;i++)
		for(j=0;j<12;j++)
	a[i][j] = 0;//����ά���鸳��ֵ
	for(i=0;i<10;i++)
	{
		for(j=0;j<i;j++)
		{
			if(j<1||i==j)//��ʵ���ﲻ���ж�i==j
				a[i][j] = 1;//��һ�к�ÿһ�е����һ�����ֶ���1
			else if(i==0)//����ǵ�һ�о��˳�ѭ������Ϊ��һ�о�һ��Ԫ�أ�
				break;
			else
				a[i][j]=a[i-1][j-1]+a[i-1][j];//���˵�һ��Ԫ���⣬������Ԫ�ض�=�����Ϸ�Ԫ��+�����Ϸ�Ԫ�ص�ǰһ��Ԫ�أ�����ÿ�����һ��Ԫ�أ�

		}
	}
	for(i=0;i<10;i++)//��ʾ��ӡǰ10��Ԫ��
	{
		for(j=0;j<i;j++)
	    printf("%-4d",a[i][j]);
		printf("\n");
	}
	return 0;
}*/

//7�������ħ����
/*
ħ�����һ��Ӧ��1���ڵ�һ�е����м�λ�ã���Ϊħ�����������׾���
ħ�����ŷŹ��ɣ�1����2��n*n������һ��Ԫ�ش�ŵ�λ����ǰһ��Ԫ�ص���-1����+1��
2�����ǰһ��Ԫ�ص���Ϊ1�Ļ������Ԫ�ص���Ϊn��Ȼ����+1��
3�����ǰһ��Ԫ�ص���Ϊn�Ļ������Ԫ�ص���Ϊ1��Ȼ����-1��
4��������������ɣ���λ������Ԫ�ػ�����һ��Ԫ�ص�λ��Ϊ��1�е�n�У����Ԫ�ؾͷ���ǰһ��Ԫ�ص����·���
*/

/*
int MoFangZhen()
{
#define H 3
#define L H
	int arr[H][L] = {0};//��ʼ����������Ԫ��Ϊ0��
	int h = 0;
	int l = L/2;
	arr[h][l] = 1;//����1��λ��
	for(int i=2;i<=H*L;i++)
	{
		//���δ���
		h = (h+H-1)%H;
		l = (l+1)%L;
		if(arr[h][l]!=0)//��λ������Ԫ�أ��������һԪ�ص����·�
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
			printf("%4d",arr[i][j]);//���ħ����
		}
		printf("\n");
	}
	return 0;
}
*/

//8���󰰵�



//9���۰��������
/*int BinSearch(int *arr,int len,int key)
{
	int a = 0;//�����һ��Ԫ�ص��±�
	int n = len-1;//���һ��Ԫ�ص��±�
	int mid;
	while(a<n)
	{
		mid = (a+n)/2;//�۰�
		if(arr[mid] == key)//�ж�Ҫ���ҵ�ֵ�ĵ���arr[mid]�����м��ֵ��
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


//12������


//13���ַ�������
char *Mystrcat(char *des,const char *src)
{
	assert(des != NULL&&src != NULL);//���������ַ�������Ϊ��
	if(des == NULL||src ==NULL)
	{
		return 0;
	}
	char *p = des; 
	while(*des !='\0')//���ַ�����β�͡�\0��
	{
		*des++;
	}
	while(*des++=*src++)//��Դ�ַ���������Ŀ���ַ���
	return p;
}

//�ַ����Ƚ�
char Compare(const char *str1,const char *str2)
{
	int tmp;
	
	while((tmp = *str1-*str2)== 0&&*str1!='\0')//�ж��ַ�����ÿ���ַ��Ĵ�С
	{
		*str1++;
		*str2++;
	}
	return tmp;//�����ַ��Ĳ�ֵ

}


int main()
{
	SuShu(100);
	//Sum();


	//MoFangZhen();


	//int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	//printf("%d\n",BinSearch(arr,sizeof(arr)/sizeof(arr[0]),12));
	//printf("%d\n",BinSearch(arr,sizeof(arr)/sizeof(arr[0]),2));


	//char des[10] = "asdf";//��ζ���des�ַ����ĳ���
	//char src[] = "zx";
	//Mystrcat(des,src);
	//printf("%s\n",des);


	
	printf("%d\n",Compare("qwert","qwert"));
	printf("%d\n",Compare("qw","qwert"));
	printf("%d\n",Compare("qwert","as"));
	printf("%d\n",Compare("asd","asx"));

	
	return 0;
}
