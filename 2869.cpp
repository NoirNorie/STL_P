#include <iostream>
using namespace std;

// ������ȣ: 2869(�����̴� �ö󰡰� �ʹ�)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long A, B, V;
	cin >> A >> B >> V;


	// �ݺ������ε� �����ѵ�
	// �ð��� �ʹ� ���� �ɸ���.
	/*
	long long move = A - B;
	long long clim = A;
	long long day = 1;
	
	while (clim < V)
	{
		clim += move;
		day++;
	}
	*/

	if ((V-B) % (A - B) == 0) // �Ϸ縸�� �ö󰡸� �������� �ʴ´�.
	{
		cout << (V - B) / (A - B) << '\n';
	}
	else
	{
		cout << ((V - B) / (A - B)) + 1 << '\n';
	}
}