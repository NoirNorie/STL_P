#include <iostream>
#include <set>
#include <map>
using namespace std;

// ���� ��ȣ: 11652(ī��)
// ��� ������ ���Դµ� �ڷ��� ũ�Ⱑ ��������


// map Ǯ��
int main()
{
	map<long long, long long> m;

	long long N; cin >> N; // ī�� ���� �Է�
	long long num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		auto e = m.find(num);
		if (e == m.end()) // ���ٸ�
			m[num] = 1;
		else // �����Ѵٸ�
			e->second++;
	}

	long long max = -1;
	long long card = -1;
	for (auto e : m) // ��Ե� �ѹ��� �����Ѵ�.
	{
		if (e.second > max) // ���� ū ���� ã�Ƴ��ٸ�
		{
			max = e.second;
			card = e.first;
		}
	}

	cout << card;

	return 0;
}

// set Ǯ�� -> �޸𸮰� �� ���� �Ҹ�ȴ�.
// �׷��ٰ� �ӵ��� ���� ���� �� �ƴϴ�.
// ����� ������ �ִٸ� map�� ����Ѵ�
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
		long long dist = distance(ms.lower_bound(e), ms.upper_bound(e)); // �Ÿ� ���� ���Ѵ�
		if (dist > max)
		{
			max = dist;
			card = e;
		}
	}

	cout << card;
}