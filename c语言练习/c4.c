#include<stdio.h>
#include<assert.h>
#include <ctype.h>
//3、判断素数的函数
bool SuShu(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
			return false;
	
 	     else return true;
    }
}

//5、字符串反转
char FanZhuan(char *str,int len)
{
	assert(str!=NULL);
	if(*str == NULL)
		return 0;
	int tmp=0;
	int i;
	char *p = str;
	for(i=0;i<len/2;i++)
	{
		p[i] = tmp;
		 p[i] = p[len-i-1];
		 p[len-1] = tmp;
	}

	return p[i];
	
}


//统计字符个数
char ZiFu(char *str)
{
	assert(str  !=NULL);
	if(str == NULL)
	{
		return 0;
	}
	char arr[]={'1','2','3','4','5','6','7','8','9','0'};
	int a,b,c,d;
	a = b = c = d = 0;
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]==isalpha(str[i]))
			a++;
		//else if(str[i]==arr[])
			//b++;
		else if(str[i] == ' ' )
			c++;
		else d++;

	}
	return a,b,c,d;
}


//统计单词个数
int TongJi(char *str)
{
	assert(str != NULL);
		if(str == NULL)
			return 0;

	int cont = 0;

	for(int i=0;str[i]!='\0';i++)
	{
		if(isalpha (str[i])&&!isalpha(str[i+1]))
			cont++;
		 
		
		    
	}
	return cont;
}


//冒泡法排序
char QiPai(char *arr,int len)
{
	int tmp,i,j;
	//char *p = arr;
	
	for(i=0;i<len;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i]>arr[i+1])
		    {
				tmp = arr[i];
			    arr[i] = arr[i+1];
			    arr[i+1] = tmp;
		    }
		}
	}
	for(i=0;i<len;i++)
	{
		printf("%s\n",arr);
	}
	return 0;
}


//13、递归发求n阶勒让德多项式
int DiGui(int n)
{
	if (n = 0)
		return 1;
}



//16、进制转换
int JinZhi(int n)
{
	printf("%d\n",n);
	int m = n;//将n的值赋给m
	int cont = 0;//定义计数器
	int power = 1;
	int J = 1;
	int a,b;
	a = b = 0;
	do
	{
		cont++;//保存十六进制数n的位数
		n /= 10;
	}while(n != 0);
	

	for(int i=1;i<cont;i++)
	{
		power *= 10;//保存要得到n的最高位所除的数

	}
	

	for(int j=1;j<cont;j++)
	{
		J *=16;//保存进制转化所需的进制量
	}
	

	do
	{
		//printf("%d\n",cont);
		//printf("%d\n",power);
		//printf("%d\n",J);
		//printf("%d\n",n);
		 a = (m/power)*J;//得到高位所对应的十进制数,
		 //printf("%d\n",a);
		 m %= power;//丢掉最高位
		 power /= 10;//向低位执行一次
		 J /= 16;//向低位执行一次
		 b += a;
		 //printf("%d\n",b);
	}while(m!=0);//现在n的值已在m中保存，应用m来判断

	return b;
}
int main()
{
	/*int n=97;
	if(SuShu(n))
		printf("%d是素数\n",n);
	else
		printf("%d不是素数\n",n);*/

	//char str[]="asdf";
	//printf("%s\n",FanZhuan(str,sizeof(str)/sizeof(str[0])));


	//char str[]="a s,d.,f d";
	//printf("%d\n",ZiFu(str));	

	//printf("%d\n",TongJi("A askdw safd xbjk jjhd-sdj"));

	//char arr[] = {7,3,2,1,9,4,5,8,6,0};
	//QiPai(arr,sizeof(arr)/sizeof(arr[0]));


	int A,B,C,D,E,F;
	A = 10;B=11;C=12;D=13;E=14;F=15;
	printf("%d\n",JinZhi(1));
	return 0;
}