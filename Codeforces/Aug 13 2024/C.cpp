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
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int m;
    cin >> m;
    vector<string> s(m);
    for (int i = 0; i < m;i++){
        cin >> s[i];
    }
    unordered_map<int, char> mp1;
    unordered_map<char, int> mp2;

    for (int j = 0; j < m; j++)
    {
        int len = s[j].length();
        string t = s[j];
        if (len != n)
        {
            cout << "NO" << endl;
        }
        else
        {
            mp1.clear();
            mp2.clear();
            bool flag = true;
            for (int i = 0; i < n; i++)
            {
                if(!mp1.count(arr[i])){
                    if(!mp2.count(t[i])){
                        mp1[arr[i]] = t[i];
                        mp2[t[i]] = arr[i];
                    }else{
                        cout << "NO" << endl;
                        mp1.clear();
                        mp2.clear();
                        flag = false;
                        break;
                    }
                }else{
                    if(!mp2.count(t[i])){
                        cout << "NO" << endl;
                        mp1.clear();
                        flag = false;
                        mp2.clear();
                        break;
                        // mp1[arr[i]] = t[i];
                        // mp2[t[i]] = arr[i];
                    }else{
                        if(mp1[arr[i]]!=t[i] || mp2[t[i]]!=arr[i]){
                            cout << "NO" << endl;
                            mp1.clear();
                            mp2.clear();
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if(flag)
                    cout << "YES" << endl;
        }
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