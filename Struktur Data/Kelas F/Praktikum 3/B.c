#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int glotrig = 0;

int truth = 0;
int cnt = 0;
char* supra[101000] = {};
char arr[1010] = {};

// DString adalah Dynamic String, prinsip nya seperti dynamic array
// Memiliki 3 attribute yaitu ptr, size, dan capacity
// ptr adalah array yang menyimpan char
// size adalah banyaknya char dalam string
// capacity adalah ukuran array maksimal sekarang
typedef struct _DString {
    char *ptr;
    int size;
    int capacity;
} DString;

// Inisialisasi DString menggunakan DStringInit
// Array dimulai dari ukuran 2
// Pada array terdapat char '\0' untuk terminasi pada saat printf()
// Penggunaan : DStringInit(&DString)
void DStringInit(DString *s){
    s->ptr = malloc(2 * sizeof(char));
    s->ptr[0] = '\0';
    s->size = 0;
    s->capacity = 2;
}

// DStringAppend menambahkan character pada akhir String
// Jika ukuran akan melebihi kapasitas maka kapasitas akan dikalikan 2
// Kemudian element array lama akan dipindah ke array yang baru
// Pada akhir string akan diberi '\0' untuk terminasi printf()
// Penggunaan : DStringAppend(&DString, 'x')
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

// DStringInput untuk menginputkan string ke dalam DString
//
// Jika terdapat string didalamnya maka akan direplace
// String akan di masukkan satu persatu kedalam array yang lama untuk mencegah pembuatan array yang baru di awal awal
//
// Jika pemindahan sudah selesai maka pada akhir array yang lama setelah indeks terakhir array baru akan diberi '\0'
// '\0' akan berperan dalam terminasi printf() sehingga element yang tidak dijangkau array baru dapat di abaikan
//
// Jika ketika pemindahan masih ada element sisa pada array terbaru maka akan di Append terus menerus hingga pemindahan selesai
// Penggunaan : DStringInput(&DString)
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

// DStringSetString digunakan untuk mengganti String pada DString
// Karena akan di replace maka array yang lama dapat di abaikan dan di free yang dilanjut dengan pemindahan array yang baru
// Capacity dan Size di isi dengan size dari String array baru
// Pada akhir string akan ditambahkan '\0'
// Penggunaan : DStringSetString(&DString,"GTA San Andreas")
void DStringSetString(DString *s, char *arr){
    int i = 0;
    s->size = strlen(arr);
    s->capacity = s->size + 1;
    char *temp = s->ptr;
    s->ptr = malloc(s->capacity * sizeof(char));
    free(temp);
    for (;i < s->size;i++){
        s->ptr[i] = arr[i];
    }
    s->ptr[s->size] = '\0';
}

