#include<stdio.h>
//����
void Paixu(int a,int b,int c)
{
	int t;
	
	if(a<b)
	{
		t=b;
		b=a;
		a=t;
		
	}
	if(b<c)
	{
		t=c;
		c=b;
		b=t;
		
	}
	if(a<b)
	{
		t=b;
		b=a;
		a=t;	
	}
	printf("%d% d% d\n",a,b,c);
}
//������ 
//bool Gbs(int a)
//{
//	if(a%3==0&&a%5==0)
//	{
//		return true;
//	}
//	else
//	return false;
//}

int main()
{
	//����
	int a = 58;
	int b = 49;
	int c = 112;
	Paixu(a,b,c);
	//������ 
	/*int a=15;
	printf("%d\n",Gbs(a));*/
	return 0;
}