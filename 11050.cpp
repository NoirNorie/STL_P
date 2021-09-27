#include <iostream>
using namespace std;

// 문제 번호: 11050(이항 계수 1)
// 팩토리얼로 풀 수 있어서 팩토리얼로 품
// 점화식을 사용하면 더 빠르게 풀 수 있을 것임

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
