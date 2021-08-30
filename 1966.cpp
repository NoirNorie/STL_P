#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>
using namespace std;

// ������ȣ: 1966(������ ť)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc;
	int N, M; // ������ ����, ������ ������ ��ġ
	int p; // �߿䵵�� ����� ����
	queue<int> imp; // �߿䵵�� ����� ť
	vector<int> v;
	int vi = 0; // ������ �ε���
	int idx;
	int trial;

	cin >> tc;

	for (int i = 0; i < tc; i++) // �׽�Ʈ ���̽� �� ��ŭ �ݺ��Ѵ�.
	{
		cin >> N >> M;
		idx = M;
		trial = 0; vi = 0;

		for (int j = 0; j < N; j++) // ������ ������ŭ �ݺ��Ѵ�.
		{
			cin >> p;	
			imp.push(p); // �Է��� ���ڸ� �����Ѵ�.
			v.push_back(p); // ���� ���Ϳ��� ����ִ´�.
		}

		// ������������ �߿䵵�� ���Ϳ� �����Ѵ�.
		sort(v.begin(), v.end(), greater<int>());

		while (imp.empty() != 1) // ť�� �� ������ �ݺ��Ѵ�.
		{
			if (v[vi] == imp.front())
			{
				imp.pop(); // �켱���� ���Ϳ� ���� ��� ť���� �����Ѵ�.
				vi++;
				trial++; // ���� Ƚ�� ����
				if (idx == 0) break;
			}
			else
			{
				// �ƴ� ��� �� �� ���� �ڷ� �ű�� �����Ѵ�.
				imp.push(imp.front());
				imp.pop();
			}
			if (--idx < 0) idx = imp.size() - 1;
		}
		cout << trial << '\n';

		while (!imp.empty())
		{
			imp.pop();
		}
		v.clear();
	}
	return 0;
}