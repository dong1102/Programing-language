#include<stdio.h>
#include<math.h>

//��3�����Լ��
int GreatestComDiv(int m,int n)
{
	int r;
	while((r=m%n) != 0)//����=����������ȼ����ڡ�=��
	{
        m=n;
	    n=r;//շת�����
	}
	return n;
}

//��3����С������
int LeastComMult(int m,int n)
{
	return m/GreatestComDiv(m,n)*n;//��С��������������֮���������ǵ����Լ��������ȳ˵Ļ�����������֮����ܴ������ȳ��ٳ�
}


//��4��ͳ�Ƹ���
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
	printf("��ĸ= %d\n����=%d\n�ո�=%d\n�����ַ�=%d\n",a,b,c,d);
	
}*/


//5����Sn=a+aa+aaa+...+aa...a��ֵ
int Identical(int a,int n)
{
	int tmp=0;
	for(int i=0;i<n;i++)
	{
		tmp = tmp*10+a;//��n��a���֣���:a,aa,aaa	
	}
	return tmp;
}




//6���׳�֮��
double JK(int t)
{
	double i,n;
	for(i=1,n=1;i<=t;i++)
		n*=i;//n��i�Ľ׳�
	return n;
}


//8��ˮ�ɻ���
bool Flower(int n)
{ 
	//int a,b,c;
	//a = b = c = 0;
	int tmp = 0;
	int m = n;
	int a;
	while(n != 0)
	{
		a=n%10;//�����λ����
		tmp += a*a*a;//��λ���ֵ����η�
		n /= 10;//������λ����

		//a=n/100;//a����n�İ�λ
		//b=(n%100)/10;//b����n��ʮλ
		//c=n%10;//c����n�ĸ�λ
		//if(n==(a*a*a+b*b*b+c*c*c))
		//	return 1;
		//else 
		//	return 0;
	
	}
	return tmp == m;//��ÿ�ζ����ĸ�λ�������η�֮�͵������������ô�������ˮ�ɻ���
}




//int SX(int);
//int main()
//{
	//printf("%d\n",GreatestComDiv(2,4));//���Լ��
	//printf("%d\n",LeastComMult(2,4));//��С������
	//printf("%d\n",GreatestComDiv(5,3));//���Լ��
	//printf("%d\n",LeastComMult(5,3));//��С������
	//printf("%d\n",GreatestComDiv(100,12300));//���Լ��
	//printf("%d\n",LeastComMult(100,12300));//��С������
	//printf("%d\n",GreatestComDiv(10000,231000000));//���Լ��
	//printf("%d\n",LeastComMult(10000,231000000));//��С������

	//int x;
	//for(x =100;x<1000;x++)
	//{
	//	if(Flower(x))//�����Զ��庯�����ж��Ƿ�Ϊˮ�ɻ���
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


//9������
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



 //������ַ��滻
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