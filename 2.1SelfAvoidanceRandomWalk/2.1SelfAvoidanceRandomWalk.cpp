/**********************************************************************
Copyright:   2019�人��ѧ17���ƿ�7��2017311500181��楷�
File name:   2.1SelfAvoidanceRandomWalk
Description: �������ӳ��Ĵ�����ΪT��
1)	�������ĳ��ȷ����Nֵ(N=50)�������������������������ͬ�ĸ����Ƕ��٣�����·����ƽ�������Ƕ��٣��ɹ��ӳ���ƽ��·�����Ⱥ���������ͬ��ƽ��·�����ȸ��Ƕ��٣�
2)	����һ�鲻ͬ��Nֵ��ͨ�����������N�Ĺ�ģ��С����������ͬ�ĸ��ʣ�������֮�����ϵ��
Author:      ��楷�
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
	int N;                                                //N���ϱ���N����������Ľֵ�
	int T;                                                //�������ӳ��Ĵ���
	int x, y;                                             //��������
	int coordinate[coordinateMax][coordinateMax] = { 0 }; //��������
	int escaperoute[try] = { 0 };                         //�����ӳ�·��
	int impasseroute[try] = { 0 };                        //��������ͬ·��
	int impasse = 0;                                      //��������ͬ
	int escapenum = 0;                                    //�ӳ�����
	int route = 0;                                        //·��
	float deadavg, passavg, allavg;                       //����ͬƽ��·�����ӳ�ƽ��·������ƽ��·��
	int n, i, j = 0, p = 0;                               //���������������Ƴ������
	float c;                                              //�������
	srand((int)time(NULL));
	printf("�Իر������������\n");
	printf("������ֵ���N(1<N<100)��");
	scanf("%d", &N);
    printf("�����볢�Դ���T��С��100000�Σ�:");
	scanf("%d", &T);
	x = (N + 1) / 2;                                      //�������ڳ������ĵ�
	y = (N + 1) / 2;                                      //�������ڳ������ĵ�
	coordinate[x][y] = 1;                                 //�߹��ĵ���1�������ظ�·
	for (i = T; i > 0; i--)                               //���ڳ����е�·��
	{
		for (;;)
		{
			for (;;)
			{
				n = rand() % 4 + 1;
				if (n == 1 && coordinate[x + 1][y] != 1)  //������
				{
					x++;
					break;
				}
				if (n == 2 && coordinate[x - 1][y] != 1)  //������
				{
					x--;
					break;
				}
				if (n == 3 && coordinate[x][y + 1] != 1)  //������
				{
					y++;
					break;
				}
				if (n == 4 && coordinate[x][y - 1] != 1)   //������
				{
					y--;
					break;
				}
				if (coordinate[x + 1][y] == 1 && coordinate[x - 1][y] == 1 
					&& coordinate[x][y + 1] == 1 && coordinate[x][y - 1] == 1)
					break;
				//��δ������һif�������¿�ʼ
			}
			coordinate[x][y] = 1;                      //�ж������⣬����Ϊ1�󻹻ᾭ��
			route++;                                   //������
			if (x > N || y > N || x == 0 || y == 0)    //�ɹ��ӳ�
			{
				escapenum++;
				escaperoute[escapenum] = route;
				break;
			}
			if (coordinate[x + 1][y] == 1 && coordinate[x - 1][y] == 1 
				&& coordinate[x][y + 1] == 1 && coordinate[x][y - 1] == 1) //��������ͬ
			{
				route--;
				impasse++;
				impasseroute[impasse] = route;
				break;
			}
		}
		route = 0;                                                      //·������
		memset(coordinate, 0, sizeof(int)*coordinateMax*coordinateMax); //�������
		x = (N + 1) / 2;                                                //�������ڳ������ĵ�
		y = (N + 1) / 2;                                                //�������ڳ������ĵ�
		coordinate[x][y] = 1;
	}
	c = (float)impasse / T;                                             //������������ͬ�ĸ���
	for (i = impasse; i > 0; i--)                                       //��������ͬƽ��·����
	{
		j = j + impasseroute[i];                                        //jΪ����ͬ����·����
	}
	deadavg = (float)j / impasse;
	for (i = escapenum; i > 0; i--)                                     //����ͨ·ƽ��·����
	{
		p = p + escaperoute[i];                                         //pΪͨ·��·����
	}
	passavg = (float)p / escapenum;
	allavg = (float)(p + j) / T;                                        //������ƽ��·����
	printf("��������������ͬ�ĸ���Ϊ��%f%", c * 100);
	printf("\n������������ƽ��·������Ϊ��%f", allavg);
	printf("\n�ɹ��ӳ���ƽ��·������Ϊ��%f\n",passavg);
	printf("��������ͬ��ƽ��·������Ϊ��%f\n", deadavg);
	system("PAUSE");
	return 0;
}

