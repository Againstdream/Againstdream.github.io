
#include<stdlib.h>
#include<stdio.h>`
typedef int ElemType;

/*
单链表定义
*/
typedef struct LNode			//定义单链表结点类型
{
	ElemType data;				//数据域
	struct LNode *next;			//指针域
}LNode,*LinkList;

/*头插法建立单链表*/
LinkList List_HeadInsert(LinkList &L)		//逆向建立单链表
{
	LNode *s;   int x;						
	L = (LinkList)malloc(sizeof(LNode));	//创建头结点
	L->next = NULL;							//初始为空链表
	scanf("%d", &x);						//输入结点的值
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));	//创建新结点
		s->data = x;						//新结点赋值
		s->next = L->next;					//将新结点插入表中，L为头指针
		L->next = s;						//将头指针指向新添加的结点
		scanf("%d", &x);					//输入下一结点的值，直到回车输入结束
	}
	return L;
}

/*按位序(带头结点)插入结点--（在第i个位置插入结点），即插在第i-1个位置之后*/
bool ListInsert(LinkList &L,int i,ElemType e)			//在第i个位置插入元素e
{
	if (i < 0)			//判断插入位置合不合法
		return false;
	LNode *p;			//利用该结点进行遍历，查找插入位置即当前扫描到的结点
	int j = 0;			//当前p指向第j个结点
	p = L;				//p指向L的首地址即指向头结点，是第0个结点，不存储数据
	while (p != NULL && j < i - 1)	//循环找到第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL)		//i值不合法
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));	//s存储插入结点的值，并插入链表第i个位置
	s->data = e;
	s->next = p->next;
	p->next = s;		//将s结点插到p结点之后
	return true;
}

/*无头结点建立单链表*/
bool InitList(LinkList &L)	//初始化一个空的单链表
{
	L = NULL;				//这是一个空表，无任何结点---防止脏数据
	return true;
}

/*按位序(无头结点)插入结点--（在第i个位置插入结点），即插在第i-1个位置之后*/
bool ListInsert(LinkList &L, int i, ElemType e)			//在第i个位置插入元素e
{
	if (i < 1)	return false;
	if(i==1)			//插入第一个结点与其他结点的操作有所不同
	{
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;			//头指针指向新结点
		/*
			解释：将新结点的next指向当前的头指针指向的结点，再将头指针向前移指向新增的结点
		*/
	}
	LNode *p;		//指向当前扫描到的结点
	int j = 1;		//当前p所指向的结点
	p = L;			//链表的头指针指向的节点---即第一个结点
	while (p != NULL && j < i - 1)		//循环找到第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL)		//p值不合法
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;		//插入成功
}

/*指定结点的后插操作*/
bool InsertNextNode(LNode *p, ElemType e)		//指定节点p后插入元素值e
{
	/*本函数：将新元素插入到指定节点之后，而其他操作仍需外部函数实现*/
	/*比如查找到p结点*/
	/*本函数的调用：return InseertNextNode(p,e);*/
	if (p == NULL)		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if (s == NULL)		return false;	//内存分配失败
	s->data = e;						//结点s保存数据元素e
	s->next = p->next;
	p->next = s;						//结点s接在结点p后面
	return true;
}

/*指定结点的前插操作*/
bool InsertPriorNode(LNode *p, ElemType e)		//指定节点p前插入元素值e
{
	/*1、新建结点s*/
	/*2、本函数设计思想：将结点s接在结点p之后，将p的数据域对s进行赋值*/
	/*3、再由e对结点p的数据域赋值*/
	/*综述：结点p后增加一个结点，先把p的数据域向后传递，再用e赋值给前面的结点p*/
	if (p == NULL)	return false;
	LNode *s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)	return false;	//内存分配失败
	s->next = p->next;				
	s = p->next;					//新结点接在p结点之后
	s->data = p->data;				//p中元素复制到s中
	p->data = e;					//p中元素府改为e

}

/*指定结点的前插操作----王道书版本*/
/*结点p前面插入新结点s操作*/
bool InsertPriorNode(LNode *p, LNode *s)
{
	if (p == NULL || s == NULL)	return false;
	s->next = p->next;
	p->next = s;	//s结点链接在p结点后面

	ElemType temp = p->data;	//交换数据域
	s->data = p->data;
	p->data = temp;
	return true;
}

/*按位序（带头结点）删除链表结点操作*/
bool ListDelete(LinkList &L, int i,ElemType &e)
{

}