#include <iostream>
using namespace std;

// 문제번호: 2869(달팽이는 올라가고 싶다)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long A, B, V;
	cin >> A >> B >> V;


	// 반복문으로도 가능한데
	// 시간이 너무 오래 걸린다.
	/*
	long long move = A - B;
	long long clim = A;
	long long day = 1;
	
	while (clim < V)
	{
		clim += move;
		day++;
	}
	*/

	if ((V-B) % (A - B) == 0) // 하루만에 올라가면 내려오지 않는다.
	{
		cout << (V - B) / (A - B) << '\n';
	}
	else
	{
		cout << ((V - B) / (A - B)) + 1 << '\n';
	}
}