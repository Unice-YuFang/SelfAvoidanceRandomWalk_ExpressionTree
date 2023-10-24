/**********************************************************************
Copyright:   2019武汉大学17级计科7班2017311500181廖妤芳
File name:   2.1SelfAvoidanceRandomWalk
Description: 狗尝试逃出的次数设为T。
1)	假设给出某个确定的N值(N=50)，分析并输出这条狗陷入死胡同的概率是多少，行走路径的平均长度是多少？成功逃出的平均路径长度和陷入死胡同的平均路径长度各是多少？
2)	给出一组不同的N值，通过运算分析出N的规模大小与陷入死胡同的概率，这两者之间的联系。
Author:      廖妤芳
Version:     1.0
Date:        2019.03.22
***********************************************************************/
#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define coordinateMax 100
#define try 100000
int main()
{
	int N;                                                //N条南北，N条东西走向的街道
	int T;                                                //狗尝试逃出的次数
	int x, y;                                             //狗的坐标
	int coordinate[coordinateMax][coordinateMax] = { 0 }; //网格坐标
	int escaperoute[try] = { 0 };                         //储存逃出路径
	int impasseroute[try] = { 0 };                        //储存死胡同路径
	int impasse = 0;                                      //储存死胡同
	int escapenum = 0;                                    //逃出次数
	int route = 0;                                        //路径
	float deadavg, passavg, allavg;                       //死胡同平均路径，逃出平均路径，总平均路径
	int n, i, j = 0, p = 0;                               //设计随机变量，控制程序变量
	float c;                                              //计算概率
	srand((int)time(NULL));
	printf("自回避随机行走问题\n");
	printf("请输入街道数N(1<N<100)：");
	scanf("%d", &N);
    printf("请输入尝试次数T（小于100000次）:");
	scanf("%d", &T);
	x = (N + 1) / 2;                                      //将狗置于城市中心点
	y = (N + 1) / 2;                                      //将狗置于城市中心点
	coordinate[x][y] = 1;                                 //走过的点置1，不走重复路
	for (i = T; i > 0; i--)                               //狗在城市中的路径
	{
		for (;;)
		{
			for (;;)
			{
				n = rand() % 4 + 1;
				if (n == 1 && coordinate[x + 1][y] != 1)  //向右走
				{
					x++;
					break;
				}
				if (n == 2 && coordinate[x - 1][y] != 1)  //向左走
				{
					x--;
					break;
				}
				if (n == 3 && coordinate[x][y + 1] != 1)  //向上走
				{
					y++;
					break;
				}
				if (n == 4 && coordinate[x][y - 1] != 1)   //向下走
				{
					y--;
					break;
				}
				if (coordinate[x + 1][y] == 1 && coordinate[x - 1][y] == 1 
					&& coordinate[x][y + 1] == 1 && coordinate[x][y - 1] == 1)
					break;
				//若未进入任一if，需重新开始
			}
			coordinate[x][y] = 1;                      //判断有问题，设置为1后还会经过
			route++;                                   //重新走
			if (x > N || y > N || x == 0 || y == 0)    //成功逃出
			{
				escapenum++;
				escaperoute[escapenum] = route;
				break;
			}
			if (coordinate[x + 1][y] == 1 && coordinate[x - 1][y] == 1 
				&& coordinate[x][y + 1] == 1 && coordinate[x][y - 1] == 1) //陷入死胡同
			{
				route--;
				impasse++;
				impasseroute[impasse] = route;
				break;
			}
		}
		route = 0;                                                      //路径清零
		memset(coordinate, 0, sizeof(int)*coordinateMax*coordinateMax); //清空坐标
		x = (N + 1) / 2;                                                //将狗置于城市中心点
		y = (N + 1) / 2;                                                //将狗置于城市中心点
		coordinate[x][y] = 1;
	}
	c = (float)impasse / T;                                             //计算陷入死胡同的概率
	for (i = impasse; i > 0; i--)                                       //计算死胡同平均路径长
	{
		j = j + impasseroute[i];                                        //j为死胡同的总路径长
	}
	deadavg = (float)j / impasse;
	for (i = escapenum; i > 0; i--)                                     //计算通路平均路径长
	{
		p = p + escaperoute[i];                                         //p为通路总路径长
	}
	passavg = (float)p / escapenum;
	allavg = (float)(p + j) / T;                                        //计算总平均路径长
	printf("这条狗陷入死胡同的概率为：%f%", c * 100);
	printf("\n这条狗的行走平均路径长度为：%f", allavg);
	printf("\n成功逃出的平均路径长度为：%f\n",passavg);
	printf("陷入死胡同的平均路径长度为：%f\n", deadavg);
	system("PAUSE");
	return 0;
}

