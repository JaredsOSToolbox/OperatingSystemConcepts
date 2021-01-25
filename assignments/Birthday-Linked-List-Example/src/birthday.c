#include "../includes/birthday.h"

#include <linux/slab.h>

struct birthday* birthday_constructor(int day, int month, int year){
    struct birthday *entity;

    entity = kmalloc(sizeof(*entity), GFP_KERNEL);
    entity->day = day;
    entity->month = month;
    entity->year = year;
    INIT_LIST_HEAD(&entity->list);
}

void traverse(struct* birthday_list_head){
    struct birthday *head;

    /*list_for_each_entry(head, &birthday_list, list){*/
        /*// pass*/
    /*}*/
}
