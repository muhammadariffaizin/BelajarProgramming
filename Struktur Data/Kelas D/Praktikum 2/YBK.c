#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef struct bstnode_t {
  int key;
  struct bstnode_t *left, *right;
} BSTNode;

typedef struct result_t
{
  double num;
  double tot;
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

void printminmax(BSTNode* root, int level, result *res) 
{
	if (root == NULL) 
		return; 
	if (level == 1)
  {
    // printf("%d..", root->key);
    res->num += root->key;
    res->tot+=1;
  } 
	else if (level > 1) 
	{ 
    // printf("flag3\n");
		printminmax(root->left, level-1, res); 
		printminmax(root->right, level-1, res); 
	} 
} 

void bfs_traversal(BSTNode* root) 
{
  result res;
	int h = height(root); 
	int i;
  double jml_l;
  
  // printf("...%d\n", h);
	for (i=1; i<=h; i++)
  {
    res.tot = 0;
    res.num = 0;
    // printf("flag\n");
		printminmax(root, i, &res);
    jml_l = res.num/res.tot;
    printf("Level %d = %.2lf\n", i-1, jml_l);
  }
} 

void bst_bfs(BST *bst)
{
  bfs_traversal(bst->_root);
}

int main()
{
  int query;
  int num;
  int input;
  int count = 0;

  scanf("%d", &query);
  BST *set = (BST*)malloc(sizeof(BST));

  while (query--)
  {
    scanf("%d", &num);

    bst_init(&set[count]);

    while (num--)
    {
      scanf("%d", &input);
      bst_insert(&set[count], input);
    }

    bst_bfs(&set[count]);
    count++;
  }
  
  return 0;
}