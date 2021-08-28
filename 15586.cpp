#include <iostream>
#include <vector>
using namespace std;

long long sum(vector<int> &a) // 참조자 & 는 주소를 넘겨준다
// 벡터 전체의 복사가 아닌 주소의 참조를 도와주는 것
{
	int result = 0;
	for (int i = 0; i < a.size(); i++)
	{
		result += a[i];
	}
	return result;
}

int main()
{
	vector<int> a;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		a.push_back(i);
	}

	cout << sum(a) << endl;
}