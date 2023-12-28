#include <stddef.h>
/*
esercizi
    implementare la rimozione (fatto)
    riddurre i casting (29/11/23 1:00-1:20)
    invertire la list 123->321 (da testare) (facoltativo)
*/

struct aiv_list_item 
{
    struct aiv_list_item* next;
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
    }
    else
    {
        tail->next = item;
        (*head)->count++;
    }

    // if(!(*head))
    // {
    //     *head = item;
    // }
    item->next = NULL;
    return item;
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

_Bool aiv_list_remove_index(struct aiv_list_item** head, const unsigned int index)
{
    if(!(*head))
    {
        return 0;
    }

    if(index == 1)
    {
        aiv_list_pop(head);
        return 1;
    }

    if((*head)->count < index && index <= 0)
    {
        return 0;
    }

    struct aiv_list_item* curr_item = *head;
    unsigned int curr_counter = 1;
    
    while(curr_counter == index)
    {
        if(curr_counter == index - 1)
        {
            curr_item->next = curr_item->next->next;
            (*head)->count--;
            return 1;
        }
        curr_item = curr_item->next;
        curr_counter++;
    }

    return 0;
}

struct aiv_list_item* aiv_list_reverse(struct aiv_list_item** head)
{
    //1->2->3->4->null
    //4->3->2->1->null


    //temp_curr_item = 1->p1
    //elemento che sto spostando 
    struct aiv_list_item* temp_curr_item = *head;

    //temp_next_item = 2->p2 = 2->3
    //il next del curr che poi diventerà il precedente, devo solo cambiare il next e riassegnarlo 
    struct aiv_list_item* temp_next_item = temp_curr_item->next;

    //temp_curr_item = 1->null
    //rendo nullo il next del current 
    temp_curr_item->next = NULL;
    //2->p0

    while (temp_next_item)
    {
        // temp_next_swapper = 3->p3 = 3->4
        //mi salvo il valore del next di temp next item, così da poterlo far diventare il prossimo temp next item
        struct aiv_list_item* temp_next_swapper = temp_next_item->next;

        //2->p2 = 2->3 diventa 2->p0 = 2->1->null giusto
        //assegno al next di temp next item il curr item, così da fare l'effettivo reverse
        temp_next_item->next = temp_curr_item;

        //1->null diventa 2->1->null = 2->p0
        //assegno all curr il valore del prossimo valore da controllare
        temp_curr_item = temp_next_item;

        //2->1->null = 2->p0 diventa 3->p3->null = 3->4->null
        temp_next_item = temp_next_swapper;
        //devo fare qualcosa qua

        //lista al momento  2->p0(1)->null
        //temp_next_item = 3->p3->null = 3->4->null
        //temp_curr_item = 2->1->null = 2->p0->null

        // // temp_next_swapper = 4->null
        // //mi salvo il valore del next di temp next item, così da poterlo far diventare il prossimo temp next item
        // struct aiv_list_item* temp_next_swapper = temp_next_item->next;

        // //4->null diventa 2->1->null = 2->p0->null giusto
        // //assegno al next di temp next item il curr item, così da fare l'effettivo reverse
        // temp_next_item->next = temp_curr_item;

        // //2->1->null diventa 3->2->1->null = 3->p1->p0
        // //assegno all curr il valore del prossimo valore da controllare
        // temp_curr_item = temp_next_item;

        // //3->2->1->null = 2->p0 diventa 4->null
        // temp_next_item= temp_next_swapper;


        // //lista al momento 3->p0(2)->p0(1)->null
        // //temp_next_item = 4->null
        // //temp_curr_item = 3->p1->p0

        // // temp_next_swapper = null
        // //mi salvo il valore del next di temp next item, così da poterlo far diventare il prossimo temp next item
        // struct aiv_list_item* temp_next_swapper = temp_next_item->next;

        // //null diventa 2->1->null = 3->p1->p0->null giusto
        // //assegno al next di temp next item il curr item, così da fare l'effettivo reverse
        // temp_next_item->next = temp_curr_item;

        // //3->p1->p0 diventa 4->3->2->1->null = 4->3->p1->p0
        // //assegno all curr il valore del prossimo valore da controllare
        // temp_curr_item = temp_next_item;

        // //4->3->2->1->null = null
        // temp_next_item= temp_next_swapper;

        //temp_next_item->next =

        //temp_curr_item = temp_next_item->next;
    }
    temp_curr_item->count = (*head)->count;
    return temp_curr_item;

}

unsigned int aiv_list_lenght(struct aiv_list_item* head)
{
    return head->count;
}


int main(int arg, char** argv)
{


}