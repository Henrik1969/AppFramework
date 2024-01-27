// UIDirector.hpp

#ifndef UIDIRECTOR_HPP
#define UIDIRECTOR_HPP

#include "IUIBuilder.hpp"

class UIDirector {
public:
    UIDirector(IUIBuilder& builder) : builder(builder) {}

    void constructUI() {
        // Example: Constructing a UI with a window and a button
        builder.createWindow("My App", 800, 600);
        builder.createButton("Click Me");
        // Add more UI construction steps as needed
    }

private:
    IUIBuilder& builder;
};

#endif // UIDIRECTOR_HPP
