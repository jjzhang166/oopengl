/**
 * @author : xiaozhuai
 * @date   : 16/12/30
 */

#ifndef X11_OPENGL_MAINWINDOW_H
#define X11_OPENGL_MAINWINDOW_H

#include "XGlWindow.h"

class MainWindow : public XGlWindow{

public:
    MainWindow(int w, int h);
    void onDraw();

};


#endif //X11_OPENGL_MAINWINDOW_H
