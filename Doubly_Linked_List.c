#include <stddef.h>
#include <stdio.h>
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

struct aiv_list_item* aiv_list_get_append(struct aiv_list_item** head, struct aiv_list_item* item)
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
        (*head)->count++;
    }

    // if(!(*head))
    // {
    //     *head = item;
    // }
    item->next = NULL;
    return item;
}
struct aiv_list_item* aiv_list_get_append_after(struct aiv_list_item** head, struct aiv_list_item* item)
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
        (*head)->count++;
    }

    // if(!(*head))
    // {
    //     *head = item;
    // }
    item->next = NULL;
    return item
}
struct aiv_list_item* aiv_list_get_append_before(struct aiv_list_item** head, struct aiv_list_item* item)
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
        (*head)->count++;
    }

    // if(!(*head))
    // {
    //     *head = item;
    // }
    item->next = NULL;
    return item
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

    if((*head)->count > index && index <= 0)
    {
        
        printf("The index is out of range");
        return NULL;
    }

    struct aiv_list_item* curr_head = *head;
    struct aiv_list_item* curr_item = curr_head->next;
    struct aiv_list_item* next;

    unsigned int curr_counter = 2;
    
    do
    {
        if(curr_counter == index)
        {
            next = curr_item->next->next;
            next->prev = curr_item;
            curr_item->next = next;
            (*head)->count--;
            printf("Item Remove");
            return curr_head;
        }
        curr_item = curr_item->next;
        curr_counter++;
    }while(curr_counter == index);
    printf("Item not found");
    return NULL;
}
struct aiv_list_item* aiv_list_Shuffle(struct aiv_list_item** head)
{
    paolo
}

unsigned int aiv_list_lenght(struct aiv_list_item* head)
{
    return head->count;
}


int main(int arg, char** argv)
{


}