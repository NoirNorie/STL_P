// 1924: 2007년
// 간단한 요일 계산

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> month = { 31,28,31,30,31,30,31,31,30,31,30,31 };
vector<string> day = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int x, y; cin >> x >> y;
	int daydif = y - 1;
	int monthdif = x - 1;
	for (int i = 0; i < monthdif; i++) daydif += month[i];

	cout << day[daydif % 7] << '\n';
	
}
