#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ��ȣ: 1931(ȸ�ǽ� ����)

bool cmp(pair<int, int> v1, pair<int, int> v2) // Ŀ���� �� �Լ�
{
	if (v1.second < v2.second) // ���� �ð��� ª�� ���� ���� ������ �Ѵ�.
		return true;
	else if (v1.second == v2.second) // ���� �ð��� ���ٸ�
	{
		if (v1.first <= v2.first)
			return true;
		else
			return false;
	}
	else return false;
}

int main()
{
	int N; cin >> N;
	int cnt = 1;
	int end;
	
	vector<pair<int, int>> v(N + 1, make_pair(0, 0));

	for (int i = 1; i <= N; i++) // ���� �ð��� �� �ð��� �Է¹޴´�.
	{
		cin >> v[i].first >> v[i].second;
		
	}

	sort(v.begin(), v.end(), cmp); // ���� ������ ������ �����Ѵ�.

	end = v[1].second; // ���� ���� ������ ���� ����Ѵ�.
	for (int i = 2; i <= N; i++)
	{
		if (v[i].first >= end) // ���� �ð��� ��ġ�� ������
		{
			end = v[i].second;
			cnt++;
		}
	}
	cout << cnt << '\n';


	return 0;
}