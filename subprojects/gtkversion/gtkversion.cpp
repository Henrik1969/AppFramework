#include <gtk/gtk.h>
#include <iostream>

int main() {
    std::cout << "GTK Version: " 
              << GTK_MAJOR_VERSION << "." 
              << GTK_MINOR_VERSION << "." 
              << GTK_MICRO_VERSION << std::endl;
    return 0;
}