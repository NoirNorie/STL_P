# 1439 : 뒤집기

#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;
	int zero = 0, one = 0;
	if (s[0] == '0') zero++;
	else one++;
	for (size_t i = 1; i < s.length(); i++)
	{
		if (s[i - 1] == s[i]) continue; // 연속된 문자의 개수는 안 세도 된다.
		else
		{
			if (s[i] == '0') zero++; // 문자가 달라지는 구간의 개수만 세면 됨
			else one++;
		}
	}
	cout << min(zero, one) << '\n'; // 그 중에서 작은 것을 출력하면 된다.
}
