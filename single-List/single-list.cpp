
#include<stdlib.h>
#include<stdio.h>`
typedef int ElemType;

/*
��������
*/
typedef struct LNode			//���嵥����������
{
	ElemType data;				//������
	struct LNode *next;			//ָ����
}LNode,*LinkList;

/*ͷ�巨����������*/
LinkList List_HeadInsert(LinkList &L)		//������������
{
	LNode *s;   int x;						
	L = (LinkList)malloc(sizeof(LNode));	//����ͷ���
	L->next = NULL;							//��ʼΪ������
	scanf("%d", &x);						//�������ֵ
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));	//�����½��
		s->data = x;						//�½�㸳ֵ
		s->next = L->next;					//���½�������У�LΪͷָ��
		L->next = s;						//��ͷָ��ָ������ӵĽ��
		scanf("%d", &x);					//������һ����ֵ��ֱ���س��������
	}
	return L;
}

/*��λ��(��ͷ���)������--���ڵ�i��λ�ò����㣩�������ڵ�i-1��λ��֮��*/
bool ListInsert(LinkList &L,int i,ElemType e)			//�ڵ�i��λ�ò���Ԫ��e
{
	if (i < 0)			//�жϲ���λ�úϲ��Ϸ�
		return false;
	LNode *p;			//���øý����б��������Ҳ���λ�ü���ǰɨ�赽�Ľ��
	int j = 0;			//��ǰpָ���j�����
	p = L;				//pָ��L���׵�ַ��ָ��ͷ��㣬�ǵ�0����㣬���洢����
	while (p != NULL && j < i - 1)	//ѭ���ҵ���i-1�����
	{
		p = p->next;
		j++;
	}
	if (p == NULL)		//iֵ���Ϸ�
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));	//s�洢�������ֵ�������������i��λ��
	s->data = e;
	s->next = p->next;
	p->next = s;		//��s���嵽p���֮��
	return true;
}

/*��ͷ��㽨��������*/
bool InitList(LinkList &L)	//��ʼ��һ���յĵ�����
{
	L = NULL;				//����һ���ձ����κν��---��ֹ������
	return true;
}

/*��λ��(��ͷ���)������--���ڵ�i��λ�ò����㣩�������ڵ�i-1��λ��֮��*/
bool ListInsert(LinkList &L, int i, ElemType e)			//�ڵ�i��λ�ò���Ԫ��e
{
	if (i < 1)	return false;
	if(i==1)			//�����һ��������������Ĳ���������ͬ
	{
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;			//ͷָ��ָ���½��
		/*
			���ͣ����½���nextָ��ǰ��ͷָ��ָ��Ľ�㣬�ٽ�ͷָ����ǰ��ָ�������Ľ��
		*/
	}
	LNode *p;		//ָ��ǰɨ�赽�Ľ��
	int j = 1;		//��ǰp��ָ��Ľ��
	p = L;			//�����ͷָ��ָ��Ľڵ�---����һ�����
	while (p != NULL && j < i - 1)		//ѭ���ҵ���i-1�����
	{
		p = p->next;
		j++;
	}
	if (p == NULL)		//pֵ���Ϸ�
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;		//����ɹ�
}

/*ָ�����ĺ�����*/
bool InsertNextNode(LNode *p, ElemType e)		//ָ���ڵ�p�����Ԫ��ֵe
{
	/*������������Ԫ�ز��뵽ָ���ڵ�֮�󣬶��������������ⲿ����ʵ��*/
	/*������ҵ�p���*/
	/*�������ĵ��ã�return InseertNextNode(p,e);*/
	if (p == NULL)		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if (s == NULL)		return false;	//�ڴ����ʧ��
	s->data = e;						//���s��������Ԫ��e
	s->next = p->next;
	p->next = s;						//���s���ڽ��p����
	return true;
}

/*ָ������ǰ�����*/
bool InsertPriorNode(LNode *p, ElemType e)		//ָ���ڵ�pǰ����Ԫ��ֵe
{
	/*1���½����s*/
	/*2�����������˼�룺�����s���ڽ��p֮�󣬽�p���������s���и�ֵ*/
	/*3������e�Խ��p��������ֵ*/
	/*���������p������һ����㣬�Ȱ�p����������󴫵ݣ�����e��ֵ��ǰ��Ľ��p*/
	if (p == NULL)	return false;
	LNode *s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)	return false;	//�ڴ����ʧ��
	s->next = p->next;				
	s = p->next;					//�½�����p���֮��
	s->data = p->data;				//p��Ԫ�ظ��Ƶ�s��
	p->data = e;					//p��Ԫ�ظ���Ϊe

}

/*ָ������ǰ�����----������汾*/
/*���pǰ������½��s����*/
bool InsertPriorNode(LNode *p, LNode *s)
{
	if (p == NULL || s == NULL)	return false;
	s->next = p->next;
	p->next = s;	//s���������p������

	ElemType temp = p->data;	//����������
	s->data = p->data;
	p->data = temp;
	return true;
}

/*��λ�򣨴�ͷ��㣩ɾ�����������*/
bool ListDelete(LinkList &L, int i,ElemType &e)
{

}