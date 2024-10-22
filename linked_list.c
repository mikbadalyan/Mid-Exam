#include <stdio.h>
#include <stdlib.h>

// I have a struct Node type (Node struction) which have two types in it. 
struct Node{ 
    // Next pointer is a pointer to the (Node struction)
    struct Node * next;
    // I create an integer value to keep my single-linked list values.
    int value; 
};

/**
 * @brief Ավելացնումա արժեք ցանկացած տեղից
 * 
 * @param head Լիստի head-ն է
 * @param value Լիստի արժեքն է
 * @param index Լիստի արժեքների համարը
 */
void insert(struct Node** head, int value, int index){
    int k = 1;
    struct Node * pahoc = *head;
    while((pahoc)->next != 0){
        pahoc=pahoc->next;
        k++;
    }
    struct Node * mek = malloc(sizeof(struct Node));
    if(index <= k){
        struct Node * stacum = *head;
        int g = 0;
        while (g < index){
            if(g == index-1){   
                mek->next = stacum->next; 
                mek->value = value;
                stacum->next = mek;     
            }else{
                stacum = stacum->next;
            }
            
            g++;
    
    }
    
        
    }else{
        printf("%d", 0);
    }
}

/**
 * @brief Adds the value at the end of the list represented by head.
 * 
 * @param head is the head of a single-linked list 
 * @param value is the value which have to be inserted. 
 */

void append(struct Node** head, int value){ 
    
    if (0 == *head) {
        *head = malloc(sizeof(struct Node));
        (*head)->value = value;
        return;
    }
    else{
        struct Node * verjin = malloc(sizeof(struct Node));
        verjin->value = value;
        
        struct Node * pahoc = *head;
        while((pahoc)->next != 0){
            pahoc=pahoc->next;
            
        }

        pahoc->next = verjin;
        return;
    }
}

/**
 * @brief Deletes the value
 * 
 * @param head the head of the list
 * @param index the location of the new value
 */

void delete(struct Node** head, int index){
    int k = 0;
    struct Node * pahoc = *head;
    struct Node* aaa = 0;
    while((pahoc)->next != 0){

        pahoc=pahoc->next;
        k++;
    }
    if(index <= k){
        struct Node * stacum = *head;
        
        int g = 0;
        while (g < index){
            if(g == index-1){
                aaa = stacum->next;
                stacum->next = stacum->next->next;
                free(aaa);
            }else{
                stacum = stacum->next;
                free(aaa);
            }
            
            
            
            
            g++;
    
    }
    
        
    }else{
        printf("%d", 0);
    }
}
/**
 * @brief Gets the values
 * 
 * @param head the head of the list
 * @param index the location of the value
 */
int get(struct Node** head, int index){
    int k = 0;
    struct Node * pahoc = *head;
    while((pahoc)->next != 0){
        pahoc=pahoc->next;
        k++;
    }
    struct Node * stacum = *head;
    int g = 0;
    while (g <= index){
        if(g == index){
            printf("%d", stacum->value);        
        }
        stacum = stacum->next;
        g++;
    }
   
    return 0;
}

void free_linked_list(struct Node** head) {
    struct Node* temp;
    
    
    while (*head != NULL) {
        temp = *head;         
        *head = (*head)->next;    
        free(temp);           
    }
}


int main(){
    struct Node * listHead = 0;
    

    printf("Head : %p\n", &listHead);
    //listHead-ը copy-ն ա;
    append(&listHead, 4);
    append(&listHead, 7);
    append(&listHead, 42);
    append(&listHead, 2);
    append(&listHead, 8);
    printf("Head : %p\n", &listHead);
    insert(&listHead, 4, 5);
    insert(&listHead, 450, 1);
    insert(&listHead, 780, 4);
    delete(&listHead, 1);
    
//    printf("Head : %p\n", &listHead);

    struct Node* ptr = listHead;
    while (ptr != 0){
        printf("%d, ", ptr->value);
        ptr = ptr->next;
    }
    free_linked_list(&listHead);
    return 0;
}