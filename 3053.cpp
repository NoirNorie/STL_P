//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

// 문제 번호: 3053(택시 기하학)

int main()
{
	double r; scanf("%lf", &r);

	printf("%6lf\n", r * r * 3.14159265358979);
	printf("%6lf\n", (double)(r * r * 2));

	return 0;
}

/*

	택시 기하학

	일반적으로 생각하는(유클리드 기하학) 거리에 대한 정의와 다른 기하학임
	- 유클리드 기하학의 5가지 공준을 모두 만족하지만 거리에 대한 정의가 다름
	- 유클리드 기하학과 다른 특성이 나타남 = 비 유클리드 기하학으로 분류

	원 = 한 점(중심)에서 같은 거리에 존재하는 점들의 집합
	- 유클리드 기하학에서는 일반적인 원의 모습을 띄고 있음
	- 택시 기하학에서는 원이 마름모(정사각형)의 모습을 띄고 있음

	따라서 택시 기하학에서의 원의 넓이는 pi * r^2 가 아니다
	- 원의 넓이: |x - a| + |y - b| = d

*/