#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ���� ��ȣ: 1152(�ܾ��� ����)

int main()
{
	string inp; getline(cin, inp);
	int cnt = 0;
	int num = 0;

	string::iterator ster = inp.begin(); // �ݺ����� ó���� �Է� ���ڿ��� ó���� ����Ų��.
	while (ster != inp.end())
	{
		if (*ster != ' ' || *ster == '\n') // ���� ���ڰ� �ƴϰ� ���⵵ �ƴϸ�
		{
			cnt++; // ���� ���� ������Ų��
		}
		else // ���⸦ ����ģ ���
		{
			if (cnt != 0) // �� ���ڶ� �־��°�?
			{
				num++; // �ܾ��� ������ ������Ų��
				cnt = 0; // ���� �� �ʱ�ȭ
			}
		}
		ster++; // �ݺ��� ����
		if (ster == inp.end() && cnt != 0) // �ݺ��ڰ� �������� �����ߴµ� ���� ���� ���� ���
		{
			num++; // ������ �ܾ �߰����ش�.
		}
	}

	cout << num << '\n';
}