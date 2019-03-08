//
//  main.c
//  fcntl
//
//  Created by glx on 2019/3/7.
//  Copyright © 2019年 glx. All rights reserved.
//

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


int main(int argc, const char * argv[]) {
 
    char * path = "/Users/glx/Desktop/Linux_Net/fcntl/main.c";
    int fd = open(path, O_RDWR | O_CREAT,0644);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    
    int flags = fcntl(fd, F_GETFL);
    printf("promiss = %d\n",flags);
    
    flags = flags | O_APPEND | O_CREAT | O_NONBLOCK;
    fcntl(fd, F_SETFL,flags);
    flags = fcntl(fd, F_GETFL);
    printf("%d\n",flags);
    
    char buf[1024];
    memset(buf, 0xf, sizeof(buf));
AIN:
    flags = fcntl(STDIN_FILENO, F_GETFL);
    fcntl(STDIN_FILENO, F_SETFL,flags | O_NONBLOCK);
    ssize_t ret = read(STDIN_FILENO, buf,sizeof(buf));
    
    if (ret == -1)
    {
        if (errno == EAGAIN)
        {
            perror("open");
            goto AIN;
        }
    }
    buf[ret] = '\0';
    printf("buf = %s\n",buf);
    
    return 0;
}


int main2(int agrc ,const char * argv[])
{
    
    char buf[10];
    ssize_t    ret;
    int flags = fcntl(STDIN_FILENO, F_GETFL);
    if(flags == -1)
    {
        perror("fcntl");
        return -1; }
    flags |= O_NONBLOCK;
    if(fcntl(STDIN_FILENO, F_SETFL, flags) == -1)
    {
        perror("fcntl");
        return -1;
    }
    
AGAIN:
    ret = read(STDIN_FILENO, buf, sizeof(buf));
    if(ret == -1)
    {
        if(errno == EAGAIN)
        {
            printf("#####read again#####\n");
            sleep(1);
            goto AGAIN;
        }
        perror("read");
        return -1;
    }
    ret = write(STDOUT_FILENO, buf, ret);
    if(ret == -1)
    {
        perror("write");
        return -1; }

    return 0;
}
