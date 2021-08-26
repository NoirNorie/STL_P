#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		string st;
		stack<char> input;
		int chk = 0;

		cin >> st;

		for (int j = 0; j < st.length(); j++)
		{
			if (st.at(j) == '(') // ���� ��ȣ���
			{
				input.push('(');
			}
			else // �ݴ� ��ȣ���
			{
				if (input.empty() == 1) // �ݴ� ��ȣ�ε� ������ �� == ����
				{
					chk = 1;
					break;
				}
				else // ������ ���� ���� ���¶�� ( ��ȣ �ϳ��� Pop ��
				{
					input.pop();
				}
			}
		}

		if (chk == 1 || input.empty() == 0)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
}