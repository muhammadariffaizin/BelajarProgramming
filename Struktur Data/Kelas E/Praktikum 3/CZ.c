#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

long long n;

typedef struct AVLNode_t
{
    long long data, total;
    struct AVLNode_t *left,*right;
    long long height;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned long _size;
}AVL;

AVLNode* _avl_createNode(int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->total = 1;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
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

long long _getHeight(AVLNode* node){
    if(node==NULL)
        return 0; 
    return node->height;
}

long long _getTotal(AVLNode* node){
    if(node==NULL)
        return 0;
    return node->total;
}

long long _max(long long a,long long b){
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
    
    pivotNode->total=_getTotal(pivotNode->left)+_getTotal(pivotNode->right)+1;
    newParrent->total=_getTotal(newParrent->left)+_getTotal(newParrent->right)+1;
    
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
    
    pivotNode->total=_getTotal(pivotNode->left)+_getTotal(pivotNode->right)+1;
    newParrent->total=_getTotal(newParrent->left)+_getTotal(newParrent->right)+1;
    
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

long long _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

AVLNode* _insert_AVL(AVL *avl, AVLNode *node,long long value){
    if(node==NULL)
        return _avl_createNode(value);
    if(value < node->data)
        node->left = _insert_AVL(avl,node->left,value);
    else if(value > node->data)
        node->right = _insert_AVL(avl,node->right,value);
    
    node->total= 1 + _getTotal(node->left) + _getTotal(node->right);
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right));

    long long balanceFactor=_getBalanceFactor(node);
    
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

void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, long long value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl,long long value){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value);
        avl->_size++;
    }

}

long long sum = 0, minRange, maxRange;

void preorderMore(AVLNode *root) {
    if (root) {
        preorderMore(root->left);
        preorderMore(root->right);
        sum += n - abs(root->data);
    }
}

void findMax(AVLNode *root, long long value){
    if(root){
        if(root->data == value)
            maxRange = root->data;
        else if(root->data < value){
            maxRange = root->data;
            findMax(root->right, value);
        }
        else{
            AVLNode *temp = root->left;
            while(temp != NULL){
                if(temp->data <= value){
                    findMax(temp, value);
                    break;
                }
                temp = temp->left;
            }
        }
    }
}

void findMin(AVLNode *root, long long value){
    if(root){
        if(root->data == value)
            minRange = root->data;
        else if(root->data > value){
            minRange = root->data;
            findMin(root->left, value);
        }
        else{
            AVLNode *temp = root->right;
            while(temp != NULL){
                if(temp->data >= value){
                    findMin(temp, value);
                    break;
                }
                temp = temp->right;
            }
        }
    }
}

long long findIndex(AVLNode *root, long long value){
    long long index = 0;
    while(root != NULL){
        if (value < root->data)
            root = root->left;
        else if (value > root->data){
            index += _getTotal(root->left) + 1;
            root = root->right;
        }
        else{
            index += _getTotal(root->left);
            // printf("LST:%d %d\n", _getTotal(root->left), root->data);
            return index;
        }
    }
    return 0;
}

void rangeAVL(AVLNode *rootMore, AVLNode *root,long long range){
    if(range >= 0){
        minRange = INT_MIN;
        maxRange = INT_MAX;

        findMin(rootMore, (-1)*range);
        findMax(rootMore, range);

        // printf("min:%d max:%d r:%d\n", minRange, maxRange, range);

        if(minRange != INT_MIN && maxRange != INT_MAX){
            if(minRange > maxRange){
                sum += n - abs(root->data);
            }
            else{
                long long min = findIndex(rootMore, minRange);
                long long max = findIndex(rootMore, maxRange);
                
                // printf("MIN:%d MAX:%d NILAI:%d %d\n", min, max, n - abs(root->data), root->data);
                sum += n - abs(root->data) - (max-min+1) ;
            }
        }
    }
}

void preorderLess(AVLNode *root, AVL *avl_more){
    if(root){
        preorderLess(root->left, avl_more);
        preorderLess(root->right, avl_more);

        rangeAVL(avl_more->_root, root, n - abs(root->data) - 1);
        // printf("s:%d rd:%d\n\n", sum, root->data);
    }
}

void checkSegment(AVL *avl_more, AVL *avl_less){
    if(avl_more->_root != NULL) preorderMore(avl_more->_root);
    // printf("M%d\n", sum);
    if(avl_less->_root != NULL) preorderLess(avl_less->_root, avl_more);
    // printf("L%d\n", sum);
}

void checkSize(AVL *a, AVL *b){
    if(a->_size >= b->_size) checkSegment(a, b);
    else checkSegment(b, a);
}

void preorder(AVLNode *root){
    if(root){
        // printf("RT:%d GT:%d\n", root->data, _getTotal(root));
        // if(root->left) printf("RL:%d\n", root->left->data);
        // if(root->right) printf("RR:%d\n", root->right->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void insertByColor(AVL *avl_odd, AVL *avl_even, long long value){
    if(value%2 == 0) avl_insert(avl_even, value);
    else avl_insert(avl_odd, value);
}

int main(){
    AVL avlBHorizon, avlBVertical, avlWHorizon, avlWVertical;
    avl_init(&avlBHorizon);
    avl_init(&avlBVertical);
    avl_init(&avlWHorizon);
    avl_init(&avlWVertical);

    long long m;
    scanf("%lld %lld", &n, &m);

    long long a, b;
    while(m--){
        scanf("%lld %lld", &a, &b);
        if(n%2 == 0){
            insertByColor(&avlBVertical, &avlWVertical, b-a);
            insertByColor(&avlWHorizon, &avlBHorizon, n+1-(a+b));
        }
        else{
            insertByColor(&avlBVertical, &avlWVertical, b-a);
            insertByColor(&avlBHorizon, &avlWHorizon, n+1-(a+b));
        }
        // preorder(avlBHorizon._root);
        // printf("\n\n");
    }
    // printf("\n");
    // preorder(avlBVertical._root);

    checkSize(&avlBHorizon, &avlBVertical);
    // printf("%d\n", sum);
    checkSize(&avlWHorizon, &avlWVertical);

    printf("%lld\n", sum);
}