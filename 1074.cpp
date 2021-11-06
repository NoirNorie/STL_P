#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 문제 번호: 1074(Z)
// 정답은 나오지만 메모리 초과로 통과하지 못함

vector<vector<int>> v;
int nums = 0;

void func(int s, int i, int j)
{
	if (s == 2) // 기저 상태에 도달한 경우
	{
		v[i][j] = nums++;
		v[i][j+1] = nums++;
		v[i+1][j] = nums++;
		v[i + 1][j + 1] = nums++;
		return; // 번호를 입력하고 반환
	}
	else
	{
		int ns = s / 2; // 다음 크기
		func(ns, i, j);
		func(ns, i , j + ns);
		func(ns, i + ns, j );
		func(ns, i + ns, j + ns);
	}
}



int main()
{
	int n, r, c;
	cin >> n >> r >> c;
	int s = pow(2, n);

	v.assign(s, vector<int>(s, 0));
	func(s, 0, 0);

	cout << v[r][c] << '\n';

	return 0;
}