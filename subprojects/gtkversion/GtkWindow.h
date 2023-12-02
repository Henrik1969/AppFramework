// MyGtkWindow.h

#ifndef MYGTKWINDOW_H
#define MYGTKWINDOW_H

#include "IWindow.h"
#include <gtk/gtk.h>

class MyGtkWindow : public IWindow {
private:
    GtkWidget *window;

public:
    MyGtkWindow() {
        gtk_init(0, nullptr);
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window), "GTK Window");
        gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    }

    ~MyGtkWindow() {
        gtk_widget_destroy(window);
    }

    void show() override {
        gtk_widget_show_all(window);
        gtk_main();
    }
};

#endif // MYGTKWINDOW_H

