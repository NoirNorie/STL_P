// 10821: 정수의 개수
// 놀러가는 날에도 풀이는 계속된다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	int sum = 0;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == ',') sum++;
	}
	cout << sum + 1;
}
