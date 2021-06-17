#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, ans;
int src, dst;
vector<vector<int>> graph;

void makeGraph();
bool bfs(int start, int end);

int main()
{
    int Testcase; //테스트케이스
    cin >> Testcase;
    for (int j = 0; j < Testcase; j++) {
        int start = 0, end = 0; 
        int k;
        // n : 정점의 개수, m : 간선의 개수, k: 질의 개수
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
    // parent : 경로를 알기 위함, dist : 경로까지의 거리를 알기 위함
    vector<int> parent, dist;
    queue<int> q;

    // parent, dist 배열 초기화
    parent.resize(n + 1, -1);
    dist.resize(n + 1, -1);

    // 시작점 셋팅 & 초기화
    parent[start] = start;
    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int tmp = q.front(); q.pop();

        for (int i = 0; i < graph[tmp].size(); i++)
        {
            int now = graph[tmp][i];
            cout <<" "<< now << endl;
            if (dist[now] == -1)
            {
                q.push(now);
                dist[now] = dist[tmp] + 1;
                parent[now] = tmp;
            }
        }
    }

    if (dist[end] == -1) // 도착점 노드를 방문하지 못했을 경우
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
        cin >> src >> dst;
        graph[src].push_back(dst);
        graph[src].push_back(dst);
    }

    /*for (int i = 0; i < n; i++)
        sort(graph[i].begin(), graph[i].end());*/
}