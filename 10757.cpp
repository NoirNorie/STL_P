#include <iostream>
#include <deque>
#include <string>
using namespace std;

// 문제 번호: 10757(큰 수 A+B)

int main()
{
	string A, B;
	cin >> A >> B; // 겁나 길 것이므로 string 형으로 받는다.

	deque<int> mid;

	int Ai = A.length() -1, Bi = B.length() -1; // 각 문자열의 맨 뒤를 가리킨다.
	int tmp = 0;
	int up = 0; // 최초에 올림 수는 없음

	while (Ai > -1 && Bi > -1)
	{
		tmp = (int)(A[Ai] - 48) + (int)(B[Bi] - 48) + up;
		
		mid.push_front(tmp % 10);

		// 올림 수가 있는 경우라면
		if (tmp >= 10) up = 1;
		else up = 0;

		Ai--; Bi--;
	}

	if (Ai > -1)
	{
		while (Ai > -1)
		{

			tmp = (A[Ai] - 48) + up;
			mid.push_front(tmp % 10);

			// 올림 수가 있는 경우라면
			if (tmp >= 10) up = 1;
			else up = 0;

			Ai--;		
		}
	}

	if (Bi > -1) 
	{
		while (Bi > -1)
		{
			tmp = (B[Bi] - 48) + up;
			mid.push_front(tmp % 10);

			// 올림 수가 있는 경우라면
			if (tmp >= 10) up = 1;
			else up = 0;

			Bi--;
		}
	}
	
	if(up == 1) // 연산을 마무리 했는데 올림수가 있는 경우
	{
		mid.push_front(1); // 자리수 하나를 추가한다.
	}
	
	while (mid.empty() != 1)
	{
		cout << mid.front();
		mid.pop_front();
	}

	return 0;
}