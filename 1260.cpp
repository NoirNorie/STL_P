#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

// ���� ��ȣ: 1260(DFS�� BFS)
/*
	���̿켱
	- ��� �Ǵ� �������� ����
	- �ϴ� ���µ� ������ �Ϲ������� �̵��Ѵ�
	- ���� �Ȱ������� ã�´�

	���̿켱
	- ť�� ����
	- �� �� �ִ� ��� ������ ť�� �ִ´�
	- ť�� �־��� ��嵵 �� �� �ִ� ������ ��� ť�� �ִ´�
	- �� �߿��� ������ ���� �͵��̸� ����ϰ� �ƴϸ� ��������.

	* � ��带 �湮�ߴ��� �ݵ�� �˻��ϰ� ����ؾ� �Ѵ�
*/

class vertex
{
private:
	int vertex_number;
	bool visited;

	vector<bool> link; // ���� ���θ� ����� ����

public:
	vertex(int n, int size) // ������
	{
		vertex_number = n;
		visited = false;
		link.assign(size + 1, false);
	}

	int get_vertex_number()
	{
		return vertex_number;
	}

	void linker(int i) // ���� ���� �Լ�
	{
		link[i] = true; // ����Ǿ��ٰ� ǥ���Ѵ�.
	}

	void set_visit()
	{
		visited = true;
	}

	bool has_linked(int i) // ���� ���θ� �˻��� �Լ�
	{
		if (link[i] == true) return true;
		else return false;
	}

	bool has_visited() // �湮 ���θ� �˻��� �Լ�
	{
		if (visited == true) return true;
		else return false;
	}
};

void DFS(int init, vector<vertex>& DFS_graph) // ���� �켱
{
	DFS_graph[init].set_visit(); // �湮�ߴٰ� ����Ѵ�.
	cout << DFS_graph[init].get_vertex_number() << " "; // ���� ���

	for (int i = 0; i < DFS_graph.size(); i++)
	{
		if (DFS_graph[init].has_linked(i)) // ���� �Ǿ��°�?
		{
			if(DFS_graph[i].has_visited() == false) // �湮���� ���� ����ΰ�?
			{			
				DFS(i, DFS_graph); // ��Ϳ� ����.
			}
		}

	}
}

void BFS(int init, vector<vertex>& BFS_graph) // ���� �켱
{
	BFS_graph[init].set_visit(); // �湮�ߴٰ� ����Ѵ�.
	cout << BFS_graph[init].get_vertex_number() << " "; // ���� ���

	queue<int, deque<int>> prt_wait;
	for (int i = 1; i < BFS_graph.size(); i++)
	{
		if (BFS_graph[init].has_linked(i)) // �ϴ� ����� ��� �� ť�� �ִ´�.
		{
			prt_wait.push(i);
		}
	}

	while (prt_wait.empty() != true) //ť�� �� ������ �ݺ��Ѵ�.
	{
		for (int i = 1; i < BFS_graph.size(); i++)
		{
			if (BFS_graph[prt_wait.front()].has_linked(i)) // �ϴ� ����� ��� �� ť�� �ִ´�.
			{
				if (BFS_graph[i].has_visited() == false) // �湮���� ���� ����ΰ�?
				{
					prt_wait.push(i);
				}
				
			}
		}

		if (BFS_graph[prt_wait.front()].has_visited() == false)
		{
			BFS_graph[prt_wait.front()].set_visit(); // �湮�ߴٰ� ����Ѵ�.
			cout << BFS_graph[prt_wait.front()].get_vertex_number() << " "; // ���� ���
		}
		prt_wait.pop(); // �����Ѵ�.
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; int M; int init; // ���� ��, ���� ��, ������
	cin >> N >> M >> init;

	vector<vertex> DFS_graph; // �������� ������ ����
	vector<vertex> BFS_graph; 

	for (int i = 0; i <= N; i++)
	{
		vertex a(i, N);
		DFS_graph.push_back(a); // ������ ���Ϳ� ����Ѵ�.
		BFS_graph.push_back(a);
	}

	for (int i = 0; i < M; i++) // ���� �� ���� ����
	{
		int a, b;
		cin >> a >> b;
		DFS_graph[a].linker(b); DFS_graph[b].linker(a);
		BFS_graph[a].linker(b); BFS_graph[b].linker(a);
	}

	// DFS ���
	DFS(init, DFS_graph);

	cout << '\n';

	// BFS ���
	BFS(init, BFS_graph);

	return 0;
}