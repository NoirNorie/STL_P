#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 문제 번호: 10816(숫자 카드 2)
// 이분 탐색 중 원소의 개수를 찾아내는 문제
// 

//vector<int> v;
//int L_bound(int num)
//{
//	int left = 0;  int right = v.size();
//	int mid;
//
//	while (left < right)
//	{
//		int mid = (left + right) / 2;
//		if (v[mid] > num) right = mid;
//		else left = mid + 1;
//	}
//	return left;
//
//}
//
//int R_bound(int num)
//{
//	int left = 0; int right = v.size();
//
//	while (left < right)
//	{
//		int mid = (left + right) / 2;
//		if (v[mid] >= num) right = mid;
//		else left = mid + 1;
//	}
//	return left;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	int N; cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		int card; cin >> card;
//		v.push_back(card);
//	}
//
//	sort(v.begin(), v.end());
//
//	int M; cin >> M;
//	for (int i = 0; i < M; i++)
//	{
//		int num; cin >> num;
//		cout << L_bound(num) - R_bound(num) << " ";
//	}
//
//	return 0;
//}

// STL 해결법
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> v;
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int card; cin >> card;
		v.push_back(card);
	}

	sort(v.begin(), v.end());

	int M; cin >> M;
	vector<int>::iterator right, left;
	for (int i = 0; i < M; i++)
	{
		int num; cin >> num;
		right = upper_bound(v.begin(), v.end(), num);
		left = lower_bound(v.begin(), v.end(), num);
		cout << right - left << " ";
	}

	// upper_bound, lower_bound 함수의 반환값
	// 배열을 사용한 경우 배열의 포인터(int*)
	// 벡터를 사용한 경우 벡터의 반복자(vector<int>::iterator)
	
	return 0;
}