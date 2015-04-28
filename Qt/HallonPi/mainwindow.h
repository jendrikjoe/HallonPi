#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTableWidget>
#include <QTabBar>
#include <QDesktopWidget>
#include <QDockWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QStringList>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QDockWidget *houseKeeping;
    QTabWidget *tabWidget;
    QWidget *tcpComWidget;
    QWidget *adcWidget;
    QGridLayout *adcLayout;
    QCheckBox *adcAverage;
    QComboBox *adcChooseChannelBox;
    QLabel *adcChooseChannelLabel;
    QDesktopWidget *desktopSize;
    QStringList *adcChannels;
};

#endif // MAINWINDOW_H
