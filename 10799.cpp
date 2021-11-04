#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string x; cin >> x; // 괄호 쌍을 받을 문자열
	stack<char> st; // 막대기를 기록할 스택

	int answer = 0; // 막대기 수를 기록할 변수
	for (int i = 0; i < x.length(); i++)
	{
		if (i == 0)
		{
			st.push(x[i]);
			continue;
		}
		if (x[i - 1] == '(' && x[i] == ')') // 괄호쌍이 인접하면 레이저
		{
			st.pop(); // 레이저는 막대기가 아니다.
			st.push('L'); // 레이저라고 기록한다.
		}
		else
		{
			st.push(x[i]);
		}
		
	}

	int stick = 0;
	while (st.empty() != true) // 개수를 센다
	{
		if (st.top() == ')')
		{
			stick++; // 잘릴 수를 추가
		}
		else if (st.top() == '(')
		{
			answer++; // 꼬다리 추가
			stick--; // 막대기 하나 제거
		}
		else // 레이저인 경우
		{
			answer += stick; // 자른 것 추가
		}
		st.pop();
	}

	cout << answer << '\n';

	return 0;
}