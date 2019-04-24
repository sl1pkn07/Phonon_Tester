#include "mainwindow.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QPushButton>

#include <KLineEdit>
#include <KLocalizedString>

#include <Phonon/AudioOutput>
#include <Phonon/MediaObject>
#include <Phonon/SeekSlider>
#include <Phonon/VolumeSlider>

MainWindow::MainWindow(QWidget *parent)
: KMainWindow(parent)
{
    // Create the widgets
    
    // File selector
    file_name = new KLineEdit(i18n("Open an audio file"), this);
    file_button = new QPushButton(i18n("Open"), this);
    file_name->setEnabled(false);
    connect(file_button, SIGNAL(clicked()), this, SLOT(openFile()));
    
    // Audio control
    Phonon::SeekSlider *seek = new Phonon::SeekSlider(this);
    QPushButton *play_button = new QPushButton(i18n("Play"), this);
    QPushButton *pause_button = new QPushButton(i18n("Pause"), this);
    QPushButton *stop_button = new QPushButton(i18n("Stop"), this);
    Phonon::VolumeSlider *volume = new Phonon::VolumeSlider(this);
    volume->setOrientation(Qt::Vertical);
    
    // Define the layout
    // File stuff
    QHBoxLayout *file_layout = new QHBoxLayout();
    file_layout->addWidget(file_name);
    file_layout->addWidget(file_button);
    
    // Buttons
    QHBoxLayout *button_layout = new QHBoxLayout();
    button_layout->addWidget(play_button);
    button_layout->addWidget(pause_button);
    button_layout->addWidget(stop_button);
    
    // Seek slider
    QVBoxLayout *left_layout = new QVBoxLayout();
    left_layout->addWidget(seek);
    left_layout->addLayout(button_layout);
    
    // Volume slider
    QHBoxLayout *audio_layout = new QHBoxLayout();
    audio_layout->addLayout(left_layout);
    audio_layout->addWidget(volume);
    
    // Let's bring it all together
    QWidget *central_widget = new QWidget();
    QVBoxLayout *central_layout = new QVBoxLayout();
    central_layout->addLayout(file_layout);
    central_layout->addLayout(audio_layout);
    central_widget->setLayout(central_layout);
    setCentralWidget(central_widget);
    
    // Create the media and define the output
    media = new Phonon::MediaObject(this);
    Phonon::AudioOutput *output = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::createPath(media, output);
    
    // Connect the widgets to the audio
    seek->setMediaObject(media);
    volume->setAudioOutput(output);
    connect(play_button, SIGNAL(clicked()), media, SLOT(play()));
    connect(pause_button, SIGNAL(clicked()), media, SLOT(pause()));
    connect(stop_button, SIGNAL(clicked()), media, SLOT(stop()));
}

void MainWindow::openFile()
{
    QString file = QFileDialog::getOpenFileName();
    if (file != ""){
        file_name->setText(file);
        media->setCurrentSource(QUrl::fromLocalFile(file));
        media->play();
    }
}
