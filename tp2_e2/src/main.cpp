// #include <iostream>
// #include <cstdlib>

// int main(int argc, char** argv) {
//     std::cout << "holi" << std::endl;
//     // if(const char* env_p = std::getenv("COLUMNS"))
//     //     std::cout << "Your PATH is: " << env_p << '\n';
//     if(const char* columns = argv[1])
//         std::cout << "Columns: " << columns << '\n';
//     if(const char* rows = argv[2])
//         std::cout << "Rows: " << rows << '\n';
//     return 0;
// }

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
    return 0;  // make sure your main returns int
}