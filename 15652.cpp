#include <iostream>
#include <vector>
using namespace std;

// ���� ��ȣ: 15652(N�� M 3)
// �񳻸����� ��Ʈ��ŷ

int N; // �ڿ����� ����
int M; // ������ ����

vector<bool> used(10, false);
vector<int> v(10);

void BT(int k)
{
	if (k == M) // ������ ���̿� ����������
	{
		for (int i = 0; i < M; i++)
		{
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		// �ߺ� ��� ��Ʈ��ŷ
		if (k > 0)
		{
			v[k] = i;
			if (v[k - 1] <= v[k]) // ���� ���ں��� ũ�ų� ���ƾ� �Ѵ�.
			{
				BT(k + 1);
			}
		}
		else // ���� 1ȸ
		{
			v[k] = i;
			BT(k + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	BT(0);
	return 0;
}