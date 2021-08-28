#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

// ������ȣ: 11866(�似Ǫ�� ���� 0)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; // ��� ��, ���ŵ� ��ȣ
	cin >> N >> K;

	queue<int> qu; // ť ����
	vector<int> vc; // ������ ����� ���� ����

	for (int i = 1; i <= N; i++) qu.push(i);
	// ť�� ��� ����ŭ ���ڸ� ����ִ´�.

	while (qu.empty() != 1) // ť�� ����� �������� ���� �ݺ��Ѵ�.
	{
		for (int j = 1; j < K; j++)
		{
			int tmp = qu.front(); // �� ���� ���ڸ� ���
			qu.pop(); // ���ڸ� ���ٰ�
			qu.push(tmp); // �ٽ� ����ִ´�.
		} // �̰� K - 1ȸ �ݺ��Ѵ�.
		
		vc.push_back(qu.front()); // K��° ���ڴ� ������ ����Ѵ�.
		qu.pop(); // �׸��� ������.
	}

	vector<int>::iterator iter;
	cout << "<";
	for (iter = vc.begin(); iter < vc.end() - 1; iter++)
	{
		cout << *iter <<", ";
	}
	cout << *iter << ">";

	return 0;
}