#include<stdio.h>
#include<math.h>

//第3题最大公约数
int GreatestComDiv(int m,int n)
{
	int r;
	while((r=m%n) != 0)//‘！=’运算符优先级高于‘=’
	{
        m=n;
	    n=r;//辗转相除法
	}
	return n;
}

//第3题最小公倍数
int LeastComMult(int m,int n)
{
	return m/GreatestComDiv(m,n)*n;//最小公倍数等于两数之积除以它们的最大公约数，如果先乘的话，难免两数之积会很大，所以先除再乘
}


//第4题统计个数
/*int main(void)
{
	char ch;
	int a,b,c,d;
	a = b = c = d  = 0;
	while((ch=getcer()) != '\n' )
	{
		if(ch>='a' && ch<='z'||ch>='A'&&ch<='Z')
		{
			a++;
			//return a;
			//printf("a=%d\n",a);
	    }
		else if(ch = ' ')
		{
			b++;
			//return b;
			//printf("b=%d\n",b);
		}
		else if(ch>='0' && ch<='9')
		{
			c++;
			//return c;
			//printf("c=%d\n",c);
		}
		else 
		{
			d++;
			//return d;
			//printf("d=%d\n",d);
		}
	}
	printf("字母= %d\n数字=%d\n空格=%d\n其他字符=%d\n",a,b,c,d);
	
}*/


//5、求Sn=a+aa+aaa+...+aa...a的值
int Identical(int a,int n)
{
	int tmp=0;
	for(int i=0;i<n;i++)
	{
		tmp = tmp*10+a;//求n个a数字，如:a,aa,aaa	
	}
	return tmp;
}




//6、阶乘之和
double JK(int t)
{
	double i,n;
	for(i=1,n=1;i<=t;i++)
		n*=i;//n是i的阶乘
	return n;
}


//8、水仙花数
bool Flower(int n)
{ 
	//int a,b,c;
	//a = b = c = 0;
	int tmp = 0;
	int m = n;
	int a;
	while(n != 0)
	{
		a=n%10;//保存个位数字
		tmp += a*a*a;//个位数字的三次方
		n /= 10;//丢掉个位数字

		//a=n/100;//a保存n的百位
		//b=(n%100)/10;//b保存n的十位
		//c=n%10;//c保存n的个位
		//if(n==(a*a*a+b*b*b+c*c*c))
		//	return 1;
		//else 
		//	return 0;
	
	}
	return tmp == m;//若每次丢掉的个位数的三次方之和等于这个数，那么这个数是水仙花数
}




//int SX(int);
//int main()
//{
	//printf("%d\n",GreatestComDiv(2,4));//最大公约数
	//printf("%d\n",LeastComMult(2,4));//最小公倍数
	//printf("%d\n",GreatestComDiv(5,3));//最大公约数
	//printf("%d\n",LeastComMult(5,3));//最小公倍数
	//printf("%d\n",GreatestComDiv(100,12300));//最大公约数
	//printf("%d\n",LeastComMult(100,12300));//最小公倍数
	//printf("%d\n",GreatestComDiv(10000,231000000));//最大公约数
	//printf("%d\n",LeastComMult(10000,231000000));//最小公倍数

	//int x;
	//for(x =100;x<1000;x++)
	//{
	//	if(Flower(x))//调用自定义函数，判断是否为水仙花数
	//		printf("%d\n",x);
	//}

	/*int t;
	double tmp = 0;
	for(t=1;t<=20;t++)
		tmp+= JK(t);
	printf("%f\n",tmp);*/
	
	/*int tmp=0 ;
	int n;
	for(n=1;n<=10;n++)
	{
		tmp += Identical(1,n);
	}
	printf("%d\n",tmp);

	return 0;*/
//}


//9、完数
/*bool Perfect(int n)
{   
	int tmp = 0;
    for(int i=1;i<n;i++)
     {
	    if(n%i == 0)
	    {
		   tmp += i;
	    }   
    }
   return tmp == n; 
}

void Show(int n)
{  
	printf("%-4d = ",n);
    int tmp=0;
	for(int i=2;i<n;i++)
	{
	  if(n%i == 0)
	  {
	    printf("1+ %d ",i);
	  }
    }
	printf("\n");
}

 int main()
 {
	for(int i=1;i<1000;i++)
	{
	    if(Perfect(i))
		{
		   Show(i);
		 }
	}
  return 0;
 }*/



 //宏就是字符替换
/*#define POW(x) (x)*(x)
#define DOUBLE(x) (x)+(x)
int main()
{
    
	printf("%d\n",POW(10+10));
	printf("%d\n",DOUBLE(10*10)*10);//(10*10)+(10*10)*10

	return 0;
}

#define M(x,y,z) x*y+z
void main()
{
	int a=1,b=2,c=3;
	printf("%d\n",M(a+b,b+c,c+a));

}*/