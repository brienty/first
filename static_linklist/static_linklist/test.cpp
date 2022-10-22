#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/*
	���ڶ�̬������newʱ������ʱ�䣬���������ǳ����ʱ��ᳬʱ
	ʵ��һ����̬�����ڲ����Ϸ�������£�������º�����
	1������ĳ�ʼ��
	2�������ͷ��
	3������ĵ�k��λ�õĺ������
	4��ɾ����k��λ�ú����Ԫ��
*/

//���ٵ������С
const int N = 100010;

//headͷ����±�
//e[N]��ʾ���i��ֵ
//ne[N]���i��nextָ���Ƕ���
//idx�洢��ǰ�Ѿ��õ����ĸ���
int head, e[N], ne[N], idx;

//��ʼ��head��idx
void init()
{
	head = -1;
	idx = 0;
}

//��x���뵽ͷ���
void add_to_head(const int x)
{
	e[idx] = x;//�洢x��ֵ
	ne[idx] = head;//��x��nextָ��head��next��Ԫ��
	head = idx;//headָ��x
	++idx;//++idx
}

//��x���뵽�±���k�Ľ��ĺ���
void add(const int k, const int x)
{
	e[idx] = x;//�洢x��ֵ
	ne[idx] = ne[k];//��x��nextָ��k��next��Ԫ��
	ne[k] = idx;//��k��nextָ��x
	++idx;//++idx
}

//���±���k�Ľ��ĺ���Ľ��ɾ��
void remove(const int k)
{
	ne[k] = ne[ne[k]];//��kָ��nextԪ�ص�next��Ԫ��
}

int main()
{
	init();//��ʼ������
	
	//�����������ݣ�10 H 9 I 1 1 D 1 D 0 H 6 I 3 6 I 4 5 I 4 5 I 3 4 D 6
	int m = 0;
	cin >> m;
	while (m--)
	{
		
		char op = 0;
		cin >> op;
		//ͷ��
		if (op == 'H')
		{
			int x = 0;
			cin >> x;
			add_to_head(x);
		}
		//����
		else if (op == 'I')
		{
			int k = 0, x = 0;
			cin >> k >> x;
			add(k - 1, x);//�±�0��ʼ��Ӧ����k-1
		}
		//ɾ�����
		else
		{
			int k = 0;
			cin >> k;
			//������Ҫ���У���Ϊɾ��ͷ���ʱ��headӦ����ָ��head��next����ͷ������һ����㣬��Ӧ�ý�ȥɾ��
			if (!k) 
				head = ne[head];
			else 
				remove(k - 1);//�±�0��ʼӦ����k-1
		}	
	}
	//�������ͷ��㿪ʼ������� 
	for (int i = head; i != -1; i = ne[i])
	{
		cout << e[i] << " ";
	}
	cout << endl;
}