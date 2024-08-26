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
    if(n&1){
        vector<int> arr(n);
        int c = 1;
        for (int i = 0; i < n / 2; i++)
        {
            arr[i] = c++;
            arr[n - i - 1] = c++;
        }
        arr[n / 2] = c;

        for (int i = 0; i < n;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main(){

    int t;
    cin >> t;
    while(t--){
        solution();
    }
    return 0;
}