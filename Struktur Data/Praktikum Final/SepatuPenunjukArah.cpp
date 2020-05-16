#include <iostream>
#include <cmath>

using namespace std;

unsigned long long getTen(unsigned long long a, unsigned long long b) {
    return (a/10) - (b/10);
}

unsigned long long getResult(int N) {
    unsigned long long atas = 1, bawah = 1, tengah = 1, jarak = 0, ten, prevA=1, prevB=1;
    for(int i=1; i<N; i++) {
        ten = 0;
        jarak++;
        prevA = atas;
        prevB = bawah;
        if(i%2 != 0) {
            if((atas+1)%10==0) {
                atas++;
            }
            atas = atas + 1;
            bawah = atas + jarak;
            ten = getTen(bawah, atas);
            prevB = bawah;
            bawah += ten;
            while(getTen(bawah, prevB)) {
                unsigned long long temp = bawah;
                bawah += getTen(bawah, prevB);
                prevB = temp;
                // cout << prevB << " " << bawah << endl;
            }
        } else {
            if((bawah+1)%10==0) {
                bawah++;
            }
            bawah = bawah + 1;
            atas = bawah + jarak;
            ten = getTen(atas, bawah);
            prevA = atas;
            atas += ten;
            while(getTen(atas, prevA)) {
                unsigned long long temp = atas;
                atas += getTen(atas, prevA);
                prevA = temp;
                // cout << prevA << " " << atas << " " << ten << endl;
            }
            
        }
        if(i%2 == 0) {
            tengah = atas - (i/2);
            tengah -= getTen(atas, tengah);
            // if(tengah%10 == 0) tengah--;
        } else {
            tengah = atas + (i/2);
            tengah += getTen(tengah, atas);
            // if(tengah%10 == 0) tengah++;
        }
        // cout << atas << " " << bawah << " " << tengah << " " << jarak << endl;
    }
    return tengah;
}

unsigned long long range(unsigned long long a, unsigned long long b) {
    if(a == b) return b;
    unsigned long long res = getTen(b, a);
    // cout << res << endl;
    if(res > 0) {
        return range(b, b+res);
    }
    return b+res;
}

unsigned long long getResult2(int N) {
    unsigned long long res = floor(((N*N)+1)/2), val;
    val = range(0, res);
    return val;
}

int main() {
    int N;
    cin >> N;
    // for(int i=1; i<=N; i++) {
    //     cout << getResult2(i) << " " << getResult(i) << " " << getResult(i) - getResult2(i) << endl;
    // }
    cout << getResult2(N) << endl;
    return 0;
}
