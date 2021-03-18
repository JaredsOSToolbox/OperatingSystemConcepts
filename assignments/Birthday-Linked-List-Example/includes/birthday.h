#include <linux/types.h>
#include <linux/slab.h>

struct birthday {
  int day;
  int month;
  int year;
  struct list_head list;
};

typedef struct birthday birthday;

void birthday_constructor(){
    birthday* person = kmalloc(sizeof(birthday), GFP_KERNEL);
    person->day = d;
    INIT_LIST_HEAD(&person->list);
    list_add_tail(&person->list,  &birthday_list);
}
