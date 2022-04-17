#include <stdio.h>

int node_Number = 6;	// ��� ����
int INF = 10000000;     // �ٷ� �� �� ���� �Ÿ��� �������� ǥ����

//��ü �׷��� 1�� ������ 6�� ��� ... 6������ 6�� �������� �Ÿ�
int a[6][6] = 
{
	{0, 3, 4, INF, INF, INF},
	{3, 0, 2, INF, INF, 5},
	{4, 2, 0, 2, 2, 3},
	{INF, INF, 2, 0, INF, INF},
	{INF, INF, 2, INF, 0, 3},
	{INF, 5, 3, INF, 3, 0},
};

bool visit[6];	    // �湮�� ���
int distance[6];	// �Ÿ�

// ���� �ּ� �Ÿ��� ������ ���� ��ȯ (�湮���� ���� ���� �� �ּ� �Ÿ��� ��ȯ)
int getSmallIndex()
{
	// min = ����
	// index = 0;
	int min = INF;
	int index = 0;

	// 0���� ��� ����
	for (int i = 0; i < node_Number; i++)
	{
		// i��° �Ÿ��� ������ ������ ���� ��
		// �׸��� i��°�� �湮�� ��尡 �ƴ� ��
		if (distance[i] < min && !visit[i])
		{
			// min�� i��° �Ÿ��� ����, index = i;
			min = distance[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start)
{
	// 0���� ����� ��������
	for (int i = 0; i < node_Number; i++)
	{
		// ���� �������� ��� �������� �Ÿ�
		distance[i] = a[start][i];
	}

	// start��° ����� �湮 ���θ� true(start��° ��� �湮)
	visit[start] = true;

	// 0���� ����� ���� - 2(4)������
	for (int i = 0; i < node_Number - 2; i++)
	{
		// current = ���� �ּ� �Ÿ��� ������ ������ ��ȯ
		int current = getSmallIndex();

		// �ּ� �Ÿ��� ������ ������ �湮 ���θ� true
		visit[current] = true;

		// 0���� 6����
		for (int j = 0; j < 6; j++)
		{
			// j��° ��� �湮 ���ΰ� false���
			if (!visit[j])
			{
				// ���� �ּ� �Ÿ��� ������ ������ �Ÿ� + a�� �������� j�� ���� j��° �Ÿ����� �۴ٸ�
				if (distance[current] + a[current][j] < distance[j])
				{
					// j��° �Ÿ� = ���� �ּ� �Ÿ��� ������ ������ �Ÿ� + a�� �������� j�� ��;
					// (�� ���� ������ ����)
					distance[j] = distance[current] + a[current][j];
				}
			}
		}
	}
}

int main(void)
{
	dijkstra(0);
	for (int i = 0; i < node_Number; i++)
	{
		printf("%d ", distance[i]);
	}
	return 0;
}