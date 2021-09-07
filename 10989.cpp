#include <iostream>
using namespace std;

// 문제 번호: 10989(수 정렬하기 3)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int Array[10001] = { 0 }; // 공백 배열 선언 및 초기화

	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		Array[x]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < Array[i]; j++)
		{
			cout << i << '\n';
		}
	}


	//vector<int> v;
	//for (int i = 0; i < N; i++)
	//{
	//	int x; cin >> x;
	//	v.push_back(x);
	//	if (x > max) max = x; // 가장 큰 수 까지만 반복하도록 체크해놓는다.
	//}

	//for (int i = 1; i <= max; i++)
	//{
	//	int cnt = 0;
	//	for (int j = 0; j < v.size(); j++) 
	//	{
	//		if (i == v[j]) cnt++;
	//	}
	//	cnt_V.push_back(make_pair(i, cnt)); // 같은 숫자를 찾아 벡터 표기한다.
	//}

	//for (int i = 0; i < cnt_V.size(); i++)
	//{
	//	while (cnt_V[i].second-- != 0)
	//	{
	//		cout << cnt_V[i].first << '\n';
	//	}
	//}

	return 0;
}