#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// 문제 번호: 18870(좌표 압축)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<int> v(N); // 입력을 받을 벡터
	vector<int> result(N); // 결과 출력에 사용할 벡터

	// 입력
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		result[i] = v[i];
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	

	for (int i = 0; i < result.size(); i++)
	{
		cout << lower_bound(v.begin(), v.end(), result[i]) - v.begin() << " ";
	}



	return 0;
}

// 시간 초과
//vector<int> tmp; // 계산용 벡터
//tmp.assign(v.begin(), v.end()); // 값을 옮겨온다.
//sort(tmp.begin(), tmp.end()); // 정렬한다.
//tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end()); // 중복된 값을 지운다.
//
//// 계산
//int index = 0;
//while (index < tmp.size())
//{
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (tmp[index] == v[i])
//		{
//			v[i] = index;
//		}
//	}
//	index++;
//}