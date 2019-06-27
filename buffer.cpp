#include "buffer.h"
#include <cstring>

buffer::buffer(int num)
{
    number = num;
    sprintf(filename, "%s%d%s", "buffer", number, ".txt");
    std::ofstream file(filename);
}

buffer::buffer()
{
    number = -1;
}

buffer::~buffer()
{
}


void buffer::get_filename(int num)
{
    number = num;
    ofstream file;
    file.open("buffer"+to_string(number)+".txt");
    file.close();
}

// для вывода, прочитать файл
string& buffer::write(string& s)
{
    // прочитать это if, записать это of
    // тут нужно прочитать 
    string file = "buffer"+to_string(number) + ".txt";
    string h;
    ifstream w(file);
    while (!w.eof()) {
        getline(w, h);
        s = s + h + '\n';
    }
    w.close();
    return s;
}

// для ввода, запись в файл
void buffer::read()
{
    string cmd = "xclip -o > buffer" + to_string(number) + ".txt";
    std::system(cmd.c_str()); // лучше применять escape
}
