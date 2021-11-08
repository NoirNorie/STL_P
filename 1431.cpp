#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 문제 번호: 1431(시리얼 번호)
// STL sort의 비교자 사용 정렬

bool cmp(string a, string b)
{
	if (a.length() != b.length()) // 길이가 짧은 것이 먼저
	{
		return a.length() < b.length();
	}
	else // 길이가 동일하면
	{
		int numa = 0, numb = 0;
		for (int i = 0; i < a.length(); i++)
		{
			if((a[i] - '0') >= 1  && (a[i] - '0') <= 9)
				numa += (a[i] - '0');
		}
		for (int i = 0; i < b.length(); i++)
		{
			if ((b[i] - '0') >= 1 && (b[i] - '0') <= 9)
				numb += (b[i] - '0');
		}

		if (numa != numb) // 작은 합이 먼저 온다
		{
			return numa < numb;
		}
		else
		{
			return a < b;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;

	vector<string> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
	
	return 0;
}