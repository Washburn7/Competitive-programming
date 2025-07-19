#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 10;
int n;
struct Tag {
    int add = 0;
    void apply(Tag &t) {
        add += t.add;
    }
}
struct Info {
    i64 mn;
    void apply(Tag &t) {
        mx += t.add;
    }
};
Info operator+(const Info &a, const Info &b) {
    return {min(a.mx, b.mx)};
}
template <class T>
struct SegmentTree {
    int n;
    vector<T> info;
    vector<T> _init;
    SegmentTree() {}
    SegmentTree(int n) {
        _init.assign(n + 1, T());
        init(_init);
    }
    SegmentTree(vector<T> &_init) {
        this->_init = _init;
        init(_init);
    }
    void init(vector<T> &_init) {
        n = (int)_init.size() - 1;
        info.assign(n * 4 + 1, T());
        build(1, 1, n);
    }
    void build(int p, int l, int r) {
        if(l == r) {
            info[p] = _init[l];
            return ;
        }
        int m = (l + r) / 2;
        build(p * 2, l, m);
        build(p * 2 + 1, m + 1, r);
        pull(p);
    };
    void push(int p) {
        tag[p * 2].apply(tag[p]);
        tag[p * 2 + 1].apply(tag[p]);
        tag[p] = Tag();
    }
    void pull(int p) {
        info[p] = info[p * 2] + info[p * 2 + 1];
    }
    void modify(int p, int l, int r, int x, int y, Tag &v) {
        if(l > y || r < x) return ;
        if(l <= x && r >= y) {
            info[p].apply(v);
            tag[p].apply(v);
        }
        else {
            int m = (l + r) / 2;
            push(p);
            if(x <= m) modify(p * 2, l, m, x, y, v);
            else modify(p * 2 + 1, m + 1, r, x, y, v);
            pull(p);
        }
    }
    void modify(int x, int y, Tag &v) {
        modify(1, 1, n, x, v);
    }
    T query(int p, int l, int r, int x, int y) {
        if(l > y || r < x) return T();
        if(x <= l && y >= r) return info[p];
        int m = (l + r) / 2;
        return query(p * 2, l, m, x, y) + query(p * 2 + 1, m + 1, r, x, y);
    }
    T query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};
void solve() {
    cin >> n;
    vector<i64> a(n + 1);
    vector<int> last(n + 1);
    SegmentTree<Info> st(n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        last[a[i]] = i;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}