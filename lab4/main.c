#include <linux/kernel.h>
#include <linux/module.h>
MODULE_AUTHOR("Present <https://github.com/danya-psch>"); // Подарунок
MODULE_DESCRIPTION("Lab1 test kernel module"); // Опис фунціоналу
MODULE_LICENSE("MIT");                         // ліцензія
/*
(hello_init)
(hello_exit).
module_init і
module_exit використовують специальні макросы ядра
*/
static int __init hw_init(void) {
  printk(KERN_ERR "Input , Kernel!\n");
  return 0;
}

static void __exit hw_exit(void) { printk(KERN_ERR "It out from, Kernel!\n"); }
module_init(hw_init);
module_exit(hw_exit);
