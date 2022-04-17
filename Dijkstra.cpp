#include <stdio.h>

int node_Number = 6;	// 노드 개수
int INF = 10000000;     // 바로 갈 수 없는 거리를 무한으로 표시함

//전체 그래프 1번 노드부터 6번 노드 ... 6번부터 6번 노드까지의 거리
int a[6][6] = 
{
	{0, 3, 4, INF, INF, INF},
	{3, 0, 2, INF, INF, 5},
	{4, 2, 0, 2, 2, 3},
	{INF, INF, 2, 0, INF, INF},
	{INF, INF, 2, INF, 0, 3},
	{INF, 5, 3, INF, 3, 0},
};

bool visit[6];	    // 방문한 노드
int distance[6];	// 거리

// 가장 최소 거리를 가지는 정점 반환 (방문하지 않은 노드들 중 최소 거리를 반환)
int getSmallIndex()
{
	// min = 무한
	// index = 0;
	int min = INF;
	int index = 0;

	// 0부터 노드 갯수
	for (int i = 0; i < node_Number; i++)
	{
		// i번째 거리가 무한의 수보다 작을 때
		// 그리고 i번째가 방문한 노드가 아닐 때
		if (distance[i] < min && !visit[i])
		{
			// min을 i번째 거리로 지정, index = i;
			min = distance[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start)
{
	// 0부터 노드의 개수까지
	for (int i = 0; i < node_Number; i++)
	{
		// 시작 지점부터 모든 노드까지의 거리
		distance[i] = a[start][i];
	}

	// start번째 노드의 방문 여부를 true(start번째 노드 방문)
	visit[start] = true;

	// 0부터 노드의 개수 - 2(4)번까지
	for (int i = 0; i < node_Number - 2; i++)
	{
		// current = 가장 최소 거리를 가지는 정점을 반환
		int current = getSmallIndex();

		// 최소 거리를 가지는 정점의 방문 여부를 true
		visit[current] = true;

		// 0부터 6까지
		for (int j = 0; j < 6; j++)
		{
			// j번째 요소 방문 여부가 false라면
			if (!visit[j])
			{
				// 가장 최소 거리를 가지는 정점의 거리 + a의 정점에서 j의 값이 j번째 거리보다 작다면
				if (distance[current] + a[current][j] < distance[j])
				{
					// j번째 거리 = 가장 최소 거리를 가지는 정점의 거리 + a의 정점에서 j의 값;
					// (더 작은 값으로 변경)
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