#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N, X;
    cin >> N;
    set<int> arr;
    while(N--) {
        cin >> X;
        if(arr.find(X) == arr.end()) {
            arr.insert(X);
        } else {
            cout << "SUSAH BANGED WOI!" << endl;
            return 0;
        }
    }
    cout << "NAH GITU DONG, NGEGAS!" << endl;
    return 0;
}