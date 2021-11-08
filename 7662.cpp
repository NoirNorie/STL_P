#include <iostream>
#include <set>
using namespace std;

// 문제 번호: 7662(이중 우선순위 큐)
// 큐라고는 하지만 멀티셋으로 구현했다

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T; // 테스트 케이스 수
	int K; // 적용할 연산의 개수
	char cmd; int num;

	while (T-- > 0)
	{
		multiset<int> ms; // 동일한 정수가 삽입될 수 있다.
		cin >> K;
		while (K-- > 0)
		{
			cin >> cmd >> num;

			// 명령은 2개만 존재한다고 한다.
			if (cmd == 'I') // 삽입 명령 
			{
				ms.insert(num);
			}
			else // 삭제 명령
			{
				// 비어있는 경우 이번 연산은 무시한다.
				if (ms.empty() == true) continue;
				
				if (num == -1) // 최소값 삭제 명령
				{
					ms.erase(ms.begin()); // 셋의 특성 상 가장 앞의 숫자가 최소 값이다.
				}
				else // 최대값 삭제 명령
				{
					ms.erase(prev(ms.end())); // 셋의 특성 상 가장 뒤의 숫자가 최대 값이다.
					// end는 뒤의 뒤를 가리키므로 뒤의 한칸 앞을 지운다.
				}
			}
		}

		if (ms.empty() == true)
		{
			cout << "EMPTY" << '\n';
		}
		else
		{
			cout << *(prev(ms.end())) << " " << *(ms.begin()) << '\n';
		}
	}
	return 0;
}