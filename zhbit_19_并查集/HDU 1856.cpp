#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <sstream>
#include <utility>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 10000010;
int bcj[maxn],bcj_num[maxn];
void inic() {
    memset(bcj_num, 0, sizeof(bcj_num));
    memset(bcj, 0, sizeof(bcj));
}
int find(int root) {
    int son, tmp;
    son = root;
    while (root != bcj[root])
        root = bcj[root];
    while (son != root) {
        tmp = bcj[son];
        bcj[son] = root;
        son = tmp;
    }
    return root;
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        inic();
        if (n == 0) {
            printf("1\n");
            continue;
        }
        while (n--) {
            int a, b;
            scanf("%d %d", &a, &b);
            if (bcj[a] == 0 && bcj[b] == 0) {
                bcj[a] = a;
                bcj[b] = a;
                bcj_num[a] = 2;
            }
            else if (bcj[a] != 0 && bcj[b] != 0) {
                a = find(a), b = find(b);
                if (a != b) {
                    bcj[a] = b;
                    bcj_num[b] += bcj_num[a]; 
                    bcj_num[a] = 0;
                }
            }
            else if (bcj[a] == 0) {
                bcj[a] = find(b);
                bcj_num[find(b)]++;
            }
            else if (bcj[b] == 0) {
                bcj[b] = find(a);
                bcj_num[find(a)]++;
            }
        }
        printf("%d\n", *max_element(bcj_num,bcj_num+maxn));
    }
    return 0;
}