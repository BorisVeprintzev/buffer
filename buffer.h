#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class buffer
{
private:
    char* filename;
    int number;

public:
    string& write(string& s); // na ekran
    void read(); // scopirovat'
    void get_filename(int number);

    buffer(int number); // sozdanie buffera
    buffer();
    ~buffer();
};

#endif