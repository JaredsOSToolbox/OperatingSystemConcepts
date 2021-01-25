#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>

#define LICENSE "GPL"
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

struct birthday{
    int day;
    struct list_head list;
};

typedef struct birthday birthday;
// instead of saying struct birthday birthday, just struct birthday

struct birthday_container {
    struct list_head list;
    struct birthday birthday_;
};

// Initialize birthday list
// Move to header file

inline birthday* birthday_constructor(int d){
    birthday* person = kmalloc(sizeof(birthday), GFP_KERNEL);
    person->day = d;
    INIT_LIST_HEAD(&person->list);
    return person;
}

static LIST_HEAD(head);

int linkedlist_init(void) {
    // insert the elements into the list
    // we're doing it in reverse order now so when it is retrieved it is in the correct order

    /*
      head->e0->e1->e2->e3->e4->(head)
    */

    int i;
    for(i = 5; i >= 0; --i){
        birthday* bday = birthday_constructor(i);
        if(i == 0) {
            /*list_add_tail(&head, &bday->list);*/
            list_add_tail(&bday->list, &head);
        } else {
            birthday *prev = list_first_entry(&head, struct birthday, list);
            /*list_add_tail(&prev->list, &bday->list);*/
            list_add_tail(&bday->list, &prev->list);
        }
        printk(KERN_INFO "[INFO] Inserting value of %d into the birthday list\n", i);
    }

    
    birthday* pos;
    birthday* n;
    

    return 0;
}

void linkedlist_exit(void){  
    birthday* pos;
    birthday* n;

    // think of this as a for loop, defined in /lib/modules/4.15.0-132-generic/build/include/linux/list.h:472

    list_for_each_entry_safe(pos, n, &head, list) {
        printk(KERN_INFO "[INFO] Removing value of %d from the list\n", pos->day);
        list_del(&(pos->list));
        kfree(pos);
    }
    printk(KERN_INFO "Removing Module Done\n");
}

module_init(linkedlist_init);
module_exit(linkedlist_exit);
 