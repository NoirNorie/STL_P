#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 문제 번호: 1037(약수)

int main()
{
	int N; cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	cout << v[0] * v[v.size() - 1] << '\n';

	return 0;
}