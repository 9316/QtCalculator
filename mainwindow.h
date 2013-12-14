#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double num1,num2,res;
    QString op;
    QString tempStr;

    
private slots:
    void on_button7_clicked();

    void on_button8_clicked();

    void on_button9_clicked();

    void on_button4_clicked();

    void on_button5_clicked();

    void on_button6_clicked();

    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

    void on_buttonAdd_clicked();

    void on_buttonSubstract_clicked();

    void on_buttonMultiply_clicked();

    void on_buttonDivide_clicked();

    void on_buttonEquals_clicked();

    void on_pushButton_clicked();

    void on_buttonDot_clicked();

    void on_button0_clicked();

    void keyPressEvent(QKeyEvent *key);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
