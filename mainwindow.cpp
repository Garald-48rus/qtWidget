#include<QKeyEvent>


#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Привет!!!");
    qApp->installEventFilter(this);
    ui->groupBoxAdmin->hide();

}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
   if(event->type() == QEvent::KeyPress)
   {

      if(watched == ui->btnSensor_1 )
      {

       QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

       if(keyEvent->key() == Qt::Key_Backspace  )
       {

          ui->groupBoxAdmin->show();
          ui->groupBoxMain->hide();


       }

      }

   }


  QObject::eventFilter(watched, event);

}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    ui->groupBoxMain->show();
    ui->groupBoxAdmin->hide();

}
