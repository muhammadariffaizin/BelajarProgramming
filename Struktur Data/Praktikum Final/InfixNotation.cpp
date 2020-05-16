#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

#define A 10080
#define B 1100
#define C 11180
#define D 12280

using namespace std;

int mod(string num, int a) { 
    int res = 0; 
  
    for (int i = 0; i < num.length(); i++) 
         res = (res*10 + (int)num[i] - '0') % a; 
  
    return res; 
} 
int precedence(char op){ 
    if(op == '+'||op == '-') 
    return 1; 
    if(op == '*'||op == '/') 
    return 2; 
    return 0; 
} 
  
// Function to perform arithmetic operations. 
int applyOp(int a, int b, char op){ 
    switch(op){ 
        case '+': return a + b; 
        case '-': return a - b; 
        case '*': return a * b; 
        case '/': return a / b; 
    } 
    return 0;
} 
  
// Function that returns value of 
// expression after evaluation. 
int evaluate(string tokens){ 
 unsigned long long i; 
  
 stack <int> values; 
 
 stack <char> ops; 
 
 for(i = 0; i < tokens.length(); i++){ 
  
  if(tokens[i] == ' ') 
   continue; 
  
  else if(tokens[i] == '('){ 
   ops.push(tokens[i]); 
  } 
  
  else if(tokens[i] == 'A')
            values.push(A);
        else if(tokens[i] == 'B')
            values.push(B);
        else if(tokens[i] == 'C')
            values.push(C);
        else if(tokens[i] == 'D')
            values.push(D);
  
  else if(tokens[i] == ')') 
  { 
   while(!ops.empty() && ops.top() != '(') 
   { 
    int val2 = values.top(); 
    values.pop(); 
    
    int val1 = values.top(); 
    values.pop(); 
    
    char op = ops.top(); 
    ops.pop(); 
    
    values.push(applyOp(val1, val2, op)); 
   } 
   
   if(!ops.empty()) 
   ops.pop(); 
  } 
  
  else
  { 
   while(!ops.empty() && precedence(ops.top()) 
        >= precedence(tokens[i])){ 
    int val2 = values.top(); 
    values.pop(); 
    
    int val1 = values.top(); 
    values.pop(); 
    
    char op = ops.top(); 
    ops.pop(); 
    
    values.push(applyOp(val1, val2, op)); 
   } 
   
   ops.push(tokens[i]); 
  } 
 } 

 while(!ops.empty()){ 
  int val2 = values.top(); 
  values.pop(); 
    
  int val1 = values.top(); 
  values.pop(); 
    
  char op = ops.top(); 
  ops.pop(); 
    
  values.push(applyOp(val1, val2, op)); 
 } 
 return values.top(); 
}

int main() {
    // int A = 10080;
    // int B = 1100;
    // int C = 11180;
    // int D = 12280;

    int T, N;

    cin >> T;
    while(T--) {
        cin >> N;
        char c;
        string input;
        c = getchar();
        while(1) {
            c = getchar();
            if(c == '\n') break;
            else {
                input.push_back(c);
            }
        }
        // cout << input << endl;
        int res = evaluate(input);
        string str = to_string(res);
        string hasil;
        while(N--) {
            for(int i=0; i<str.length(); i++) {
                hasil.push_back(str[i]);
            }
        }
        res = mod(hasil, 3331);
        cout << res << endl;
    }
    
    return 0;
}
