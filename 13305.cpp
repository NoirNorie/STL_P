#include <iostream>
#include <vector>
using namespace std;

// ���� ��ȣ: 13305(������)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N; // ������ ���� �Է�
	vector<long long int> road(N - 1, 0);// ������ ����
	vector<long long int> price(N, 0); // �⸧ ����
	
	long long int price_sum = 0;

	for (int i = 0; i < N-1; i++)
	{
		cin >> road[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> price[i];
	}

	// �ϴ� ���� �Ǿ��� ���� ���÷� �̵��� �⸧�� �־�� ��
	int p = 0; int move = 0;
	price_sum += road[p] * price[p];

	while ((++move) < N-1)
	{
		if (price[p] > price[move]) // ���� ���ú��� ���� ������ �⸧ ������ �� �Ѱ�?
		{
			// �⸧ ���� �� ������ �̵��Ѵ�.		
			p = move;
		}
		// ���� ������ �⸧ ������ �� �ΰų� ���ٸ�
		// ���� ���ÿ��� �⸧�� �� �߰��Ѵ�.
		price_sum += road[move] * price[p];
	}

	cout << price_sum << '\n';

	return 0;
}