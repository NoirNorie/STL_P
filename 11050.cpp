#include <iostream>
using namespace std;

// ���� ��ȣ: 11050(���� ��� 1)

inline int facto(int x)
{
	if (x == 0 || x == 1) return 1;
	else return x * facto(x - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	int K; cin >> K;

	cout << facto(N) / (facto(K) * facto(N - K)) << '\n';
	
	return 0;
}