#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ��ȣ: 18870(��ǥ ����)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<int> v(N); // �Է��� ���� ����
	vector<int> result(N); // ��� ��¿� ����� ����

	// �Է�
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

// �ð� �ʰ�
//vector<int> tmp; // ���� ����
//tmp.assign(v.begin(), v.end()); // ���� �Űܿ´�.
//sort(tmp.begin(), tmp.end()); // �����Ѵ�.
//tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end()); // �ߺ��� ���� �����.
//
//// ���
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