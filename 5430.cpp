#include <iostream>
#include <string>
#include <deque>
using namespace std;

// ���� ��ȣ: 5430(AC)
// deque�� �̿��ؼ� ��¸� �׷����ϰ� �ٲٴ� �����̴�.
// ������ �ٲ�°� pop, front, back �ۿ� ����.

int main()
{
	int T; cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		string cmd; cin >> cmd;
		bool cmd_state = true; // true�� ��� ������, false�� ��� ������
		bool error_chk = false; // ���� �� ���¿��� D ������ �����Ѵٸ� ������ ����ϵ��� �Ѵ�.

		int arr_size; cin >> arr_size;
		
		deque<int> dq; // �� �ʱ�ȭ �� ����
		
		// �迭 ũ�Ⱑ 1�̻��̸� ���� ������ �ش�.
		if (arr_size > 0)
		{
			string arr = "";
			getline(cin, arr, '['); // �귡Ŷ ���� ����
			for (int j = 0; j < arr_size - 1; j++)
			{
				getline(cin, arr, ',');
				dq.push_back(stoi(arr)); // ���ڿ��� ���ڷ� ��ȯ�Ͽ� ���� ����ִ´�.
			}
			getline(cin, arr, ']'); // �귡Ŷ ����
			dq.push_back(stoi(arr));
		}
		else // �迭 ũ�� 0�� ���� ����ó��
		{
			string arr;
			cin >> arr;
			// �극Ŷ ���� �Է¹޴� �κ��̴�.
			// ���� ������ ���� �ʴ´�.
			// ������ ����� ������ ä�������� ó���Ѵ�.
		}
		
		for (int j = 0; j < cmd.length(); j++)
		{
			if (cmd[j] == 'R')
			{
				// ���¸� �������ش�.
				if (cmd_state == true) // �������̸�
				{
					cmd_state = false; // ����������
				}
				else // �������̸�
				{
					cmd_state = true; // ����������
				}
			}
			else // ����� 2���� �ִٰ� �����Ѵ�.
			{
				// ���� ������ ��� �ߴܽ�Ű�� üũ���ش�.
				if (dq.size() == 0)
				{
					error_chk = true;
					break;
				}

				// ���¿� ���� �ٸ��� �����Ѵ�.
				if (cmd_state == true) // �������� ���
				{
					dq.pop_front(); // �տ��� ����
				}
				else // �������� ���
				{
					dq.pop_back(); // �ڿ��� ����
				}
			}
		}

		// ��º�
		if (error_chk == true) // D�� �迭 ũ�⺸�� ���� ���� ���
		{
			cout << "error" << '\n';
		}
		else // ���ǿ� �� �����ϰų� �迭 ũ�Ⱑ 0�̾��� ���
		{
			cout << "["; // �ϴ� �극Ŷ�� ����

			if (dq.size() == 0) // ũ�Ⱑ 0������ ���� ������ ��� ó��
			{
				cout << "]" << '\n'; // �귡Ŷ�� �ݰ�
				continue; // ���� ������ �����Ѵ�.
			}
			else if (cmd_state == true) // �������� ���
			{
				while (dq.size() > 1)
				{
					cout << dq.front() << ",";
					dq.pop_front();
				}
				cout << dq.front(); // ������ ���ڴ� ,�� �ȵ��Ƿ� ���� ó���Ѵ�.
				dq.pop_front();
			}
			else // ������ ���
			{
				while (dq.size() > 1)
				{
					cout << dq.back() << ",";
					dq.pop_back();
				}
				cout << dq.back();
				dq.pop_back();
			}	
			cout << "]" << '\n';
		}
	}
	return 0;
}
