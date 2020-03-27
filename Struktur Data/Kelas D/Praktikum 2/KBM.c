#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t {
  int key;
  int num1;
  int num2;
  int num3;
  struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t {
  BSTNode *_root;
  unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value) {
  BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
  newNode->key = value;
  newNode->num1 = 0;
  newNode->num2 = 0;
  newNode->num3 = 0;
  newNode->left = newNode->right = NULL;
  return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, int prevval) {
  if (root == NULL)
  {
    return __bst__createNode(value);
  }

  if (value < root->key)
  {
    if (root->left == NULL && root->right != NULL)
    {
      root->num1 += root->key;
      root->num1 += value;
      root->num1 += root->right->key;
    }
    
    if (root->left == NULL && prevval != 0)
    {
      root->num2 += prevval;
      root->num2 += root->key;
      root->num2 += value;
    }

    prevval = root->key;

    root->left = __bst__insert(root->left, value, prevval);
  }
  else if (value > root->key)
  {
    if (root->right == NULL && root->left != NULL)
    {
      root->num1 += root->key;
      root->num1 += value;
      root->num1 += root->left->key;
    }
    
    if (root->right == NULL && prevval != 0)
    {
      root->num3 += prevval;
      root->num3 += root->key;
      root->num3 += value;
    }

    prevval = root->key;

    root->right = __bst__insert(root->right, value, prevval);
  }
  
  return root;
}

bool search_recur(BSTNode *root, int value)
{  
  if (root != NULL)
  {
    if (root->num1 == value || root->num2 == value || root->num3 == value)
      return true;
    
    // if (root->left != NULL)
    // {
    //   if (root->left->key == value)
    //     return root->key;
    // }

    // if (root->right != NULL)
    // {
    //   if (root->right->key == value)
    //     return root->key;
    // }
    
    bool key = search_recur(root->left, value);
    
    if (key)
      return true;

    key = search_recur(root->right, value);
    
    if (key)
      return true;
  }

  return false;
}

int height(BSTNode* node) 
{ 
	if (node==NULL) 
		return 0; 
	else
	{
		int lheight = height(node->left); 
		int rheight = height(node->right); 

		if (lheight > rheight) 
			return(lheight+1); 
		else return(rheight+1); 
	} 
} 

void printminmax(BSTNode* root, int level) 
{
	if (root == NULL) 
		return; 
	if (level == 1)
  {
    printf("%d ", root->key);
  } 
	else if (level > 1) 
	{ 
    // printf("flag3\n");
		printminmax(root->left, level-1); 
		printminmax(root->right, level-1); 
	} 
} 

void bfs_traversal(BSTNode* root) 
{
	int h = height(root); 
	int i;
  
  // printf("...%d\n", h);
	for (i=1; i<=h; i++)
  {
    printf("%d\n", i);
		printminmax(root, i);
    printf("\n");
  }
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

void __bst__preorder(BSTNode *root) {
  if (root) {
    if (root->num1 != 0 || root->num2 != 0 || root->num3 != 0)
      printf("%d 1. %d 2. %d 3. %d\n", root->key, root->num1, root->num2, root->num3);
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

void bst_insert(BST *bst, int value, int prevval) {
  if (!bst_find(bst, value)) {
    bst->_root = __bst__insert(bst->_root, value, prevval);
    bst->_size++;
  }
}

void bst_preorder(BST *bst) {
  __bst__preorder(bst->_root);
}

bool se_rec (BST *bst, int value)
{
  return search_recur(bst->_root, value);
}

void bst_bfs(BST *bst)
{
  bfs_traversal(bst->_root);
}
 
int main()
{
  BST set;
  bst_init(&set);

  int num;
  int wanted;
  int input;
  int count = 0;

  scanf("%d", &num);

  while (num--)
  {
    scanf("%d", &input);

    bst_insert(&set, input, 0);
  }

  scanf("%d", &wanted);
  // bst_bfs(&set);
  // bst_preorder(&set);

  if (se_rec(&set, wanted))
    printf("Ada\n");
  else
    printf("Tidak Ada\n");
  
  
  return 0;
}