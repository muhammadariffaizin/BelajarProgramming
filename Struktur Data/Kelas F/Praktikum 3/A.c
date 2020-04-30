#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int m = 0;
int n = 0;

int pt = 0;

char arr[600][600] = {};
bool araara[600][600] = {};

typedef struct _DString {
    char *ptr;
    int size;
    int capacity;
} DString;

DString* all[2622144] = {};

void DStringInit(DString *s){
    s->ptr = malloc(2 * sizeof(char));
    s->ptr[0] = '\0';
    s->size = 0;
    s->capacity = 2;
}

void DStringAppend(DString *s, char x){
    if (s->size + 1 > s->capacity){
        char *arr = malloc(s->capacity * 2 * sizeof(char));
        int i = 0;
        for (;i < s->capacity;i++){
            arr[i] = s->ptr[i];
        }
        char *temp = s->ptr;
        s->ptr = arr;
        free(temp);
        s->capacity *= 2;
    }

    s->ptr[s->size++] = x;
    s->ptr[s->size] = '\0';
}

// DStringLength untuk mendapatkan panjang DString tanpa menghitung panjangnya kembali
// Penggunaan : int length = DStringLength(&DString)
int DStringLength(DString *s){
    return s->size;
}

void DStringInput(DString *s){
    int n = 0;
    while (1){
        char c = getchar();
        if (c == '\n' || c == ' '){
            s->ptr[n] = '\0';
            break;
        } else {
            if (n < s->size){
                s->ptr[n] = c;
            } else {
                DStringAppend(s,c);
            }
        }
        n++;
    }
}

// DStringGetString digunakan untuk mendapatkan pointer array DString
// Penggunaan : char *awal = DStringGetString(&DString)
char* DStringGetString(DString *s){
    return s->ptr;
}

void DStringSetString(DString *s, char *aka){
    // char *temp = s->ptr;
    // s->size = 0;
    // s->capacity = 2;
    // s->ptr = (char*)malloc(s->capacity * sizeof(char));
    // free(temp);
    // s->ptr[0] = '\0';

    int i = 0;
    s->size = strlen(aka);
    s->capacity = s->size + 1;
    char *temp = s->ptr;
    s->ptr = malloc(s->capacity * sizeof(char));
    free(temp);
    for (;i < s->size;i++){
        s->ptr[i] = aka[i];
    }
    s->ptr[s->size] = '\0';
}

// Attribute AVLNode ditambah dengan attribute DString key dan DString value
// key untuk menyimpan string kunci node (Yang dapat dicari)
// value untuk menyimpan string nilai node (Nilai dari yang dicari)
typedef struct AVLNode_t
{
    DString key;
    struct AVLNode_t *left,*right;
    int height;
    int total;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

// createNode di tambah dengan parameter key dan value yang bertipe pointer char
// Kemudian didalam fungsi akan membuat DString dari variable key dan value
// Yang lalu di set dengan variable pointer char yang di pass kan
AVLNode* _avl_createNode(char *key) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    DStringInit(&newNode->key);
    DStringSetString(&newNode->key,key);
    newNode->height=1;
    newNode->total = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Search key menggunakan strcmp() yang digunakan untuk membandingkan key mana yang lebih awal dan key mana yang lebih akhir
// Yang akan mengembalikan node yang memiliki key yang dicari
AVLNode* _search(AVLNode *root, char *key) {
    while (root != NULL) {
        if (strcmp(key,DStringGetString(&root->key)) < 0)
            root = root->left;
        else if (strcmp(key,DStringGetString(&root->key)) > 0)
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

// Semua rotasi masih tetap karena tidak berhubungan dengan DString
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

// Insert AVL ditambah variable char *key dan char *value untuk menambahkan node pada AVL
// Perbandingan akan menggunakan strcmp(),
// nilai dari DString masing masing node bisa didapatkan dengan menggunakan fungsi DStringGetString()
// Kemudian rotasi juga menggunakan perbandingan strcmp() dan DString didapat dengan menggunakan fungsi DStringGetString()
AVLNode* _insert_AVL(AVL *avl,AVLNode* node,char *key){

    if(node==NULL)
        return _avl_createNode(key);
    if(strcmp(key,DStringGetString(&node->key)) < 0)
        node->left = _insert_AVL(avl,node->left,key);
    else if(strcmp(key,DStringGetString(&node->key)) > 0)
    	node->right = _insert_AVL(avl,node->right,key);

    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right));

    int balanceFactor=_getBalanceFactor(node);

    if(balanceFactor > 1 && strcmp(key, DStringGetString(&node->left->key)) < 0)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && strcmp(key, DStringGetString(&node->left->key)) > 0)
		return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && strcmp(key, DStringGetString(&node->right->key)) > 0)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && strcmp(key, DStringGetString(&node->right->key)) < 0)
        return _rightLeftCaseRotate(node);

    return node;
}

AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

// Remove AVL menggunakan pencarian key yang akan dicari dengan menggunakan rekursif
// Pencarian child menggunakan strcmp() untuk mencari key yang dicari
// Setelah itu akan dilakukan rotasi agar AVL seimbang
AVLNode* _remove_AVL(AVLNode* node,char *key){
    if(node==NULL)
        return node;
    if(strcmp(key,DStringGetString(&node->key)) > 0)
    	node->right=_remove_AVL(node->right,key);
    else if(strcmp(key,DStringGetString(&node->key)) < 0)
    	node->left=_remove_AVL(node->left,key);
    else{
        AVLNode *temp;
        if((node->left==NULL)||(node->right==NULL)){
            temp=NULL;
            if(node->left==NULL) temp=node->right;
            else if(node->right==NULL) temp=node->left;

            if(temp==NULL){
                temp=node;
                node=NULL;
            }
            else
                *node=*temp;

            free(temp);
        }
        else{
            temp = _findMinNode(node->right);
            node->key=temp->key;
            node->right=_remove_AVL(node->right,DStringGetString(&temp->key));
        }
    }

	if(node==NULL) return node;

    node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

    int balanceFactor= _getBalanceFactor(node);

    if(balanceFactor>1 && _getBalanceFactor(node->left)>=0)
        return _leftCaseRotate(node);

    if(balanceFactor>1 && _getBalanceFactor(node->left)<0)
        return _leftRightCaseRotate(node);

    if(balanceFactor<-1 && _getBalanceFactor(node->right)<=0)
        return _rightCaseRotate(node);

    if(balanceFactor<-1 && _getBalanceFactor(node->right)>0)
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

// Mengembalikan apakah node dengan key yang dicari ada atau tidak
bool avl_find(AVL *avl, char *key) {
    AVLNode *temp = _search(avl->_root, key);
    if (temp == NULL)
        return false;

    if (strcmp(DStringGetString(&temp->key), key) == 0)
        return true;
    else
        return false;
}

// Digunakan untuk memasukkan pasangan key dan value baru apabila key tidak ada pada AVLTree
// Jika key sudah ada maka proses akan diabaikan

void avl_insert(AVL *avl,char *key){
    AVLNode *temp = _search(avl->_root,key);
    // printf("%s\n",DStringGetString(&temp->key));
    if(temp == NULL){
        avl->_root=_insert_AVL(avl,avl->_root,key);
        avl->_size++;
    } else {
        temp->total++;
    }
}


void _____map_inorder(AVLNode *root) {
    if (root) {
        _____map_inorder(root->left);
        // printf("%s\n", DStringGetString(&root->key));
        // if (strcmp(DStringGetString(&root->key),"") != 0){
            printf("%s %d\n",DStringGetString(&root->key),root->total);
            all[pt++] = &root->key;
        // }
        _____map_inorder(root->right);
    }
}

// Sama dengan inisialisasi pohon avl dengan nama map_init
void map_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

// Sama dengan insert pohon avl dengan nama map_insert
void map_insert(AVL *avl,char *key){
    avl_insert(avl,key);
}
// Pemanggilan print inorder dari pohon avl
void map_inorder(AVL *avl){
    _____map_inorder(avl->_root);
}

void recc(DString *gta, int y, int x){
    if (x >= 0 && x < m && y >= 0 && y < n) {
        if(arr[y][x] != '.'){
            DStringAppend(gta,arr[y][x]);
            arr[y][x] = '.';
            recc(gta,y,x+1);
            recc(gta,y+1,x);
            recc(gta,y,x-1);
            recc(gta,y-1,x);
        }
        // arr[y][x] = '.';
    }
}

void reccmaindd(AVL *lav, DString *gta, int y, int x, int m, int n){
    int i = 0;
    for (i = x;i <= n;i++){
        if (araara[y][i]){
            DStringInit(gta);
            // DStringSetString(gta,"");
            if (arr[y][i] != '.'){
                recc(gta,y,i);
                map_insert(lav,DStringGetString(gta));
                // printf("%s\n",DStringGetString(gta));
            }
            // printf("%d %d\n",y,i);
            araara[y][i] = false;
        } else {
            return;
        }
    }

    for (i = y + 1;i <= m;i++){
        if (araara[i][n]){
            DStringInit(gta);
            // DStringSetString(gta,"");
            if (arr[i][n] != '.'){
                recc(gta,i,n);
                map_insert(lav,DStringGetString(gta));
                // printf("%s\n",DStringGetString(gta));
            }
            // printf("%d %d\n",i,n);
            araara[i][n] = false;
        } else {
            return;
        }
    }

    for (i = n - 1;i >= x;i--){
        if (araara[m][i]){
            // DStringSetString(gta,"");
            DStringInit(gta);
            if (arr[m][i] != '.'){
                recc(gta,m,i);
                map_insert(lav,DStringGetString(gta));
                // printf("%s\n",DStringGetString(gta));
            }
            // printf("%d %d\n",m,i);
            araara[m][i] = false;
        } else {
            return;
        }
    }

    for (i = m - 1;i > y;i--){
        if (araara[i][x]){
            // DStringSetString(gta,"");
            DStringInit(gta);
            if (arr[i][x] != '.'){
                recc(gta,i,x);
                map_insert(lav,DStringGetString(gta));
                // printf("%s\n",DStringGetString(gta));
            }
            // printf("%d %d\n",i,x);
            araara[i][x] = false;
        } else {
            return;
        }
    }

    if (araara[y+1][x+1]) {
        reccmaindd(lav,gta,y+1,x+1,m-1,n-1);
    }
}

int main (){
    AVL lav;
    map_init(&lav);

    DString gta;
    DStringInit(&gta);

    scanf("%d%d",&n,&m);
    getchar();

    int i = 0;

    for (i = 0;i < 600;i++){
        int j = 0;
        for (;j < 600;j++){
            arr[i][j] = '.';
            araara[i][j] = false;
        }
    }

    for (i = 0;i < n;i++){
        int j = 0;
        for (;j < m;j++){
            char c = getchar();
            arr[i][j] = c;
            araara[i][j] = true;
        }
        getchar();
    }

    reccmaindd(&lav,&gta,0,0,n-1,m-1);

    // system("pausE");

    map_inorder(&lav);

    // system("pausE");

    int k = 0;
    scanf("%d",&k);

    getchar();

    for (i = 0;i < k;i++){
        int a = 0;
        int b = 0;
        char c = 0;
        scanf("%d",&a);
        getchar();
        scanf("%c",&c);
        scanf("%d",&b);
        int j = 0;
        int tt = 0;
        int trig = 0;
        int bjirr = (*all[a-1]).size;
        for (;j < bjirr;j++){
            if (DStringGetString(all[a-1])[j] == c){
                tt++;
                if (tt == b){
                    trig = 1;
                    printf("%d",j+1);
                    break;
                }
            }
        }
        if (trig == 0){
            printf("-1");
        }
        printf("\n");
    }

    // system("pausE");
}
