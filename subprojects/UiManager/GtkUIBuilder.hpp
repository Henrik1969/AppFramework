// GtkUIBuilder.hpp

#ifndef GTKUIBUILDER_HPP
#define GTKUIBUILDER_HPP

#include "IUIBuilder.hpp"
#include <gtk/gtk.h>

class GtkUIBuilder : public IUIBuilder {
public:
	GtkUIBuilder(int argc, char* argv[]) {
        gtk_init(&argc, &argv);
    }
    
    void run() {
        gtk_main();
    }
    
    void createWindow(const std::string& title, int width, int height) override {
        GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_default_size(GTK_WINDOW(window), width, height);
        gtk_window_set_title(GTK_WINDOW(window), title.c_str());
        gtk_widget_show_all(window);
    }

    void createButton(const std::string& label) override {
        GtkWidget* button = gtk_button_new_with_label(label.c_str());
        // Add button to a container, e.g., a window or a panel (not shown here)
        gtk_widget_show(button);
    }

    // Additional GTK-specific methods as needed
};

#endif // GTKUIBUILDER_HPP
