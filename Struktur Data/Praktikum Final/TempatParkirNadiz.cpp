#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K, A, E;
    while(1) {
        cin >> N >> K;
        if(N==0 && K==0) break;
        vector<pair<int,int>> jam;
        vector<int> parkir;
        int max = 0;
        int flag = 0;
        while(N--) {
            cin >> A >> E;
            jam.push_back(make_pair(A,E));
            if(A > max) {
                max = A;
            }
            if(E > max) {
                max = E;
            }
            if(A == E) {
                flag = 1;
                break;
            }
        }
        sort(jam.begin(), jam.end());
        for(int i=0; i<jam.size(); i++) {
            if(jam[i].first == jam[i+1].first || jam[i].second == jam[i+1].second) {
                flag = 1;
            }
        }
        int temp = 0;
        for(int i=0; i<=max; i++) {
            if(!parkir.empty()) {
                int maks = parkir.back();
                if(i == maks) {
                    parkir.pop_back();
                    if(!parkir.empty() && maks >= parkir.back()) {
                        flag = 1;
                    }
                }
            }
            if(i==jam[temp].first) {
                parkir.push_back(jam[temp++].second);
            // cout << flag << endl;
            }
            if(parkir.size() > K) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            cout << "Lancar Jaya" << endl;
        } else if(flag == 1) {
            cout << "Gak Bisa Woi" << endl;
        }
    }
    return 0;
}
