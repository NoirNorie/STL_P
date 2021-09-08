#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 문제 번호: 11651(좌표 정렬하기 2)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<pair<int, int>> v;

	for (int i = 0 ; i <N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(y, x));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		cout << v[i].second << " " << v[i].first << '\n';
	}

	return 0;
}
