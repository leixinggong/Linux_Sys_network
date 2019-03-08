//
//  main.c
//  access
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

    char * path = "/Users/glx/Desktop/Linux_Net/access/main.c";
    int fd = access(path, R_OK | W_OK | F_OK);
    if (fd == -1)
    {
        perror("access");
        return -1;
    }
    
    printf("当前用户对文件 rwx  %d\n",fd);
    
    
    return 0;
}
