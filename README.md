# Self Avoidance RandomWalk & Expression Tree
Date: 2019/03/23

课程内容：高级语言程序设计实验环节1


# 摘要
自回避随机行走问题及表达式树的建立和遍历实验的实验目的是加强培养学生动手编程能力。

实验设计主要遵循高级语言程序设计(C 语言)和数据结构等课程所学之内容。

实验内容主要包括: 1.自回避随机行走问题 2.表达式树的建立和遍历。

**关键词:C 语言;自回避随机行走;表达式树的建立;表达式树的遍历;** 


# 1 实验目的和意义
## 1.1 实验目的 
本实验是提高我们综合运用所学知识写程序的基本能力，熟悉并掌握程序的设计与实现。
本实验以个人为单位，依照题目要求，使用 C 语言编写出自回避随机行走和
表达式树的建立与遍历程序，使程序成功运行。

## 1.2 实验意义 
使我们熟悉掌握所学之高级语言程序设计课程及数据结构课程的知识，依照要求完成作业，并为以后的课程积累经验:提高问题分析能力、逻辑判断能力及 处理问题的能力;有效检验及巩固知识。

# 2 实验要求
假设有一条狗放在某个城市中心点，它试图逃出城市，此城市有 N 条南北走 向的街道和 N 条东西走向的街道，所有街道均匀交叉分布构成网格形式。这条狗 在逃出城市的过程中，遇到每个交叉路口则按照随机概率的大小选择前进方向， 它能够通过灵敏的嗅觉和记忆不走重复路。当狗走到某个交叉路口时，如果三个 可选方向均指向以前走过的路口就必须回头，则陷入死胡同状态。
狗尝试逃出的次数设为 T。
1) 假设给出某个确定的 N 值(N=50)，分析并输出这条狗陷入死胡同的概率
   是多少，行走路径的平均长度是多少?成功逃出的平均路径长度和陷入
   死胡同的平均路径长度各是多少?
2) 给出一组不同的 N 值，通过运算分析出 N 的规模大小与陷入死胡同的概
率，这两者之间的联系。
2.2 表达式树的建立和遍历
  编程实现表达式树的建立和遍历。
1) 表达式支持的运算符自行设定，例如，四则运算。
2) 采用某种方式输入表达式，例如后缀表达式形式。将用户输入的表达式
   创建成如上图所示的表达式树。
3) 遍历该表达式树，分别输出该表达式的中缀表达式和后缀表达式形式。

# 3 实验设计
## 3.1 实验环境

Visual Studio Professional 2015。

## 3.2 实验原理

### 3.2.1 自回避随机行走问题 3.2.1.1 程序流程图
<img width="395" alt="Screenshot 2023-10-24 at 10 09 06 AM" src="https://github.com/Unice-YuFang/SelfAvoidanceRandomWalk_ExpressionTree/assets/74975816/9cb574ba-7562-4e44-943a-773004c6a663">


### 3.2.2 表达式树的建立和遍历 
#### 3.2.2.1 附加功能
  计算出个位四则运算的值及输出前缀表达式。
  
#### 3.2.2.2 程序流程图
<img width="341" alt="Screenshot 2023-10-24 at 10 09 36 AM" src="https://github.com/Unice-YuFang/SelfAvoidanceRandomWalk_ExpressionTree/assets/74975816/cd50ccdd-ada8-4643-b0ca-bbadb8f5f005">

## 3.3 实验结果
### 3.3.1 自回避随机行走问题
<img width="467" alt="Screenshot 2023-10-24 at 10 10 31 AM" src="https://github.com/Unice-YuFang/SelfAvoidanceRandomWalk_ExpressionTree/assets/74975816/8912fa35-ea25-4b70-8490-f631c953c1e5">

### 3.3.2 表达式树的建立和遍历
<img width="464" alt="Screenshot 2023-10-24 at 10 10 53 AM" src="https://github.com/Unice-YuFang/SelfAvoidanceRandomWalk_ExpressionTree/assets/74975816/6b9637f5-537c-491f-86f3-9b3d5ada2766">


# 4 问题与心得体会
在编写代码时，遇到了许多问题，如:出现 Stack Overflow 的情形 (如图一)，最后学会设定堆叠预留大小及堆叠基本配置大小(如图二)。

图一、发生错误

<img width="466" alt="Screenshot 2023-10-24 at 10 11 20 AM" src="https://github.com/Unice-YuFang/SelfAvoidanceRandomWalk_ExpressionTree/assets/74975816/c6abff0c-5a21-4d12-bf7a-d87f08078ebe">

图二、解决办法

<img width="467" alt="Screenshot 2023-10-24 at 10 11 43 AM" src="https://github.com/Unice-YuFang/SelfAvoidanceRandomWalk_ExpressionTree/assets/74975816/c47814e3-fd49-4d37-a31a-d42ac7dab617">


# 参考文献
[1] 谭成予.《C 语言及程序设计基础》,武汉大学出版社,2010.02.

[2] 李春葆.《数据结构教程》,清华大学出版社,2017.07.

[3] 李春葆.《数据结构教程学习指导》,清华大学出版社,2017.07.

[4] 李春葆.《数据结构教程上机实验指导》,清华大学出版社,2017.07. 

[5] 网络文献,如:百度文库、CSDN

