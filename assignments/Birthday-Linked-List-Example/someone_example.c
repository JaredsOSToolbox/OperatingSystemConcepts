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

/*void birthday_container_append(struct birthday* birthday_object){*/
    /*if(head->tail == NULL){*/
        /*list_add_tail(&birthday_object->list, &head);*/
    /*} else {*/
        /*struct birthday* prev = */
    /*}*/
/*}*/

static LIST_HEAD(head);

int linkedlist_init(void) {
    // insert the elements into the list
    // we're doing it in reverse order now so when it is retrieved it is in the correct order

    for(int i = 0; i < 5; ++i){
        birthday* bday = birthday_constructor(i);
        if(i == 0) {
            list_add_tail(&head, &bday->list);
        } else {
            struct birthday *prev = list_last_entry(&head, struct birthday, list);
            list_add_tail(&prev->list, &bday->list);
        }
    }

    /*birthday* e0 = birthday_constructor(0);*/
    /*birthday* e1 = birthday_constructor(1);*/
    /*birthday* e2 = birthday_constructor(2);*/
    /*birthday* e3 = birthday_constructor(3);*/
    /*birthday* e4 = birthday_constructor(4);*/
    
    birthday* pos;
    birthday* n;
    
    /*
      head->e0->e1->e2->e3->e4->(head)
    */

    /*list_add_tail(&e4->list, &head);*/
    /*list_add_tail(&e3->list, &e4->list);*/
    /*list_add_tail(&e2->list, &e3->list);*/
    /*list_add_tail(&e1->list, &e2->list);*/
    /*list_add_tail(&e0->list, &e1->list);*/
    
    // think of this as a for loop, defined in /lib/modules/4.15.0-132-generic/build/include/linux/list.h:472

    list_for_each_entry_safe(pos, n, &head, list) {
        struct birthday *object =  pos;
        printk(KERN_INFO "here baby cakes\n");
    }

    return 0;
}

void linkedlist_exit(void){  
    birthday* pos;
    birthday* n;
    list_for_each_entry_safe(pos, n, &head, list);
    printk(KERN_INFO "Removing Module Done\n");
}

module_init(linkedlist_init);
module_exit(linkedlist_exit);
 
