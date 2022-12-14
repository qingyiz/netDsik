#pragma once
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/epoll.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <syslog.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <signal.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/md5.h>
#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#define ARGS_CHECK(argc, val)       \
    {                               \
        if (argc != val)            \
        {                           \
            printf("Args ERROR\n"); \
            return -1;              \
        }                           \
    }
#define THREAD_ERROR_CHECK(ret, funcName)               \
    {                                                   \
        if (ret != 0)                                   \
        {                                               \
            printf("%s:%s\n", funcName, strerror(ret)); \
            return -1;                                  \
        }                                               \
    }
#define ERROR_CHECK(ret, retval, filename) \
    {                                      \
        if (ret == retval)                 \
        {                                  \
            perror(filename);              \
            return -1;                     \
        }                                  \
    }
#define ORDERARGS_CHECK(order, name) 					\
    {                                      				\
        if (name == "")                 				\
        {                                  				\
            cout << order << ": missing operand" <<endl;\
            continue;                    				\
        }                                  				\
    }

/*****************************************?????????????????????******************************************/
#define IP "175.178.93.109"
#define PORT 8999
#define THREADNUM 10
#define MAXEVENTS 10
struct Packet
{
    int dataLen;    // ???????????????????????????????????????
    char buf[1000]; // ??????????????????????????????
};

//????????????????????????
struct LoadTask
{
    string username; //?????????
    int Dir;         //????????????
    string orders;   //??????????????????????????????
};

int tcpInit(int *);

//??????,?????????????????????????????????????????????
int recvFile(int sockfd, const char *, off_t);
int sendFile(int, const char *FILENAME);
void *upLoad(void *arg);
void *downLoad(void *arg);

//???????????????????????????
int recvCycle(int, void *, size_t);
int sendCycle(int, void *, size_t);

//????????????md5???
int get_file_md5(const std::string &file_name, std::string &md5_value);

