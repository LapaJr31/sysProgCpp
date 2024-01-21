#include <linux/module.h>
#include <linux/random.h>
#include <linux/slab.h>
#include <linux/types.h>


#ifndef UINT32_MAX
#define UINT32_MAX (~(uint32_t)0)
#endif


MODULE_AUTHOR("");
MODULE_DESCRIPTION("Lab 1.2, using struct list_head");
MODULE_LICENSE("MIT");
#define LIST_LEN 10
#define MSG_PREF "TEST: "

#define print_msg(msg, ...) printk(KERN_ERR MSG_PREF msg, ##__VA_ARGS__);
typedef struct {
  struct list_head lnode;
  uint32_t val;
} int_node_t;

#define ilfree(list_head)                                                      \
  do {                                                                         \
    int_node_t *__ptr, *__tmp;                                                 \
    list_for_each_entry_safe(__ptr, __tmp, (list_head), lnode) {               \
      kfree(__ptr);                                                            \
    }                                                                          \
  } while (0)

#define ilprint(list_head)                                                     \
  do {                                                                         \
    int_node_t *__ptr;                                                         \
    print_msg("List: {");                                                      \
    list_for_each_entry(__ptr, (list_head), lnode) {                           \
      printk(KERN_ERR "\t%i ", __ptr->val);                                    \
    }                                                                          \
    printk(KERN_ERR "}\n");                                                    \
  } while (0)

static struct list_head int_list = LIST_HEAD_INIT(int_list);

static uint32_t list_and_conjunction(void) {
  uint32_t result = ~0;
  int_node_t *ptr;
  list_for_each_entry(ptr, &int_list, lnode) { result &= ptr->val; }
  return result;
}

static uint32_t list_max_value(void) {
  uint32_t max_val = 0;
  int_node_t *ptr;
  list_for_each_entry(ptr, &int_list, lnode) {
    if (ptr->val > max_val)
      max_val = ptr->val;
  }
  return max_val;
}

static uint32_t list_min_value(void) {
  uint32_t min_val = UINT32_MAX;
  int_node_t *ptr;
  list_for_each_entry(ptr, &int_list, lnode) {
    if (ptr->val < min_val)
      min_val = ptr->val;
  }
  return min_val;
}

static void list_divide_by(uint32_t divisor) {
  int_node_t *ptr;
  list_for_each_entry(ptr, &int_list, lnode) { ptr->val /= divisor; }
}

static void list_shift_left(void) {
  int_node_t *ptr;
  list_for_each_entry(ptr, &int_list, lnode) { ptr->val <<= 1; }
}

static void list_shift_right(void) {
  int_node_t *ptr;
  list_for_each_entry(ptr, &int_list, lnode) { ptr->val >>= 1; }
}

static void list_invert_values(void) {
  int_node_t *ptr;
  list_for_each_entry(ptr, &int_list, lnode) { ptr->val = ~ptr->val; }
}

static int __init list_module_init(void) {
  int i;
  int ret = 0;
  print_msg("List allocation start...\n");

  for (i = 0; i < LIST_LEN; ++i) {
    int_node_t *ptr = (int_node_t *)kmalloc(sizeof(*ptr), GFP_KERNEL);
    if (!ptr) {
      print_msg("Can't alloc memory\n");
      ret = -ENOMEM;
      goto alloc_err;
    }
    get_random_bytes(&ptr->val, sizeof(ptr->val));
    list_add_tail(&ptr->lnode, &int_list);
  }

  print_msg("List allocation finish\n");
  ilprint(&int_list);

  print_msg("AND conjunction: %u\n", list_and_conjunction());
  print_msg("Max value: %u\n", list_max_value());
  print_msg("Min value: %u\n", list_min_value());
  list_divide_by(25);
  ilprint(&int_list);
  list_shift_left();
  ilprint(&int_list);
  list_shift_right();
  ilprint(&int_list);
  list_invert_values();
  ilprint(&int_list);

  return 0;

alloc_err:
  ilfree(&int_list);
  return ret;
}

static void __exit list_module_exit(void) {
  ilfree(&int_list);
  print_msg("Hasta la vista, Kernel!\n");
}

module_init(list_module_init);
module_exit(list_module_exit);
