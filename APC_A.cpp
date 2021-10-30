#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// 문제 번호: A(코딩 바이오리듬)

int calc(int birth, int date);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int max = 0; int result = 0; int chk = 0;

	int birth; cin >> birth; // 생일 입력
	int N; cin >> N; // 일 수 입력

	vector<int> date(N);
	for (int i = 0; i < N; i++) // 코딩할 날짜 입력
	{
		cin >> date[i];
	}

	sort(date.begin(), date.end());

	for (int i = 0; i < N; i++)
	{
		chk = calc(birth, date[i]);
		if (chk > max)
		{
			max = chk;
			result = i;
		}
	}

	cout << date[result] << '\n';

	return 0;
}

int calc(int birth, int date)
{
	int result = 1; int tmp = 0;

	for (int i = 0; i < 2; i++) // 일
	{
		tmp += pow(((birth % 10) - (date % 10)), 2);
		birth /= 10; date /= 10;
	}
	result *= tmp; tmp = 0;

	for (int i = 0; i < 2; i++) // 월
	{
		tmp += pow(((birth % 10) - (date % 10)), 2);
		birth /= 10; date /= 10;
	}
	result *= tmp; tmp = 0;

	for (int i = 0; i < 4; i++) // 연
	{
		tmp += pow(((birth % 10) - (date % 10)), 2);
		birth /= 10; date /= 10;
	}
	result *= tmp; tmp = 0;


	return result;
}