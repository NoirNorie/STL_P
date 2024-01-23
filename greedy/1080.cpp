#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> X(N, vector<int>(M));
	vector<vector<int>> Y(N, vector<int>(M)); 

	for(int i = 0; i < N; ++i){
		string s; cin >> s;
		for(int j = 0; j < s.length(); ++j){
			X[i][j] = s[j] - '0';
		}
	}
	for(int i = 0; i < N; ++i){
		string s; cin >> s;
		for(int j = 0; j < s.length(); ++j){
			Y[i][j] = s[j] - '0';
		}
	}

	if(N < 3 || M < 3){
		for(int i = 0 ; i < N; ++i){
			for(int j = 0 ; j < M; ++j){
				if(X[i][j] != Y[i][j]){
					cout << -1 << '\n';
					return 0;
				}
			}
		}
		cout << 0 << '\n';
	}
	else{
		int cnt = 0;
		for(int i = 0; i < N - 2; ++i){
			for(int j = 0; j < M - 2; ++j){
				if(X[i][j] != Y[i][j]){
					X[i][j]		= 1 - X[i][j];		X[i][j+1] = 1 - X[i][j+1];	X[i][j+2] = 1 - X[i][j+2];
					X[i+1][j]	= 1 - X[i+1][j];	X[i+1][j+1] = 1 - X[i+1][j+1];	X[i+1][j+2] = 1 - X[i+1][j+2];
					X[i+2][j]	= 1 - X[i+2][j];	X[i+2][j+1] = 1 - X[i+2][j+1];	X[i+2][j+2] = 1 - X[i+2][j+2];
					cnt+=1;
				}
			}
		}
		for(int i = 0 ; i < N; ++i){
			for(int j = 0 ; j < M; ++j){
				if(X[i][j] != Y[i][j]){
					cout << -1 << '\n';
					return 0;
				}
			}
		}
		cout << cnt << '\n';
	}
}
