#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

typedef set<pair<string,int>> nSet;
typedef pair<int, string> i_sPair;

struct Servers {
    string name;
    int floor_s;
    vector <string> Datas;
};

struct Client{
    int floor_c;
    vector <string> Asked;
};

class Building {
private:
    vector<Servers> N;
    vector<Client> C;
    set <string> NeededData;
    map<string, nSet> processed;

    void find() {
        nSet tempSet;

        for (auto it = NeededData.begin(); it != NeededData.end(); it++) {
            tempSet.clear();
            for (auto itr = N.begin(); itr != N.end(); itr++) {
                for (auto xtr = itr->Datas.begin(); xtr != itr->Datas.end(); xtr++) {
                    if (*it == *xtr) {
                        tempSet.insert(make_pair(itr->name, itr->floor_s));
                    }
                }
            }
            processed.insert({*it, tempSet});
        }
    }
public:
    void insert_s(string s_name, int s_floor, int s_data) {
        string data_name;
        Servers temp;
        vector<string> tempData;
        for (int i = 0; i < s_data; i++) {
            cin >> data_name;
            tempData.push_back(data_name);
        }
        temp = {s_name, s_floor};
        temp.Datas.swap(tempData);
        N.push_back(temp);

        return;
    }

    void insert_c(int c_floor, int c_needs) {
        Client temp;
        vector<string> tempData;
        string dataName;

        for (int i = 0; i < c_needs; i++) {
            cin >> dataName;
            tempData.push_back(dataName);
            NeededData.insert(dataName);
        }
        temp = {c_floor};
        temp.Asked.swap(tempData);
        C.push_back(temp);

        return;
    }

    void findServer() {
        find();
        int clientC = 1, conn = 0;

        for (auto it = C.begin(); it != C.end(); it++) {
            set<i_sPair> orders;
            set<string> connected;

            int cLevel = (*it).floor_c;

            for (auto itr = it->Asked.begin(); itr != it->Asked.end(); itr++) {
                int diff = INT_MAX;
                nSet tempSet = processed[*itr];

                for (auto xtr = tempSet.begin(); xtr != tempSet.end(); xtr++) {
                    connected.insert(xtr->first);
                    diff = min(diff, abs(xtr->second - cLevel));
                }
                orders.insert(make_pair(diff, *itr));
            }

            printf("Client %d:\n", clientC);
            for (auto p = orders.begin(); p != orders.end(); p++) {
                cout << (*p).second << endl;
        }

            conn += connected.size();
            clientC++;
        }

        printf("Total Koneksi: %d\n", conn);

        return;
    }

};

int main() {
    Building LAN;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        string name;
        int amount, floors;
        cin >> name >> amount >> floors;
        LAN.insert_s(name, floors, amount);
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int needs, location;
        scanf("%d%d", &needs, &location);
        LAN.insert_c(location, needs);
    }

    LAN.findServer();

    return 0;
}
