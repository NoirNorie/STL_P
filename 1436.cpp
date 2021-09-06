#include <iostream>
#include <string>
using namespace std;

// 문제 번호: 1436(영화감독 슘)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int cnt = 0;
	int num = 665;
	string str;

	do
	{
		num++;
		str = to_string(num);
		if (str.find("666") != -1) cnt++;

	} while (cnt != N); // 순서대로 찾아가야 한다

	cout << str << '\n';

	return 0;
}