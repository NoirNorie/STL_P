#include <iostream>
using namespace std;
bool isused1[40]; // 열 검사
bool isused2[40]; // 상향 대각선 검사
bool isused3[40]; // 하향 대각선 검사

int cnt = 0; int n;

void func(int cur)
{
	if (cur == n)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (isused1[i] || isused2[cur + i] || isused3[cur - i + n - 1]) continue; // 둘 수 없는 부분

		isused1[i] = 1;
		isused2[cur + i] = 1;
		isused3[cur - i + n - 1] = 1;
		// 해당 지역을 둘 수 없는 곳으로 만든다
		func(cur + 1); // 다음 단계 실행
		isused1[i] = 0;
		isused2[cur + i] = 0;
		isused3[cur - i + n - 1] = 0;
		// 해당 지역을 해제
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	func(0);
	cout << cnt;

}
