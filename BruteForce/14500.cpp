// 14500: 테트로미노
// 전수 조사 문제

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<pair<int, int>>> tet = {
	{{0,0}, {0,1}, {0,2}, {0,3}},
	{{0,0}, {1,0}, {2,0}, {3,0}},
	{{0,0}, {1,0}, {2,0}, {2,1}},
	{{0,0}, {0,1}, {0,2},{-1,2}},
	{{0,0}, {-1,0}, {-2,0}, {-2,-1}},
	{{0,0}, {-1,0}, {-1,1}, {-1,2}},
	{{0,0}, {0,1}, {-1,1}, {-2,1}},
	{{0,0}, {0,1}, {0,2}, {1,2}},
	{{0,0}, {-1,0}, {-2,0}, {-2,1}},
	{{0,0}, {1,0}, {1,1}, {1,2}},
	{{0,0}, {-1,0}, {-1, 1}, {-2, 1}},
	{{0,0}, {0,1}, {1,1}, {1,2}},
	{{0,0}, {1,0}, {1,1}, {2,1}},
	{{0,0}, {0,1}, {-1, 1}, {-1,2}},
	{{0,0}, {0,1}, {-1, 1}, {0,2}},
	{{0,0}, {0,1}, {-1, 1}, {1,1}},
	{{0,0}, {0,1}, {1,1}, {0,2}},
	{{0,0}, {1,0}, {2,0}, {1,1}},
	{{0,0}, {1,0}, {0,1}, {1,1}}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	int mx = 0;
	bool chk = true;
	vector<vector<int>> area(n, vector<int>(m, 0));
	for (size_t i = 0; i < area.size(); i++)
	{
		for (size_t j = 0; j < area[i].size(); j++) cin >> area[i][j];
	}

	for (int i = 0; i < area.size(); i++)
	{
		for (int j = 0; j < area[i].size(); j++)
		{
			//cout << i << " " << j << " 시도" << '\n';
			for (int t = 0; t < 19; t++)
			{
				int cnt = 0; chk = true;
				for (int a = 0; a < 4; a++)
				{
					if (i + tet[t][a].first < 0 || i + tet[t][a].first >= n || j + tet[t][a].second < 0 || j + tet[t][a].second >= m)
					{
						chk = false;
						break;
					}
					//cout << i + tet[t][a].first << " " << j + tet[t][a].second << '\n';
					cnt += area[i + tet[t][a].first][j + tet[t][a].second];
				}
				if(chk == true) mx = max(cnt, mx);
			}
		}
	}
	cout << mx << '\n';


}
