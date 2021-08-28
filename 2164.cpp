#include <iostream>
#include <deque>
#include <queue>
using namespace std;

// 문제번호: 2164(카드)

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	queue<int> q;

	int N;
	cin >> N; // N장의 카드


	for (int i = 1; i <= N; i++)
		q.push(i);

	while (q.size() != 1) // 한장만 남긴다.
	{
		q.pop(); // 맨 위의 한장을 버린다.
		int tmp = q.front(); // 다음 카드를 저장하고
		q.pop();// 버린다
		q.push(tmp); // 저장한 카드를 맨 아래 넣는다.
	}

	cout << q.front() << '\n';


	return 0;
}