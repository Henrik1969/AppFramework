// IUIBuilder.hpp

#ifndef IUIBUILDER_HPP
#define IUIBUILDER_HPP

#include <string>

class IUIBuilder {
public:
    virtual ~IUIBuilder() {}
    virtual void createWindow(const std::string& title, int width, int height) = 0;
    // Basic Widgets
    virtual void createButton(const std::string& label) = 0;
//    virtual void createLabel(const std::string& text) = 0;
//    virtual void createEntry() = 0;
//    virtual void createTextView() = 0;
//    virtual void createComboBox(const std::vector<std::string>& items) = 0;
//    virtual void createCheckBox(const std::string& label) = 0;
//    virtual void createRadioButton(const std::string& label) = 0;
//    virtual void createProgressBar() = 0;
//    virtual void createSlider(double min, double max, double step) = 0;
//    virtual void createScrollbar(double min, double max, double step) = 0;
//    virtual void createTreeView() = 0;
//    virtual void createNotebook() = 0;
//    virtual void createMenuBar() = 0;
//    virtual void createToolbar() = 0;
//    virtual void createDialog(const std::string& title) = 0;
//    virtual void createStatusbar() = 0;
//    virtual void createFrame(const std::string& label) = 0;
//    virtual void createBox(bool horizontal) = 0;
//    virtual void createPanedWindow(bool horizontal) = 0;
//    virtual void createEventBox() = 0;
//    virtual void createDrawingArea() = 0;
//    virtual void createImage(const std::string& file_path) = 0;
    // Add other UI component methods as needed
};



#endif // IUIBUILDER_HPP

