#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set> //rb tree
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#include "algo/modular.h"
#include "algo/ADA.h"
#include "algo/NT.h"

#else
#define debug(x...)
#endif

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define endl '\n'
#define yes "YES\n"
#define no "NO\n"
#define int long long
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
#define INF 9223372036854775807
#define forr(x, from, to) for (int x = from; x < (to); x++)

vector<vector<int>> graph;
vector<int> subans;
vector<int> child_sum;
vector<int> ans;

int total_nodes;

void dfs1(int curnode = 0, int parent = -1e8 + 69)
{
    for (int child : graph[curnode])
    {
        if (child != parent)
        {
            // dfs1(child, curnode);
            // write here
        }
    }
}
void dfs2(int curnode = 0, int parent = -1e8 + 69)
{
    for (int child : graph[curnode])
    {
        if (child != parent)
        {
            // write here
            // dfs2(child, curnode);
        }
    }
}

void solve()
{
    cin >> total_nodes;
    graph = vector<vector<int>>(total_nodes);
    subans = vector<int>(total_nodes, 0);
    child_sum = vector<int>(total_nodes, 0);
    ans = vector<int>(total_nodes, 0);
    forr(i, 1, total_nodes)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs1();
    dfs2();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long test_cases = 1;
    // cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }
}