// IWidgetFactory.h

#ifndef IWIDGETFACTORY_H
#define IWIDGETFACTORY_H

#include "IWindow.h"
#include <memory>

class IWidgetFactory {
public:
    virtual ~IWidgetFactory() {}
    virtual std::shared_ptr<IWindow> createWindow() = 0;
};

#endif // IWIDGETFACTORY_H
