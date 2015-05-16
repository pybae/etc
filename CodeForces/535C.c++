#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll a, b, n;
ll l, t, m;

int main(int argc, char *argv[])
{
    cin >> a >> b >> n;
    while (n--) {
        cin >> l >> t >> m;
        ll left = l;
        ll right = (t - a) / b + 1;
        ll ans = -1;

        while (left <= right) {
            ll mid = left + (right - left) / 2;
            if ((mid - l + 1)*a + ((b * (mid - l + 1) * (l + mid - 2)) / 2) <= m*t) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
