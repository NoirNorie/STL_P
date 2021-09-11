#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 문제 번호: 10809

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string x; cin >> x;
	vector<int> v(26, -1);

	for (int i = 0; i < x.length(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (x[i] == 97 + j && v[j] == -1)
			{
				v[j] = i;
				break;
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}


	return 0;
}