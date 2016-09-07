/*��vvip.c�ļ�����������*/
#include "vvip.h"
#include <stdio.h>

int readVip(Vvip  *vip , int n)          /*�����Ա��¼ֵ����Ա��Ϊ0������涨������¼ʱֹͣ*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one vvip\'s information\n");
		printf("num:  ");
	        scanf("%ld", &vip[i].num);
		if (vip[i].num==0) break;
		printf("name: ");
		scanf("%s",vip[i].name);	
		printf("sex:  ");
		scanf("%s",vip[i].sex);
		printf("date: ");
		scanf("%s",vip[i].date);
    	     vip[i].total=0;                /*�ܴ�����Ҫ������ã���ֵ��Ϊ0*/
		printf("Input four quarters of the vvip:\n");
		for (j=0;j<4;j++)
	    {
		    scanf("%d",&vip[i].time[j]);	
		}
		vip[i].rank=0;                 /*������Ҫ�����ܴ��������㣬��ֵ��Ϊ0*/
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printVip ( Vvip  *vip , int n)       /*������л�Ա��¼��ֵ*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", vip[i].num);
		printf("%8s", vip[i].name);
		printf("%8s", vip[i].sex);
		printf("%10s", vip[i].date);
		for (j=0;j<4;j++)
		   printf("%10d",vip[i].time[j]);
	    printf("%10d",vip[i].total);
	    printf("%10d\n",vip[i].rank);
	}
}

int equal(Vvip v1,Vvip v2,int condition)  /*����ж�����Vvip��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϻ�Ա��*/
		return v1.num==v2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
     {
	     if (strcmp(v1.name,v2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/
	     return v1.rank==v2.rank;
 else if (condition==4)                /*�������condition��ֵΪ4����Ƚ��ܴ���*/
		return v1.total==v2.total;
	else return 1;                       /*�����������1*/
} 

int larger(Vvip v1,Vvip v2,int condition)  /*����condition�����Ƚ�����Vvip��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϻ�Ա��*/
		return v1.num>v2.num;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ��ܴ���*/
		return v1.total>v2.total;	
	else return 1; /*�����������1*/
}

void reverse(Vvip vip[],int n)             /*����Ԫ������*/
{
	int i;
	Vvip temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=vip[i];
		vip[i]=vip[n-1-i];
		vip[n-1-i]=temp;
	}
}

void calcuTotal(Vvip vip[],int n)         /*�������л�Ա������ܴ���*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*���ѭ���������л�Ա��¼*/
	{
		vip[i].total =0;
		for (j=0;j<4;j++)               /*�ڲ�ѭ�������ĸ�����*/
			vip[i].total +=vip[i].time[j];
	}	
}

void calcuRank(Vvip vip[],int n)          /*�����ּܷ������л�Ա�����������������ͬ��������ͬ*/
{
	int i ;                       
	sortVip(vip,n,2);                     /*�ȵ���sortVip�㷨�����ܴ�����С��������*/
	reverse(vip,n);                      /*�����ã����ܴ����ɴ�С������*/
	vip[0].rank=1;                      /*��һ����¼������һ����1*/
	for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/
	{
		if (equal(vip[i],vip[i-1],4))         /*��ǰ��¼�������ڵ�ǰһ����¼����ܴ������*/
			vip[i].rank=vip[i-1].rank;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/ 
	    else
			vip[i].rank=i+1;             /*�����ʱ��ǰ��¼���ε������±��+1*/
	}
}

void calcuMark(double m[4][4],Vvip vip[],int n) /*���ĸ����ȵ���ߡ���͡�ƽ������*/
/*������ʽ������ά����m�ĵ�һά�����ĸ����ȣ��ڶ�ά������ߡ���͡�ƽ������*/
{
	int i,j;
	for (i=0;i<4;i++)                 /*���ĸ����ȵ���ߴ���*/		
	{ 
		m[i][0]=vip[0].time[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<vip[j].time[i])
				m[i][0]=vip[j].time[i];
	}
	for (i=0;i<4;i++)                  /*���ĸ����ȵ���ʹ���*/
	{ 
		m[i][1]=vip[0].time[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>vip[j].time[i])
				m[i][1]=vip[j].time[i];
	}
	for (i=0;i<4;i++)                 /*���ĸ����ȵ�ƽ������*/
	{ 
		m[i][2]=vip[0].time[i];     
		for (j=1;j<n;j++)
			m[i][2]+=vip[j].time[i];
		m[i][2]/=n;
	}
}

void sortVip(Vvip vip[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Vvip t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(vip[minpos],vip[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=vip[i];
			vip[i]=vip[minpos];
			vip[minpos]=t;
		}
	}
}

int searchVip(Vvip vip[],int n,Vvip s,int condition,int f[ ])  /*��vip��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(vip[i],s,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int insertVip(Vvip vip[],int n,Vvip v)              /*��vip��������ѧ�ŵ�������һ��Ԫ��s*/
{
	int i;
	sortVip(vip,n,1);                              /*�Ȱ���Ա������*/
	for (i=0;i<n;i++)
	{
		if (equal(vip[i],v,1))                      /*��Ա����ͬ��������룬��֤��Ա�ŵ�Ψһ��*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*����Ա�Ŵ�С��������*/
	{
		if (!larger(vip[i],v,1))                    /*���s���ڵ�ǰԪ��vip[i]�����˳�ѭ��*/
		break;
		vip[i+1]=vip[i];                         /*����Ԫ��vip[i]����һ��λ��*/
	}
	vip[i+1]=v;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deleteVip(Vvip vip[],int n,Vvip v)            /*��������ɾ��ָ����Ա�ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(vip[i],v,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(vip[i],s,1)����*/ 
		vip[j]=vip[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                            
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}