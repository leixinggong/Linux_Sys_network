//
//  main.c
//  open
//
//  Created by glx on 2019/3/7.
//  Copyright © 2019年 glx. All rights reserved.
//

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

ssize_t readn(int fd, const void * sbuf,size_t size)
{
    size_t nleft = size;
    ssize_t nread;
    char * nbuf =(char *)sbuf;
    
    while (nleft > 0)
    {
        if ((nread = read(fd, nbuf, nleft)) == -1)
        {
            if (errno == EINTR)
                continue;
            else
                perror("read");
                return -1;
        }
        else if (nread == 0)
        {
            break;
        }
        else
        {
            nleft -= nread;
            nbuf += nread;
        }
    }
    return (size - nleft);
}


int main(int argc, const char * argv[])
{
    char * path = "/Users/glx/Desktop/ZAC_loan_apply/ZAC_loan_apply/DynamicUI/UI/ZAC_AuthorPowerController.xib";
    int fd = open(path,O_RDWR);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    
    char buf[10];
    memset(buf, 0x0, sizeof(buf));
    
    while (readn(fd, buf, sizeof(buf)) > 0)
    {
        printf("%s",buf);
    }
    
    close(fd);
    
    
    return 0;
}
