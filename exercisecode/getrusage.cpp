//getrusage() 监测缺页的数量 以及其他信息
//获取资源的使用情况
#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>
#include <string>
void printRusage()
{
    int who = RUSAGE_SELF;
    struct rusage usage;
    int ret = getrusage(who, &usage);
    //得到CPU使用时间
    long sec = usage.ru_utime.tv_sec + usage.ru_stime.tv_sec;
    long usec = usage.ru_utime.tv_usec + usage.ru_stime.tv_usec;
    sec += usec/1000000;
    usec%=1000000;
    std::cout<<"sec: "<<sec<<std::endl;
    std::cout<<"usec: "<<usec<<std::endl;
}
int main()
{
    for(int i=0; i<100000; i++)
    {
    //    string s{std::to_string(i)};
        if(i%10000)
            printRusage();
    }
}
