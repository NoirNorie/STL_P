#include <iostream>
#include <string>
#include <deque>
using namespace std;

// 문제 번호: 5430(AC)
// deque를 이용해서 출력만 그럴듯하게 바꾸는 문제이다.
// 실제로 바뀌는건 pop, front, back 밖에 없다.

int main()
{
	int T; cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		string cmd; cin >> cmd;
		bool cmd_state = true; // true인 경우 정방향, false인 경우 역방향
		bool error_chk = false; // 덱이 빈 상태에서 D 연산을 수행한다면 오류를 출력하도록 한다.

		int arr_size; cin >> arr_size;
		
		deque<int> dq; // 덱 초기화 및 생성
		
		// 배열 크기가 1이상이면 덱에 영향을 준다.
		if (arr_size > 0)
		{
			string arr = "";
			getline(cin, arr, '['); // 브래킷 열기 제거
			for (int j = 0; j < arr_size - 1; j++)
			{
				getline(cin, arr, ',');
				dq.push_back(stoi(arr)); // 문자열을 숫자로 변환하여 덱에 집어넣는다.
			}
			getline(cin, arr, ']'); // 브래킷 제거
			dq.push_back(stoi(arr));
		}
		else // 배열 크기 0에 대한 예외처리
		{
			string arr;
			cin >> arr;
			// 브레킷 쌍을 입력받는 부분이다.
			// 덱에 영향을 주지 않는다.
			// 실제로 쓸모는 없지만 채점때문에 처리한다.
		}
		
		for (int j = 0; j < cmd.length(); j++)
		{
			if (cmd[j] == 'R')
			{
				// 상태를 전이해준다.
				if (cmd_state == true) // 정방향이면
				{
					cmd_state = false; // 역방향으로
				}
				else // 역방향이면
				{
					cmd_state = true; // 정방향으로
				}
			}
			else // 명령은 2개만 있다고 생각한다.
			{
				// 에러 조건일 경우 중단시키고 체크해준다.
				if (dq.size() == 0)
				{
					error_chk = true;
					break;
				}

				// 상태에 따라 다르게 동작한다.
				if (cmd_state == true) // 정방향인 경우
				{
					dq.pop_front(); // 앞에서 뺀다
				}
				else // 역방향인 경우
				{
					dq.pop_back(); // 뒤에서 뺀다
				}
			}
		}

		// 출력부
		if (error_chk == true) // D가 배열 크기보다 많이 나온 경우
		{
			cout << "error" << '\n';
		}
		else // 조건에 다 부합하거나 배열 크기가 0이었던 경우
		{
			cout << "["; // 일단 브레킷은 열고

			if (dq.size() == 0) // 크기가 0이지만 정상 동작인 경우 처리
			{
				cout << "]" << '\n'; // 브래킷을 닫고
				continue; // 다음 동작을 생략한다.
			}
			else if (cmd_state == true) // 정방향인 경우
			{
				while (dq.size() > 1)
				{
					cout << dq.front() << ",";
					dq.pop_front();
				}
				cout << dq.front(); // 마지막 숫자는 ,가 안들어가므로 따로 처리한다.
				dq.pop_front();
			}
			else // 뒤집힌 경우
			{
				while (dq.size() > 1)
				{
					cout << dq.back() << ",";
					dq.pop_back();
				}
				cout << dq.back();
				dq.pop_back();
			}	
			cout << "]" << '\n';
		}
	}
	return 0;
}
