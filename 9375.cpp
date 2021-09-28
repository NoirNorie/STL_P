#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ���� ��ȣ: 9375(�мǿ� ���غ�)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	

	for (int i = 0; i < T; i++)
	{
		int n; cin >> n;
		vector<pair<string, int>> part; // ������ �ǻ� ���� �������� ���� ����

		for (int j = 0; j < n; j++)
		{
			bool chk = true;
			string name, tp;
			cin >> name >> tp;

			for (int p = 0; p < part.size(); p++)
			{
				if (tp == part[p].first) // ���� ������ �����Ѵٸ�
				{
					part[p].second++; // �ǻ� ���� �߰����ش�.
					chk = false; // ���� ������ �����ߴٴ� ����� ����� �÷���
					break;
				}	
			}

			if (chk) // ���� ������ ���� �������� �ʾҴٸ�
			{
				part.push_back(make_pair(tp, 1)); // �ڽ��� ������ 1�� �������� ����� ���Ϳ� ��´�.
			}
		}
		
		int sum = 1;
		for (int k = 0; k < part.size(); k++)
		{
			sum *= (part[k].second + 1);
		}
		cout << sum - 1 << '\n'; // �� ���� ��츦 �����ϱ� ���ؼ� -1
	}

	return 0;
}