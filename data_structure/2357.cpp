// 2357: 최솟값과 최댓값
// 세그먼트 트리 문제

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int arr[100001];
vector<int> min_tree, max_tree;

void init(int node, int start, int end) {
    if (start == end) {
        min_tree[node] = max_tree[node] = arr[start];
        return;
    }
    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);
    min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
    max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
    return;
}

pair<int, int> find(int node, int a, int b, int left, int right) {
    if (left > b || right < a) return make_pair(2147483647, 0);
    if (a <= left && right <= b) {
        return make_pair(min_tree[node], max_tree[node]);
    }
    pair<int, int> l, r;
    l = find(node * 2, a, b, left, (left + right) / 2);
    r = find(node * 2 + 1, a, b, (left + right) / 2 + 1, right);
    return make_pair(min(l.first, r.first), max(l.second, r.second));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int ts = 1 << int(ceil(log2(n)) + 1);
    min_tree.resize(ts);
    max_tree.resize(ts);

    for (int i = 0; i < n; i++) cin >> arr[i];
    init(1, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        pair<int, int> f = find(1, a - 1, b - 1, 0, n - 1);
        cout << f.first << " " << f.second << '\n';
    }

    return 0;
}
