// 7785: 회사에 있는 사람
// 맵을 써도 딱히 문제는 없는데 세트를 사용하는 것이 더 편해서 세트를 사용하여 풀이함

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

set<string> st;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long n; cin >> n;
	while (n--)
	{
		string name, status; cin >> name >> status;
		if (status == "enter") st.insert(name);
		else st.erase(st.find(name));
	}
	set<string>::reverse_iterator stiter;
	for (stiter = st.rbegin(); stiter != st.rend(); stiter++) cout << *stiter << '\n';
}
