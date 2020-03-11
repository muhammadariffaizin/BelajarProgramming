#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct darrchar_t {
    char **_arr;
    unsigned _size, _capacity;
} Darrchar;

typedef struct darrint_t {
    int *_arr;
    unsigned _size, _capacity;
} Darrint;

//Array Character
void init_char(Darrchar *arrchar);
bool empty_char(Darrchar *arrchar);
void push_char(Darrchar *arrchar, char *value);
//Array Angka
void init_int(Darrint *arrint);
bool empty_int(Darrint *arrint);
void push_int(Darrint *darray, int value);

int main(){
    Darrint posisi,jum;
    Darrchar nama;
    init_char(&nama);
    init_int(&posisi);
    init_int(&jum);
    int t,i,query=0,total=0;
    scanf("%d",&t);
    for (i=0;i<t; i++){
        int opsi;
        scanf("%d",&opsi);
        if(opsi == 1){
            int orang;
            scanf("%d",&orang);
            int j;
            total+=orang;
            push_int(&jum,orang);
            push_int(&posisi,total);
            for(j=0;j<orang;j++){
                char temp[50];
                scanf("%s",temp);
                push_char(&nama,temp);
            }
            //printf("%s\n",nama._arr[query]);
            query++;
            
        }else if(opsi == 2){
            
            int letak,urutan;
            scanf("%d %d",&letak,&urutan);
            if(letak<=query && urutan <= jum._arr[letak-1]){
                //printf("ok\n");
                printf("%s\n",nama._arr[(letak==1 ? 0 : posisi._arr[letak-2]) + urutan - 1]);
            }else{
                printf("-1\n");
            }
        }
    }
    return 0;
}
//fungsi char
void init_char(Darrchar *arrchar){
    arrchar->_capacity = 2u;
    arrchar->_size = 0u;
    arrchar->_arr = (char**)malloc(arrchar->_capacity*sizeof(char*));
    int i;
    for(i=0;i<arrchar->_capacity;i++){
        arrchar->_arr[i] = (char*)malloc(100*sizeof(char));
    }
}
bool empty_char(Darrchar *arrchar) {
    return (arrchar->_size == 0);
}

void push_char(Darrchar *arrchar, char *value){
    if (arrchar->_size + 1 > arrchar->_capacity) {
        
        unsigned it;
        arrchar->_capacity *= 2;
        char **newArr = (char**)malloc(arrchar->_capacity*sizeof(char*));
        
        for (it=0; it < arrchar->_capacity; ++it){
            newArr[it] = (char*)malloc(100*sizeof(char));
            if(it<arrchar->_size){
                strcpy(newArr[it],arrchar->_arr[it]);
            }
        }
        char **oldArray = arrchar->_arr;
        arrchar->_arr = newArr;
        free(oldArray);
    }
    strcpy(arrchar->_arr[arrchar->_size++],value);
}


//fungsi int
void init_int(Darrint *arrint){
    arrint->_capacity = 2u;
    arrint->_size = 0u;
    arrint->_arr = (int*) malloc(sizeof(int) * 2);
}
bool empty_int(Darrint *arrint) {
    return (arrint->_size == 0);
}
void push_int(Darrint *arrint, int value){
    if (arrint->_size + 1 > arrint->_capacity) {
        unsigned it;
        arrint->_capacity *= 2;
        int *newArr = (int*) malloc(sizeof(int) * arrint->_capacity);

        for (it=0; it < arrint->_size; ++it)
            newArr[it] = arrint->_arr[it];
        
        int *oldArray = arrint->_arr;
        arrint->_arr = newArr;
        free(oldArray);
    }
    arrint->_arr[arrint->_size++] = value;
}