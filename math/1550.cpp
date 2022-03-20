// 1550: 16진수
// 문제 자체는 쉬운데 stoi로 16진수를 빠르게 표현할 수 있는 방법이 존재해서 기록함

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	cout << stoi(s, nullptr, 16) << '\n';
}
