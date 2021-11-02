#include <iostream>
#include <vector>
using namespace std;

// ���� ��ȣ: 15650(N�� M 2)

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
		if (used[i] == false) // ���� �� ���ٸ�
		{
			used[i] = true; // ����ߴٰ� ǥ���Ѵ�.
			v[k] = i;
			if (k > 0) // ���� ��Ż ����
			{
				if (v[k - 1] < v[k]) // 
				{
					BT(k + 1);
				}
			}
			else // �ϴ� �ѹ��� ��������.
			{
				BT(k + 1);
			}
			used[i] = false; // ��� �Ϸ� ǥ��
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