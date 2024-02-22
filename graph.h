#include <iostream>
#include <vector>

using namespace std;
#define int long long

bool detect_cycle_directed_dfs(int curnode, vector<vector<int>> &graph, vector<int> &visit)
{
    if (visit[curnode] == 2)
        return false;
    if (visit[curnode] == 1)
        return true;
    visit[curnode] = 1;
    for (int neighbor : graph[curnode])
    {
        if (detect_cycle_directed_dfs(neighbor, graph, visit))
            return true;
    }
    visit[curnode] = 2;
    return false;
}
bool detect_cycle_directed(vector<vector<int>> graph) // O(V+E)
{
    int nodes = graph.size();
    vector<int> visit(nodes, 0); // 0 unvisted // 1 visiting // 2 visted
    for (int i = 0; i < nodes; i++)
    {
        if ((visit[i] == 0) && (detect_cycle_directed_dfs(i, graph, visit)))
            return true;
    }
    return false;
}

bool detect_cycle_undirected_dfs(int curnode, int parent, vector<vector<int>> &graph, vector<bool> &visited)
{
    if (visited[curnode])
        return true;
    visited[curnode] = true;
    for (int neighbor : graph[curnode])
    {
        if ((neighbor != parent) && (detect_cycle_undirected_dfs(neighbor, curnode, graph, visited)))
            return true;
    }
    return false;
}
bool detect_cycle_undirected(vector<vector<int>> graph) // O(V+E) // is tree
{
    int nodes = graph.size();
    vector<bool> visited(nodes, false);
    for (int i = 0; i < nodes; i++)
    {
        if ((!visited[i]) && (detect_cycle_undirected_dfs(i, -1e9 - 69, graph, visited)))
            return true;
    }
    return false;
}

void topological_sort_dfs(int curnode, vector<int> &ans, vector<int> &visited, vector<vector<int>> &graph)
{
    if (visited[curnode])
        return;
    visited[curnode] = 1;
    for (int child : graph[curnode])
    {
        topological_sort_dfs(child, ans, visited, graph);
    }
    ans.push_back(curnode);
}
vector<int> topological_sort(vector<vector<int>> &graph) // DAG
{
    int nodes = graph.size();
    vector<int> ans;
    vector<int> visited(nodes, 0);
    for (int i = 0; i < nodes; i++)
    {
        topological_sort_dfs(i, ans, visited, graph);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}