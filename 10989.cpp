#include <iostream>
using namespace std;

// ���� ��ȣ: 10989(�� �����ϱ� 3)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int Array[10001] = { 0 }; // ���� �迭 ���� �� �ʱ�ȭ

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
	//	if (x > max) max = x; // ���� ū �� ������ �ݺ��ϵ��� üũ�س��´�.
	//}

	//for (int i = 1; i <= max; i++)
	//{
	//	int cnt = 0;
	//	for (int j = 0; j < v.size(); j++) 
	//	{
	//		if (i == v[j]) cnt++;
	//	}
	//	cnt_V.push_back(make_pair(i, cnt)); // ���� ���ڸ� ã�� ���� ǥ���Ѵ�.
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