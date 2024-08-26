#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n;i++){
            cin >> arr[i];
        }
        for (int i = 0; i < n;i++){
            int temp = arr[i] + 1;
            if(temp>n)
                temp = 1;
            cout << temp << " ";
        }
        cout << endl;
    }
}