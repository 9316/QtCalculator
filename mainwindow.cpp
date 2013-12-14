#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("QTLator");



}
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_button7_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "7"); //დააყენე 7 plainTextedit-თვის მიმატების დროს რომ არ წაშალოს რიცხვი

}

void MainWindow::on_button8_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "8");
}

void MainWindow::on_button9_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "8");
}

void MainWindow::on_button4_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "4");
}

void MainWindow::on_button5_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "5");
}

void MainWindow::on_button6_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "6");
}

void MainWindow::on_button1_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "1");
}

void MainWindow::on_button2_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "2");
}

void MainWindow::on_button3_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "3");
}

void MainWindow::on_buttonAdd_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "+");
}

void MainWindow::on_buttonSubstract_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "-");

}

void MainWindow::on_buttonMultiply_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "*");
}

void MainWindow::on_buttonDivide_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "/");
}

void MainWindow::on_buttonEquals_clicked()
{
    tempStr = ui->plainTextEdit->toPlainText(); //tempStr განკუთვნილია plainTextEdit- ისათვის
    for(int i=0; i<tempStr.size(); i++){   // ციკლი რომელიც ტრიალებს tempStr zomamde
        if(tempStr[i]=='+')        // მოქმედების შემოწმება
            op="+";
        else if(tempStr[i]=='-')
            op="-";
        else if(tempStr[i]=='*')
            op="*";
        else if(tempStr[i]=='/')
            op="/";
    }


    if(op=="+"){ //თუ ოპერაცია(op) ტოლია + ის
        QStringList nums = tempStr.split("+"); // nums მასივი დაანაწევრე + - ით
        num1=nums[0].toDouble();  //num1 ტოლია nums მასივის 0-ლე წევრის დაბლში გადაყვანა
        num2=nums[1].toDouble();
        res=num1+num2;   //რეზულტატი num1 + num2
        ui->plainTextEdit->setPlainText(QString::number(res)); // plainTextedit-ზე რეზულტატის დაყენება (რიცხვების)
    }
    else if(op=="-"){
        QStringList nums = tempStr.split("-");
        num1=nums[0].toDouble();
        num2=nums[1].toDouble();
        res=num1-num2;
        ui->plainTextEdit->setPlainText(QString::number(res));
    }
    else if(op=="*"){
        QStringList nums = tempStr.split("*");
        num1=nums[0].toDouble();
        num2=nums[1].toDouble();
        res=num1*num2;
        ui->plainTextEdit->setPlainText(QString::number(res));
    }

    else if(op=="/"){
        QStringList nums = tempStr.split("/");
        num1=nums[0].toDouble();
        num2=nums[1].toDouble();
        res=num1/num2;
        ui->plainTextEdit->setPlainText(QString::number(res));
    }
}

void MainWindow::on_pushButton_clicked()
{
    res=num1=num2=0; //თუ   res ტოლია num1 ტოლია num2 უდრის 0 ანუ (false)
    ui->plainTextEdit->clear(); //გაასუფთავე
}

void MainWindow::on_buttonDot_clicked()
{
    if(ui->plainTextEdit->toPlainText().trimmed().isEmpty()){ //თუ plainTextedit ცარიელია
        ui->plainTextEdit->setPlainText("0."); //მიუწერე 0.
    }
    else ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "."); //დააყენე წერტილი
}
void MainWindow::on_button0_clicked()
{
    if(ui->plainTextEdit->toPlainText()!="0"){ //თუ არ უდრის 0
        ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + "0"); // დააყენე 0
    }
}
void MainWindow::keyPressEvent(QKeyEvent *key) {
    switch (key->key()) {
        case Qt::Key_Return: on_buttonEquals_clicked();
            break;
        case Qt::Key_0: on_button0_clicked();
            break;
        case Qt::Key_1: on_button1_clicked();
            break;
        case Qt::Key_2: on_button2_clicked();
            break;
        case Qt::Key_3: on_button3_clicked();
           break;
        case Qt::Key_4: on_button4_clicked();
           break;
        case Qt::Key_5: on_button5_clicked();
           break;
        case Qt::Key_6: on_button6_clicked();
           break;
        case Qt::Key_7: on_button7_clicked();
            break;
        case Qt::Key_8: on_button8_clicked();
            break;
        case Qt::Key_9: on_button9_clicked();
            break;
        case Qt::Key_Comma: on_buttonDot_clicked();
             break;
        case Qt::Key_Plus: on_buttonAdd_clicked();
             break;
        case Qt::Key_Minus: on_buttonSubstract_clicked();
            break;
        case Qt::Key_Slash: on_buttonDivide_clicked();
            break;
        case Qt::Key_Asterisk: on_buttonMultiply_clicked();
            break;
        case Qt::Key_Backspace: on_pushButton_clicked();
            break;
        default:
            break;
    }
}
