#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 문제 번호: 9020(골드바흐의 추측)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, n;
	int flag, chk;


	vector<int> v; // 소수를 담을 벡터
	// 검사
	int max = sqrt(10000); // 가능한 범위 내의 소수를 모두 찾아내 저장한다.

	for (int i = 2; i <= 10000; i++) // 1은 소수가 아니다.
	{
		flag = 0;
		chk = 2;

		while (chk <= max) // 소수 검사
		{
			if (i != chk && i % chk == 0) // 소수가 아니라면
			{
				flag = 1; // 판별 변수를 체크한다.
				break; // 더 이상 검사할 필요 없음
			}
			chk++;
		}
		if (flag != 1) v.push_back(i); // 소수가 아니면 벡터에 집어넣는다.
	}

	cin >> T;
	pair<int, int> result; 
	for (int trial = 0; trial < T; trial++)
	{
		cin >> n; // 짝수 입력

		int index = 0;

		while (v[index] < n)
			index++;

		int min = 99999;
		for (int i = index; i >= 0; i--)
		{
			for (int j = index; j >= 0; j--)
			{
				if (v[i] + v[j] == n)
				{
					if (abs(v[i] - v[j]) < min) // 차이가 가장 작은가?
					{
						result.first = v[j];
						result.second = v[i];
						min = v[i] - v[j];
					}
				}
			}
		}
		cout << result.first << " " << result.second << '\n';
	}

	return 0;
}