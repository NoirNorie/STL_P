#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ���� ��ȣ: 2675(���ڿ� �ݺ�)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int rep; string x; string result = "";
		cin >> rep >> x;

		string::iterator siter;
		for (siter = x.begin(); siter != x.end(); siter++)
		{
			for (int i = 0; i < rep; i++)
			{
				result += *siter;
			}
		}

		for (siter = result.begin(); siter != result.end(); siter++)
		{
			cout << *siter;
		}
		cout << '\n';
	}


	return 0;
}