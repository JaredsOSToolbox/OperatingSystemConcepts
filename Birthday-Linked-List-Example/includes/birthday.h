#include <linux/types.h>

struct birthday {
  int day;
  int month;
  int year;
  struct list_head list;
}

struct birthday* birthday_constructor();
