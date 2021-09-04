#include <iostream>
#include <cmath>
using namespace std;

// 문제 번호: 1085(직사각형에서 탈출)

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int y_min, x_min;
	x_min = ((w - x <= x) ? w - x : x);
	y_min = ((h - y <= y) ? h - y : y);

	int min = (x_min <= y_min) ? x_min : y_min;

	cout << min << '\n';

	return 0;
}