#include <bits/stdc++.h>

using namespace std;


vector<int> LIS(vector<int> &a, int s, int e) {
    vector<int> seq(a.size(), 0);
    vector<int> lis(a.size(), 0);
    int len = 0;
    if (s == 0) {
        for (int i = s; i < e; ++i) {
            auto it = lower_bound(seq.begin(), seq.begin() + len, a[i]);
            if (it == seq.begin() + len) {
                seq[len++] = a[i];        //append if current element (a[i]) is greater than last element in seq.
            } else {
                *it = a[i];              //replace with the element that is greater than or equal to a[i].
            }
            lis[i] = it - seq.begin() + 1;
        }
    } else {
        for (int i = s; i >= e; --i) {
            auto it = lower_bound(seq.begin(), seq.begin() + len, a[i]);
            if (it == seq.begin() + len) {
                seq[len++] = a[i];        //append if current element (a[i]) is greater than last element in seq.
            } else {
                *it = a[i];              //replace with the element that is greater than or equal to a[i].
            }
            lis[i] = it - seq.begin() + 1;
        }
    }
    return lis;
}

int main() {
    int n, ans, x, lis, mini;
    while (scanf("%d", &n) != EOF) {
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        lis = 1;
        vector<int> lis_fromLeft = LIS(a, 0, n);
        vector<int> lis_fromRight = LIS(a, n - 1, 0);
        for (int i = 0; i < n; ++i) {
            mini = min(lis_fromLeft[i], lis_fromRight[i]);
            lis = max(lis, mini * 2 - 1);
        }
        cout << lis << endl;
    }
    return 0;
}
