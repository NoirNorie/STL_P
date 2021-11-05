#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool status[101][101]; // 연결 상태를 표시할 벡터
bool visited[101]; // 방문 여부를 표시할 벡터
stack<int> s;

int main()
{
	int n, m;

	cin >> n; // 컴퓨터의 수
	cin >> m; // 링크의 수

	// 범위 내의 컴퓨터들의 상태를 초기화해준다.
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			status[i][j] = false;
		}
		visited[i] = false;
	}
	
	for (int i = 0; i < m; i++) // 연결 동작
	{
		int linker, linked;
		cin >> linker >> linked;

		// 연결되었다고 표시해준다.
		status[linker][linked] = true;
		status[linked][linker] = true;
	}

	int nums = 0; 
	s.push(1); // 1번 컴퓨터로 감염되는 컴퓨터 수를 출력하므로
	visited[1] = true; // 1번에서 시작하므로 1번은 방문함
	while (s.empty() != true)
	{
		int current = s.top(); s.pop();
		for (int i = 1; i <= n; i++)
		{
			if (status[current][i] == true)
			{
				if (visited[i] == true) continue; // 방문했다면 건너뛴다.

				s.push(i);
				visited[i] = true;// 방문 표시
				nums++;
			}
		}
	}

	cout << nums << '\n';


	return 0;
}