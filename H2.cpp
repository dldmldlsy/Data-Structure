#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, ans;
int from, to;
vector<vector<int>> graph;

void makeGraph();
bool bfs(int start, int end);

int main()
{
    int T;
    cin >> T;
    for (int j = 0; j < T; j++) {
        int start = 0, end = 0;
        int k;
        // n : ������ ����, m : ������ ����
        cin >> n >> m >> k;
        makeGraph();
        for (int i = 0; i < k; i++) {
            cin >> start >> end;
            if (bfs(start, end))
                cout << ans << endl;
            else
                cout << "0" << endl;
        }
        graph.clear();
    }
    return 0;
}

bool bfs(int start, int end)
{
    // parent : ��θ� �˱� ����, dist : ��α����� �Ÿ��� �˱� ����
    vector<int> parent, dist;
    queue<int> q;

    // parent, dist �迭 �ʱ�ȭ
    parent.resize(n + 1, -1);
    dist.resize(n + 1, -1);

    // ������ ���� & �ʱ�ȭ
    parent[start] = start;
    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int tmp = q.front(); q.pop();

        for (int i = 0; i < graph[tmp].size(); i++)
        {
            int now = graph[tmp][i];

            if (dist[now] == -1)
            {
                q.push(now);
                dist[now] = dist[tmp] + 1;
                parent[now] = tmp;
            }
        }
    }

    if (dist[end] == -1) // ������ ��带 �湮���� ������ ���
        return false;
    else {
        ans = dist[end];
        return true;
    }
}

void makeGraph()
{
    graph.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    /*for (int i = 0; i < n; i++)
        sort(graph[i].begin(), graph[i].end());*/
}