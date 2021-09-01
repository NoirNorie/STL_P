#include <iostream>
using namespace std;

// 문제 번호: 10250(ACM 호텔)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; // 테스트 케이스 수
	int H, W, N; // 호텔의 층 수, 각 층의 방의 수, 손님의 번호


	cin >> T;
	for (int i = 0; i < T; i++) // 테스트 케이스 수 만큼 반복한다.
	{
		cin >> H >> W >> N; // 해당 테스트 케이스의 입력을 받는다.

		int r = 0, c = 0; // 위치를 잡아낼 변수

		for (int j = 0; j < N; j += H) // 호 수를 찾아낸다.
			c++;

		r = (N - (c - 1) * H);

		cout << r * 100 + c << '\n';
	}

	return 0;
}