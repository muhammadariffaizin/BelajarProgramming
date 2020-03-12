#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define ULL unsigned long long int
typedef struct bstnode_t {
    ULL key;
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    ULL _size;
} BST;

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

BSTNode* __bst__createNode(ULL value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, ULL value) {
    if (root == NULL) 
        return __bst__createNode(value);
    if (value < root->key){
        root->left = __bst__insert(root->left, value);
    }
    else if(value > root->key){
        root->right = __bst__insert(root->right, value);
    }
    return root;
}

BSTNode* __bst__search(BSTNode *root, ULL value) {
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

bool bst_find(BST *bst, ULL value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, ULL value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

ULL *kurang(ULL *kurang){
    *kurang = *kurang - 1;
    return kurang;
}

void __bst__inorder(BSTNode *root,ULL *urutan,int *sudah) {
    if (root) {
        __bst__inorder(root->left,urutan,sudah);
        if(*urutan == 1 && *sudah == 0){
            printf("%llu\n", root->key);
            *sudah = 1;
            return;
        }
        else if(*urutan > 1)*urutan-=1;
         __bst__inorder(root->right,urutan,sudah);
    }
}

void __bst__postorder(BSTNode *root,ULL *urutan,int *sudah) {
    if (root) {
        __bst__postorder(root->left,urutan,sudah);
        __bst__postorder(root->right,urutan,sudah);
        if(*urutan == 1 && *sudah == 0){
            printf("%llu\n", root->key);
            *sudah = 1;
            return;
        }
        else if(*urutan > 1)*urutan-=1;

    }
}

void __bst__preorder(BSTNode *root,ULL *urutan,int *sudah) {
    if (root) {

        if(*urutan == 1 && *sudah == 0){
            printf("%llu\n", root->key);
            *sudah = 1;
            return;
        }
        else if(*urutan > 1)*urutan-=1;
        __bst__preorder(root->left,urutan,sudah);
        __bst__preorder(root->right,urutan,sudah);
    }
}

void bst_inorder(BST *bst,ULL *urutan,int *sudah) {

    __bst__inorder(bst->_root,urutan,sudah);
}

void bst_postorder(BST *bst,ULL *urutan,int *sudah) {
    __bst__postorder(bst->_root,urutan,sudah);
}

void bst_preorder(BST *bst,ULL *urutan,int *sudah) {
    __bst__preorder(bst->_root,urutan,sudah);
}


int main(){
    BST set;
    bst_init(&set);
    ULL t;
    scanf("%llu",&t);
    while(t--){
        ULL opsi;
        scanf("%llu",&opsi);
        if(opsi==1){
            ULL sem;
            scanf("%llu",&sem);
            bst_insert(&set,sem);
        }else if(opsi==2){
            char cmd[10];
            ULL cari;
            int sudah=0;
            scanf("%s",cmd);
            scanf("%llu",&cari);
            if(cmd[1] == 'n'){
                bst_inorder(&set,&cari,&sudah);
            }else if(cmd[1] == 'r'){
                bst_preorder(&set,&cari,&sudah);
            }else if(cmd[1] == 'o'){
                bst_postorder(&set,&cari,&sudah);
            }
        }
    }

    return 0;
}