#include <iostream>
#include <set>
#include <map>
using namespace std;

// 문제 번호: 11652(카드)
// 계속 오답이 나왔는데 자료형 크기가 문제였음


// map 풀이
int main()
{
	map<long long, long long> m;

	long long N; cin >> N; // 카드 개수 입력
	long long num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		auto e = m.find(num);
		if (e == m.end()) // 없다면
			m[num] = 1;
		else // 존재한다면
			e->second++;
	}

	long long max = -1;
	long long card = -1;
	for (auto e : m) // 어떻게든 한번은 동작한다.
	{
		if (e.second > max) // 가장 큰 값을 찾아낸다면
		{
			max = e.second;
			card = e.first;
		}
	}

	cout << card;

	return 0;
}

// set 풀이 -> 메모리가 더 많이 소모된다.
// 그렇다고 속도가 빠른 것은 또 아니다.
// 비슷한 문제가 있다면 map을 사용한다
int main()
{
	multiset<long long> ms;
	set<long long> s;

	long long n, num; cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		s.insert(num);
		ms.insert(num);
	}

	long long max = -1;
	long long card;

	for (auto e : s)
	{
		long long dist = distance(ms.lower_bound(e), ms.upper_bound(e)); // 거리 차를 구한다
		if (dist > max)
		{
			max = dist;
			card = e;
		}
	}

	cout << card;
}