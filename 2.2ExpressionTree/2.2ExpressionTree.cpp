/**********************************************************************
Copyright:   2019武汉大学17级计科7班2017311500181廖妤芳
File name:   2.2ExpressionTree
Description:编程实现表达式树的建立和遍历。
1)	表达式支持的运算符自行设定，例如，四则运算。
2)	采用某种方式输入表达式，例如后缀表达式形式。将用户输入的表达式创建成如上图所示的表达式树。
3)	遍历该表达式树，分别输出该表达式的中缀表达式和后缀表达式形式。
Author:      廖妤芳
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
typedef char ElemType;                                   //二叉树顺序存储结构的类型声明
typedef struct node
{
	ElemType data;                                       //数据元素
	struct node *lchild;                                 //指向左孩子结点
	struct node *rchild;                                 //指向右孩子结点
}BTNode;                                               //声明二叉链结点类型

/*创建二叉树*/
void CreateBTree(BTNode * &b, char * str)
{
	BTNode * St[MaxSize], *p;                             //St数组作为顺序栈
	int top = -1, k = 0, j = 0;                              //top为栈顶指针  
	char ch;
	b = NULL;                                            //初始时二叉链为空
	ch = str[j];
	while (ch != '\0')                                   //循环扫描str中的每个字符
	{
		switch (ch)
		{
		case '(':                            //开始处理左孩子结点
			top++;
			St[top] = p;
			k = 1;                           //表示其后创建的结点将作为这个栈顶结点的左孩子
			break;
		case ')':                           //栈顶结点的子树处理完毕
			top--;
			break;
		case ',':                           //开始处理右孩子结点
			k = 2;                          //表示其后创建的结点将作为当前栈顶结点的右孩子结点
			break;
		default:
			p = (BTNode *)malloc(sizeof(BTNode));   //创建一个结点，由p指向它
			p->data = ch;                           //存放结点值
			p->lchild = p->rchild = NULL;           //左、右指针都设置为空
			if (b == NULL)                          //若尚未建立根结点（b为空）   
			{                                       //p所指结点就作为根结点
				b = p;
			}
			else                                    //已建立二叉树根结点
			{
				switch (k)
				{
				case 1:St[top]->lchild = p;        //新建结点作为栈顶结点的左孩子
					break;
				case 2:St[top]->rchild = p;        //新建结点作为栈顶结点的右孩子
					break;
				}
			}
		}
		j++;
		ch = str[j];                                    //继续扫描str
	}
}

/*销毁二叉树*/
void DestroyBTree(BTNode*&b)
{
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}

/*输出二叉树*/
void DispBTree(BTNode *b)                                 //以括号表示法输出二叉树
{
	if (b != NULL)
	{
		printf("%c", b->data);                           //输出结点b的结点值
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");                                 //有孩子结点时才输出“（”
			DispBTree(b->lchild);                        //递归处理左子树
			if (b->rchild != NULL)                       //有右孩子结点时才输出“,”
			{
				printf(",");
			}
			DispBTree(b->rchild);                        //递归处理右子树
			printf(")");                                 //有孩子结点时才输出“）”
		}
	}
}

/*先序遍历递归算法*/
void PreOrder(BTNode *b)
{
	if (b != NULL)
	{
		printf("%c", b->data);       //访问根结点
		PreOrder(b->lchild);         //先序遍历左子树
		PreOrder(b->rchild);         //先序遍历右子树
	}
}

/*中序遍历递归算法*/
void InOrder(BTNode *b)
{
	if (b != NULL)
	{
		InOrder(b->lchild);        //中序遍历左子树
		printf("%c", b->data);     //访问根结点
		InOrder(b->rchild);        //中序遍历右子树
	}
}

/*后序遍历递归算法*/
void PostOrder(BTNode *b)
{
	if (b != NULL)
	{
		PostOrder(b->lchild);      //后序遍历左子树
		PostOrder(b->rchild);      //后序遍历右子树
		printf("%c", b->data);     //访问根结点
	}
}

/*算术表达式的处理*/
BTNode*CRTree(char s[], int i, int j)            //建立简单的算术表达式s[i..j]对应的二叉树
{
	BTNode*p;
	int k, plus = 0, posi;                       //plus记录运算符的个数
	if (i == j)                                  //处理i=j的情况，说明只有一个字符
	{
		p = (BTNode *)malloc(sizeof(BTNode));
		p->data = s[i];
		p->lchild = p->rchild = NULL;
		return p;
	}
	/*当i！=j时处理以下代码*/
	for (k = i; k <= j; k++)                            //首先查找+和-运算符
		if (s[k] == '+' || s[k] == '-')
		{
			plus++;                              //plus记录+或者-的个数
			posi = k;                            //posi记录最后一个+或-的位置
		}
	if (plus == 0)                                   //没有+或-的情况
		for (k = i; k <= j; k++)
			if (s[k] == '*' || s[k] == '/')
			{
				plus++;                          //plus记录*或者/的个数
				posi = k;                        //posi记录最后一个*或/的位置
			}
	if (plus != 0)                               //有运算符的情况，创建一个存放它的结点
	{
		p = (BTNode*)malloc(sizeof(BTNode));
		p->data = s[posi];
		p->lchild = CRTree(s, i, posi - 1);      //递归处理s[i..posi-1]构造左子树
		p->rchild = CRTree(s, posi + 1, j);      //递归处理s[posi+1..j]构造右子树
		return p;
	}
	else                                         //若没有任何运算符，返回NULL
		return NULL;
}

/*计算二叉树对应表达式的值*/
double Comp(BTNode*b)
{
	double v1, v2;
	if (b == NULL)
	{
		return 0;
	}
	if (b->lchild == NULL&&b->rchild == NULL)     //叶子结点直接返回结点值
	{
		return b->data - '0';
	}
	v1 = Comp(b->lchild);                         //递归求出左子树的值v1
	v2 = Comp(b->rchild);                         //递归求出右子树的值v2
	switch (b->data)                              //根据b结点做出相应运算
	{
	case '+': return v1 + v2;
	case '-': return v1 - v2;
	case '*': return v1*v2;
	case '/':
		if (v2 != 0)
		{
			return v1 / v2;
		}
		else abort();                             //除0异常退出
	}
}


int main()
{
	BTNode*b;
	char s[MaxSize];
	printf("表达式树的建立和遍历\n请输入个位数四则运算中缀表达式：");
Label:	gets_s(s);
	if (strspn(s, "0123456789") || strspn(s, "+")
		|| strspn(s, "-") || strspn(s, "*") || strspn(s, "/") == strlen(s))
	{
		b = CRTree(s, 0, strlen(s) - 1);
		printf("对应二叉树:");
		DispBTree(b);
		printf("\n");
		printf("前缀表达式：");
		PreOrder(b);
		printf("\n");
		printf("中缀表达式：");
		InOrder(b);
		printf("\n");
		printf("后缀表达式：");
		PostOrder(b);
		printf("\n算术表达式值：%g\n", Comp(b));
		DestroyBTree(b);
		system("PAUSE");
		return 1;
	}
	else
	{
		printf("输入错误！请重新输入:");
		goto Label;
	}
	return 0;
}
