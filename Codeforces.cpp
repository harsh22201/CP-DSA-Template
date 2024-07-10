#include <bits/stdc++.h>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#include "algo/modular.h"
#include "algo/NT.h"
#include "algo/graph.h"
#include "algo/strings.h"
#include "algo/segment_tree.h"

#else
#define debug(x...)
#endif

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// https://codeforces.com/blog/entry/72437
#define endl '\n'
#define yes "YES\n"
#define no "NO\n"
#define yesno(x) cout << (x ? "YES\n" : "NO\n")
#define impossible "IMPOSSIBLE\n"
#define int long long
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
#define INF 9223372036854775807
#define zero (long long)0
#define mod 1000000007
#define print(x)          \
    for (auto i : x)      \
        cout << i << ' '; \
    cout << '\n';
#define vvi(n, m, i) vector<vector<int>>(n, vector<int>(m, i))
#define forr(x, from, to) for (int x = from; x < (to); x++)
#define swap(a, b) a ^= b, b ^= a, a ^= b
#define len(a) a.size()

void solve()
{
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--)
    {
        solve();
        // cout << endl;
    }
}
