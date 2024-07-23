#include <iostream>
#include <math.h>

using namespace std;

typedef unsigned long long int ll;

ll arr[10000] = {0, };
int cnt = 1;

// 0 ~ t 까지의 1의 개수를 반환
ll f(ll t) {
    int ptLog = cnt, tmp = 0;
    ll pt = pow(2, ptLog - 1), ans = 0;

    while (pt) {
        if (t & pt) {
            ans += arr[ptLog - 1] + 1;
            ans += pt * tmp++;
        }
        pt >>= 1;
        ptLog--;
    }

    return ans;
}

int main() {
    ll a, b, tmp = 1; cin >> a >> b;

    // b까지 arr 배열 누적합 연산
    while (b > tmp) {
        arr[cnt] = (arr[cnt - 1] * 2) + tmp;
        tmp *= 2; cnt++;
    }

    ll ZeroToAVal = f(a); // 0 ~ a - 1 까지의 1의 개수
    ll bVal = f(b);       // 0 ~ b 까지의 1의 개수
    ll aVal = 0;          // a 의 1의 개수
    
    ll pt = pow(2, cnt);
    while (pt) {
        if (a & pt) aVal++;
        pt >>= 1;
    }

    printf("%lld\n", bVal - ZeroToAVal + aVal);
}