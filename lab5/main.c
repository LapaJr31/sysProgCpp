#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "my_module"
#define CLASS_NAME "my_class"

MODULE_LICENSE("GPL");

static int majorNumber;
static int counter = 0;
static struct class* myClass = NULL;
static struct device* myDevice = NULL;

static int dev_open(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);

static struct file_operations fops =
{
    .open = dev_open,
    .read = dev_read,
};

static int __init my_module_init(void){
    majorNumber = register_chrdev(0, DEVICE_NAME, &fops);
    myClass = class_create(CLASS_NAME);
    if (IS_ERR(myClass)) { // Check for error and clean up if there is
        unregister_chrdev(majorNumber, DEVICE_NAME);
        return PTR_ERR(myClass);
    }
    myDevice = device_create(myClass, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);
    if (IS_ERR(myDevice)) { // Clean up if there is an error
        class_destroy(myClass);
        unregister_chrdev(majorNumber, DEVICE_NAME);
        return PTR_ERR(myDevice);
    }
    return 0;
}

static void __exit my_module_exit(void){
    device_destroy(myClass, MKDEV(majorNumber, 0));
    class_unregister(myClass);
    class_destroy(myClass);
    unregister_chrdev(majorNumber, DEVICE_NAME);
}

static int dev_open(struct inode *inodep, struct file *filep){
    counter = 0;
    return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset){
    int error_count = 0;
    counter++;
    error_count = copy_to_user(buffer, &counter, sizeof(counter));
    return sizeof(counter);
}

module_init(my_module_init);
module_exit(my_module_exit);