#include <iostream>
#include <deque>
#include <string>
using namespace std;

// ���� ��ȣ: 10757(ū �� A+B)

int main()
{
	string A, B;
	cin >> A >> B; // �̳� �� ���̹Ƿ� string ������ �޴´�.

	deque<int> mid;

	int Ai = A.length() -1, Bi = B.length() -1; // �� ���ڿ��� �� �ڸ� ����Ų��.
	int tmp = 0;
	int up = 0; // ���ʿ� �ø� ���� ����

	while (Ai > -1 && Bi > -1)
	{
		tmp = (int)(A[Ai] - 48) + (int)(B[Bi] - 48) + up;
		
		mid.push_front(tmp % 10);

		// �ø� ���� �ִ� �����
		if (tmp >= 10) up = 1;
		else up = 0;

		Ai--; Bi--;
	}

	if (Ai > -1)
	{
		while (Ai > -1)
		{

			tmp = (A[Ai] - 48) + up;
			mid.push_front(tmp % 10);

			// �ø� ���� �ִ� �����
			if (tmp >= 10) up = 1;
			else up = 0;

			Ai--;		
		}
	}

	if (Bi > -1) 
	{
		while (Bi > -1)
		{
			tmp = (B[Bi] - 48) + up;
			mid.push_front(tmp % 10);

			// �ø� ���� �ִ� �����
			if (tmp >= 10) up = 1;
			else up = 0;

			Bi--;
		}
	}
	
	if(up == 1) // ������ ������ �ߴµ� �ø����� �ִ� ���
	{
		mid.push_front(1); // �ڸ��� �ϳ��� �߰��Ѵ�.
	}
	
	while (mid.empty() != 1)
	{
		cout << mid.front();
		mid.pop_front();
	}

	return 0;
}