#include <iostream>
#include <vector>
using namespace std;

// 문제 번호: 1904(01타일)


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> v(1000001, 0);
	v[1] = 1; v[2] = 2;

	int N; cin >> N;

	for (int i = 3; i <= N; i++)
	{
		v[i] = v[i - 1] + v[i - 2];
		v[i] %= 15746;
	}

	cout << v[N] << '\n';

	return 0;
}