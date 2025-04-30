#include <iostream>
#include <string>

using namespace std;

int arr[1001][1001] = {0, };
string str1, str2;

void print(int x, int y) {
    if (!arr[x][y]) return;

    if (str1[x - 1] == str2[y - 1]) {
        print(x - 1, y - 1);
        printf("%c", str1[x - 1]);
        return;
    }

    arr[x - 1][y] > arr[x][y - 1] ? print(x - 1, y) : print(x, y - 1);
}

int main() {
    cin >> str1 >> str2;

    int len1 = str1.size(), len2 = str2.size();

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (!i || !j) arr[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1]) arr[i][j] = arr[i - 1][j - 1] + 1;
            else arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
        }
    }

    printf("%d\n", arr[len1][len2]);
    print(len1, len2);
}