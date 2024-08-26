#include<iostream>       // For I/O
#include<vector>         // For Vector
#include<climits>        // For INT_MAX etc..
#include <iostream>      // For standard I/O operations (cin, cout)
#include <vector>        // For dynamic arrays
#include <deque>         // For double-ended queues
#include <list>          // For doubly-linked lists
#include <set>           // For set data structures (unique elements)
#include <map>           // For associative arrays (key-value pairs)
#include <unordered_set> // For hash sets (C++11)
#include <unordered_map> // For hash maps (C++11)
#include <algorithm>     // For algorithms like sort, find, etc.
#include <numeric>       // For numeric operations like accumulate
#include <string>        // For string class
#include <cmath>         // For mathematical functions like sqrt, pow
#include <cstdlib>       // For general utilities like rand, exit

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

void solution(){
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vector<int> arr(w);
    for (int i = 0; i < w;i++){
        cin >> arr[i];
    }
    sort(arr.rbegin(), arr.rend());
    vector<ll> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;j++){
            ll x = min(i + k - 1, n - 1) - max(i, k - 1) + 1;
            ll y = min(j + k - 1, m - 1) - max(j, k - 1) + 1;
            temp.push_back(x * y);
        }
    }
    sort(temp.rbegin(), temp.rend());
    ll ans = 0;
    for (int i = 0; i < w; i++)
    {
        ans += arr[i] * temp[i];
    }
    cout << ans << endl;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        solution();
    }
    return 0;
}