#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 문제 번호: 1152(단어의 개수)

int main()
{
	string inp; getline(cin, inp);
	int cnt = 0;
	int num = 0;

	string::iterator ster = inp.begin(); // 반복자의 처음은 입력 문자열의 처음을 가리킨다.
	while (ster != inp.end())
	{
		if (*ster != ' ' || *ster == '\n') // 개행 문자가 아니고 띄어쓰기도 아니면
		{
			cnt++; // 글자 수를 증가시킨다
		}
		else // 띄어쓰기를 마주친 경우
		{
			if (cnt != 0) // 한 글자라도 있었는가?
			{
				num++; // 단어의 개수를 증가시킨다
				cnt = 0; // 글자 수 초기화
			}
		}
		ster++; // 반복자 증가
		if (ster == inp.end() && cnt != 0) // 반복자가 마지막에 도달했는데 글자 수가 남은 경우
		{
			num++; // 마지막 단어를 추가해준다.
		}
	}

	cout << num << '\n';
}