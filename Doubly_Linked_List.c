#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define AIV_LIST(x) &(x.list_item)
/*
esercizi
    sono da implementare
    implementare la rimozione forse fatto
    inserimento prima di un elemento da implementare
    inserimento dopo di un elemento da implementare
    shuffle (facoltativo)
*/

struct aiv_list_item 
{
    struct aiv_list_item* next;
    struct aiv_list_item* prev;
    unsigned int count;
};

struct aiv_int_item
{
    struct aiv_list_item list_item;
    int value;
};

struct aiv_list_item* aiv_list_get_tail(struct aiv_list_item* head)
{
    if(!head)
    {
        return NULL;
    }

    struct aiv_list_item* current_item = head;
    struct aiv_list_item* last_item = head;

    while(current_item)
    {
        last_item = current_item;
        current_item = current_item->next;
    }

    return last_item;
}

struct aiv_list_item* aiv_list_append(struct aiv_list_item** head, struct aiv_list_item* item)
{
    struct aiv_list_item* tail = aiv_list_get_tail(*head);

    if(!tail)
    {
        *head = item;
        (*head)->count = 1;
        item->prev = NULL;
    }
    else
    {
        tail->next = item;
        item->prev = tail;
        struct aiv_list_item* prev = item->prev;
        struct aiv_int_item* intprev = (struct aiv_int_item *)(prev);
        printf("%d\n", intprev->value);
        (*head)->count++;
    }

    // if(!(*head))
    // {
    //     *head = item;
    // }
    item->next = NULL;
    
        //printf("count %d", (*head)->count);

    printf("appended\n");
    return item;
}

struct aiv_list_item* aiv_list_append_after(struct aiv_list_item** head, struct aiv_list_item* item, struct aiv_list_item* item_to_add)
{
    struct aiv_list_item* curr_item = *head;
    struct aiv_list_item* next_item = curr_item->next;

    while(curr_item)
    {
        if(curr_item == item)
        {
            item_to_add->prev = curr_item;
            item_to_add->next = next_item;
            curr_item->next = item_to_add;
            next_item->prev = curr_item->next;
            printf("Item added after\n");
            return item_to_add;
        }
        curr_item = next_item;
        next_item = next_item->next;
    }

    printf("Item not added");
    return NULL;
}

struct aiv_list_item* aiv_list_append_before(struct aiv_list_item** head, struct aiv_list_item* item, struct aiv_list_item* item_to_add)
{
    struct aiv_list_item* curr_item = *head;
    struct aiv_list_item* next_item = curr_item->next;

    while(curr_item)
    {
        if(next_item == item)
        {
            item_to_add->prev = curr_item;
            item_to_add->next = next_item;
            curr_item->next = item_to_add;
            next_item->prev = curr_item->next;
            printf("Item added before\n");
            return item_to_add;
        }
        curr_item = next_item;
        next_item = next_item->next;
    }

    printf("Item not added");
    return NULL;
}


struct aiv_list_item* aiv_list_pop(struct aiv_list_item** head)
{
    if(!(*head))
    {
        return NULL;
    }

    struct aiv_list_item* current_head = *head;
    const unsigned int current_counter = current_head->count;
    if(*head)
    {
        (*head)->count = current_counter - 1;
    }

    current_head->next = NULL;
    return current_head;
}

struct aiv_list_item* aiv_list_remove_index(struct aiv_list_item** head, const unsigned int index)
{
    if(!(*head))
    {
        printf("The list is empty");
        return NULL;
    }

    if(index == 1)
    {
        printf("Head Pop");
        return aiv_list_pop(head);
    }

    if(index == (*head)->count)
    {
        struct aiv_list_item* tail;
        tail = aiv_list_get_tail(*head);
        tail = NULL;
        printf("Tail remove\n");
        return *head;
    }

    if((*head)->count < index || index <= 0)
    {
        
        printf("The index is out of range\n");
        return NULL;
    }

    struct aiv_list_item* curr_head = *head;
    struct aiv_list_item* curr_item = curr_head->next;
    struct aiv_list_item* next = curr_item->next;

    unsigned int curr_counter = 2;
    
    do
    {
        if(curr_counter == index)
        {
            next = curr_item->next;
            next->prev = curr_item->prev;
            curr_item = NULL;
            (*head)->count--;
            printf("Item Remove\n");
            return curr_head;
        }
        curr_item = curr_item->next;
        next = curr_item->next;
        curr_counter++;
    }while(curr_counter <= index);
    printf("Item not found\n");
    return NULL;
}

