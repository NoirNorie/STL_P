#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ��ȣ: 10816(���� ī�� 2)
// �̺� Ž�� �� ������ ������ ã�Ƴ��� ����
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

// STL �ذ��
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

	// upper_bound, lower_bound �Լ��� ��ȯ��
	// �迭�� ����� ��� �迭�� ������(int*)
	// ���͸� ����� ��� ������ �ݺ���(vector<int>::iterator)
	
	return 0;
}