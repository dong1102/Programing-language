#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
//
//
////1��2���������Ǳ����еĵڼ���
//typedef struct date 
//{
//	int year;//��
//	int month;//��
//	int day;//��
//}date;
//
//int Days(date a)
//{
//	int r = a.day;//����������ڵ��µ�����
//	int d = 0;//���屣�������ı���
//	int i ;//���������ı���
//	for(i=1;i<a.month;i++)
//	{
//		if((a.year%4==0 && a.year%100!=0 || a.year%400==0)&&i == 2)
//	   {
//		   a.day = 29;
//	    }
//		else if(i == 2)
//			a.day = 28;
//		if(i == 1||i == 3||i == 5||i == 7||i == 8||i == 10||i == 12)
//	    {
//			a.day = 31;
//		}
//	    else if(i == 4||i == 6||i == 9||i == 11)
//	   {
//		   a.day = 30;
//	   }
//		d += a.day; 
//	}
//
//	d += r;
//	return d;
//}
//
//
//3����¼ѧ����Ϣ
//typedef struct student
//{
//	int num;
//	char name[20];
//	int score[3]; 
//}student;
//
//int Print(student *p,int len)
//{
//	printf("\n ѧ��     ����       ����\n");
//	for(int i=0;i<len;i++)
//	{
//		printf("sum:%d  name:%s  ",p[i].num,p[i].name);
//		for(int j=0;j<3;j++)
//		{
//			printf("score[%d]:%d  ",j,p[i].score[j]);
//		}
//		printf("\n");
//	}
//
//
//	return 0;
//}
//int main()
//{
//	/*date a1 = {2018,1,31};
//	date a2 = {2018,2,1};
//	date a3 = {2004,3,10};
//	date a4 = {2018,4,10};
//	date a5 = {2018,5,10};
//	date a6 = {2018,6,10};
//	
//	printf("%d\n",Days(a1));
//	printf("%d\n",Days(a2));
//	printf("%d\n",Days(a3));
//	printf("%d\n",Days(a4));
//	printf("%d\n",Days(a5));
//	printf("%d\n",Days(a6));*/
//
//	//3����¼ѧ����Ϣ
//	student stu[5] = {{1,"zhaoyi",87,88,89},{2,"qianer",85,88,90},{3,"sunsan",88,89,87},{4,"lisi",90,87,89},{5,"zhouwu",87,90,98}};
//	student *p = stu;
//	Print(stu,sizeof(stu)/sizeof(stu[0]));
//	return 0;
//}




//4.�ڵ�����Ļ����ϣ���дһ��input������������5��ѧ��������


//typedef struct student//����ѧ���ṹ��
//{
//	int num;
//	char name[20];
//	int score[3];
//}student;
//
//void Input(student *p)//���뺯��
//{
//	printf("�������ѧ���Ļ�����Ϣ\n");
//	for(int i=0;i<5;i++)
//	{
//		scanf("%d %s %d %d %d",&p[i].num,&p[i].name,&p[i].score[1],&p[i].score[2],&p[i].score[3]);//�������ѧ���Ļ�����Ϣ
//	}
//	
//	
//}
//
//void Print(student *p)//�������
//{
//	printf("\n ѧ��          ����             ����\n");
//	for(int j=0;j<5;j++)
//	{
//		printf("sum: %d,name: %s,score[1]: %d,score[2]: %d,score[3]: %d\n",p[j].num,p[j].name,p[j].score[1],p[j].score[2],p[j].score[3]);//������ѧ���Ļ�����Ϣ
//	   /* for(int i=1;i<4;i++)
//	    {
//			printf("score[%d]:%d",i,p[j].score[i]);
//	    }
//	    printf("\n");*/
//
//	}
//	
//}
//
//int main()
//{
//	student stu[5];//����һ������ѧ����Ϣ������
//	Input(stu);
//	Print(stu);
//	return 0;
//}

//5��10��ѧ����ƽ���ɼ�����ƽ������ߵ�ѧ���Ļ�����Ϣ

typedef struct student//����ѧ���ṹ��
{
	int num;
	char name[20];
	int score[3];
}student;

void Input(student *p)//���뺯��
{
	printf("����10��ѧ���Ļ�����Ϣ\n");
	for(int i=0;i<2;i++)
	{
		scanf("%d %s %d %d %d",&p[i].num,&p[i].name,&p[i].score[1],&p[i].score[2],&p[i].score[3]);//�������ѧ���Ļ�����Ϣ
	}
	
	
}

void Print(student *p)//�������
{
	
	double a,b = 0;
	for(int i=0;i<2;i++)
	{
	    a = (p[i].score[1]+p[i].score[2]+p[i].score[3])/3;
		printf("%f\n",a);
		while(a != 0)
		{
			if(a>b)
				b=a;
		}
		
	}
	printf("%c\n",b);
	
	 
}

int main()
{
	student stu[10];//����һ������ѧ����Ϣ������
	Input(stu);
	Print(stu);
	return 0;
}