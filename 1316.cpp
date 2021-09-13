#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ���� ��ȣ: 1316(�׷� �ܾ� üĿ)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	vector<string> vs(T);
	for (int i = 0; i < T; i++)
	{
		cin >> vs[i];
	}

	int cnt = 0;
	vector<string>::iterator vsiter = vs.begin();
	while (vsiter != vs.end())
	{
		vector<bool> vc(26, true);
		int i = 0;
		for (i; i < vsiter->length() - 1; i++)
		{
			if (vc[vsiter->at(i) - 97] == false) break; // �� �̻� �˻��� �ʿ䰡 ��������.
			
			if (vsiter->at(i) != vsiter->at(i + 1)) // ���� ���ĺ��� ������ ��� ������ �������� ���Ѵ�
			{
				vc[vsiter->at(i) - 97] = false; // ���� ���Ϳ� ǥ���Ѵ�.
			}
		}

		if (vc[vsiter->at(i) - 97] == false) // ������ ���Ҹ� �˻����� ���ϹǷ� üũ���ش�.
		{
			vsiter++;
			continue;
		}
		if (i >= vsiter->length() - 1) // ������ �ϼ��� ��� �׷� �ܾ �ǹǷ� ī��Ʈ
		{
			cnt++;
		}
		vsiter++;	
	}

	cout << cnt << '\n';

	return 0;
}