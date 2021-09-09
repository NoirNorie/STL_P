#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 문제 번호: 10814(나이 순 정렬)

bool comp_year(const pair<int, string>& a, const pair<int, string>& b)
{
	if (a.first < b.first) return true; // 나이는 정렬에 관계 없는 변수
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