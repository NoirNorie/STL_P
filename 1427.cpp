#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// 문제 번호: 1427(소트인사이드)

int main()
{
	string N; cin >> N;
	vector<int> v;
	// 0 은 아스키 코드로 48

	for (int i = 0; i < N.length(); i++)
	{
		v.push_back(N[i] - 48);
	}
	sort(v.begin(), v.end(), greater<>());

	for (int i = 0 ; i < v.size(); i++)
	{
		cout << v[i];
	}

	return 0;
}