unsigned int aiv_list_lenght(struct aiv_list_item* head)
{
    return head->count;
}

struct aiv_list_item* aiv_list_Shuffle(struct aiv_list_item** head)
{
    struct aiv_list_item* curr_tail= aiv_list_get_tail(*head);
    struct aiv_list_item* item_to_swap = *head;

    unsigned int count = aiv_list_lenght(*head);
    srand(time(NULL));
    int r = (rand()%(*head)->count)+1;
    for(int i = 0; i < count; i++)
    {
        printf("rand %d, count %d\n", r, count);
        for(int j = 1; j <= count; j++)
        {
            if(r==1)
            {
                struct aiv_list_item* item_to_swap_next = item_to_swap->next;
                struct aiv_list_item* curr_tail_prev = curr_tail->prev;
                curr_tail->prev = NULL;
                item_to_swap_next->prev = curr_tail;
                curr_tail->count = count;
                item_to_swap->next = NULL;
                curr_tail_prev = item_to_swap->prev;
                *head = curr_tail;
                printf("Swap head\n");
                break;
                
            }
            if(r==count)
            {
                printf("tail swap\n");
                break;
            }
            if(j==r)
            {
                struct aiv_list_item* item_to_swap_next = item_to_swap->next;
                struct aiv_list_item* curr_tail_prev = curr_tail->prev;
                struct aiv_list_item* item_to_swap_prev = item_to_swap->prev;

                curr_tail_prev->next = item_to_swap;
                curr_tail->next = item_to_swap_prev;
                item_to_swap_next->prev = curr_tail;
                item_to_swap_prev->next = curr_tail;
                item_to_swap->next = NULL;

                printf("Swap n %d\n", j);
                
                break;
            }
            item_to_swap = item_to_swap->next;
        }
        printf("next swap\n");
        item_to_swap = *head;
        curr_tail= aiv_list_get_tail(*head);
        r = (rand()%(*head)->count)+1;
    }
}

void aiv_list_print(struct aiv_int_item* head) 
{
    if(head == NULL)
    {
        printf("The list is empty");
        return;
    }

    struct aiv_int_item* curr_item = head;
    struct aiv_int_item* next_item = curr_item->list_item.next;

    
    while (next_item)
    {
        printf("ciccio");
        if(curr_item->value)
            printf("%d\n",curr_item->value);
        curr_item = next_item;
        next_item = curr_item->list_item.next;
    } 

    return;
};


int main(int arg, char** argv)
{
    struct aiv_list_item *head = NULL;

    struct aiv_int_item int_item1;
    struct aiv_int_item int_item2;
    struct aiv_int_item int_item3;
    struct aiv_int_item int_item4;
    struct aiv_int_item int_item5;
    struct aiv_int_item int_item6;
    struct aiv_int_item int_item7;
    struct aiv_int_item int_item8;
    struct aiv_int_item int_item9;
    struct aiv_int_item int_item10;
    struct aiv_int_item int_item11;
    struct aiv_int_item int_item12;

    int_item1.value = 100;
    int_item2.value = 101;
    int_item3.value = 102;
    int_item4.value = 103;
    int_item5.value = 104;
    int_item6.value = 105;
    int_item7.value = 106;
    int_item8.value = 107;
    int_item9.value = 108;
    int_item10.value = 109;
    
    aiv_list_append(&head, AIV_LIST(int_item1));
    aiv_list_append(&head, AIV_LIST(int_item2));
    aiv_list_append(&head, AIV_LIST(int_item3));
    aiv_list_append(&head, AIV_LIST(int_item4));

    aiv_list_append_after(&head, AIV_LIST(int_item1), AIV_LIST(int_item5));
    aiv_list_append_before(&head, AIV_LIST(int_item5), AIV_LIST(int_item6));
    aiv_list_append_after(&head, AIV_LIST(int_item2), AIV_LIST(int_item7));
    

    aiv_list_append(&head, AIV_LIST(int_item7));
    aiv_list_append(&head, AIV_LIST(int_item8));
    aiv_list_append(&head, AIV_LIST(int_item9));
    aiv_list_append(&head, AIV_LIST(int_item10));
    //aiv_list_remove_index(&head, 4);
    aiv_list_print((struct aiv_int_item *)head);
    //aiv_list_Shuffle(&head);
}