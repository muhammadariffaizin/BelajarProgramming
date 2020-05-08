#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
 
int main(){
 
    unsigned int size;
    cin >> size;
 
    int num[size];
    map<int, vector<unsigned int>> num_pos;
 
    for(unsigned int i=0;i<size;i++){
        cin >> num[i];
        num_pos[num[i]].push_back(i);
        // for(int x=0; x<num_pos[num[i]].size(); x++) {
        //     cout << num_pos[num[i]][x] << endl;
        // }
    }
 
    unsigned int TEST,TEST_CASE,left;
    bool found;
    cin >> TEST;
 
    for(int i=1;i<=TEST;i++){
        cin >> TEST_CASE;
        cout << "Case " << i << ":";
        found=false;
        int foundA, foundB;
 
        for(unsigned int front=0;front<size;front++) {
            left=TEST_CASE-num[front]; //possible pair
 
            map<int,vector<unsigned int>>::iterator it=num_pos.find(left); //finding pair
            if(it!=num_pos.end()){
                for(unsigned int list=0;list<it->second.size();list++){
                    if(it->second[list] > front){
                        foundA = front+1;
                        foundB = it->second[list]+1;
                        found = true;
                        break;
                    }
                }
            }
            if (found) break;
        }
 
        if(!found) {
            cout << " " << TEST_CASE << " not found\n";
        } else {
            cout << " " << foundA << " " << foundB << endl;
        }
        cout.flush();
    }
}