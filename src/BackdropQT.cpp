#include <QtWebEngineWidgets>
#include <QtWebEngine>
#include "BackdropQT.h"
#include "ui_BackdropQT.h"
#include <iostream>

BackdropQT::BackdropQT(QWidget *parent) : QMainWindow(parent), ui(new Ui::BackdropQT) {
   ui->setupUi(this);

   ui->webview->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
   ui->webview->settings()->setAttribute(QWebEngineSettings::ShowScrollBars, false);
   ui->webview->settings()->setAttribute(QWebEngineSettings::PlaybackRequiresUserGesture, false);
}

BackdropQT::~BackdropQT(){
    delete ui;
}

void BackdropQT::start(QUrl url){
    ui->webview->load(url);
}

void BackdropQT::makeDesktop(QApplication * app, int monitor){   
   auto screens = app->screens(); 
   
   if(monitor >=  screens.length()){
        fprintf(stderr, "ERROR: Given monitor is out of bounds: %d out of %d \n", monitor + 1, screens.length()); 
        exit(2); 
   }

   QRect desktop = screens.at(monitor)->geometry();
   printf("%d %d %d %d \n",desktop.x(),desktop.y(),desktop.height(),desktop.width());

   setAttribute(Qt::WA_X11NetWmWindowTypeDesktop);
   setAttribute(Qt::WA_X11DoNotAcceptFocus);
   setAttribute(Qt::WA_TransparentForMouseEvents);
   setWindowModality(Qt::NonModal);
   setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);
   setGeometry(desktop);

}
