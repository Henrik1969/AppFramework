/*
  This file is part of the AppEssential project.

  AppEssential is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, GPL version 4.

  AppEssential is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License version 4 for more details.

  You should have received a copy of the GNU General Public License
  along with AppEssential. If not, see <https://www.gnu.org/licenses/>.
*/

// UiManager.cpp

#include "UiManager.hpp"
#include <clocale> 
#include <libintl.h>
#include <string>

#define _(String) gettext(String)

// Constructor


UIManager::UIManager(ConfigManager& configManager, Arguments& cmdArgs)
    : configManager(configManager), cmdArgs(cmdArgs) {
    initializeGtk();
    createMainWindow();
}

UIManager::~UIManager() {
    // Assuming window will be automatically destroyed when the main loop quits
    // If any additional cleanup is needed, do it here
}

void UIManager::initializeGtk() {
    // Extract the GTK-specific arguments from the command line arguments
    std::vector<char*> gtkArgs;
    auto gtkArgList = cmdArgs.getGtkArguments(); // You need to implement this method
    for (auto& arg : gtkArgList) {
        gtkArgs.push_back(const_cast<char*>(arg.c_str()));
    }
    int gtkArgc = gtkArgs.size();
    char** gtkArgv = gtkArgs.data();

    // Initialize GTK
    gtk_init(&gtkArgc, &gtkArgv);
}

void UIManager::createMainWindow() {
    // Use settings from ConfigManager to set up the main window
    
    int width = configManager.get<int>("AppFramework.Config.Defaults.gtk.window.width");
    int height = configManager.get<int>("AppFramework.Config.Defaults.gtk.window.height");
    int xpos = configManager.get<int>("AppFramework.Config.Defaults.gtk.window.pos_x");
	int ypos = configManager.get<int>("AppFramework.Config.Defaults.gtk.window.pos_y");

	std::string title = configManager.get<std::string>("AppFramework.Config.Defaults.gtk.window.title");
 
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_default_size(GTK_WINDOW(window), width, height);
	gtk_window_move(GTK_WINDOW(window), xpos, ypos);
	gtk_window_set_title(GTK_WINDOW(window),title.c_str());

    // Connect the window's destroy signal to gtk_main_quit to exit the application
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Additional setup for widgets inside the window
    
}

void UIManager::run() {
    // Show the window and all its contents
    gtk_widget_show_all(window);

    // Enter the GTK main event loop
    gtk_main();
}
