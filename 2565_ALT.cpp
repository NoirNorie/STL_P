#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	vector<pair<int, int>> v(N + 1, make_pair(0, 0));

	vector<pair<int, int>> Front(N + 1, make_pair(0, 0));
	vector<pair<int, int>> Rear(N + 1, make_pair(0, 0));

	

	for (int i = 1; i <= N; i++) // ���� ���� �Է� �޴´�.
	{
		cin >> v[i].first >> v[i].second;
	}

	// ���� �˻�
	int Fsub = 0;
	for (int i = 1; i <= N; i++) // �տ��� �ڷ�
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (v[i].first < v[j].first && v[i].second > v[j].second)
			{
				Rear[i].first++; // �ڽź��� �Ʒ��� ��ġ�� ���� ���� �ڽŰ� ������ ��� ī��Ʈ�� ������Ų��.
			}
		}
		if (Rear[i].first > 0) Fsub++;

		Rear[i].second = Fsub;
	}
	int Rsub = 0;
	for (int i = N; i >= 0; i--) // �ڿ��� ������
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (v[i].first < v[j].first && v[i].second > v[j].second)
			{
				Front[i].first++; // �ڽź��� ���� ��ġ�� ���� ���� �ڽŰ� ������ ��� ī��Ʈ�� ������Ų��.
			}
		}
		if (Front[i].first > 0) Rsub++;

		Front[i].second = Rsub;
	}

	int fcnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (Front[i].first - Rear[i-1].second > 0 || Rear[i].first - Front[i-1].second > 0) fcnt++;
	}

	cout << fcnt << '\n';
	

	return 0;
}