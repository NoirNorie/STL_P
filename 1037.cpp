#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ��ȣ: 1037(���)

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