// 1049: 기타줄

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;

	vector<int> pack(k, 0), single(k, 0);
	for (size_t i = 0; i < pack.size(); i++) cin >> pack[i] >> single[i];

	sort(pack.begin(), pack.end());
	sort(single.begin(), single.end());

	int fs = single[0] * n;								// 전부 낱개로 사기
	int comp = pack[0] * (n / 6) + single[0] * (n % 6);	// 섞어서 사기
	int fc = pack[0] * ((n / 6) + 1);					// 전부 묶음으로 사기

	int answer = min(fs, min(comp,fc));
	cout << answer << '\n';
}
