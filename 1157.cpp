#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 문제 번호: 1157(단어 공부)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string x; cin >> x;
	vector<int> v(26, 0);
	int max = 0, idx = 0;
	bool chk = false;

	for (int i = 0; i < x.length(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (x[i] == 97 + j || x[i] == 65 + j)
			{
				v[j]++;
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > max)
		{
			max = v[i]; idx = i;
			chk = false;
		}
		else if (v[i] == max) // 같은 값이 존재한다면
		{
			chk = true;
		}
	}

	if (chk)
	{
		cout << "?" << '\n';
	}
	else
	{
		cout << (char)(65 + idx) << '\n';
	}
	
	return 0;
}