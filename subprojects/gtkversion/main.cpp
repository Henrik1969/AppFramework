// main.cpp

#include "GtkWidgetFactory.h"
#include <memory>

int main() {
    std::shared_ptr<IWidgetFactory> factory = std::make_shared<GtkWidgetFactory>();
    auto window = factory->createWindow();
    window->show();
    return 0;
}