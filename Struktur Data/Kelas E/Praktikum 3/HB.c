#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void check(BSTNode *root, int total, int val, int *result){
    if(root){
        total += root->key;
        if(total < val){
            check(root->left, total, val, result);
            check(root->right, total, val, result);
        }
        if(total==val)
            *result = val;
    }    
}

void notFound(BSTNode *root, int val, int *result){
    if(root){
        if (root->key < val){
            check(root->left, root->key, val, result);
            check(root->right, root->key, val, result);
        }else{
            notFound(root->left,val, result);
            notFound(root->right,val, result);
        }
    }
}

void find(BST *bst, int val, int *result){
    BSTNode *temp = __bst__search(bst->_root, val);

    if (temp == NULL) notFound(bst->_root, val, result);
    else if(temp->key == val) *result = val;
}

int main(){
    int result;
    BST set;
    bst_init(&set);
    
    int N, cases, value;
    scanf("%d", &N);
    
    for(int i=0 ; i<N ; i++){
        scanf("%d %d", &cases, &value);
        if(cases == 1 ){
            bst_insert(&set, value);
        }
        else if(cases == 2){
            find(&set, value, &result);

            result == value ? printf("<3\n") : printf("<>\n");
        }
        result = 0;
    }

    return 0;
}
