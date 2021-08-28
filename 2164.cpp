#include <iostream>
#include <deque>
#include <queue>
using namespace std;

// ������ȣ: 2164(ī��)

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	queue<int> q;

	int N;
	cin >> N; // N���� ī��


	for (int i = 1; i <= N; i++)
		q.push(i);

	while (q.size() != 1) // ���常 �����.
	{
		q.pop(); // �� ���� ������ ������.
		int tmp = q.front(); // ���� ī�带 �����ϰ�
		q.pop();// ������
		q.push(tmp); // ������ ī�带 �� �Ʒ� �ִ´�.
	}

	cout << q.front() << '\n';


	return 0;
}