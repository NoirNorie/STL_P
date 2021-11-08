#include <iostream>
#include <set>
using namespace std;

// ���� ��ȣ: 7662(���� �켱���� ť)
// ť���� ������ ��Ƽ������ �����ߴ�

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T; // �׽�Ʈ ���̽� ��
	int K; // ������ ������ ����
	char cmd; int num;

	while (T-- > 0)
	{
		multiset<int> ms; // ������ ������ ���Ե� �� �ִ�.
		cin >> K;
		while (K-- > 0)
		{
			cin >> cmd >> num;

			// ����� 2���� �����Ѵٰ� �Ѵ�.
			if (cmd == 'I') // ���� ��� 
			{
				ms.insert(num);
			}
			else // ���� ���
			{
				// ����ִ� ��� �̹� ������ �����Ѵ�.
				if (ms.empty() == true) continue;
				
				if (num == -1) // �ּҰ� ���� ���
				{
					ms.erase(ms.begin()); // ���� Ư�� �� ���� ���� ���ڰ� �ּ� ���̴�.
				}
				else // �ִ밪 ���� ���
				{
					ms.erase(prev(ms.end())); // ���� Ư�� �� ���� ���� ���ڰ� �ִ� ���̴�.
					// end�� ���� �ڸ� ����Ű�Ƿ� ���� ��ĭ ���� �����.
				}
			}
		}

		if (ms.empty() == true)
		{
			cout << "EMPTY" << '\n';
		}
		else
		{
			cout << *(prev(ms.end())) << " " << *(ms.begin()) << '\n';
		}
	}
	return 0;
}