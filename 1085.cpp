#include <iostream>
#include <cmath>
using namespace std;

// ���� ��ȣ: 1085(���簢������ Ż��)

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