#include <iostream>
using namespace std;

int available[3];	//假设系统有3类资源
int Max[5][3];		//假设有5个进程，以下是资源的开始需求矩阵 
int allocation[5][3]; 	//假设有5个进程，以下是资源的已分配矩阵
int need[5][3];		//假设有5个进程，以下是还需要资源个数矩阵
 
bool safe(int n)
{
	int work[3];				//work表示可提供给进程继续运行所需的各类资源数目 
	for (int i = 0; i < 3; i++)
	{
		work[i] = available[i];
	}
	
	
	bool finish[n] = {false};			//表示是否有足够多的第n中资源分配给该请求资源的进程
	int temp = 0;		//记录有多少个进程通过了安全算法 
	int index[n];		//依次记录能通过申请的进程的下标 
	int flag = 0;	//检测finish数组是否全为true
		
	while(temp < 5)
	{
		bool hasPassed;
		for (int i = 0; i < n; i++)			//针对每个进程 ，从第一个进程开始 
		{
			int workTemp = 0;		//判断对于该种资源，当前进程是否能够申请成功
			hasPassed = false; 
			if (finish[i] == false)
			{
				for (int j = 0; j < 3; j++)
				{
					if (need[i][j] <= work[j])
					{
						workTemp++;				//每项资源能满足分配，则满足的记录加1 
					}
				}
				
				if (workTemp == 3)				//3种资源都满足，则该进程的资源请求可以达成 
					{
						for (int j = 0; j < 3; j++)
						{
							work[j] += allocation[i][j];
						}
						finish[i] = true;
						index[temp] = i;		//记录该进程的下标 
						temp++;
						hasPassed = true;
						break;
					}
				else
				{
					continue;
					}	
			 } 
			else 
			{
				continue;
			}
				
				
		}
		
		if (hasPassed == true)
			continue;
		 
		 
		for (int p = 0; p < 5; p++)
		{
			if (finish[p] == true)
				flag++;
		 }
		 if (flag < 5)
		 	{
		 		cout<<"系统处于不安全状态！"<<endl;
		 		return false;
				 break;
			  } 
	}
	
			for (int p = 0; p < 5; p++)
		{
			if (finish[p] == true)
				flag++;
		 }
		 if (flag < 5)
		 	{
		 		cout<<"系统处于不安全状态！"<<endl;
		 		return false;
			  } 
	
	
	if (flag == 5)
	{
		cout<<"系统处于安全状态！ 安全序列为："<<endl;
		for (int i = 0; i < 4; i++)
		{
			cout<<"P"<<index[i]<<"->";
		}
		cout<<"P"<<index[4];
		return true;
	}

	cout<<endl;
}  
 
 
void Banker(int i, int request[])	//银行家算法 
{
	for (int j = 0; j < 3; j++)
	{
			if (request[j] > need[i][j])
		{
			cout<<"该进程所需要的资源超过了它所宣布的最大值！"<<endl;
			exit(0);
		} 
			if (request[j] > available[j])
		{
			cout<<"暂无足够资源，此进程需要等待！"<<endl;
			exit(0);
		}
	}

	//尝试分配资源给进程i 
	for (int j = 0; j < 3; j++)
	{
		available[j] -= request[j];
		allocation[i][j] += request[j];
		need[i][j] -= request[j];
	}
	
	if (safe(5) == false)
	{
		for (int j = 0; j < 3; j++)
		{
			available[j] += request[j];
			allocation[i][j] -= request[j];
			need[i][j] += request[j];
		}
		cout<<"无法满足该进程的需求！";
	}
	
	cout<<endl;
}

int main() 
{
	cout<<"**********欢迎使用银行家算法**************"<<endl;
	cout<<"下面请输入系统中初始的三种资源的数量"<<endl;
	
	for (int i = 0; i < 3; i++)
	{
		cin>>available[i];
	}
	
	cout<<"请输入5个进程对于三种系统资源的最大需求矩阵"<<endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin>>Max[i][j];
		}
	}
	
	cout<<"请输入初始时5个进程的资源分配情况矩阵"<<endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin>>allocation[i][j];
		}
	}
	
	//初始分配后，初始资源要减去初始分配的资源
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			available[i] = available[i] - allocation[i][j];
		}
	}
	available[0] = 3;
	
	//need矩阵表示每一个进程还需要的各种资源数，它能通过Max和allocation求得 
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			need[i][j] = Max[i][j] - allocation[i][j];
		}
	}
	
	if (safe(5) == true)		//首先进行一次安全性检测 
	{
		cout<<"------------------------------------------"<<endl;
		cout<<"下面开始进入银行家算法"<<endl;
		cout<<"请输入目前需要请求资源分配的进程"<<endl;
		//输入请求向量Requesti
		int i;	//i表示第几个进程，j表示i进程请求的第几种资源 
		int Requesti[3];
		cin>>i; 
		cout<<"请输入请求向量（输入该进程需要的是第几种资源和它的数目）"<<endl;
		for (int j = 0; j < 3; j++)
		{
			cin>>Requesti[j];
		}
	
		Banker(i, Requesti);
	}
	system("pause");
	return 0;
}
