//
//  main.c
//  creat
//
//  Created by glx on 2019/3/7.
//  Copyright © 2019年 glx. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, const char * argv[]) {

    int fd = creat("/Users/glx/Desktop/AAA.txt", 0644);
    if (fd == -1)
    {
        perror("creat");
        return -1;
    }
    
    printf("creat success");
    
    return 0;
}
