#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int Div_Sum(int IN);

// 문제번호: 2231 (분해합)
int main()
{
	int IN; // 입력받을 변수
	cin >> IN;

	cout << Div_Sum(IN);

	return 0;
}

int Div_Sum(int IN)
{
	int result = 0;
	int min = IN; // 생성자는 입력된 변수보다 작을 것이다.
	int tmp = 0; // 계산용 변수

	for (int d = IN; d > 0; d--) // 가능한 모든 경우를 조사한다.
	{
		tmp = d;

		// 자릿수 분해
		vector<int> Nums; // 자릿수를 저장할 벡터
		for (int i = 1; i <= 7; i++)
		{
			Nums.push_back(((d % (int)(pow(10, i))) / pow(10, i - 1)));
		}
		// 벡터에는 1, 10, 100, ... 자리수 순으로 저장된다.

		// 각 자릿수와 생성자를 더한다.
		vector<int>::iterator iter;
		for (iter = Nums.begin(); iter != Nums.end(); iter++)
		{
			tmp += *iter;
		}

		if (tmp == IN) // 수행한 결과가 입력된 자연수와 동일할 경우 분해합이다.
		{
			if (d < min) // 가장 작은 생성자를 찾아낸다면
			{
				min = d; // 찾아낸 변수를 가장 작은 생성자로 기록한다.
			}
		}
		tmp = 0; // 계산용 변수 초기화
	}

	if (min != IN)
	{
		return min;
	}
	else // 생성자가 없는 경우 리턴
	{
		return 0;
	}
}