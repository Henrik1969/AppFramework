// GtkWidgetFactory.h

#ifndef GTKWIDGETFACTORY_H
#define GTKWIDGETFACTORY_H

#include "IWidgetFactory.h"
#include "GtkWindow.h"

class GtkWidgetFactory : public IWidgetFactory {
public:
    std::shared_ptr<IWindow> createWindow() override {
        return std::make_shared<MyGtkWindow>();
    }
};

#endif // GTKWIDGETFACTORY_H
