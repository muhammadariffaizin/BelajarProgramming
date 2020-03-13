#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
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


int bst_left(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if(temp->key == value) {
        if(temp->left!=NULL) {
            temp = temp->left;
            return temp->key;
        }
    }
    return -1;
}

int bst_right(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if(temp->key == value) {
        if(temp->right!=NULL) {
            temp = temp->right;
            return temp->key;
        }
    }
    return -1;
}

BSTNode* __bst__searchParent(BSTNode *root, int value) {
    BSTNode *temp = NULL;
    while (root != NULL) {
        if (value < root->key) {
            temp = root;
            root = root->left;
        }else if (value > root->key){
            temp = root;
            root = root->right;
        }else{
            return temp;
        }
    }
    return temp;
}

int bst_findParent(BST *bst, int value) {
    BSTNode *temp = __bst__searchParent(bst->_root, value);
    if(temp == NULL) {
        return -1;
    } else {
        return temp->key;
    }
}

int main()
{
    BST set;
    bst_init(&set);

    int Q, query;
    scanf("%d", &Q);

    for(int i=0; i<Q; i++) {
        scanf("%d", &query);
        if(query == 1) {
            int K;
            scanf("%d", &K);
            bst_insert(&set, K);
        } else if(query == 2) {
            int X;
            char S[100];
            scanf("%s %d", S, &X);
            if(strcmp(S, "anaK") == 0) {
                int A, B;
                A = bst_left(&set, X);
                B = bst_right(&set, X);
                if(A<1 && B<1) {
                    printf("diManakah Anak- aNakkuu :(\n");
                    break;
                }
                if(A<1) {
                    printf("- ");
                } else {
                    printf("%d ", A);
                }
                if(B<1) {
                    printf("-\n");
                } else {
                    printf("%d\n", B);
                }
            } else if(strcmp(S, "ibU") == 0) {
                int A;
                A = bst_findParent(&set, X);
                if(A == -1) {
                    printf("Aku adalaH sesepuH\n");
                } else {
                    printf("%d\n", A);
                }
            }
        }
    }
    return 0;
}
