/*
 * Author     : Apu Das Orgho
 * Problem    : The Monster's Dice (Easy Version)
 * Created on : 27-09-2025
 */
#include<bits/stdc++.h>
#define iamspeed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define ll int
using namespace std;
const int N = 5e6 + 5;
const ll mod = 998244353;
string s, ss;
ll d, x, y, z, cnt, t, tt, cnt2, sum, ans, res, q, n, m, k, i, j;
vector<pair<ll,ll> > graph[N];
ll dijk(int sz, int dest, int src) {
    priority_queue<pair<ll,ll> > pq;
    pq.push({0, src});
    vector<bool> vis(sz + 2, 0);
    while (!pq.empty()) {
        auto [cost,node] = pq.top();
        pq.pop();
        cost *= -1;
        if (node == dest) {
            return cost;
        }
        if (vis[node])continue;
        vis[node] = true;
        for (auto [child,wt]: graph[node]) {
            pq.push({-cost - wt, child});
        }
    }
    return -1;
}

int main() {
    iamspeed
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    cin >> n >> m >> q;
    set<ll> st;
    int id = 1;
    map<ll,ll> mp;
    map<ll, bool> block;
    vector<pair<ll,ll> > pr;
    st.insert(1);
    st.insert(n);
    while (m--) {
        cin >> x >> y >> z;
        st.insert(x);
        st.insert(y);
        pr.push_back({x, y});
    }
    vector<ll> queries(q);
    for (i = 0; i < q; i++) {
        cin >> queries[i];
        st.insert(queries[i]);
    }
    vector<ll> v2;
    copy(st.begin(), st.end(), back_inserter(v2));
    st.clear();
    vector<pair<ll,ll> > v;
    for (ll x: v2) {
        for (i = 0; i <= 6; i++) {
            if (!st.count(x + i) && x + i <= n) {
                st.insert(x + i);
            }
        }
    }
    for (ll val: st) {
        mp[val] = id++;
    }
    ll sz = id;
    for (auto [val,id]: mp) {
        v.push_back({val, id});
    }
    sort(v.begin(), v.end());
    for (i = 0; i <= id + 5; i++) {
        graph[i].clear();
    }
    for (auto [xx,yy]: pr) {
        xx = mp[xx], yy = mp[yy];
        block[xx] = true;
        graph[xx].push_back({yy, 0});
    }
    for (i = 0; i < v.size(); i++) {
        auto [ai,id] = v[i];
        if (block[id])continue;
        int ct = 0;
        for (j = i + 1; j < v.size(); j++) {
            auto [aj,nid] = v[j];
            ll dist = (aj - ai) / 6 + ((aj - ai) % 6 != 0);
            graph[id].push_back({nid, dist});
            if (aj == v[j - 1].first + 1)ct++;
            else ct = 1;
            if (ct >= 6)break;
        }
    }
    for (int id = 0; id < q; id++) {
        cout << dijk(sz, mp[n], mp[queries[id]]) << endl;
    }

    return 0;
}