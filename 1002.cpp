#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int RangeCalc(int x1, int y1, int r1, int x2, int y2, int r2);

// 문제 번호: 1002(터렛)

int main()
{
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0, r1 = 0, r2 = 0;
	// 각 좌표 초기화
	// 1번은 조규현, 2번은 백승환
	// r은 류재명과의 거리
	vector<int> Result_V; // 결과를 담을 벡터 생성
	
	// 테스트케이스 입력
	int T; cin >> T;

	for (int i = 0; i < T; i++) // 테스트 케이스 반복
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		// 해당 테스트 케이스의 좌표, 거리 값 입력

		Result_V.push_back(RangeCalc(x1, y1, r1, x2, y2, r2));
		//cout << RangeCalc(x1, y1, r1, x2, y2, r2) << endl;
	}

	vector<int>::iterator iter; // 결과 출력
	for (iter = Result_V.begin(); iter != Result_V.end(); iter++)
	{
		cout << *iter << endl;
	}
	return 0;
}

int RangeCalc(int x1, int y1, int r1, int x2, int y2, int r2)
{
	double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	if (x1 == x2 && y1 == y2 && r1 == r2) // 원 자체가 일치
	{
		return -1;
	}
	else if(dist == r1 + r2) // 외접하는 경우
	{
		return 1;
	}
	else if (dist == abs(r1-r2)) // 내접하는 경우
	{
		return 1;
	}
	else if (dist > r1 + r2) // 두 원이 서로 떨어져 있고 접점 X
	{
		return 0;
	}
	else if (dist <= abs(r1-r2) ) // 원이 다른 원 내부에 존재, 접점 X
	{
		return 0;
	}
	else // 그 밖의 경우는 모두 두 점에서 만난다.
	{
		return 2;
	}
}
