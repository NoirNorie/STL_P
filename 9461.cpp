#include <iostream>
#include <vector>
using namespace std;

// 문제 번호: 9461(파도반 수열)

vector<long long int> v(101, 0);
// N이 100 이면 값이 888,855,064,897이 나온다.
// int의 범위를 벗어나므로 long long int를 사용함

void Calc()
{
	v[1] = 1; v[2] = 1; v[3] = 1;
	v[4] = 2; v[5] = 2;

	for (int i = 6; i <= 100; i++)
	{
		v[i] = v[i - 1] + v[i - 5];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Calc();
	
	int T; cin >> T;

	for (int x = 0; x < T; x++)
	{
		int N; cin >> N;

		cout << v[N] << '\n';
	}
	return 0;
}