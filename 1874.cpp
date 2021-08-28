#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 문제번호: 1874(스택 수열)

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// c++ 표준 입출력인 cin, cout 속도를 빠르게 하기 위한 방법
	// 추가로 endl 대신 '\n'을 사용하는 것이 권장된다고 한다.

	stack<int> sq; // 수열을 담을 스택
	vector<char> chr; // 기호를 담고 출력할 스택
	
	int T, IN; // 시도 횟수, 입력 변수
	int chk, flag = 0; // 체크, 플래그(0 = 정상, -1 = 오류)


	cin >> T; // 입력
	int i = 1, t = 0; // 인덱스 변수, 숫자 입력 횟수 변수
	while (t != T && flag != -1)
	{
		cin >> IN; // 숫자 입력
		t++; // 시도 수 증가
		
		if (i <= IN) // CASE 1
		{
			for (;i <= IN;++i)
			{
				sq.push(i); // 숫자를 스택에 쌓는다.
				chr.push_back('+'); // push 시도 기록
			}
			sq.pop(); // 마지막 숫자를 스택에서 뺀다
			chr.push_back('-'); // pop 시도 기록
		}
		else // CASE 2
		{
			if (sq.empty() == 1) // 스택이 비었으면 오류
			{
				flag = -1;
				break; // 플래그를 오류로 전환하고 반복 종료
			}
			for (int j = sq.size() ; j > 0 ; j--) // 스택을 조사한다.
			{
				if (sq.empty() == 1) // 스택이 비었으면 오류
				{
					flag = -1;
					break; // 플래그를 오류로 전환하고 반복 종료
				}
				else // 스택에 뭔가 있다.
				{
					if (sq.top() == IN) // 스택의 가장 위의 숫자가 입력과 같다면
					{
						sq.pop(); // 마지막 숫자를 스택에서 뺀다
						chr.push_back('-'); // pop 시도 기록
						break; // 정상 동작으로 종료한다.
					}
					else
					{
						sq.pop(); // 마지막 숫자를 스택에서 뺀다
						chr.push_back('-'); // pop 시도 기록
					}
				}
			}
		}
	}

	if (flag == -1 || sq.empty() != 1)
	{
		cout << "NO" << '\n';
	}
	else
	{
		vector<char>::iterator iter;
		for (iter = chr.begin(); iter != chr.end(); iter++)
		{
			cout << *iter << '\n';
		}
	}

	return 0;
}