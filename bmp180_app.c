#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("/dev/bmp180", O_RDONLY);
    if (fd < 0) {
        perror("Failed to open /dev/bmp180");
        return 1;
    }

    char buf[32];
    int n = read(fd, buf, sizeof(buf));
    if (n > 0) {
        buf[n] = '\0';
        printf("Temperature: %s", buf);
    }

    close(fd);
    return 0;
}
