#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = 0;
    int cont = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            velha[i][j] = cont + '0';
            cont++;
        }

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Check(QPushButton *btn, int col, int row)
{
    if(player == 0)
    {
        btn->setText("O");
        velha[row][col] = 'O';
        player = 1;
    }
    else
    {
        btn->setText("X");
        velha[row][col]='X';
        player = 0;
    }



    btn->setEnabled(false);
}

void MainWindow::ResetMatriz()
{
    int cont = 1;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            velha[i][j] = cont + '0';
            cont++;
        }
    }
}


bool MainWindow::CheckWin()
{

    // GANHOU HORIZONTALMENTE
    if ((velha[0][0] == velha[0][1] && velha[0][1] == velha[0][2]) ||
        (velha[1][0] == velha[1][1] && velha[1][1] == velha[1][2]) ||
        (velha[2][0] == velha[2][1] && velha[2][1] == velha[2][2]))
        return true;

    // GANHOU VERTICALMENTE
    if ((velha[0][0] == velha[1][0] && velha[1][0] == velha[2][0]) ||
        (velha[0][1] == velha[1][1] && velha[1][1] == velha[2][1]) ||
        (velha[0][2] == velha[1][2] && velha[1][2] == velha[2][2]))
        return true;

    // GANHOU DIAGONALMENTE
    if ((velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2]) ||
        (velha[2][0] == velha[1][1] && velha[1][1] == velha[0][2]))
        return true;

    return false;

}

void MainWindow::HasWinned()
{
    QMessageBox win;
    win.setStyleSheet("QMessageBox{background-color:black;\ncolor:white;}"
                      "QMessageBox QLabel{color:white;}");
    if(player == 0)
    {

        win.information(NULL,"Fim de Jogo","Xs ganharam");
    }
    else
    {
        win.information(NULL,"Fim de Jogo","Bolas ganharam");
    }

}


void MainWindow::ResetButton(QPushButton *btn)
{
    btn->setText("");
    btn->setEnabled(true);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            velha[i][j]='-';
        }
    }
}


void MainWindow::ClearScreen()
{
    ResetButton(ui->btn1);
    ResetButton(ui->btn2);
    ResetButton(ui->btn3);
    ResetButton(ui->btn4);
    ResetButton(ui->btn5);
    ResetButton(ui->btn6);
    ResetButton(ui->btn7);
    ResetButton(ui->btn8);
    ResetButton(ui->btn9);
}


void MainWindow::EndGame()
{
    if(CheckWin() == true)
    {
        HasWinned();
        ClearScreen();
        ResetMatriz();
    }
}
void MainWindow::on_btn1_clicked()
{
    Check(ui->btn1,0,0);
    EndGame();
}


void MainWindow::on_btn2_clicked()
{
    Check(ui->btn2,0,1);
    EndGame();
}


void MainWindow::on_btn3_clicked()
{
    Check(ui->btn3,0,2);
    EndGame();
}


void MainWindow::on_btn4_clicked()
{
    Check(ui->btn4,1,0);
    EndGame();
}


void MainWindow::on_btn5_clicked()
{
    Check(ui->btn5,1,1);
    EndGame();
}


void MainWindow::on_btn6_clicked()
{
    Check(ui->btn6,1,2);
    EndGame();
}


void MainWindow::on_btn7_clicked()
{
    Check(ui->btn7,2,0);
    EndGame();
}


void MainWindow::on_btn8_clicked()
{
    Check(ui->btn8,2,1);
    EndGame();
}


void MainWindow::on_btn9_clicked()
{
    Check(ui->btn9,2,2);
    EndGame();
}

