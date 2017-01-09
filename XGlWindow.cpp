/**
 * @author : xiaozhuai
 * @date   : 16/12/30
 */

#include "XGlWindow.h"

const int XGlWindow::fbCfgAttribslist[5] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };

XGlWindow::XGlWindow(int w, int h) {
    width = w;
    height = h;

    display = XOpenDisplay(NULL);
    if (display == NULL) {
        std::cout << "Cannot open display\n";
        exit(1);
    }

    root = DefaultRootWindow(display);

    vi = glXChooseVisual(display, 0, (int*)fbCfgAttribslist);
    if(vi == NULL) {
        std::cout << "could not get visual\n";
        exit(0);
    }

    cmap = XCreateColormap(display, root, vi->visual, AllocNone);
    swa.colormap = cmap;
    swa.border_pixel = 0;
    swa.event_mask = ExposureMask | KeyPressMask | StructureNotifyMask;

    window = XCreateWindow(display, root, 0, 0, width, height,
                           0, vi->depth, InputOutput, vi->visual,
                           CWBorderPixel | CWColormap | CWEventMask, &swa);
    XSetStandardProperties(display, window, "OpenGL X11", "OpenGL X11", None, NULL, 0, NULL);

    XMapWindow(display, window);
    XIfEvent(display,  &event,  WaitForMapNotify,  (char *)window);

    glxContext = glXCreateContext(display, vi,  None, GL_TRUE);
    if (glxContext == NULL) {
        std::cout << "could not create rendering context\n";
        exit(1);
    }
    glXMakeCurrent(display, window, glxContext);
    glViewport(0, 0, width, width);
//    glEnable(GL_DEPTH_TEST);
}

void XGlWindow::draw() {
    onPreDraw();
    onDraw();
    onAfterDraw();
}

void XGlWindow::onPreDraw() {

}

void XGlWindow::onAfterDraw() {
    glXSwapBuffers(display, window);
}

void XGlWindow::onDraw()
{


}

void XGlWindow::start() {
    eventLoop = true;
    std::cout << "start...\n";
    while (eventLoop) {
        KeySym key;

        while (XPending(display)) {
            XNextEvent(display, &event);
            switch (event.type) {
                case KeyPress:
                    XLookupString((XKeyEvent *)&event, NULL, 0, &key, NULL);
                    switch (key) {
                        case XK_Escape:
                            stop();
                            break;
                    }
                    break;
            }
        }
        usleep(16000);
        draw();
    }
    XCloseDisplay(display);
}

void XGlWindow::stop() {
    std::cout << "stop...\n";
    eventLoop = false;
}

Bool XGlWindow::WaitForMapNotify(Display *d, XEvent *e, char *arg)
{
    if ((e->type == MapNotify) && (e->xmap.window == (Window)arg)) {
        return GL_TRUE;
    }
    return GL_FALSE;
}