#include <iostream>
#include <vector>
using namespace std;

// ���� ��ȣ: 1912 (������)


inline int MAX(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<int> v(N + 1, -1001); // �Է� �迭
	vector<int> calc(N + 1, -1001);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	calc[1] = v[1]; // �ϴ� ���� �ϳ��� ���� �ϹǷ� �����Ѵ�

	int Result = -1001;
	for (int i = 1; i <= N; i++)
	{
		calc[i] = MAX(v[i],calc[i-1] + v[i]);
		Result = MAX(Result, calc[i]);
	}

	cout << Result << '\n';

	return 0;
}

