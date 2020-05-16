#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int N;
    char c;
    cin >> N;
    N++;
    while(N--) {
        vector<string> arr;
        string str;
        c = getchar();
        while(1) {
            if(c == ' ' || c == '\n') {
                auto it = find(arr.begin(), arr.end(), str);
                if(it == arr.end() && str.size() != 0) {
                    arr.push_back(str);
                    // cout << str << endl;
                } else {
                    // cout << "( " << str << " )" << endl;
                }
                str.clear();
                if(c == '\n') break;
            } else {
                str.push_back(c);
            }
            c = getchar();
        }
        sort(arr.begin(), arr.end());
        for(unsigned int i=0; i<arr.size(); i++) {
            cout << arr[i];
            if(i < arr.size() - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }
    return 0;
}