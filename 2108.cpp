#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// 문제 번호: 2108(통계학)

void AVG(vector<int> v);
void FREQ(vector<int> v);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int avg = 0;

	AVG(v); // 산술 평균

	if (v.size() == 1) cout << v[0] << '\n';
	else cout << v[v.size() / 2] << '\n'; // 중앙값 출력
	
	FREQ(v);

	cout << v[v.size() - 1] - v[0] << '\n'; // 범위 출력

	return 0;
}


void AVG(vector<int> v)
{
	double avg = 0;

	for (int i = 0; i < v.size(); i++)
	{
		avg += v[i];
	}

	cout << fixed;
	cout.precision(0);
	cout << avg / v.size() << '\n';

}

void FREQ(vector<int> v)
{
	vector<int> cnt(8001, 0);

	int max = 0, chk = 0;
	int index;

	for (int i = 0; i < v.size(); i++)
	{
		cnt[4000 + v[i]]++;

		if (cnt[4000 + v[i]] > max) max = cnt[4000 + v[i]];
	}

	for (int i = 0; i < 8001; i++)
	{
		if (cnt[i] == 0) continue;

		if (cnt[i] == max)
		{
			if (chk == 0)
			{
				index = i;
				chk++;
			}
			else if (chk == 1)
			{
				index = i;
				break;
			}
		}
	}

	

	cout << index - 4000 << '\n';

}