#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, X, Y, Z;
    int count;
    cin >> T;
    while(T--) {
        vector<int> arr;
        count = 0;
        cin >> X >> Y;
        while(X--) {
            cin >> Z;
            if(Z!=0) {
                arr.push_back(Z);
                count++;
            }
            // cout << "# " << count << " " << Y << endl;
            if(Z==0) {
                if(count<Y) {
                    cout << "-1" << endl;
                } else {
                    sort(arr.begin(), arr.end());
                    cout << arr.at(Y-1) << endl;
                }
            }
        }
    }
    return 0;
}
