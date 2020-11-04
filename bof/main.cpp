/* g++ -fno-pie -fno-stack-protector -fzero-initialized-in-bss main.cpp */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILEPATH "msg_file.txt"

int main();
void vuln(const char* line);
void stack_dump(void* ptr, int counts);
void hello();

int main()
{
    char linebuf[1024];
    FILE *fp;
    long mark1 = 0x2121212121212121;
    memset(linebuf, 0, sizeof(linebuf));

    fp = fopen(FILEPATH, "r");
    fgets(linebuf, sizeof(linebuf)-1, fp);
    fclose(fp);

    vuln(linebuf);

    printf("------------- end of main() -------------\n");
}

void vuln(const char* line)
{
    char msg[20];
    long mark2 = 0x2222222222222222;
    memset(msg, 0, sizeof(msg));

    strcpy(msg, line);

    stack_dump(&mark2, 13);

    printf("INPUT[%s]\n", msg);
}

void stack_dump(void* ptr, int counts)
{
    int i;
    unsigned long *ulong_ptr = (unsigned long *)ptr;
    unsigned char uchar_buf[8];

    printf("------------------------------------------------------------------\n");
    printf("  address | +0 +1 +2 +3 +4 +5 +6 +7 | 01234567 |         long var \n");
    printf("------------------------------------------------------------------\n");
    for(i=0; i<counts; i++) {
        printf(" %p |", &ulong_ptr[i]);
        memcpy(uchar_buf, &ulong_ptr[i], sizeof(uchar_buf));
        printf(" %02x %02x %02x %02x %02x %02x %02x %02x |",
        uchar_buf[0], uchar_buf[1], uchar_buf[2], uchar_buf[3],
        uchar_buf[4], uchar_buf[5], uchar_buf[6], uchar_buf[7]);
        for (int j = 0; j < 8; ++j) {
            // ASCII印字可能文字以外は.
            if(uchar_buf[j]<32 || uchar_buf[j]>126) uchar_buf[j] = '.';
        }
        printf(" %c%c%c%c%c%c%c%c |",
        uchar_buf[0], uchar_buf[1], uchar_buf[2], uchar_buf[3],
        uchar_buf[4], uchar_buf[5], uchar_buf[6], uchar_buf[7]);
        printf(" %08lx\n", ulong_ptr[i]);
    }
    printf("-----------------------------------------\n");
}

void hello()
{
    printf("+----------+\n");
    printf("| HELLO! |\n");
    printf("+----------+\n");
    exit(0);
}
