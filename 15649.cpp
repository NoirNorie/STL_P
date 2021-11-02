#include <iostream>
#include <vector>
using namespace std;

// ���� ��ȣ: 15649(N�� M)

int n; // �ڿ����� ����
int m; // ������ ����

vector<bool> used(10, false);
vector<int> v(10);

void BT(int k) // ��Ʈ��ŷ �Լ�
{
	if (k == m) // ������ �� ä�� ���
	{
		for (int i = 0; i < m; i++)
		{
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (used[i] == false) // �ش� ���ڰ� ������ ���� ���ڶ��
		{
			v[k] = i;
			used[i] = true; // ���Ǿ����� ǥ���Ѵ�
			BT(k + 1);
			used[i] = false; // ��� ����
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	BT(0);

	return 0;
}