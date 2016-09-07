/* ��vvip.h�ļ����������� */
#ifndef _VVIP            /*�������룬��ֹ�ظ������Ĵ���*/
#define _VVIP
#include <string.h>
#define NUM 20                /*�����Ա�����������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Vvip                   /*��Ա��¼��������*/
{
		long num;
		char name[20];
		char sex[10];
		int time[4];
                char date[20];
		int total;
		int rank;
};
typedef struct Vvip Vvip;
#define sizeVip sizeof(Vvip)      /*һ����Ա��¼����Ҫ���ڴ�ռ��С*/
int readVip(Vvip vip[],int n);       /*�����Ա��¼ֵ����Ա��Ϊ0������涨������¼ʱֹͣ*/
void printVip(Vvip  *vip , int n);   /*������л�Ա��¼��ֵ*/

int equal(Vvip v1,Vvip v2,int condition);  /*����condition�����ж�����Vvip����������ȷ�*/
int larger(Vvip v1,Vvip v2,int condition);  /*����condition�Ƚ�Vvip�������ݴ�С*/
void reverse(Vvip vip[],int n);             /*��Ա��¼����Ԫ������*/

void calcuTotal(Vvip vip[],int n);           /*�������л�Ա���ܷ�*/
void calcuRank(Vvip vip[],int n);           /*�����ܴ��������Ա�����Σ������в�������*/
void calcuMark(double m[4][4],Vvip vip[],int n); /*���ĸ����ȵ���ߡ���͡�ƽ��������m�����һά*/
/*��ʾ���ſΣ��ڶ�ά��ʾ��ߡ���͡�ƽ����*/

void sortVip(Vvip vip[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/

int searchVip(Vvip vip[],int n,Vvip s,int condition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertVip(Vvip vip[],int n,Vvip v);                   /*�������в���һ��Ԫ�ذ���Ա������*/
int deleteVip(Vvip vip[],int n,Vvip v);                   /*��������ɾ��һ��ָ����Ա�ŵ�Ԫ��*/
#endif
