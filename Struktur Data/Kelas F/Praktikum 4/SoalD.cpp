/*
Soal D - "Soal Wibu 1"
AC di Praktikum :)
*/


#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void decConvert(unsigned long long num) {
    array<int, 32> binaryNum;

    int i = 0;
    while (num > 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        cout << binaryNum[j];
    }
}

unsigned long long toNumbers(string str) {
    unsigned long long num = 0, base = 1;

    for (int i = str.length() - 1; i >= 0; i--) {
        num += (str[i] - 48) * base;
        base = base * 10;
    }

    return num;
}

unsigned long long binConvert(string bin) {
    unsigned long long dec_num = 0, base = 1;
    for (int i = bin.length() - 1; i >= 0; i--) {
        dec_num += (bin[i] - 48) * base;
        base = base * 2;
    }

    return dec_num;
}

class chall {
    vector<string> nums;
    vector<char> type;
    vector<unsigned long long> fin;

    int size, d_amount, b_amount;

    public: 
    void init() {
        size = d_amount = b_amount = 0;
    }

    void insert(char ty, string str) {
        type.push_back(ty);
        nums.push_back(str);

        if (ty == 'b') {
            b_amount++;
        }
        else {
            d_amount++;
        }

        size++;
    }

    void decision() {
        if (d_amount > b_amount) {
            for (int i = 0; i < size; i++) {
                cout << fin[i];
                if (i != size - 1) cout << endl;
            }
        }
        else {
            //display binary
            toBinary();
        }
    }

    void allToDec() {
        for (int i = 0; i < size; i++) {
            if (type[i] == 'b') {
                fin.push_back(binConvert(nums[i]));
            }
            else {
                fin.push_back(toNumbers(nums[i]));
            }
        }
        sort(fin.begin(), fin.end());
    }

    void toBinary() {
        for (int i = 0; i < size; i++) {
            decConvert(fin[i]);
            if (i != size - 1) cout << endl;
        }
    }

};

int main() {
    int N;
    char type;
    string num;

    chall something;
    something.init();

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> type >> num;
        something.insert(type, num);
    }
    something.allToDec();
    something.decision();
}