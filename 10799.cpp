#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string x; cin >> x; // ��ȣ ���� ���� ���ڿ�
	stack<char> st; // ����⸦ ����� ����

	int answer = 0; // ����� ���� ����� ����
	for (int i = 0; i < x.length(); i++)
	{
		if (i == 0)
		{
			st.push(x[i]);
			continue;
		}
		if (x[i - 1] == '(' && x[i] == ')') // ��ȣ���� �����ϸ� ������
		{
			st.pop(); // �������� ����Ⱑ �ƴϴ�.
			st.push('L'); // ��������� ����Ѵ�.
		}
		else
		{
			st.push(x[i]);
		}
		
	}

	int stick = 0;
	while (st.empty() != true) // ������ ����
	{
		if (st.top() == ')')
		{
			stick++; // �߸� ���� �߰�
		}
		else if (st.top() == '(')
		{
			answer++; // ���ٸ� �߰�
			stick--; // ����� �ϳ� ����
		}
		else // �������� ���
		{
			answer += stick; // �ڸ� �� �߰�
		}
		st.pop();
	}

	cout << answer << '\n';

	return 0;
}