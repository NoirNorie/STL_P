#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// ���� ��ȣ: 1427(��Ʈ�λ��̵�)

int main()
{
	string N; cin >> N;
	vector<int> v;
	// 0 �� �ƽ�Ű �ڵ�� 48

	for (int i = 0; i < N.length(); i++)
	{
		v.push_back(N[i] - 48);
	}
	sort(v.begin(), v.end(), greater<>());

	for (int i = 0 ; i < v.size(); i++)
	{
		cout << v[i];
	}

	return 0;
}