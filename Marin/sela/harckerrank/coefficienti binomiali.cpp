#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int bionomiale(int n, int k) {
    if (k == 0 || k == n) return 1;
    return binomiale(n - 1, k - 1) + binomiale(n - 1, k);
}

int main() {
    int n, k;
    cout << "n e k: ";
    cin >> n >> k;
    cout << " = " << binomiale(n, k) << endl;
    return 0;
}
