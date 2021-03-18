#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/utsname.h>

#include "includes/birthday.h"

#define LICENSE "MIT"
#define DESCRIPTION "McCarthy Assignment 0"
#define AUTHOR "Jared Dyreson"

/*
 * Adapated from these two sources:
 *
 * https://stackoverflow.com/questions/16230524/explain-list-for-each-entry-and-list-for-each-entry-safe
 * https://github.com/jz33/C-OS-Solution-Manual/blob/master/2_1.c
 *
 * I took one look at Kernel dev and said, "that's a no from me Chief"
*/

MODULE_LICENSE(LICENSE);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_AUTHOR(AUTHOR);

static LIST_HEAD(head);


void ll_insert(int day, int month, int year){
    birthday* person = kmalloc(sizeof(birthday), GFP_KERNEL);
    person->day = day;
    person->month = month;
    person->year = year;
    INIT_LIST_HEAD(&person->list);
    list_add_tail(&person->list, &head);
}

void ll_delete(void){
    birthday* pos;
    birthday* n;

    list_for_each_entry_safe(pos, n, &head, list) {
        birthday *element = list_first_entry(&head, struct birthday, list);
        printk(KERN_INFO "[INFO] Removing %02d/%02d/%02d\n", element->day, element->month, element->year);
        list_del(&(pos->list));
        kfree(pos);
    }
}

int linkedlist_init(void) {
    printk(KERN_INFO "[INFO] Creating birthday list\n");
    ll_insert(1, 1, 1000);
    ll_insert(2, 1, 1000);
    ll_insert(3, 1, 1000);
    ll_insert(4, 1, 1000);
    ll_insert(5, 1, 1000);

    return 0;
}

void linkedlist_exit(void){  
    ll_delete();
    printk(KERN_INFO "Removing Module Done\n");
}

module_init(linkedlist_init);
module_exit(linkedlist_exit);
 
