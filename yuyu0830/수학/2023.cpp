#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool notPrime[10000] = {0, };

bool isPrime(int t) {
    for (int i = 2; i <= sqrt(t); i++) {
        if (notPrime[i]) continue;
        if (t % i == 0) {
            notPrime[i] = true;
            return false;
        }
    }
    return true;
}

int main() {
    int n; cin >> n;

    int start = 1;

    vector<int> v[2];
    bool e = false;

    v[1].push_back(0);
    
    for (int i = 0; i < n; i++) {
        for (int p : v[!e]) {
            for (int t = 0; t < 10; t++) {
                int cur = p * 10 + t;
                if (isPrime(cur)) v[e].push_back(cur);
            }
        }

        v[!e].clear();
        e = !e;
    }

    for (int i : v[e]) 
        printf("%d\n", i);
}