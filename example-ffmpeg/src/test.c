#include <stdio.h>
#include <inttypes.h>
#include <libavformat/avio.h>

#define text "fanhl"

int main(int argc,char *argv[]) 
{ 
    char filemode[40];
    int64_t myType=123456789;
    // snprintf(filemode, 40, "%3"PRIo64, filetype);

    // snprintf(filemode,40,"%3"PRIo64,myType);
    snprintf(filemode,40,"%3ld",myType);
    printf("dddddd:%-9s\n",filemode);

    printf("aaaaaa:"text"\n");
    av_log(NULL, AV_LOG_INFO,"%-5s\n","123456789");
    return 0;

} 