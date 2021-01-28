#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/utsname.h>

#define LICENSE "MIT"
#define DESCRIPTION "McCarthy Assignment <++>"
#define AUTHOR "Jared Dyreson"

MODULE_LICENSE(LICENSE);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_AUTHOR(AUTHOR);


static int __init lkm_example_init(void) {
    printk(KERN_INFO "Hello, World!\n");
    /* Add more code here */
    return 0;
}
static void __exit lkm_example_exit(void) {
    /* Add more code here */
    printk(KERN_INFO "Goodbye, World!\n");
}

module_init(lkm_example_init);
module_exit(lkm_example_exit);
