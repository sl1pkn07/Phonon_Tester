#include <QApplication>
#include <QCommandLineParser>

#include <KAboutData>
#include <KLocalizedString>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
    KAboutData aboutData(QStringLiteral("PhononTester"), i18n("Phonon Tester. only Audio"), QStringLiteral("1.0"),
                         i18n("A Phonon tester. only Audio."),
                         KAboutLicense::BSDL,
                         i18n("(c) 2019"));
    aboutData.setHomepage(QStringLiteral("https://github.com/sl1pkn07"));
    aboutData.setBugAddress("https://github.com/sl1pkn07/Phonon_Tester/issues");
    aboutData.addAuthor(i18n("Gustavo Alvarez. (c) 2019"),
                        i18n(" "),
                        QStringLiteral("sl1pkn07@gmail.com"));
    aboutData.addAuthor(i18n("Jon Ander Peñalba. Original author. (c) 2011-2013"),
                        i18n(" "),
                        QStringLiteral("jonan88@gmail.com"));
    KAboutData::setApplicationData(aboutData);
    
    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    aboutData.setupCommandLine(&parser);
    parser.process(app);
    aboutData.processCommandLine(&parser);
    
    MainWindow *window = new MainWindow();
    window->show();
    
    return
        app.exec();
}
