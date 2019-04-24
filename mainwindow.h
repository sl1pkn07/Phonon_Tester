#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <KMainWindow>

class KLineEdit;
class QPushButton;

namespace Phonon {
    class MediaObject;
}

class MainWindow : public KMainWindow
{
    Q_OBJECT
    
    public:
    MainWindow(QWidget *parent=0);
    
    private slots:
    void openFile();
    
    private:
    Phonon::MediaObject *media;
    
    KLineEdit *file_name;
    QPushButton *file_button;
};

#endif // MAINWINDOW_H
