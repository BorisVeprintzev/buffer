#include "buffer.h"
#include <linux/input.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <chrono>
#include <stdio.h>

//struct input_event event;

/* 
int control_butten(ifstream& ev)
{
    char data[sizeof(event)];
    if (ev.is_open()) {
        bool session = true;
        time_t prev;
        while (session) {
            ev.read(data, sizeof(event));

            memcpy(&event, data, sizeof(event));

            if(event.type == EV_KEY) {
                if (event.code == KEY_ESC) {
                    session = false;
                } else if (event.code == ) {

                }
            }
        }
    }
}
*/

typedef struct cmd
{
    int num;
    char cmd;
};

// v - paste
// c - copy
// r - error
cmd contr_butten()
{
    cmd ans;
    char a = getchar();
    while (a == '\n') {
        a = getchar();
    }
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    char b = getchar();
    while (b == '\n') {
        b = getchar();
    }
    char num = getchar();
    while (num == '\n') {
        num = getchar();
    }
    end = std::chrono::system_clock::now();
    int elapsed_s = std::chrono::duration_cast<std::chrono::seconds>
                             (end-start).count();
    if (((a == 'a' && b == 'v' && num >= '0' && num <= '9')
        || (a >= '0' && a <= '9' && b == 'a' && num == 'v')
        || (a == 'v' && b >= '0' && b <= '9' && num == 'a')
        || (a >= '0' && a <= '9' && b == 'v' && num == 'a')
        || (a == 'v' && b == 'a' && num >= '0' && num <= '9')
        || (a == 'a' && b >= '0' && b <= '9' && num == 'v'))
        && elapsed_s < 10) {
            if (a >= '0' && a <= '9') {
                ans.num = a - '0';
                ans.cmd = 'v';
            } else if (b >= '0' && b <= '9') {
                ans.num = b - '0';
                ans.cmd = 'v';
            } else {
                ans.num = num - '0';
                ans.cmd = 'v';
            } 
    } else if (((a == 'a' && b == 'c' && num >= '0' && num <= '9')
        || (a >= '0' && a <= '9' && b == 'a' && num == 'c')
        || (a == 'c' && b >= '0' && b <= '9' && num == 'a')
        || (a >= '0' && a <= '9' && b == 'c' && num == 'a')
        || (a == 'c' && b == 'a' && num >= '0' && num <= '9')
        || (a == 'a' && b >= '0' && b <= '9' && num == 'c'))
        && elapsed_s < 10) {
            if (a >= '0' && a <= '9') {
                ans.num = a - '0';
                ans.cmd = 'c';
            } else if (b >= '0' && b <= '9') {
                ans.num = b  - '0';
                ans.cmd = 'c';
            } else {
                ans.num = num  - '0';
                ans.cmd = 'c';
            }
    } else {
        ans.cmd = 'r';
    }
    return ans;
}


int main()
{
    buffer* buf = new buffer[9];

    for (int i = 0; i < 10; ++i) {
        buf[i].get_filename(i);
    }

    std::string s;
    //ifstream event_file("/dev/input/event1");
    cmd status = contr_butten();
    while (status.cmd != 'r') {
        //запись в файл
        if (status.cmd == 'c') {
            buf[status.num].read();
        }
        //взять из файла
        else if (status.cmd == 'v') {
            s = buf[status.num].write(s);
            std::cout << s << std::endl;
        }
        status = contr_butten();
    }
    return 0;
}