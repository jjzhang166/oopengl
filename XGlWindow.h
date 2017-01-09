/**
 * @author : xiaozhuai
 * @date   : 16/12/30
 */

#ifndef X11_OPENGL_XGLWINDOW_H
#define X11_OPENGL_XGLWINDOW_H

#include <X11/Xlib.h>
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

class XGlWindow {

public:
    int width;
    int height;


    Display* display;
    Window root;
    Window window;
    XEvent event;

    XVisualInfo* vi;
    GLXContext glxContext;
    Colormap cmap;
    XSetWindowAttributes swa;

public:
    XGlWindow(int w, int h);

    virtual void draw();
    virtual void onPreDraw();
    virtual void onDraw();
    virtual void onAfterDraw();
    void start();
    void stop();

protected:
    static Bool WaitForMapNotify(Display *d, XEvent *e, char *arg);


    static const int fbCfgAttribslist[5];


private:
    bool eventLoop;

};


#endif //X11_OPENGL_XGLWINDOW_H
