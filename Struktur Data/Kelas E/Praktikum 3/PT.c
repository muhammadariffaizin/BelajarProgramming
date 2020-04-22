#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct AVLNode_t
{
    int data;
    int cost;
    struct AVLNode_t *left,*right;
    int height;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

AVLNode* _avl_createNode(int value, int cost) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height=1;
    newNode->left = newNode->right = NULL;
    newNode->cost = cost;
    return newNode;
}

AVLNode* _search(AVLNode *root, int value) {
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

int _getHeight(AVLNode* node){
    if(node==NULL)
        return 0; 
    return node->height;
}

int _max(int a,int b){
    return (a > b)? a : b;
}

AVLNode* _rightRotate(AVLNode* pivotNode){

    AVLNode* newParrent=pivotNode->left;
    pivotNode->left=newParrent->right;
    newParrent->right=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->right;
    pivotNode->right=newParrent->left;
    newParrent->left=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftCaseRotate(AVLNode* node){
    return _rightRotate(node);
}

AVLNode* _rightCaseRotate(AVLNode* node){
    return _leftRotate(node);
}

AVLNode* _leftRightCaseRotate(AVLNode* node){
    node->left=_leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode* _rightLeftCaseRotate(AVLNode* node){
    node->right=_rightRotate(node->right);
    return _leftRotate(node);
}

int _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value, int cost){
    
    if(node==NULL)
        return _avl_createNode(value, cost);
    if(value < node->data)
        node->left = _insert_AVL(avl,node->left,value, cost);
    else if(value > node->data)
    	node->right = _insert_AVL(avl,node->right,value, cost);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

    int balanceFactor=_getBalanceFactor(node);
    
    if(balanceFactor > 1 && value < node->left->data)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && value > node->left->data)
		return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && value > node->right->data)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && value < node->right->data)
        return _rightLeftCaseRotate(node);
    
    return node;
}

AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->data == value)
        return true;
    else
        return false;
}

int avl_findCost(AVL *avl, int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return 0;
    
    if (temp->data == value)
        return temp->cost;
    else
        return 0;
}

void avl_insert(AVL *avl,int value, int cost){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value,cost);
        avl->_size++;
    }

}

int main() {
    int N, M;
    int P, Q;
    int X, Y;
    AVL avlku;
    avl_init(&avlku);
    scanf("%d %d", &M, &N);
    int temp=1;
    for(int i=0; i<M; i++) {
        scanf("%d %d",&P, &Q);
        if(P != temp) {
            printf("ID harus urut\n");
            return 0;
        }
        temp++;
        if(Q>0) {
            avl_insert(&avlku, P, Q);
        }
    }
    int total=0;
    for(int i=0; i<N; i++) {
        scanf("%d %d",&X, &Y);
        if(Y<0) {
            printf("Maaf barang tidak tersedia\n");
            continue;
        } else if(Y==0) {
            continue;
        }
        if(avl_find(&avlku, Y)) {
            if(X>0) {
                total += (X * avl_findCost(&avlku, Y));
            }
            // printf("temp = %d\n", total);
        } else {
            printf("Maaf barang tidak tersedia\n");
        }
    }
    printf("%d\n", total);
    return 0;
}