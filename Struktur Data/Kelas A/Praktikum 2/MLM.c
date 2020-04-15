/*
    Nama    : Bayu Eka Prawira
    NRP     : 05111940000042
    Kelas   : Struktur Data A
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t {
    int key;
    int parent;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

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

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

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

// This function finds predecessor of key in BST. 
BSTNode* findPred(BSTNode* _root, int a, int b) 
{ 
    while(_root != NULL)
    {
    	if(a == _root->key || b == _root->key)
    	{
    		if(_root->left != NULL || _root->right != NULL)
    		{
    			if(_root->left != NULL && (a == _root->left->key || b == _root->left->key))
    				return _root;
    			else if(_root->right != NULL && (a == _root->right->key || b == _root->right->key))
    				return _root;
			}
			else
				return NULL;
		}
		else if(a == _root->left->key || a == _root->right->key)
		{
			if(b ==  _root->left->key || b == _root->right->key)
			{
				return _root;
			}
		}
		else if(a != _root->key || b != _root->key)
		{
			if(a < _root->key || b < _root->key)
				_root = _root->left;
			else if(a > _root->key || b > _root->key)
				_root = _root->right;
		}
	}
	return _root;
} 

void findRelation(BST *bst, int a, int b)
{
	BSTNode* temp = findPred(bst->_root,a,b);
	if(temp == NULL)
	{
		printf("Data tidak valid.\n");
		return;
	}
	else
	{
		printf("%d\n",temp->key);
	}
}

int main()
{
    BST set;
//    BST *bst;
    bst_init(&set);
	int testcase,i;
	scanf("%d",&testcase);
	int ch,in;
	int a,b;
	for(i=0;i<testcase;i++)
	{
		scanf("%d",&ch);
		if(ch == 1)
		{
			scanf("%d",&in);
			bst_insert(&set,in);
		}
		else if(ch == 2)
		{
			scanf("%d %d",&a,&b);
			findRelation(&set,a,b);
		}
	}
	
    return 0;
}