// Attribute AVLNode ditambah dengan attribute DString key dan DString value
// key untuk menyimpan string kunci node (Yang dapat dicari)
// value untuk menyimpan string nilai node (Nilai dari yang dicari)
typedef struct AVLNode_t
{
    DString key;
    DString value;
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
AVLNode* _avl_createNode(char *key, char *value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    DStringInit(&newNode->key);
    DStringInit(&newNode->value);
    DStringSetString(&newNode->key,key);
    DStringSetString(&newNode->value,value);
    newNode->height=1;
    newNode->total=1;
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

AVLNode* _searchstr(AVLNode *root, char *key) {
    while (root != NULL) {
        if (strstr(DStringGetString(&root->key),key) == DStringGetString(&root->key)){
            return root;
        }
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
AVLNode* _insert_AVL(AVL *avl,AVLNode* node,char *key,char *value){

    if(node==NULL)
        return _avl_createNode(key,value);
    if(strcmp(key,DStringGetString(&node->key)) < 0)
        node->left = _insert_AVL(avl,node->left,key,value);
    else if(strcmp(key,DStringGetString(&node->key)) > 0)
    	node->right = _insert_AVL(avl,node->right,key,value);

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

    if (strcmp(DStringGetString(&temp->key), key) == 0) {
        temp->total += 1;
        return true;
    }
    else
        return false;
}

// Digunakan untuk mengganti value dari key yang dicari
// Key dicari dengan menggunakan _search, kemudian setelah mendapatkan node,
// value dari node tersebut akan diset dengan parameter value yang dipass kan
bool avl_modify(AVL *avl, char *key, char *value){
    AVLNode *temp = _search(avl->_root, key);
    if (temp == NULL){
        return false;
    }

    DStringSetString(&temp->value,value);
    return true;
}

// Digunakan untuk mendapatkan value dari key yang dicari
// Akan mereturn String secara langsung
// Pengembalian String menggunakan DStringGetString()
char *avl_get(AVL *avl, char *key){
    AVLNode *temp = _search(avl->_root, key);
    if (temp == NULL){
        return NULL;
    }

    return DStringGetString(&temp->value);
}

// Digunakan untuk memasukkan pasangan key dan value baru apabila key tidak ada pada AVLTree
// Jika key sudah ada maka proses akan diabaikan
void avl_insert(AVL *avl,char *key, char *value){
    if(!avl_find(avl,key)){
        avl->_root=_insert_AVL(avl,avl->_root,key,value);
        avl->_size++;
    }
}

// Digunakan untuk menghapus pasangan key dan value apabila key terdapat pada AVLTree
// Jika key tidak ada maka proses akan diabaikan
void avl_remove(AVL *avl,char *key){
    if(avl_find(avl,key)){
        avl->_root=_remove_AVL(avl->_root,key);
        avl->_size--;
    }
}

// Digunakan untuk mengeprint semua value pada AVLTree yang akan diprint terhadap key secara preorder
void preorder(AVLNode *root) {
    if (root) {
        preorder(root->left);
        printf("%s\n", DStringGetString(&root->value));
        preorder(root->right);
    }
}

// Fungsi dibawah digunakan untuk mempermudah dalam menggunakan map dari modifikasi fungsi avl tree

// Digunakan untuk mengeprint semua value pada AVLTree yang akan diprint terhadap key secara inorder dari besar ke kecil
// Reverse dilakukan dengan cara menjalankan rekursif dari child kanan kemudian dilanjut ke child kiri
void _____map_reverse_inorder(AVLNode *root) {
    if (root) {
        _____map_reverse_inorder(root->right);
        printf("%s\n", DStringGetString(&root->value));
        _____map_reverse_inorder(root->left);
    }
}

// Digunakan untuk mengeprint semua value pada AVLTree yang akan diprint terhadap key secara inorder dari kecil ke besar
void _____map_inorder(AVLNode *root) {
    if (root) {
        _____map_inorder(root->left);
        if (strstr(DStringGetString(&root->key),arr) == DStringGetString(&root->key)){
            cnt++;
            truth += root->total;
            supra[cnt] = DStringGetString(&root->key);
            glotrig = 1;
        } else {
            if (glotrig)
                return;
        }
        _____map_inorder(root->right);
    } else {
        if (glotrig)
            return;
    }
}

// Digunakan untuk mengeprint semua value pada AVLTree yang akan diprint terhadap key secara preorder
void _____map_preorder(AVLNode *root) {
    if (root) {
        printf("%s\n", DStringGetString(&root->value));
        _____map_preorder(root->left);
        _____map_preorder(root->right);
    }
}

// Digunakan untuk mengeprint semua value pada AVLTree yang akan diprint terhadap key secara postorder
void _____map_postorder(AVLNode *root) {
    if (root) {
        _____map_postorder(root->left);
        _____map_postorder(root->right);
        printf("%s\n", DStringGetString(&root->value));
    }
}

// Sama dengan inisialisasi pohon avl dengan nama map_init
void map_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

// Sama dengan insert pohon avl dengan nama map_insert
void map_insert(AVL *avl,char *key, char *value){
    avl_insert(avl,key,value);
}

// Sama dengan remove pohon avl dengan nama map_remove
void map_remove(AVL *avl, char *key){
    avl_remove(avl,key);
}

// Sama dengan modifikasi node pohon avl dengan nama map_modify
bool map_modify(AVL *avl, char *key, char *value){
    return avl_modify(avl,key,value);
}

// Sama dengan get pohon avl dengan nama map_get
char *map_get(AVL *avl, char *key){
    return avl_get(avl,key);
}

// Pemanggilan print reverse inorder dari pohon avl
void map_reverse_inorder(AVL *avl){
    _____map_reverse_inorder(avl->_root);
}

// Pemanggilan print inorder dari pohon avl
void map_inorder(AVL *avl){
    _____map_inorder(avl->_root);
}

// Pemanggilan print postorder dari pohon avl
void map_postorder(AVL *avl){
    _____map_postorder(avl->_root);
}

// Pemanggilan print preorder dari pohon avl
void map_preorder(AVL *avl){
    _____map_preorder(avl->_root);
}

int main (){
    AVL lav;

    map_init(&lav);
    DString s;
    DStringInit(&s);

    int n = 0;
    scanf("%d",&n);
    getchar();
    int j = 0;
    for (; j < n;j++){
        DStringInput(&s);
        map_insert(&lav,s.ptr,"");
    }

    int x = 0;
    scanf("%d",&x);

    getchar();

    int i = 1;
    for (;i <= x;i++){
        glotrig = false;
        cnt = 0;
        truth = 0;
        scanf("%s",arr);
        AVLNode *temp = lav._root;
        // while (temp && temp->left && temp->right && strstr(DStringGetString(&temp->key),arr) != DStringGetString(&temp->key)){
        //     if (strcmp(arr,DStringGetString(&temp->key)) < 0){
        //         temp = temp->left;
        //     } else if (strcmp(arr,DStringGetString(&temp->key)) < 0){
        //         temp = temp->right;
        //     } else {
        //         break;
        //     }
        // }
        // while (temp != NULL && strcmp(arr,DStringGetString(&temp->key)) > 0){
        //     temp = temp->right;
        // }
        temp = _searchstr(temp,arr);
        _____map_inorder(temp);
        // map_inorder(&lav);
        if (cnt == 0){
            printf("Kasus #%d: Tidak ada hasil\n",i);
            continue;
        }
        printf("Kasus #%d: %d\n",i,truth);
        int pt = 1;
        for (; pt <= cnt;pt++){
            printf("%s\n",supra[pt]);
        }
    }
    // system("pausE");
    //sda
}
