#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 문제 번호: 10818 (최소, 최대)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	cout << v[0] << " " << v[n-1] << '\n';
	return 0;
}