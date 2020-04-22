#include<cstdio>
#include<cstdlib>
#include<queue>
#include<limits.h>
#include<algorithm>
using namespace std;

typedef struct node{
	int val;
	struct node *left, *right;
}node;

/* Enter your in code here */
void print(node* root) {
   if(root == NULL) {
      return;
   } else {
      print(root->left);
      printf("%d ", root->val);
      print(root->right);
   }
}

int max(int a, int b) {
   return (a >= b) ? a : b;
}

int cari(node *node) {
   if(node==NULL) {
      return 0;
   } 
   return 1 + max(cari(node->left), cari(node->right));
}

bool __checkLeftRight(node *check, int min, int max) {
   if (check==NULL) 
      return true;

   if(check->val < min || check->val > max)
      return false;

   return __checkLeftRight(check->left, min, check->val-1) &&
   __checkLeftRight(check->right, check->val+1, max);
}

bool checkLeftRight(node* check) {
   return (__checkLeftRight(check, -2147483648, 2147483647));
}

bool __is_valid(node *root){
   int left, right;

   if(root == NULL) {
      return true;
   }

   left = cari(root->left);
   right = cari(root->right);
   
   if(abs(left-right) <= 1 && __is_valid(root->left) && __is_valid(root->right)) {
      return true;
   }

   return false;
}

bool is_valid(node *root) {
   if(__is_valid(root) && checkLeftRight(root)) {
      return true;
   }
   return false;
}

/* Enter your in code here */


node* insert(){
   int n;
   scanf("%d", &n);
   if(n < 1)
      return NULL;
  
   node *temp,
        *head = (node*) malloc(sizeof(node));
   queue<node*> q;
   int x;
  
   n--;
   scanf("%d", &x);
   head->val = x;
   q.push(head);

   while(n > 0){
      temp = q.front();
      q.pop();

      scanf("%d", &x);
      if(x == -1)
         temp->left = NULL;
      else{
         node *left = (node*) malloc(sizeof(node));
         left->val = x;
         temp->left = left;
         q.push(left);
         n--;
      }
      if(n > 0){
         scanf("%d", &x);
         if(x == -1)
            temp->right = NULL;
         else{
            node *right = (node*) malloc(sizeof(node));
            right->val = x;
            temp->right = right;
            q.push(right);
            n--;
         }
      }
      else
         temp->right = NULL;
   }

   while(!q.empty()){
      temp = q.front();
      temp->left = NULL;
      temp->right = NULL;
      q.pop();
   }

   return head;
}

int main() {
   node* head = insert();

   print(head);
   printf("\n");

   if( is_valid(head) )
      printf("YES\n");
   else
      printf("NO\n");
   return 0;
}
