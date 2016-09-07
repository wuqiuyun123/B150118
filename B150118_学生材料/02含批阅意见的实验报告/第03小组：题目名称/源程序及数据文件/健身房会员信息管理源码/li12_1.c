/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"vvip.h"

void printHead( )      /*��ӡ��Ա��Ϣ�ı�ͷ*/
{
printf("%8s%10s%8s%10s%10s%10s%10s%10s%10s%10s\n","��Ա��","����","�Ա�","�������","��һ����","�ڶ�����","��������","���ļ���","�ܴ���","��������");
}

void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. ��Ա����������� ********\n");
		printf("******** 4. ���Ƚ������ͳ�� ********\n");
            printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. �����Ա��¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ����Ա��¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸Ļ�Ա��¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuTime( )     /*3����Ա�����������˵�����*/
{
		printf("@@@@@@@@ 1. �����Ա�����ܴ��� @@@@@@@@\n");
		printf("@@@@@@@@ 2. �����ܴ������� @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )    /*4����Ա�������ͳ�Ʋ˵�����*/
{
		printf("&&&&&&&& 1. ���������� &&&&&&&&\n");
		printf("&&&&&&&& 2. �������ٴ��� &&&&&&&&\n");
		printf("&&&&&&&& 3. �󼾶Ƚ���ƽ������ &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. ����Ա�Ų�ѯ   ########\n");
		printf("######## 2. ��������ѯ   ########\n");
		printf("######## 3. �����������ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}

int baseManage(Vvip vip[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*����Ա�Ž��в���ɾ���޸ģ���Ա�Ų����ظ�*/
{  
		int choice,t,find[NUM];
     Vvip v;
do
	    {   
menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*����ѡ��*/
		     switch(choice)
		     {
			   case 1:	 readVip(&v,1);       /*����һ��������Ļ�Ա��¼*/
					 n=insertVip(vip,n,v);   /*���ú��������Ա��¼*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&v.num);  /*����һ����ɾ���Ļ�Ա��*/
					 n=deleteVip(vip,n,v);   /*���ú���ɾ��ָ����Ա�ŵĻ�Ա��¼*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&v.num);  /*����һ�����޸ĵĻ�Ա��*/
				      t=searchVip(vip,n,v,1,find) ; /*���ú�������ָ����Ա�ŵĻ�Ա��¼*/
				      if (t)                 /*����û�Ա�ŵļ�¼����*/
					 {
						  readVip(&v,1);   /*����һ�������Ļ�Ա��¼��Ϣ*/
					      vip[find[0]]=v;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*����û�Ա�ŵļ�¼������*/ 
 printf("this vvip is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}

void timeManage(Vvip vip[],int n)          /*�ú�����ɻ�Ա���������Ϣ������*/
{  
	int choice;
	do
	{
		menuTime( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(vip,n);         /*�����л�Ա���ܴ���*/
					  break;
			case 2:   calcuRank(vip,n);         /*�������л�Ա���ܴ���������*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void printMarkQuarter(char *v,double m[4][4],int k)   /*��ӡ�������ͨ�ú�������countManage ����*/
{                 /*��ʽ����k���������ͬ�����ݣ�0��1��2�ֱ��Ӧ��ߴ�������ʹ�����ƽ������*/
int i;
    printf(v);                                  /*�����v���������������������ʾ��Ϣ*/
    for (i=0;i<4;i++)                           /*i������һ����*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(Vvip vip[],int n)               /*�ú�����ɽ������ͳ�ƹ���*/
{
		int choice;
		double mark[4][4];
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			calcuMark(mark,vip,n);                 /*���ô˺������ĸ����ȵ���ߡ���͡�ƽ��ֵ*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkQuarter("�ĸ����ȵ���ߴ����ֱ���:\n",mark,0);  /*�����ߴ���*/
				      break;
				case 2:   printMarkQuarter("�ĸ����ȵ���ʹ����ֱ���:\n",mark,1);  /*�����ʹ���*/
				      break;
				case 3:   printMarkQuarter("�ĸ����ȵ�ƽ�������ֱ���:\n",mark,2);  /*���ƽ������*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Vvip vip[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
Vvip v;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a vvip\'s num will be searched:\n");
				      scanf("%ld",&v.num);         /*�������ѯ��Ա�Ļ�Ա��*/
					  break;
				case 2:   printf("Input a vvip\'s name will be searched:\n");
				      scanf("%s",v.name);	          /*�������ѯ��Ա������*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&v.rank);          /*�������ѯ��Ա������*/
				      break;
                        case 0:   break;
 			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchVip(vip,n,v,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printVip(&vip[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}

int runMain(Vvip vip[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortVip(vip,n,1);         /*����Ա����С�����˳�������¼*/ 
          	 printVip(vip,n);          /*����Ա����С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(vip,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: timeManage(vip,n);     /* 3. ��Ա�����������*/
					break;
			case 4: countManage(vip,n);     /* 4. ��Ա�������ͳ��*/
					break;
			case 5: searchManage(vip,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Vvip vip[NUM];                /*����ʵ��һά����洢��Ա��¼*/
      int choice,n;
	 n=readFile(vip);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(vip);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(vip,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortVip(vip,n,1);                   /*�����ļ�ǰ����Ա����С��������*/ 
	     saveFile(vip,n);                   /*����������ļ�*/
      return 0;
}

