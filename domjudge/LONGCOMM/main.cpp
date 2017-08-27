
#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
#define INF 1000000000

vector<vector<ii>> AdjList; // a t o
ll N, M;
vi d, dA, dB;

void dijkstra(vi& dist, int s) {
  dist.assign(N, INF); dist[s] = 0;
  priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
  while (!pq.empty()) {
    ii front = pq.top(); pq.pop();
    ll d = front.first, u = front.second;
    if (d > dist[u]) continue;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      ii v = AdjList[u][j];
      if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second;
        pq.push(ii(dist[v.first], v.first));
      }
    }
  }
}

int main() {
  ll T; cin >> T;
  FOR(t, 0, T) {
    AdjList.clear();
    cin >> N >> M;
    AdjList.resize(N);
    ll S, A, B; cin >> S >> A >> B;
    FOR(m,0,M) {
      ll a,o,t; cin >> a >> o >> t;
      AdjList[a].push_back(ii(o,t));
      AdjList[o].push_back(ii(a,t));
    }
    dijkstra(d, S);
    dijkstra(dA, A);
    dijkstra(dB, B);

    ll maxi = 0;
    FOR(i, 0, d.size()) {  
      if (dB[i] + d[i] == d[B] && dA[i] + d[i] == d[A]) {
        maxi = max(maxi, d[i]);
      }
    }
    cout << maxi << endl;
  }
}
