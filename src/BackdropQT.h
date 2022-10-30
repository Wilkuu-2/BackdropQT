
#include <QMainWindow>
#include <QUrl>

namespace Ui {
    class BackdropQT;
}

class BackdropQT : public QMainWindow{
    Q_OBJECT

    public:
        // -- Constructor 
        explicit BackdropQT(QWidget *parent = nullptr);
        // -- Destructor 
        ~BackdropQT();
        
        // -- Starting a website 
        void start(QUrl url); 

        void makeDesktop(QApplication * app, int mon);

    private:
        // -- UI 
        Ui::BackdropQT *ui; 
}; 
