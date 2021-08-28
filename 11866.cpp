#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

// 문제번호: 11866(요세푸스 문제 0)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K; // 사람 수, 제거될 번호
	cin >> N >> K;

	queue<int> qu; // 큐 생성
	vector<int> vc; // 순열을 기록할 벡터 생성

	for (int i = 1; i <= N; i++) qu.push(i);
	// 큐에 사람 수만큼 숫자를 집어넣는다.

	while (qu.empty() != 1) // 큐에 사람이 없어질때 까지 반복한다.
	{
		for (int j = 1; j < K; j++)
		{
			int tmp = qu.front(); // 맨 앞의 숫자를 기록
			qu.pop(); // 숫자를 뺐다가
			qu.push(tmp); // 다시 집어넣는다.
		} // 이걸 K - 1회 반복한다.
		
		vc.push_back(qu.front()); // K번째 숫자는 순열에 기록한다.
		qu.pop(); // 그리고 날린다.
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