#include <iostream>
#include <vector>
using namespace std;

// ���� ��ȣ: 7568(��ġ)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<pair<int, int>> v;
	pair<int, int> character;

	int N; cin >> N;
	int a, b;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		character.first = a;
		character.second = b;

		v.push_back(character);
	}

	vector<pair<int, int>>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		int num = 1;

		vector<pair<int, int>>::iterator srch;
		for (srch = v.begin(); srch != v.end(); srch++)
		{
			if (iter->first < srch->first && iter->second < srch->second) // ������ ��ġ���� ū ��ġ�� �ִٸ�
			{
				num++;
			}
		}
		cout << num << " ";
	}
	return 0;
}