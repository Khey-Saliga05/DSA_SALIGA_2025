#include <stdio.h>
#include "linked_list.h"


int main(void) {
    LinkedList list;
    linked_list_append(&list, (void *) 69);

    linked_list_clear(&list);
}
