#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
#include <vector>
#define INF 987654321

using namespace std;

int N, Q;
vector<pair<int, int>> videos[5001];
int visited[5001] = {0, };
int dist[5001] = {0, };

int BFS(int k, int v)
{
	int ans = 0;
	queue<pair<int, int>> q;
	dist[v] = 0;
	visited[v] = 1;
	q.push(make_pair(v, 0));
	while(!q.empty())
	{
		int curr = q.front().first;
		q.pop();
		for(int i = 0; i < videos[curr].size(); i++)
		{
			int next = videos[curr][i].first;
			int next_dst = videos[curr][i].second;
			if(visited[next] != 0)
				continue;
			if(dist[curr] == 0) //시작 동영상
			{
				dist[next] = next_dst;
			}
			else
			{
				dist[next] = min(dist[curr], next_dst); // 둘 중 유사도가 낮은 것
			}
			q.push(make_pair(next, next_dst));
			visited[next] = 1;
		}
	}
	for(int i = 1; i <= N; i++)
	{
		if(dist[i] >= k)
			ans++;
	}
	return ans;
}

int main()
{
	cin >> N >> Q;

	for(int i = 1; i < N; i++)
	{
		int p, q, r;
		cin >> p >> q >> r;
		videos[p].push_back(make_pair(q, r));
		videos[q].push_back(make_pair(p, r));
	}

	for(int i = 0; i < Q; i++)
	{
		int k, v;
		cin >> k >> v;
		memset(visited, 0, sizeof(visited));
		memset(dist, INF, sizeof(dist));
		cout << BFS(k, v) << endl;
	}
}
