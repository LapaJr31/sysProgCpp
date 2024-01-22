#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE "/dev/my_module"

int main(){
    int i;
    int fd;
    fd = open(DEVICE, O_RDWR);
    if (fd == -1){
        printf("Failed to open device.\n");
        return -1;
    }
    for(int j = 0; j < 10; j++) {
        read(fd, &i, sizeof(i));
        printf("Counter: %d\n", i);
    }
    close(fd);
    return 0;
}