#include <iostream>
#include <string>
using namespace std;

int main()
{
	int H, M; cin >> H >> M;

	if (M - 45 < 0)
	{
		if (H - 1 < 0)
		{
			cout << 24 + (H - 1) << " " << 60 + (M - 45) << '\n';
		}
		else
		{
			cout << H - 1 << " " << 60 + (M - 45) << '\n';
		}
	}
	else
	{
		cout << H <<" " << M - 45 << '\n';
	}

	return 0;
}
