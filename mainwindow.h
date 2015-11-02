#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void readPendingDatagrams();
    //void on_btSendUDP_clicked();
    void readResponse();
    //void on_btSendSerial_clicked();

    void on_btOpenSerial_clicked();

    void on_btRefresh_clicked();

    void on_btCloseSerial_clicked();

    void on_btOpenUDP_clicked();

    void on_btSendUDP_clicked();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
