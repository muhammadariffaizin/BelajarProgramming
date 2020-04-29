#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
//daftar id pemain	
void pemain(int id){
    if(id == -1){
        printf("Tidak ada pemenang\n");
        return;
    }
    switch(id){
        case 1: printf("Elpis\n");
                break;
        case 2: printf("Leonard\n");
                break;
        case 3: printf("Haza\n");
                break;
        case 4: printf("Pupuro\n");
                break;
        case 5: printf("Horus\n");
                break;
        case 6: printf("Xiwangmu\n");
                break;
        case 7: printf("Nuwa\n");
                break;
        case 8: printf("Yog\n");
                break;
        case 9: printf("Giemsa\n");
                break;
        case 10: printf("Reimu\n");
                break;
        case 11: printf("Cang Bi\n");
                break;
        case 12: printf("Radha\n");
                break;
        case 13: printf("Aurora\n");
                break;
        case 14: printf("Astrid\n");
                break;
        case 15: printf("Ralph\n");
                break;
        case 16: printf("Shamash\n");
                break;
        case 17: printf("Enlil\n");
                break;
        case 18: printf("Marduk\n");
                break;
        case 19: printf("Veronica\n");
                break;
        case 20: printf("Marisa\n");
                break;
        case 21: printf("Spencer\n");
                break;
        case 22: printf("Diamond\n");
                break;
        case 23: printf("Amber\n");
                break;
        case 24: printf("Jade\n");
                break;
        case 25: printf("Sapphire\n");
                break;
        case 26: printf("Ruby\n");
                break;
        case 27: printf("Lyndis\n");
                break;
        case 28: printf("Florina\n");
                break;
        case 29: printf("Fiora\n");
                break;
        case 30: printf("Sakuya\n");
                break;
        case 31: printf("Farina\n");
                break;
        case 32: printf("Nino\n");
                break;
        case 33: printf("Renault\n");
                break;
        case 34: printf("Eirika\n");
                break;
        case 35: printf("Vanessa\n");
                break;
        case 36: printf("Tana\n");
                break;
        case 37: printf("Syrene\n");
                break;
        case 38: printf("Amelia\n");
                break;
        case 39: printf("Joshua\n");
                break;
        case 40: printf("Alice\n");
                break;
        case 41: printf("Hansekyo\n");
                break;
        case 42: printf("Dwuaykicong\n");
                break;
        case 43: printf("NETral\n");
                break;
        case 44: printf("iNSANiTY\n");
                break;
        case 45: printf("Vinseks\n");
                break;
        case 46: printf("Aiedail\n");
                break;
        case 47: printf("Heisser\n");
                break;
        case 48: printf("MAXiMUSE\n");
                break;
        case 49: printf("p03tato\n");
                break;
        case 50: printf("Youmu\n");
                break;
        case 51: printf("Ikta\n");
                break;
        case 52: printf("Franz\n");
                break;
        case 53: printf("Zephiel\n");
                break;
        case 54: printf("Idunn\n");
                break;
        case 55: printf("Shanna\n");
                break;
        case 56: printf("thea\n");
                break;
        case 57: printf("Juno\n");
                break;
        case 58: printf("Yaisyeky\n");
                break;
        case 59: printf("Gerik\n");
                break;
        case 60: printf("Mayumi\n");
                break;
        case 61: printf("Cecilia\n");
                break;
        case 62: printf("Sophia\n");
                break;
        case 63: printf("Douglas\n");
                break;
        case 64: printf("Duessel\n");
                break;
    }
}
//data[0] berisi nomor id, data[1] berisi damage
int i,data[2][100];

typedef struct AVLNode_t{
	int data;
	int id_player;
	int damage;
	struct AVLNode_t *left,*right;
	int height;
}AVLNode;
	
typedef struct AVL_t{
	AVLNode *_root;
	unsigned int _size;
}AVL;
	
