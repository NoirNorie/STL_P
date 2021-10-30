#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

// 문제 번호: 1260(DFS와 BFS)
/*
	깊이 우선 탐색 (Depth First Search)
	- 재귀 또는 스택으로 구현
	- 일단 가는데 까지는 일방향으로 이동한다
	- 이후 안가본데를 찾는다

	너비 우선 탐색 (Breadth First Search)
	- 큐로 구현
	- 갈 수 있는 모든 방향을 큐에 넣는다
	- 큐에 넣어진 노드도 갈 수 있는 방향을 모두 큐에 넣는다
	- 그 중에서 가본적 없는 것들이면 출력하고 아니면 빼버린다.

	* 어떤 노드를 방문했는지 반드시 검사하고 기록해야 한다
*/

class vertex
{
private:
	int vertex_number;
	bool visited;

	vector<bool> link; // 연결 여부를 기록할 벡터

public:
	vertex(int n, int size) // 생성자
	{
		vertex_number = n;
		visited = false;
		link.assign(size + 1, false);
	}

	int get_vertex_number()
	{
		return vertex_number;
	}

	void linker(int i) // 연결 지정 함수
	{
		link[i] = true; // 연결되었다고 표시한다.
	}

	void set_visit()
	{
		visited = true;
	}

	bool has_linked(int i) // 연결 여부를 검사할 함수
	{
		if (link[i] == true) return true;
		else return false;
	}

	bool has_visited() // 방문 여부를 검사할 함수
	{
		if (visited == true) return true;
		else return false;
	}
};

void DFS(int init, vector<vertex>& DFS_graph) // 깊이 우선
{
	DFS_graph[init].set_visit(); // 방문했다고 기록한다.
	cout << DFS_graph[init].get_vertex_number() << " "; // 정점 출력

	for (int i = 0; i < DFS_graph.size(); i++)
	{
		if (DFS_graph[init].has_linked(i)) // 연결 되었는가?
		{
			if(DFS_graph[i].has_visited() == false) // 방문된적 없는 노드인가?
			{			
				DFS(i, DFS_graph); // 재귀에 들어간다.
			}
		}

	}
}

void BFS(int init, vector<vertex>& BFS_graph) // 넓이 우선
{
	BFS_graph[init].set_visit(); // 방문했다고 기록한다.
	cout << BFS_graph[init].get_vertex_number() << " "; // 정점 출력

	queue<int, deque<int>> prt_wait;
	for (int i = 1; i < BFS_graph.size(); i++)
	{
		if (BFS_graph[init].has_linked(i)) // 일단 연결된 경우 다 큐에 넣는다.
		{
			prt_wait.push(i);
		}
	}

	while (prt_wait.empty() != true) //큐가 빌 때까지 반복한다.
	{
		for (int i = 1; i < BFS_graph.size(); i++)
		{
			if (BFS_graph[prt_wait.front()].has_linked(i)) // 일단 연결된 경우 다 큐에 넣는다.
			{
				if (BFS_graph[i].has_visited() == false) // 방문된적 없는 노드인가?
				{
					prt_wait.push(i);
				}
				
			}
		}

		if (BFS_graph[prt_wait.front()].has_visited() == false)
		{
			BFS_graph[prt_wait.front()].set_visit(); // 방문했다고 기록한다.
			cout << BFS_graph[prt_wait.front()].get_vertex_number() << " "; // 정점 출력
		}
		prt_wait.pop(); // 제거한다.
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; int M; int init; // 정점 수, 간선 수, 시작점
	cin >> N >> M >> init;

	vector<vertex> DFS_graph; // 정점으로 구성될 벡터
	vector<vertex> BFS_graph; 

	for (int i = 0; i <= N; i++)
	{
		vertex a(i, N);
		DFS_graph.push_back(a); // 정점을 벡터에 기록한다.
		BFS_graph.push_back(a);
	}

	for (int i = 0; i < M; i++) // 정점 간 연결 지정
	{
		int a, b;
		cin >> a >> b;
		DFS_graph[a].linker(b); DFS_graph[b].linker(a);
		BFS_graph[a].linker(b); BFS_graph[b].linker(a);
	}

	// DFS 출력
	DFS(init, DFS_graph);

	cout << '\n';

	// BFS 출력
	BFS(init, BFS_graph);

	return 0;
}
