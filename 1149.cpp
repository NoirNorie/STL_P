#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

// 문제 번호: 1149(RGB 거리)

int min(int a, int b) { return a < b ? a : b; }

int main() {

    int N, i, j;

    int arr[1000][3];
    int dp[1000][3];

    scanf("%d", &N);

    for (i = 0; i < N; i++)
        for (j = 0; j < 3; j++) scanf("%d", &arr[i][j]);

    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for (i = 1; i < N; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    }

    int ans = 999999999;
    for (i = 0; i < 3; i++) {
        if (dp[N - 1][i] < ans) ans = dp[N - 1][i];
    }

    printf("%d\n", ans);

    return 0;
}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int def_num = 1001;
//int memo_arr[1001][3];
//
//pair<char, int> Min(int R, int G, int B)
//{
//	if (R <= G)
//	{
//		if (R <= B) return make_pair('R', R);
//		else return make_pair('B', B);
//	}
//	else if (G <= B) return make_pair('G', G);
//	else return make_pair('B', B);
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	int N; cin >> N;
//	int R, G, B;
//	vector<pair<char, int>> v(def_num, make_pair('X', 0));
//	
//	for (int i = 0; i < N; i++) // 배열에 값 기록
//	{
//		cin >> R >> G >> B;
//		memo_arr[i][0] = R;
//		memo_arr[i][1] = G;
//		memo_arr[i][2] = B;
//	}
//
//	int sum = 0;
//
//	for (int i = N-1; i >= 0; i--)
//	{
//		if (i == N-1)
//		{
//			v[i] = Min(memo_arr[i][0], memo_arr[i][1], memo_arr[i][2]);
//			sum += v[i].second;
//		}
//		else
//		{
//			if (v[i + 1].first == 'R') v[i] = Min(def_num, memo_arr[i][1], memo_arr[i][2]);
//			else if(v[i + 1].first == 'G') v[i] = Min(memo_arr[i][0], def_num, memo_arr[i][2]);
//			else v[i] = Min(memo_arr[i][0], memo_arr[i][1], def_num);
//
//			sum += v[i].second;
//		}
//	}
//
//	cout << sum << '\n';
//
//	return 0;
//}