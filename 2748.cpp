#include <iostream>
#include <vector>
using namespace std;

vector<long long int> DP;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    DP.assign(N+1, 0);

    DP[0] = 0; DP[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2];
    }

    cout << DP[N] << '\n';
 
	return 0;
}
