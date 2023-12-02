// IWindow.h

#ifndef IWINDOW_H
#define IWINDOW_H

class IWindow {
public:
    virtual ~IWindow() {}
    virtual void show() = 0;
};

#endif // IWINDOW_H
