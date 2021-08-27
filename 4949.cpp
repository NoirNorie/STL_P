#include <iostream>
#include <stack>
#include <string>

using namespace std;

// ������ȣ: 4949(�������� ����)

int main()
{
	string str;
	while(1)
	{	
		int chk = 0;
		stack<char> input; // �˻�� ���� ����

		getline(cin, str, '\n');

		if (str == ".") // Ż�� ����
			break;

		for (int i = 0; i < str.length(); i++)
		{
			if (str.at(i) == '.') break; // . ������ ����

			if (str.at(i) == '(') // ���� �Ұ�ȣ���
			{
				input.push('('); // ���ÿ� �ִ´�.
			}
			else if (str.at(i) == '[') // ���� ���ȣ���
			{
				input.push('['); // �̰͵� ���ÿ� �ִ´�.
			}
			else // ���� ���� �ݴ� �Ϲ� ���� �Ǵ� �ݴ� �Ұ�ȣ, ���ȣ
			{
				if (str.at(i) == ']') // �ݴ� ���ȣ�� ���
				{
					if (input.empty() == 1) // ������ ��������� ���ǿ� ���� �ʴ�.
					{
						chk = 1; // �÷��� ������ üũ
						break;
					}
					else if (input.top() == '(') // ������ ���� �ʾ����� ¦�� ���� �ʴ´ٸ� ���ǿ� ���� ����
					{
						chk = 1;
						break;
					}
					else // ������ ���� ���ǿ� �����Ƿ� ���ȣ �ϳ��� pop ��
					{
						input.pop(); 
					}
				}
				else if (str.at(i) == ')') // �ݴ� �Ұ�ȣ�� ���
				{
					if (input.empty() == 1) // ������ ��������� ���ǿ� ���� �ʴ�.
					{
						chk = 1; // �÷��� ������ üũ
						break;
					}
					else if (input.top() == '[') // ������ ���� �ʾ����� ¦�� ���� �ʴ´ٸ� ���ǿ� ���� ����
					{
						chk = 1;
						break;
					}
					else // ������ ���� ���ǿ� �����Ƿ� ���ȣ �ϳ��� pop ��
					{
						input.pop();
					}
				}

			}
		}

		if (chk == 1 || input.empty() == 0) // �÷��װ� ���Ͽ��ų� ������ ������� ������ ���ǿ� ���� ����
		{
			cout << "no" << endl;
		}
		else
		{
			cout << "yes" << endl;
		}

	} 
	// while (str != ".");

	return 0;
}