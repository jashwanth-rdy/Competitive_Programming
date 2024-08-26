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
    int n;
    cin >> n;
    vector<int> parent(n + 1, -1);
    auto f = [&](int i, int node, auto &&self) -> void
    {
        cout << "? " << i << " " << node << endl;
        int x;
        cin >> x;
        if(i==x)
            parent[node] = i;
        else
            self(x, node, self);
    };

    for (int i = 2; i <= n;i++)
        f(1, i, f);
    cout << "! ";

    for (int i = 2; i <= n;i++){
        cout << i << " " << parent[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solution();
    }
    return 0;
}