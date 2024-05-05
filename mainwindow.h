#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    int player;
    char velha[3][3];

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Check(QPushButton *btn, int col, int row);
    bool CheckWin();
    void HasWinned();
    void ResetButton(QPushButton *btn);
    void ResetMatriz();
    void ClearScreen();
    void EndGame();

private slots:
    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
