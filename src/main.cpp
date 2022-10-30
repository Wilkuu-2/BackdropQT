
#include "BackdropQT.h"

#include <stdio.h>
#include <QApplication>
#include <string.h>

void setWindowToX11Root(BackdropQT * window);
const char* default_url = "http::/www.wilkuu.xyz/";

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    BackdropQT window = BackdropQT();

    int monitor;
    QUrl url; 
    // Argument parsing TODO: Make/Use a argument parser 
    if(argc > 1){
        url = QUrl(argv[1]);
        if(argc > 2 ){
            monitor = QString(argv[2]).toInt();
        } else {
            monitor = 0;
        }
    }
    else
        url = QUrl(default_url);

    window.start(url);

    window.makeDesktop(&app,monitor);

    window.show();
    return app.exec();
}


