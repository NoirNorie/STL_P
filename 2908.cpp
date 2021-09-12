#include <iostream>
#include <string>
using namespace std;

// 문제 번호: 2908(상수)

int main()
{
	string x, y;
	cin >> x >> y;
	bool big = false;

	string::reverse_iterator rx = x.rbegin(), ry = y.rbegin();
	// 각 문자열의 반복자는 문자열의 맨 뒤를 가리킨다.
	while (rx != x.rend())
	{
		if ((*rx - 48) > (*ry - 48))
		{
			big = true;
			break;
		}
		else if ((*rx - 48) < (*ry - 48))
		{
			big = false;
			break;
		}
		else // 둘이 같을 수도 있으므로 다음 비교로 넘어간다
		{
			rx++; ry++;
		}
	}

	if (big)
	{
		rx = x.rbegin();
		for (rx; rx != x.rend(); rx++)
		{
			cout << *rx;
		}
	}
	else
	{
		ry = y.rbegin();
		for (ry; ry != y.rend(); ry++)
		{
			cout << *ry;
		}
	}
	return 0;
}