/**
 * @author : xiaozhuai
 * @date   : 16/12/30
 */

#include "MainWindow.h"

MainWindow::MainWindow(int w, int h) : XGlWindow(w, h)
{

}

int step = 0;

void MainWindow::onDraw() {

    std::cout << "draw...\n";
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    switch ((step%300)/100){
        case 0:
            glClearColor(1.0, 0.0, 0.0, 1.0);
            break;
        case 1:
            glClearColor(0.0, 1.0, 0.0, 1.0);
            break;
        case 2:
            glClearColor(0.0, 0.0, 1.0, 1.0);
            break;
        default:
            break;
    }

    step ++;
}