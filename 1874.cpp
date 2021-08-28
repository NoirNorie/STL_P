#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ������ȣ: 1874(���� ����)

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// c++ ǥ�� ������� cin, cout �ӵ��� ������ �ϱ� ���� ���
	// �߰��� endl ��� '\n'�� ����ϴ� ���� ����ȴٰ� �Ѵ�.

	stack<int> sq; // ������ ���� ����
	vector<char> chr; // ��ȣ�� ��� ����� ����
	
	int T, IN; // �õ� Ƚ��, �Է� ����
	int chk, flag = 0; // üũ, �÷���(0 = ����, -1 = ����)


	cin >> T; // �Է�
	int i = 1, t = 0; // �ε��� ����, ���� �Է� Ƚ�� ����
	while (t != T && flag != -1)
	{
		cin >> IN; // ���� �Է�
		t++; // �õ� �� ����
		
		if (i <= IN) // CASE 1
		{
			for (;i <= IN;++i)
			{
				sq.push(i); // ���ڸ� ���ÿ� �״´�.
				chr.push_back('+'); // push �õ� ���
			}
			sq.pop(); // ������ ���ڸ� ���ÿ��� ����
			chr.push_back('-'); // pop �õ� ���
		}
		else // CASE 2
		{
			if (sq.empty() == 1) // ������ ������� ����
			{
				flag = -1;
				break; // �÷��׸� ������ ��ȯ�ϰ� �ݺ� ����
			}
			for (int j = sq.size() ; j > 0 ; j--) // ������ �����Ѵ�.
			{
				if (sq.empty() == 1) // ������ ������� ����
				{
					flag = -1;
					break; // �÷��׸� ������ ��ȯ�ϰ� �ݺ� ����
				}
				else // ���ÿ� ���� �ִ�.
				{
					if (sq.top() == IN) // ������ ���� ���� ���ڰ� �Է°� ���ٸ�
					{
						sq.pop(); // ������ ���ڸ� ���ÿ��� ����
						chr.push_back('-'); // pop �õ� ���
						break; // ���� �������� �����Ѵ�.
					}
					else
					{
						sq.pop(); // ������ ���ڸ� ���ÿ��� ����
						chr.push_back('-'); // pop �õ� ���
					}
				}
			}
		}
	}

	if (flag == -1 || sq.empty() != 1)
	{
		cout << "NO" << '\n';
	}
	else
	{
		vector<char>::iterator iter;
		for (iter = chr.begin(); iter != chr.end(); iter++)
		{
			cout << *iter << '\n';
		}
	}

	return 0;
}