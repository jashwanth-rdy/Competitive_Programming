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

string solution(){
    int n;
    cin >> n;
    string s = to_string(n);
    if (s.length() <= 2)
        return "NO";
    if(s[0]!='1' || s[1]!='0')
        return "NO";
    string t = s.substr(2);
    if(t[0]=='0')
        return "NO";
    if (t[0] >= '2')
        return "YES";
    if(t[0]=='1'){
        if(t.length()==1)
            return "NO";
        else
            return "YES";
    }
}

int main(){

    int t;
    cin >> t;
    while(t--){
        cout << solution() << endl;
    }
    return 0;
}