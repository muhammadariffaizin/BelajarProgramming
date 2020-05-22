#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

typedef pair<int, int> iPair;
typedef pair<int, string> i_sPair;

bool comparator(const i_sPair &a, const i_sPair &b) {
    if (a.second != b.second ) 
        return a.second > b.second; 
  
    return (a.first > b.first); 
}

struct server {
    int data_amount, floor;
    vector<string> datas;
};

class building {
private:
    map<int, server> N;
    array<int, 1001> l_server;

    int serv, conn;

    bool find(string q, int index, unsigned int dist) {
        for (auto x : N[index].datas) {
            if (x == q) {
                return true;
            }
        }
        return false;
    }

public:
    building() {
        this->serv = this->conn = 0;
        // this->l_server.fill(false);
    }
    void reset() {
        serv = 0;
    }

    void insert(int s_datas, int s_floor) {
        N[s_floor] = {s_datas, s_floor};

        l_server[serv] = s_floor;
        
        string temp;
        for (int i = 0; i < s_datas; i++) {
            cin >> temp;
            N[s_floor].datas.push_back(temp);
        }
        serv++;
    }

    void findServer(int needs, int floors, int i) {
        priority_queue<iPair, vector<iPair>, greater<iPair>> delta;
        vector<string> query;
        vector<i_sPair> l_print;
        map<string, int> done;


        for (int i = 0; i < serv; i++) {
            int diff = abs(l_server[i] - floors);
            delta.push(make_pair(diff, l_server[i]));
        }

        string temp;
        for (int i = 0; i < needs; i++) {
            cin >> temp;
            query.push_back(temp);
            done["temp"] = 0;
        }

        while (!delta.empty()) {
            int index = delta.top().second, \
                dist  = delta.top().first;
            
            int first = 0;
            for (auto x : query) {
                if(find(x, index, dist)) {
                    if (done[x] != 1) {
                        cout << "dist of " << x << " is " << dist << endl;
                        l_print.push_back(make_pair(dist, x));
                        done[x] = 1;
                    }

                    if (!first) {
                        conn++;
                        first = 1;
                    }
                }
            }
            delta.pop();
        }

        sort(l_print.begin(), l_print.end(), comparator);

        printf("Client %d:\n", i+1);
        for (auto x : l_print) {
            cout << x.second << endl;
        }
    }
    int n_connection() {
        return conn;
    }

};

int main() {
    building LAN;

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        string name;
        int amount, floors;
        cin >> name >> amount >> floors;
        LAN.insert(amount, floors);

    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int needs, floors;
        cin >> needs >> floors;
        LAN.findServer(needs, floors, i);
    }
    
    cout << "Total Koneksi: " << LAN.n_connection() << endl;
}