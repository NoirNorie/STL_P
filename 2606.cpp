#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool status[101][101]; // ���� ���¸� ǥ���� ����
bool visited[101]; // �湮 ���θ� ǥ���� ����
stack<int> s;

int main()
{
	int n, m;

	cin >> n; // ��ǻ���� ��
	cin >> m; // ��ũ�� ��

	// ���� ���� ��ǻ�͵��� ���¸� �ʱ�ȭ���ش�.
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			status[i][j] = false;
		}
		visited[i] = false;
	}
	
	for (int i = 0; i < m; i++) // ���� ����
	{
		int linker, linked;
		cin >> linker >> linked;

		// ����Ǿ��ٰ� ǥ�����ش�.
		status[linker][linked] = true;
		status[linked][linker] = true;
	}

	int nums = 0; 
	s.push(1); // 1�� ��ǻ�ͷ� �����Ǵ� ��ǻ�� ���� ����ϹǷ�
	visited[1] = true; // 1������ �����ϹǷ� 1���� �湮��
	while (s.empty() != true)
	{
		int current = s.top(); s.pop();
		for (int i = 1; i <= n; i++)
		{
			if (status[current][i] == true)
			{
				if (visited[i] == true) continue; // �湮�ߴٸ� �ǳʶڴ�.

				s.push(i);
				visited[i] = true;// �湮 ǥ��
				nums++;
			}
		}
	}

	cout << nums << '\n';


	return 0;
}