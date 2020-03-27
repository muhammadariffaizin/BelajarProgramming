#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t {
    int key;
    int jarak;
    int min;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
} BST;

BSTNode* __bst__createNode(int value, int jarak) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    newNode->jarak = jarak;
    newNode->min = 2147483647;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, int jarak) {
    if (root == NULL)
        return __bst__createNode(value, jarak);

    if (value < root->key) {
        root->left = __bst__insert(root->left, value, jarak);
    } else if (value > root->key) {
        root->right = __bst__insert(root->right, value, jarak);
    }
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

void bst_insert(BST *bst, int value,int dist) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value, dist);
    }
}

int __bst__minimize(BSTNode* root) {
    if(root->left == NULL && root->right == NULL) {
        root->min = 0;
        return 0;
    } else {
        int lchild, rchild;
        if(root->left) {
            lchild = __bst__minimize(root->left) + root->left->jarak;
            root->min = lchild;
        }
        if(root->right) {
            rchild = __bst__minimize(root->right) + root->right->jarak;
            if(root->min > rchild) {
                root->min = rchild;
            }
        }
        return root->min;
    }
    return 0;
}

void __bst__minParent(BSTNode *root) {
    int temp;
    if(root->left) {
        if(root->left->left || root->left->right) {
            temp = root->left->jarak + root->min;
            if(root->left->min > temp){
                root->left->min = temp;
            }
            __bst__minParent(root->left);
        }
    }
    if(root->right) {
        if(root->right->left || root->right->right) {
            temp = root->right->jarak + root->min;
            if(root->right->min > temp){
                root->right->min = temp;
            }
            __bst__minParent(root->right);
        }
    }
}

void bst_minim(BST *bst) {
    bst->_root->min = __bst__minimize(bst->_root);
    __bst__minParent(bst->_root);
}

int bst_findMinim(BST *bst, int cari) {
    BSTNode *temp = __bst__search(bst->_root, cari);
    if(temp){
        return temp->min;
    } else {
        return 0;
    }
}

int main()
{
    BST set;
    bst_init(&set);

    int N, M, Q, R;
    int ai, bi;
    int result;

    scanf("%d", &N);
    scanf("%d", &M);
    bst_insert(&set, M, 0);
    --N;
    while(N--) {
        scanf("%d %d", &ai, &bi);
        bst_insert(&set, ai, bi);
    }
    bst_minim(&set);
    
    scanf("%d", &Q);
    while(Q--) {
        scanf("%d", &R);
        result = bst_findMinim(&set, R);
        printf("%d\n", result);
    }

    return 0;
}