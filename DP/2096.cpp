// 2096: 내려가기
// 메모리로 인해 벡터를 쓸 수 없다

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int map[100000][3];
int maxd[2][3];
int mind[2][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) cin >> map[i][j];

	mind[0][0] = maxd[0][0] = map[0][0];
	mind[0][1] = maxd[0][1] = map[0][1];
	mind[0][2] = maxd[0][2] = map[0][2];

	for (int i = 1; i < n; i++)
	{
		maxd[1][0] = map[i][0] + max(maxd[0][0], maxd[0][1]);
		maxd[1][1] = map[i][1] + max(max(maxd[0][1], maxd[0][2]), maxd[0][0]);
		maxd[1][2] = map[i][2] + max(maxd[0][1], maxd[0][2]);

		maxd[0][0] = maxd[1][0];
		maxd[0][1] = maxd[1][1];
		maxd[0][2] = maxd[1][2];

		mind[1][0] = map[i][0] + min(mind[0][0], mind[0][1]);
		mind[1][1] = map[i][1] + min(min(mind[0][1], mind[0][2]), mind[0][0]);
		mind[1][2] = map[i][2] + min(mind[0][1], mind[0][2]);

		mind[0][0] = mind[1][0];
		mind[0][1] = mind[1][1];
		mind[0][2] = mind[1][2];
	}

	int mn = min(min(mind[0][1], mind[0][2]), mind[0][0]);
	int mx = max(max(maxd[0][1], maxd[0][2]), maxd[0][0]);

	cout << mx << " " << mn << '\n';

}
