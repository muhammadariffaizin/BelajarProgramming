#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct bstnode_t {
    unsigned long long key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(unsigned long long value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, unsigned long long value) {
    if (root == NULL)
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);

    return root;
}

BSTNode* __bst__search(BSTNode *root, unsigned long long value) {
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

BSTNode* __bst__remove(BSTNode *root, unsigned long long value) {
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

void __bst__inorder(BSTNode *root, int syarat) {
    if (root) {
        __bst__inorder(root->left, syarat);
        if(syarat == 1) {
            if(root->key % 2 == 0) {
                printf("%llu\n", root->key);
            }
        } else if (syarat == 2) {
            if(root->key % 2 == 1) {
                printf("%llu\n", root->key);
            }
        } else if (syarat == 3) {
            int prime = 0;
            for(unsigned long long i=2; i<root->key; i++) {
                if(root->key % i == 0) {
                    prime = 1;
                    break;
                }
            }
            if(prime == 0 && root->key > 1) {
                printf("%llu\n", root->key);
            }
        } else if (syarat == 4) {
            printf("%llu\n", root->key);
        }
        __bst__inorder(root->right, syarat);
    }
}

void __bst__postorder(BSTNode *root, int syarat) {
    if (root) {
        __bst__postorder(root->left, syarat);
        __bst__postorder(root->right, syarat);
        if(syarat == 1) {
            if(root->key % 2 == 0) {
                printf("%llu\n", root->key);
            }
        } else if (syarat == 2) {
            if(root->key % 2 == 1) {
                printf("%llu\n", root->key);
            }
        } else if (syarat == 3) {
            int prime = 0;
            for(unsigned long long i=2; i<root->key; i++) {
                if(root->key % i == 0) {
                    prime = 1;
                    break;
                }
            }
            if(prime == 0 && root->key > 1) {
                printf("%llu\n", root->key);
            }
        } else if (syarat == 4) {
            printf("%llu\n", root->key);
        }
    }
}

void __bst__preorder(BSTNode *root, int syarat) {
    if (root) {
        if(syarat == 1) {
            if(root->key % 2 == 0) {
                printf("%llu\n", root->key);
            }
        } else if (syarat == 2) {
            if(root->key % 2 == 1) {
                printf("%llu\n", root->key);
            }
        } else if (syarat == 3) {
            int prime = 0;
            for(unsigned long long i=2; i<root->key; i++) {
                if(root->key % i == 0) {
                    prime = 1;
                    break;
                }
            }
            if(prime == 0 && root->key > 1) {
                printf("%llu\n", root->key);
            }
        } else if (syarat == 4) {
            printf("%llu\n", root->key);
        }
        __bst__preorder(root->left, syarat);
        __bst__preorder(root->right, syarat);
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

void bst_inorder(BST *bst, int syarat) {
    __bst__inorder(bst->_root, syarat);
}

void bst_postorder(BST *bst, int syarat) {
    __bst__postorder(bst->_root, syarat);
}

void bst_preorder(BST *bst, int syarat) {
    __bst__preorder(bst->_root, syarat);
}

int main()
{
    BST set;
    bst_init(&set);

    unsigned long long input;
    scanf("%llu", &input);
    bst_insert(&set, input);
    while(input != -1) {
        scanf("%llu", &input);
        if(input != -1) {
            bst_insert(&set, input);
        }
    }
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        char command[100], syarat[100];
        int nilai;
        scanf("%s %s", command, syarat);
        printf("Command : #%d\n", i+1);
        if(strcmp(syarat, "genap") == 0) {
            nilai = 1;
        } else if (strcmp(syarat, "ganjil") == 0) {
            nilai = 2;
        } else if (strcmp(syarat, "prima") == 0) {
            nilai = 3;
        } else if (strcmp(syarat, "semua") == 0) {
            nilai = 4;
        }
        if(strcmp(command, "inorder") == 0) {
            bst_inorder(&set, nilai);
        } else if(strcmp(command, "postorder") == 0) {
            bst_postorder(&set, nilai);
        } else if(strcmp(command, "preorder") == 0) {
            bst_preorder(&set, nilai);
        }
    }

    return 0;
}
