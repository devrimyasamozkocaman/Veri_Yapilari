#include <stdio.h>
#include <stdlib.h>

struct node {
    int icerik;
    struct node *left;
    struct node *right;
};
struct binary_search_tree {
    struct node *root;
};
struct stack{
    int capacity;
    int top;
    struct node **array;
};
void non_recursive_preorder(int *dizi, int eleman_sayisi){
	struct binary_search_tree1 * tree1=NULL;
	struct binary_search_tree ** tree = &tree1;
	*tree = (struct binary_search_tree *) malloc(sizeof(struct binary_search_tree));
    if (*tree == NULL) {
    	printf("Agac icin gereken yer ayrilamadi");
        exit(1);}
	(*tree)->root = NULL;
	int i, j;
	for (i=0; i<eleman_sayisi; i++){
		struct node *dugum = (struct node *) malloc(sizeof(struct node));
    	if (dugum == NULL) {
        	printf("Heapte bu düðüm için yer ayrýlamadý \n");
        	exit(1);}
        dugum->icerik =*(dizi+i);
    	dugum->left = NULL;
    	dugum->right = NULL;
        struct node *dugum1;
        struct node *dugum2;

        dugum1=(*tree)->root;
        while(dugum1!=NULL) {
        	dugum2=dugum1;
            if(*(dizi+i) < dugum1->icerik) dugum1=dugum1->left;
            else if(*(dizi+i) > dugum1->icerik) dugum1= dugum1->right;
            else continue;}
        if((*tree)->root==NULL) {
            (*tree)->root = dugum;
            continue;
        }
        if(*(dizi+i) < dugum2->icerik) dugum2->left = dugum;
        else dugum2->right = dugum;

}  //buraya kadar olan kýsým ikili arama aðacý oluþturup düðümlerine diziden aldýðý elemanlarý yerleþtirdi.

	struct node *kok;                                                     //iteratif preorder baþlangýcý.
	struct node *temp;
	kok=(*tree)->root;
	if(kok==NULL){
        return;
    }
    int *dizim= (int*)malloc(eleman_sayisi*sizeof(int));        // aðacýn tüm düðümlerini preorder olarak gezerek düðümlerin "icerik" deðerlerini stack yardýmýyla dizim dizisine yerleþtirecek.
    struct stack *stack1= (struct stack*)malloc(sizeof(struct stack));
    stack1->capacity = eleman_sayisi;
    stack1->top=-1;
    stack1->array = (struct node**)malloc(eleman_sayisi*sizeof(struct node*));
    if(stack1->top==stack1->capacity-1){
    	return;
	}
	stack1->array[++stack1->top]=kok;
	i=0;
	while(stack1->top!=-1){
		temp=stack1->array[stack1->top--];
		dizim[i++]=temp->icerik;
		if(temp->right){
			if(stack1->top==stack1->capacity-1){
    			return;
	}
            stack1->array[++stack1->top]=temp->right;
        }
        if(temp->left){
        	if(stack1->top==stack1->capacity-1){
    			return;
	}
            stack1->array[++stack1->top]=temp->left;
        }
	} //
	int k;
	printf("Verilen elemanlarla olusturulan ikili arama agacinin preorder siralanisi: ");
	for(k=0; k<eleman_sayisi; k++){      
		printf("  %d  ", dizim[k]);
	}

	}
	
	
	
int main() {
		int dizi[10]={80,8,30,90,5,3,15,7,22,85};
		non_recursive_preorder(dizi, 10);
		int k;
}
