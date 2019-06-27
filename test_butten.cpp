#include <linux/input.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <chrono>

struct cmd
{
    int num;
    char cmd;
};

int main()
{
    cmd ans;
    char a = getchar();
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    char b = getchar();
    char num = getchar();
    end = std::chrono::system_clock::now();
    int elapsed_s = std::chrono::duration_cast<std::chrono::seconds>
                             (end-start).count();
    if (((a == 'a' && b == 'v' && num >= '0' && num <= '9')
        || (a >= '0' && a <= '9' && b == 'a' && num == 'v')
        || (a == 'v' && b >= '0' && b <= '9' && num == 'a')
        || (a >= '0' && a <= '9' && b == 'v' && num == 'a')
        || (a == 'v' && b == 'a' && num >= '0' && num <= '9')
        || (a == 'a' && b >= '0' && b <= '9' && num == 'v'))
        && elapsed_s < 2) {
            if (a >= '0' && a <= '9') {
                ans.num = a;
                ans.cmd = 'v';
                printf("1-ый оказалося числом, вставка\n");
            } else if (b >= '0' && b <= '9') {
                ans.num = b;
                ans.cmd = 'v';
                printf("2-ой оказалося числом, вставка\n");
            } else {
                ans.num = num;
                ans.cmd = 'v';
                printf("3-ий оказалося числом, вставка\n");
            } 
    } else if (((a == 'a' && b == 'c' && num >= '0' && num <= '9')
        || (a >= '0' && a <= '9' && b == 'a' && num == 'c')
        || (a == 'c' && b >= '0' && b <= '9' && num == 'a')
        || (a >= '0' && a <= '9' && b == 'c' && num == 'a')
        || (a == 'c' && b == 'a' && num >= '0' && num <= '9')
        || (a == 'a' && b >= '0' && b <= '9' && num == 'c'))
        && elapsed_s < 2) {
            if (a >= '0' && a <= '9') {
                ans.num = a - '0';
                ans.cmd = 'c';
                printf("1-ый оказалося числом, копирование\n");
            } else if (b >= '0' && b <= '9') {
                ans.num = b;
                ans.cmd = 'c';
                printf("2-ой оказалося числом, копирование\n");
            } else {
                ans.num = num;
                ans.cmd = 'c';
                printf("3-ий оказалося числом, копирование\n");
            }
    } else {
        printf("не сработало(\n");
    }
    return 0;
}