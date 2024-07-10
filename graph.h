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

void topological_sort_dfs(int curnode, vector<int> &ordering, vector<bool> &visited, vector<vector<int>> &graph)
{
    visited[curnode] = true;
    for (int child : graph[curnode])
        if (!visited[curnode])
            topological_sort_dfs(child, ordering, visited, graph);
    ordering.push_back(curnode);
}
vector<int> topological_sort(vector<vector<int>> &graph) // DAG
{
    int nodes = graph.size();
    vector<int> ordering;
    vector<bool> visited(nodes, false);
    for (int i = 0; i < nodes; i++)
        topological_sort_dfs(i, ordering, visited, graph);
    reverse(ordering.begin(), ordering.end());
    return ordering;
}

vector<pair<int, int>> dijkstra(vector<vector<pair<int, int>>> &graph, int start) // O((V+E)logV)
{
    int nodes = graph.size();
    // start--;

    vector<pair<int, int>> d(nodes, {1e18, -1}); // <distance, predecessor>
    set<pair<int, int>> q;                       // <distance, node>
    d[start].first = 0;
    q.insert({0, start});

    while (!q.empty())
    {
        int curnode = q.begin()->second;
        int curnode_dist = q.begin()->first;
        q.erase(q.begin());

        for (auto adj : graph[curnode])
        {
            int adj_node = adj.first;
            int adj_weight = adj.second;
            int adj_cur_dist = d[adj_node].first;
            int adj_new_dist = curnode_dist + adj_weight;

            if (adj_cur_dist > adj_new_dist)
            {
                q.erase({adj_cur_dist, adj_node});
                q.insert({adj_new_dist, adj_node});
                d[adj_node].first = adj_new_dist;
                d[adj_node].second = curnode;
            }
        }
    }
    return d;
}

vector<int> dijkstra_path(vector<pair<int, int>> d, int reach)
{
    vector<int> path;
    int cur = reach;
    while (cur != -1)
    {
        path.push_back(cur);
        cur = d[cur].second;
    }
    reverse(path.begin(), path.end());
    return path;
}

void kosaraju_dfs1(int curnode, vector<vector<int>> &graph, vector<int> &order, vector<bool> &visited)
{
    visited[curnode] = true;
    for (auto v : graph[curnode])
        if (!visited[v])
            kosaraju_dfs1(v, graph, order, visited);
    order.push_back(curnode);
}
void kosaraju_dfs2(int curnode, vector<vector<int>> &graph_rev, vector<int> &component, vector<bool> &visited)
{
    visited[curnode] = true;
    component.push_back(curnode);
    for (auto v : graph_rev[curnode])
        if (!visited[v])
            kosaraju_dfs2(v, graph_rev, component, visited);
}

vector<vector<int>> kosaraju(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> graph_scc; // condensation graph //DAG
    vector<vector<int>> graph_rev(n);
    for (int u = 0; u < n; u++)
    {
        for (auto v : graph[u])
            graph_rev[v].push_back(u);
    }
    // kind of like topological order since graph is not DAG
    vector<int> order;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i])
            kosaraju_dfs1(i, graph, order, visited);
    reverse(order.begin(), order.end());
    //
    visited.assign(n, false);
    vector<int> component;
    for (auto i : order)
    {
        if (!visited[i])
        {
            kosaraju_dfs2(i, graph_rev, component, visited);
            // process component
            //
            component.clear();
        }
    }
    return graph_scc;
}

bool edmonds_karp_bfs(vector<vector<int>> &graph, vector<vector<int>> &capacity, vector<int> &parent, int s, int t)
{
    fill(parent.begin(), parent.end(), -2); // unvisited
    parent[s] = -1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : graph[u])
        {
            if (parent[v] == -2 && capacity[u][v])
            {
                parent[v] = u;
                if (v == t)
                    return true;
                q.push(v);
            }
        }
    }
    return false;
}

// graph - adj list //capacity - adj matrix //ford_fulkerson uses dfs O(V(flow)) //O(V*E^2)
int edmonds_karp(vector<vector<int>> &graph, vector<vector<int>> &capacity, int s, int t)
{
    int n = graph.size();
    vector<int> parent(n);
    int max_flow = 0;
    while (edmonds_karp_bfs(graph, capacity, parent, s, t))
    {
        int aug_flow = 2e9;
        int v = t;
        while (v != s)
        {
            int u = parent[v];
            aug_flow = min(aug_flow, capacity[u][v]);
            v = u;
        }
        max_flow += aug_flow;
        v = t;
        while (v != s)
        {
            int u = parent[v];
            capacity[u][v] -= aug_flow;
            capacity[v][u] += aug_flow;
            v = u;
        }
    }
    return max_flow;
}

// DSU
template <typename T>
void make_set(int v, T &parent)
{
    parent[v] = v;
}
template <typename T>
int find_set(int v, T &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}
template <typename T>
void set_union(int a, int b, T &parent)
{
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b)
        parent[b] = a;
}
//
int kruskal(vector<vector<pair<int, int>>> &graph)
{
    int n = graph.size();
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        make_set(i, parent);
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < n; i++)
        for (auto v : graph[i])
            edges.push_back({v.second, {i, v.first}});
    sort(edges.begin(), edges.end());
    int mstw = 0;
    for (auto edge : edges)
    {
        int w = edge.first, u = edge.second.first, v = edge.second.second;
        if (find_set(u, parent) != find_set(v, parent))
        {
            mstw += w;
            set_union(u, v, parent);
        }
    }
    return mstw;
}

int prims(vector<vector<pair<int, int>>> &graph, int start = 0)
{
    int n = graph.size();
    set<pair<int, int>> q;
    vector<int> d(n, -1);
    vector<bool> vistied(n, false);
    int mstw = 0;
    q.insert({0, start});
    d[start] = 0;
    while (!q.empty())
    {
        debug(q);
        int curnode = q.begin()->second;
        q.erase(q.begin());
        vistied[curnode] = true;
        for (auto adj : graph[curnode])
        {
            auto adj_node = adj.first;
            if (vistied[adj_node])
                continue;
            auto adj_cur_dist = d[adj_node];
            auto adj_new_dist = adj.second;
            if (adj_cur_dist == -1 || adj_new_dist < adj_cur_dist)
            {
                q.erase({adj_cur_dist, adj_node});
                q.insert({adj_new_dist, adj_node});
                d[adj_node] = adj_new_dist;
            }
        }
    }
    int sum_mst = 0;
    return sum_mst;
}
