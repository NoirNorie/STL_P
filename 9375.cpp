#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 문제 번호: 9375(패션왕 신해빈)
// 수형도를 그리니까 편하게 풀렸다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	

	for (int i = 0; i < T; i++)
	{
		int n; cin >> n;
		vector<pair<string, int>> part; // 종류와 의상 숫자 순서쌍을 담을 벡터

		for (int j = 0; j < n; j++)
		{
			bool chk = true;
			string name, tp;
			cin >> name >> tp;

			for (int p = 0; p < part.size(); p++)
			{
				if (tp == part[p].first) // 같은 종류가 존재한다면
				{
					part[p].second++; // 의상 수만 추가해준다.
					chk = false; // 같은 종류가 존재했다는 사실을 기록할 플래그
					break;
				}	
			}

			if (chk) // 같은 종류의 옷이 존재하지 않았다면
			{
				part.push_back(make_pair(tp, 1)); // 자신의 종류와 1로 순서쌍을 만들어 벡터에 담는다.
			}
		}
		
		int sum = 1;
		for (int k = 0; k < part.size(); k++)
		{
			sum *= (part[k].second + 1); // 분류한 모든 의상 종류의 수 + 1(벗는 경우 포함)를 곱해준다.
		}
		cout << sum - 1 << '\n';
		// 벗는 경우가 모든 의상 종류에 포함되게 된다.
		// 다 벗는 경우가 하나 발생하게 되므로 -1을 해줘 문제의 조건에 맞춘다.
	}

	return 0;
}
