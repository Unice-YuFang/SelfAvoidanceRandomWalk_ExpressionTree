/**********************************************************************
Copyright:   2019�人��ѧ17���ƿ�7��2017311500181��楷�
File name:   2.2ExpressionTree
Description:���ʵ�ֱ��ʽ���Ľ����ͱ�����
1)	���ʽ֧�ֵ�����������趨�����磬�������㡣
2)	����ĳ�ַ�ʽ������ʽ�������׺���ʽ��ʽ�����û�����ı��ʽ����������ͼ��ʾ�ı��ʽ����
3)	�����ñ��ʽ�����ֱ�����ñ��ʽ����׺���ʽ�ͺ�׺���ʽ��ʽ��
Author:      ��楷�
Version:     1.0
Date:        2019.03.22
***********************************************************************/
#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MaxSize 100
#define MaxWidth 100
using namespace std;
typedef char ElemType;                                   //������˳��洢�ṹ����������
typedef struct node
{
	ElemType data;                                       //����Ԫ��
	struct node *lchild;                                 //ָ�����ӽ��
	struct node *rchild;                                 //ָ���Һ��ӽ��
}BTNode;                                               //�����������������

/*����������*/
void CreateBTree(BTNode * &b, char * str)
{
	BTNode * St[MaxSize], *p;                             //St������Ϊ˳��ջ
	int top = -1, k = 0, j = 0;                              //topΪջ��ָ��  
	char ch;
	b = NULL;                                            //��ʼʱ������Ϊ��
	ch = str[j];
	while (ch != '\0')                                   //ѭ��ɨ��str�е�ÿ���ַ�
	{
		switch (ch)
		{
		case '(':                            //��ʼ�������ӽ��
			top++;
			St[top] = p;
			k = 1;                           //��ʾ��󴴽��Ľ�㽫��Ϊ���ջ����������
			break;
		case ')':                           //ջ�����������������
			top--;
			break;
		case ',':                           //��ʼ�����Һ��ӽ��
			k = 2;                          //��ʾ��󴴽��Ľ�㽫��Ϊ��ǰջ�������Һ��ӽ��
			break;
		default:
			p = (BTNode *)malloc(sizeof(BTNode));   //����һ����㣬��pָ����
			p->data = ch;                           //��Ž��ֵ
			p->lchild = p->rchild = NULL;           //����ָ�붼����Ϊ��
			if (b == NULL)                          //����δ��������㣨bΪ�գ�   
			{                                       //p��ָ������Ϊ�����
				b = p;
			}
			else                                    //�ѽ��������������
			{
				switch (k)
				{
				case 1:St[top]->lchild = p;        //�½������Ϊջ����������
					break;
				case 2:St[top]->rchild = p;        //�½������Ϊջ�������Һ���
					break;
				}
			}
		}
		j++;
		ch = str[j];                                    //����ɨ��str
	}
}

/*���ٶ�����*/
void DestroyBTree(BTNode*&b)
{
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}

/*���������*/
void DispBTree(BTNode *b)                                 //�����ű�ʾ�����������
{
	if (b != NULL)
	{
		printf("%c", b->data);                           //������b�Ľ��ֵ
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");                                 //�к��ӽ��ʱ�����������
			DispBTree(b->lchild);                        //�ݹ鴦��������
			if (b->rchild != NULL)                       //���Һ��ӽ��ʱ�������,��
			{
				printf(",");
			}
			DispBTree(b->rchild);                        //�ݹ鴦��������
			printf(")");                                 //�к��ӽ��ʱ�����������
		}
	}
}

/*��������ݹ��㷨*/
void PreOrder(BTNode *b)
{
	if (b != NULL)
	{
		printf("%c", b->data);       //���ʸ����
		PreOrder(b->lchild);         //�������������
		PreOrder(b->rchild);         //�������������
	}
}