AVLNode* _avl_createNode(int value) {
	AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
	newNode->data = value;
	newNode->id_player=-1;
	newNode->damage=-1;
	newNode->height=1;
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
	
	pivotNode->height=_max(_getHeight(pivotNode->left),_getHeight(pivotNode->right))+1;
	newParrent->height=_max(_getHeight(newParrent->left),_getHeight(newParrent->right))+1;
	
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
	
AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value){
	
	if(node==NULL)
		return _avl_createNode(value);
	if(value < node->data)
		node->left = _insert_AVL(avl,node->left,value);
	else if(value > node->data)
		node->right = _insert_AVL(avl,node->right,value);
	
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
	
AVLNode* _remove_AVL(AVLNode* node,int value){
	if(node==NULL)
		return node;
	if(value > node->data)
		node->right=_remove_AVL(node->right,value);
	else if(value < node->data)
		node->left=_remove_AVL(node->left,value);
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
			node->data=temp->data;
			node->right=_remove_AVL(node->right,temp->data);
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
	
bool avl_find(AVL *avl, int value) {
	AVLNode *temp = _search(avl->_root, value);
	if (temp == NULL)
		return false;
	
	if (temp->data == value)
		return true;
	else
		return false;
}
	
void avl_insert(AVL *avl,int value){
	if(!avl_find(avl,value)){
		avl->_root=_insert_AVL(avl,avl->_root,value);
		avl->_size++;
	}
	
}
	
void avl_remove(AVL *avl,int value){
	if(avl_find(avl,value)){
		avl->_root=_remove_AVL(avl->_root,value);
		avl->_size--;
	}
	
}
	
void preorder(AVLNode *root) {
	if (root) {
		preorder(root->left);
		printf("%d heigtnya = %d\n", root->data,root->height);
		preorder(root->right);
	}
}
//fungsi untuk membuat bagan(siapa melawan siapa) dengan inorder
void sign_peserta(AVLNode *node){
    AVLNode *temp;
    if(node==NULL||node->damage!=-1)return;
    sign_peserta(node->left);
 
    if(node->left==NULL&&node->damage==-1){
    	//value data -3 untuk menandai bagan yang berisi player
        temp = _avl_createNode(-3);
        temp->damage=data[1][i];
        temp->id_player=data[0][i];
        node->left=temp;
        i++;
    }
    if(node->right==NULL&&node->damage==-1){
    	//value data -3 untuk menandai bagan yang berisi player
        temp=_avl_createNode(-3);
        temp->damage=data[1][i];
        temp->id_player=data[0][i];
        node->right=temp;
        i++;
    }
    sign_peserta(node->right);
}
//fungsi yang menjalakan pertarungan secara post order
void Geluddd(AVLNode *root) {
    if (root) {
    	//jika damage nya -1 berarti belum terjadi pertarungan
        if(root->damage==-1)
        Geluddd(root->left);
        if(root->damage==-1);
        Geluddd(root->right);
    }
    if(root){
    	//jika damage=-1 maka bisa dilakukan pertarungan pada node tersebut
        if(root->damage==-1){
        	//tidak akan ada pemenang pada node ini
            if(root->left->damage==root->right->damage){
                printf("Pemenang pertarungan ke-%d: Tidak ada pemenang\n",i);
                i++;
                root->damage=0;
                root->id_player=0;
            }
            //menang yang kiri
            else if(root->left->damage > root->right->damage){
                printf("Pemenang pertarungan ke-%d: ",i);
                i++;
                pemain(root->left->id_player);
                root->damage = root->left->damage - root->right->damage;
                root->id_player = root->left->id_player;
            }
            //menang yang kanan
            else {
                printf("Pemenang pertarungan ke-%d: ",i);
                i++;
                pemain(root->right->id_player);
                root->damage = root->right->damage - root->left->damage;
                root->id_player = root->right->id_player;
            }
        }
    }
}

bool flag=true;	
void _cekbalance(AVLNode *pivot){
	if(pivot != NULL && flag==true){
		int bal_factor=_getBalanceFactor(pivot);
		if(bal_factor>1||bal_factor<-1){
			printf("NO\n");
			flag=false;
			return;
		}else if(bal_factor<=1&&bal_factor>=-1){
			_cekbalance(pivot->left);
			_cekbalance(pivot->right);
		}
	}
	if(flag==true){
		printf("YES\n");
		flag=false;
		return;
	}
}
	
int main(){
	AVL avlku;
	avl_init(&avlku);
	int N,j,k,id1,dmg;
	scanf("%d",&N);
	//buat bagan kosong yang akan menampung N-1 pertandingan(tanpa perebutan juara 3)
	for(j=1;j<N;j++){
		avl_insert(&avlku,j);
	}
	//simpan data data player yang akan bertarung
	for(j=0;j<N;j++){
		scanf("%d %d",&id1,&dmg);
		data[0][j]=id1;
		data[1][j]=dmg;
	}
	//inisialisasi i untuk digunakan pada fungsi sign_peserta
	i=0;
	sign_peserta(avlku._root);
	//inisialisasi i untuk menghitung pertarungan ke-
	i=1;
	Geluddd(avlku._root);
}


