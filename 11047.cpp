#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int K; cin >> K;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int chk = N - 1;
	int cnt = 0;
	while (K != 0)
	{
		if (v[chk] > K)
		{
			chk--;
		}
		else
		{
			K -= v[chk];
			cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;
}