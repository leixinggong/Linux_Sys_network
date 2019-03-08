//
//  main.c
//  lseek
//
//  Created by glx on 2019/3/7.
//  Copyright © 2019年 glx. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, const char * argv[]) {

    int fd = open("/Users/glx/Desktop/AAA.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }
    
    off_t off = lseek(fd, 0, SEEK_CUR);
    printf("offset = %lld\n",off);
    int i = 1024 * 1024 * 1024 - 1;
    off = lseek(fd, i, SEEK_CUR);
    write(fd,"\0", off);
    
    close(fd);
    return 0;
}
