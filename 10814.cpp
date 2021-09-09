#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ��ȣ: 10814(���� �� ����)

bool comp_year(const pair<int, string>& a, const pair<int, string>& b)
{
	if (a.first < b.first) return true; // ���̴� ���Ŀ� ���� ���� ����
	else return false;
}

int main()
{
	int year; string name;
	vector<pair<int, string>> v;

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> year >> name;
		v.push_back(make_pair(year, name));
	}

	stable_sort(v.begin(), v.end(), comp_year);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " " << v[i].second << '\n';
	}

	return 0;
}