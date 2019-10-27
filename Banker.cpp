#include <iostream>
using namespace std;

int available[3];	//����ϵͳ��3����Դ
int Max[5][3];		//������5�����̣���������Դ�Ŀ�ʼ������� 
int allocation[5][3]; 	//������5�����̣���������Դ���ѷ������
int need[5][3];		//������5�����̣������ǻ���Ҫ��Դ��������
 
bool safe(int n)
{
	int work[3];				//work��ʾ���ṩ�����̼�����������ĸ�����Դ��Ŀ 
	for (int i = 0; i < 3; i++)
	{
		work[i] = available[i];
	}
	
	
	bool finish[n] = {false};			//��ʾ�Ƿ����㹻��ĵ�n����Դ�������������Դ�Ľ���
	int temp = 0;		//��¼�ж��ٸ�����ͨ���˰�ȫ�㷨 
	int index[n];		//���μ�¼��ͨ������Ľ��̵��±� 
	int flag = 0;	//���finish�����Ƿ�ȫΪtrue
		
	while(temp < 5)
	{
		bool hasPassed;
		for (int i = 0; i < n; i++)			//���ÿ������ ���ӵ�һ�����̿�ʼ 
		{
			int workTemp = 0;		//�ж϶��ڸ�����Դ����ǰ�����Ƿ��ܹ�����ɹ�
			hasPassed = false; 
			if (finish[i] == false)
			{
				for (int j = 0; j < 3; j++)
				{
					if (need[i][j] <= work[j])
					{
						workTemp++;				//ÿ����Դ��������䣬������ļ�¼��1 
					}
				}
				
				if (workTemp == 3)				//3����Դ�����㣬��ý��̵���Դ������Դ�� 
					{
						for (int j = 0; j < 3; j++)
						{
							work[j] += allocation[i][j];
						}
						finish[i] = true;
						index[temp] = i;		//��¼�ý��̵��±� 
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
		 		cout<<"ϵͳ���ڲ���ȫ״̬��"<<endl;
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
		 		cout<<"ϵͳ���ڲ���ȫ״̬��"<<endl;
		 		return false;
			  } 
	
	
	if (flag == 5)
	{
		cout<<"ϵͳ���ڰ�ȫ״̬�� ��ȫ����Ϊ��"<<endl;
		for (int i = 0; i < 4; i++)
		{
			cout<<"P"<<index[i]<<"->";
		}
		cout<<"P"<<index[4];
		return true;
	}

	cout<<endl;
}  
 
 
void Banker(int i, int request[])	//���м��㷨 
{
	for (int j = 0; j < 3; j++)
	{
			if (request[j] > need[i][j])
		{
			cout<<"�ý�������Ҫ����Դ�������������������ֵ��"<<endl;
			exit(0);
		} 
			if (request[j] > available[j])
		{
			cout<<"�����㹻��Դ���˽�����Ҫ�ȴ���"<<endl;
			exit(0);
		}
	}

	//���Է�����Դ������i 
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
		cout<<"�޷�����ý��̵�����";
	}
	
	cout<<endl;
}

int main() 
{
	cout<<"**********��ӭʹ�����м��㷨**************"<<endl;
	cout<<"����������ϵͳ�г�ʼ��������Դ������"<<endl;
	
	for (int i = 0; i < 3; i++)
	{
		cin>>available[i];
	}
	
	cout<<"������5�����̶�������ϵͳ��Դ������������"<<endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin>>Max[i][j];
		}
	}
	
	cout<<"�������ʼʱ5�����̵���Դ�����������"<<endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin>>allocation[i][j];
		}
	}
	
	//��ʼ����󣬳�ʼ��ԴҪ��ȥ��ʼ�������Դ
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			available[i] = available[i] - allocation[i][j];
		}
	}
	available[0] = 3;
	
	//need�����ʾÿһ�����̻���Ҫ�ĸ�����Դ��������ͨ��Max��allocation��� 
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			need[i][j] = Max[i][j] - allocation[i][j];
		}
	}
	
	if (safe(5) == true)		//���Ƚ���һ�ΰ�ȫ�Լ�� 
	{
		cout<<"------------------------------------------"<<endl;
		cout<<"���濪ʼ�������м��㷨"<<endl;
		cout<<"������Ŀǰ��Ҫ������Դ����Ľ���"<<endl;
		//������������Requesti
		int i;	//i��ʾ�ڼ������̣�j��ʾi��������ĵڼ�����Դ 
		int Requesti[3];
		cin>>i; 
		cout<<"��������������������ý�����Ҫ���ǵڼ�����Դ��������Ŀ��"<<endl;
		for (int j = 0; j < 3; j++)
		{
			cin>>Requesti[j];
		}
	
		Banker(i, Requesti);
	}
	system("pause");
	return 0;
}