/*��������ݹ��㷨*/
void InOrder(BTNode *b)
{
	if (b != NULL)
	{
		InOrder(b->lchild);        //�������������
		printf("%c", b->data);     //���ʸ����
		InOrder(b->rchild);        //�������������
	}
}

/*��������ݹ��㷨*/
void PostOrder(BTNode *b)
{
	if (b != NULL)
	{
		PostOrder(b->lchild);      //�������������
		PostOrder(b->rchild);      //�������������
		printf("%c", b->data);     //���ʸ����
	}
}

/*�������ʽ�Ĵ���*/
BTNode*CRTree(char s[], int i, int j)            //�����򵥵��������ʽs[i..j]��Ӧ�Ķ�����
{
	BTNode*p;
	int k, plus = 0, posi;                       //plus��¼������ĸ���
	if (i == j)                                  //����i=j�������˵��ֻ��һ���ַ�
	{
		p = (BTNode *)malloc(sizeof(BTNode));
		p->data = s[i];
		p->lchild = p->rchild = NULL;
		return p;
	}
	/*��i��=jʱ�������´���*/
	for (k = i; k <= j; k++)                            //���Ȳ���+��-�����
		if (s[k] == '+' || s[k] == '-')
		{
			plus++;                              //plus��¼+����-�ĸ���
			posi = k;                            //posi��¼���һ��+��-��λ��
		}
	if (plus == 0)                                   //û��+��-�����
		for (k = i; k <= j; k++)
			if (s[k] == '*' || s[k] == '/')
			{
				plus++;                          //plus��¼*����/�ĸ���
				posi = k;                        //posi��¼���һ��*��/��λ��
			}
	if (plus != 0)                               //������������������һ��������Ľ��
	{
		p = (BTNode*)malloc(sizeof(BTNode));
		p->data = s[posi];
		p->lchild = CRTree(s, i, posi - 1);      //�ݹ鴦��s[i..posi-1]����������
		p->rchild = CRTree(s, posi + 1, j);      //�ݹ鴦��s[posi+1..j]����������
		return p;
	}
	else                                         //��û���κ������������NULL
		return NULL;
}

/*�����������Ӧ���ʽ��ֵ*/
double Comp(BTNode*b)
{
	double v1, v2;
	if (b == NULL)
	{
		return 0;
	}
	if (b->lchild == NULL&&b->rchild == NULL)     //Ҷ�ӽ��ֱ�ӷ��ؽ��ֵ
	{
		return b->data - '0';
	}
	v1 = Comp(b->lchild);                         //�ݹ������������ֵv1
	v2 = Comp(b->rchild);                         //�ݹ������������ֵv2
	switch (b->data)                              //����b���������Ӧ����
	{
	case '+': return v1 + v2;
	case '-': return v1 - v2;
	case '*': return v1*v2;
	case '/':
		if (v2 != 0)
		{
			return v1 / v2;
		}
		else abort();                             //��0�쳣�˳�
	}
}


int main()
{
	BTNode*b;
	char s[MaxSize];
	printf("���ʽ���Ľ����ͱ���\n�������λ������������׺���ʽ��");
Label:	gets_s(s);
	if (strspn(s, "0123456789") || strspn(s, "+")
		|| strspn(s, "-") || strspn(s, "*") || strspn(s, "/") == strlen(s))
	{
		b = CRTree(s, 0, strlen(s) - 1);
		printf("��Ӧ������:");
		DispBTree(b);
		printf("\n");
		printf("ǰ׺���ʽ��");
		PreOrder(b);
		printf("\n");
		printf("��׺���ʽ��");
		InOrder(b);
		printf("\n");
		printf("��׺���ʽ��");
		PostOrder(b);
		printf("\n�������ʽֵ��%g\n", Comp(b));
		DestroyBTree(b);
		system("PAUSE");
		return 1;
	}
	else
	{
		printf("�����������������:");
		goto Label;
	}
	return 0;
}
