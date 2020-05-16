#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int idA=0, idB=0;
    string input;
    vector<pair<int,string>> branch, feature;
    int ind = 0, pos = 0;;
    while(1) {
        cin >> input;
        if(input == "commit") {
            string nama;
            cin >> nama;
            if(ind == 0) {
                pair<int,string> x = make_pair(idA,nama);
                branch.push_back(x);
                pos = idA;
                idA++;
            } else if(ind == 1) {
                pair<int,string> x = make_pair(idB,nama);
                feature.push_back(x);
                pos = idB;
                idB++;
            }
        } else if (input == "reset") {
            int del;
            cin >> del;
            if(ind == 0) {
                for(int l = branch.size()-1; l>=0; l--) {
                    if(branch[l].first==del) {
                        pos = l;
                        cout << "Anda berada di commit " << branch[l].second << endl;
                        while(branch.back().first != del) {
                            branch.pop_back();
                        }
                        break;
                    }
                }
            } else if(ind == 1) {
                for(int l = feature.size()-1; l>=0; l--) {
                    if(feature[l].first==del) {
                        pos = l;
                        cout << "Anda berada di commit " << feature[l].second << endl;
                        while(feature.back().first != del) {
                            feature.pop_back();
                        }
                        break;
                    }
                }
            }
        } else if (input == "log") {
            if(ind == 0) {
                if(branch.size()==0) {
                    cout << endl;
                } else {
                    for(int l = branch.size()-1; l>=0; l--) {
                        cout << branch[l].first << endl << branch[l].second << endl;
                    }
                }
            } else if(ind == 1) {
                if(feature.size()==0) {
                    cout << endl;
                } else {
                    for(int l = feature.size()-1; l>=0; l--) {
                        cout << feature[l].first << endl << feature[l].second << endl;
                    }
                }
            }
        } else if (input == "checkout") {
            int idx;
            cin >> idx;
            if(ind==0) {
                int flag = 0;
                for(int l=0; l<=branch.size()-1; l++) {
                    if(branch[l].first == idx) {
                        flag = 1;
                        pos = l;
                        cout << "Anda berada di commit " << branch[l].second << endl;
                    }
                }
                if(flag == 0) {
                    cout << "ID tidak ditemukan" << endl;
                }
            }else if(ind == 1) {
                int flag = 0;
                for(int l=0; l<=feature.size()-1; l++) {
                    if(feature[l].first == idx) {
                        flag = 1;
                        pos = l;
                        cout << "Anda berada di commit " << feature[l].second << endl;
                    }
                }
                if(flag == 0) {
                    cout << "ID tidak ditemukan" << endl;
                }

            }
        } else if (input == "status") {
            if(ind == 0) {
                cout << "Anda berada di commit " << branch[pos].second << endl;
            } else if(ind == 1) {
                cout << "Anda berada di commit " << feature[pos].second << endl;
            }
        } else if (input == "branch") {
            string choice;
            cin >> choice;
            if(choice == "master") {
                ind = 0;
                if(branch.empty()) {
                    pos = 0;
                } else {
                    pos = branch[branch.size()-1].first;
                }
            } else if(choice == "feature") {
                ind = 1;
                if(feature.empty()) {
                    pos = 0;
                } else {
                    pos = feature[feature.size()-1].first;
                }
            }
        } else if (input == "sync") {
            if(ind == 0) {
                for(int l = min(branch.size(),feature.size())-1; l >= 0; l--) {
                    if(branch[l].first == feature[l].first && branch[l].second == feature[l].second) {
                        while(feature[l].first != feature.back().first) {
                            feature.pop_back();
                        }
                        break;
                    }
                }
            } else if(ind == 1) {
                for(int l = min(branch.size(),feature.size())-1; l >= 0; l--) {
                    if(branch[l].first == feature[l].first && branch[l].second == feature[l].second) {
                        while(branch[l].first != branch.back().first) {
                            branch.pop_back();
                        }
                        break;
                    }
                }
            }
        } else if (input == "quit") {
            break;
        } 
    }

    return 0;
}
