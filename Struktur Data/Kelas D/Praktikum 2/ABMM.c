#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t {
  int key;
  struct bstnode_t *left, *right;
} BSTNode;

typedef struct result_t
{
  int num;
  int marker;
} result;

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

void printminmax(BSTNode* root, int level, int marker, result *res) 
{
	if (root == NULL) 
		return; 
	if (level == 1)
  {
    if (marker < 0)
    {
      // printf("flag min\n");
      if (res->marker == 0)
      {
        // printf("sada %d\n", marker2);
        res->num = root->key;
        res->marker = 1;
      }
      
      if (res->num > root->key)
      {
        // printf("asd  %d\n", res->num);
        res->num = root->key;
      }
      // printf("%d... %d\n", root->key, res->num);
    }
    else if (marker > 0)
    {
      if (res->marker == 0)
      {
        // printf("flag max\n");
        res->num = root->key;
        res->marker = 1;
      }
      else if (res->num < root->key)
      {
        res->num = root->key;
      }
    }
  } 
	else if (level > 1) 
	{ 
		printminmax(root->left, level-1, marker, res); 
		printminmax(root->right, level-1, marker, res); 
	} 
} 

void bfs_traversal(BSTNode* root) 
{
  result res;
	int h = height(root); 
	int i;
  int marker = -1;
  
  // printf("...%d\n", h);
	for (i=h; i>=1; i--)
  {
    res.marker = 0;
		printminmax(root, i, marker, &res);
    if (i > 1)
      printf("%d ", res.num);
    else if (i == 1)
      printf("%d\n", res.num);
    marker *= -1;
  }
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
  int input;

  scanf("%d", &num);

  while (num--)
  {
    scanf("%d", &input);

    bst_insert(&set, input);
  }

  bst_bfs(&set);
  
  return 0;
}