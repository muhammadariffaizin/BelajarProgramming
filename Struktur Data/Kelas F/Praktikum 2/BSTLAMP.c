/*
Author : Ahmad Syafiq Aqil Wafi
NRP : 05111940000089
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int lower[10100] = {};

int lam[10100] = {};
int maxLevel = 1;
int minPower = 0;
int maxPower = 0;

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    int level;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value, int level) {
    if (level > maxLevel) maxLevel = level;
    if (value < minPower) minPower = value;
    if (value > maxPower) maxPower = value;
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->level = level;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, int level) {
    if (root == NULL){
        return __bst__createNode(value,level);
    }

    if (value < root->key)
        root->left = __bst__insert(root->left, value, root->level + 1);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value, root->level + 1);

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

BSTNode* __bst__search__mod(BSTNode *root, int value, int *outLevel) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
        (*outLevel)++;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key)
        root->right = __bst__remove(root->right, value);
    else if (value < root->key)
        root->left = __bst__remove(root->left, value);
    else {

        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
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

bool bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value, 1);
        bst->_size++;
        return true;
    }
    return false;
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

void cableCount(int n){
    printf(">> Interconnected cable: %d",n-1);
}

void longestCable(){
    printf(">> Longest cable: %d",maxLevel-1);
}

void brokenLamp(BSTNode *root){
    int j = 0;
    int x = 0;
    char c = 0;
    c = getchar();
    if (c == ' '){
        while (1){
            scanf("%d",&x);
            c = getchar();
            lam[j++] = x;
            if (c == '\n') break;
        }
    }

    int k = 0;
    int minim = INT_MAX;
    int key = 0;
    for (k = 0;k < j;k++){
        int tempLevel = 1;
        if (!__bst__search__mod(root,lam[k],&tempLevel)){
            printf(">> Error: lamp(s) not found\n\n");
            return;
        }
        if (tempLevel < minim) {
            minim = tempLevel;
            key = lam[k];
        }
    }

    if (j == 1){
        printf(">> Only a lamp inserted. You need minimum of two lamps\n\n");
    } else if (j >= 2){

        int val = 0;

        while (root != NULL){
            val = root->key;
            int lef = 0;
            int rig = 0;

            int trig = 0;
            int k = 0;
            for (;k < j;k++){
                if (lam[k] < root->key){
                    lef++;
                }

                if (lam[k] > root->key){
                    rig++;
                }

                if (lam[k] == root->key){
                    trig = 1;
                    break;
                }
            }
            if (trig){
                break;
            } else if (rig == 0){
                root = root->left;
            } else if (lef == 0){
                root = root->right;
            } else {
                break;
            }
        }

        printf(">> There might be a problem with cable on the lamp %d and so on\n\n",val);
    }
}

int iter = 0;

void totalPowerLower(BSTNode *root) {
    if (root) {
        totalPowerLower(root->left);
        //printf("%d ", root->key);
        lower[iter++] = root->key;
        totalPowerLower(root->right);
    }
}

void totalPower(BSTNode *root,int n){
    int x = 0;
    scanf("%d",&x);

    //CHECK ULANG
    // if (n == 1){
    //     if ((minPower + maxPower == x)){
    //         printf(">> Lamp with total of %d are %d and %d\n\n",x,minPower,maxPower); //GALAU
    //     } else {
    //         printf(">> No lamps found\n\n");
    //     }
    //     return;
    // }

    iter = 0;
    totalPowerLower(root);

    int batas = iter;

    int trig = 0;

    for (iter = 0;iter < batas;iter++){
        int j = batas - 1;;
        for (;j > iter;j--){
            if (lower[iter] + lower[j] == x){
                minPower = lower[iter];
                maxPower = lower[j];
                trig = 1;
                break;
            }
        }
        if (trig){
            break;
        }
    }

    if (trig) {
        printf(">> Lamp with total of %d are %d and %d\n\n",x,minPower,maxPower); //GALAU
    } else {
        printf(">> No lamps found\n\n");
    }
    return;
}

char arr[1010] = {};

int main()
{
    BST lgn;
    bst_init(&lgn);

    int n = 0;

    minPower = INT_MAX;
    maxPower = -1;

    printf("Initializing application...\n");
    printf("Insert your initial configuration:\n");

    int x = 0;
    char c;
    while (1){
        scanf("%d",&x);

        bst_insert(&lgn,x);
        n++;

        c = getchar();
        if (c == '\n') break;
    }

    printf("Starting interactive shell...\n");

    while (1){
        scanf("%s",arr);
        char c = 0;
        c = getchar();
        if (strcmp(arr,"install") == 0){
            if (c == ' '){
                scanf("%d",&x);
                if (bst_insert(&lgn,x)){
                    n++;
                    printf(">> Lamp %d installed\n\n",x);
                } else {
                    printf(">> Lamp %d already exist\n\n",x);
                }
            } else {
                printf(">> Error: argument required -> [lamp_power]\n");
                //printf("    \n");
                printf("\n");
                printf("    install <lamp_power>\n");
                printf("\n");
            }
        } else if (strcmp(arr,"inspect") == 0){
            if (c == ' '){
                scanf("%s",arr);
                if (strcmp(arr,"--all") == 0){
                    longestCable();
                    printf("\n");
                    cableCount(n);
                    printf("\n\n");
                } else if (strcmp(arr,"--longestCable") == 0){
                    longestCable();
                    printf("\n\n");
                } else if (strcmp(arr,"--cableCount") == 0){
                    cableCount(n);
                    printf("\n\n");
                } else {
                    printf(">> Error: invalid argument\n\n");
                }
            } else if (c == '\n'){
                longestCable();
                printf("\n");
                cableCount(n);
                printf("\n\n");
            }
        } else if (strcmp(arr,"analyze") == 0){
            if (c == ' '){
                scanf("%s",arr);
                if (strcmp(arr,"--brokenLamp") == 0){
                    brokenLamp(lgn._root);
                } else if (strcmp(arr,"--totalPower") == 0){
                    totalPower(lgn._root,n);
                } else {
                    printf(">> Error: invalid argument\n\n");
                }
            } else {
                printf(">> Error: argument required -> [options]\n");
                printf(">> You can try one of the following options:\n");
                printf("\n");
                printf("    analyze --brokenLamp <args...>\n");
                printf("    analyze --totalPower <arg>\n");
                printf("\n");
            }
        } else if (strcmp(arr,"exit") == 0){
            printf(">> Exiting application\n\n");
            break;
        } else {
            //if (c == '\n')
            printf(">> Error: unrecognized command\n\n");
        }
    }

    printf("Application stopped\n");

    //system("pausE");

    return 0;
}
