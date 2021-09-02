#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;
bool typingSecondNUm = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_plusminus,SIGNAL(released()),this,SLOT(unitary_operation_pressed()));
    connect(ui->pushButton_percent,SIGNAL(released()),this,SLOT(unitary_operation_pressed()));

    connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_subtract,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->pushButton_add->setCheckable(true);
    ui->pushButton_subtract->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed(){

    QPushButton* button =  (QPushButton*)sender();
    double labelnumber;
    QString newlabel;

    if((ui->pushButton_add->isChecked()||ui->pushButton_subtract->isChecked() ||
            ui->pushButton_multiply->isChecked()||ui->pushButton_divide->isChecked()) && (!typingSecondNUm))
    {
         labelnumber=button->text().toDouble();
         typingSecondNUm=true;
         newlabel= QString::number(labelnumber,'g',15);


    }
    else{
        if (ui->label->text().contains('.') && (button->text()=="0")){

             newlabel=ui->label->text()+ button->text();
        }
        else{
         labelnumber=(ui->label->text()+ button->text()).toDouble();
         newlabel= QString::number(labelnumber,'g',15);
        }
    }

    ui->label->setText(newlabel);
}


void MainWindow::on_pushButton_decimal_released()
{

    ui->label->setText(ui->label->text()+".");
}

void MainWindow::unitary_operation_pressed(){
    QPushButton* button =  (QPushButton*)sender();
    double labelnumber;
    QString newlabel;

    if (button->text()=="+/-"){
        labelnumber= ui->label->text().toDouble();
        labelnumber= labelnumber* (-1);
        newlabel= QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
    }
    else if (button->text()=="%"){
        labelnumber= ui->label->text().toDouble();
        labelnumber= labelnumber* (0.01);
        newlabel= QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
    }
}

void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_add->setChecked(false);
    ui->pushButton_subtract->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);

    ui->label->setText("0");
}

void MainWindow::on_pushButton_equals_released()
{
    double labelnumber, secondNum;
    secondNum=ui->label->text().toDouble();
    QString newlabel;


    if(ui->pushButton_add->isChecked())
    {
        labelnumber = firstNum+ secondNum;
        newlabel = QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_add->setChecked(false);
    }
    else if(ui->pushButton_subtract->isChecked())
    {   labelnumber = firstNum - secondNum;
        newlabel = QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_subtract->setChecked(false);

    }
    else if(ui->pushButton_multiply->isChecked())
    {
        labelnumber = firstNum* secondNum;
        newlabel = QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_multiply->setChecked(false);

    }
    else if(ui->pushButton_divide->isChecked())
    {
        labelnumber = firstNum/ secondNum;
        newlabel = QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_multiply->setChecked(false);

    }

    typingSecondNUm= false;
}

void MainWindow::binary_operation_pressed(){
    QPushButton* button =  (QPushButton*)sender();

    firstNum = ui->label->text().toDouble();
    button->setChecked(true);
}
