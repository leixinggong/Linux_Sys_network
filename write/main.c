//
//  main.c
//  write
//
//  Created by glx on 2019/3/7.
//  Copyright © 2019年 glx. All rights reserved.
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

ssize_t writen(int fd ,const void * buf,size_t size)
{
    size_t nleft = size;
    ssize_t nwrite;
    char * nbuf = (char *) buf;
    
    while (nleft > 0)
    {
        if ((nwrite = write(fd, nbuf, nleft)) == -1)
        {
            if (errno == EINTR)
                continue;
            else
                return -1;
        }
        else
        {
            nleft -= nwrite;
            nbuf += nwrite;
        }
    }
    return (size - nleft);
}

int main(int argc, const char * argv[])
{
 
    int fd = open("/Users/glx/Desktop/AAA.txt", O_RDWR | O_CREAT | O_APPEND,0664);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    printf("open success file\n");
    
    char * buf = (char *) argv[0];
    ssize_t ret = writen(fd, buf, strlen(argv[0]));
    if (ret == -1)
    {
        perror("write");
        
        return -1;
    }
    printf("write success\n");
    
    return 0;
}

