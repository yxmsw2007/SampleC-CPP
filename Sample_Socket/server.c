/**********************************************************
 * Author        : yxmsw2007
 * Email         : yxmsw2007@gmail.com
 * Last modified : 2015-05-24 23:21
 * Filename      : server.c
 * Description   : 
 * *******************************************************/
#include <stdlib.h>  
#include <pthread.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <errno.h>
#include <stdio.h>
#include <string.h>

int handle(int point);

int main(int argc, char *argv[])
{
    int sfd, ind;
    struct sockaddr_in addr;
    struct sockaddr_in clent;
    char resv[1024], sendbuf[1024];
    char buf[1024];
    char *myaddr = "127.0.0.1";

    int ret; //返回值设置
    socklen_t lent;
    int pid;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET; //IPv4 Internet protocols
    addr.sin_port = htons(5050); //服务器端口
    addr.sin_addr.s_addr = inet_addr(myaddr); //INADDR_ANY表示本机IP

    // 获取socket描述副，IP4ads
    printf("socket start \n");
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd < 0)
    {
        printf("socket error \n");
        return -1;
    }
    printf("bind start \n");
    //将套接字与指定端口链接
    if (bind(sfd, (struct sockaddr *) &addr, sizeof(struct sockaddr)) < 0)
    {
        printf("bind err \n");
        return -1;
    }

    //监听套接字
    printf("listen start \n");
    if (listen(sfd,1024))
    {
        printf("listen error \n");
        return -1;
    }
    for (; ; )
    {
        //接受来自客户端的信息
        printf("accept start \n");
        memset(&clent, 0, sizeof(clent));
        lent = sizeof(clent);
        ind = accept(sfd, (struct sockaddr *) &clent, &lent);
        if (ind < 0)
        {
            printf("accept error %d \n", ind);
            return -1;
        }
        printf("infor \n");
        printf("clent addr %s porit %d\n", inet_ntop(AF_INET, &clent.sin_addr, buf, sizeof(buf)),
                ntohs(clent.sin_port));
        pid = fork();

        if (pid == 0)
        {
            //子进程
            close(sfd);
            handle(ind);
        } else if (pid < 0)
        {
            //error
            close(sfd);
        } else
        {
            //父进程
        }
    }
    return EXIT_SUCCESS;
}

int handle(int point) {
    int retn;
    char buf[1024];
    for (; ; )
    {
       retn = read(point, buf, sizeof(buf));
       if (retn < 0)
       {
           printf("read error \n");
           close(point);
           break;
       } else if (retn == 0)
       {
           printf("client exit \n");
           break;
       }
       printf("client： %s \n", buf);
       if (strcmp("exit", buf) == 0)
       {
           printf("exit \n");
           close(point);
           return 0;
       }
    } 
    return 0;
}

