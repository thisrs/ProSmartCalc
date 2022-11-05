#include "View.h"

#include <QLabel>
#include <QString>
#include <exception>

#include "./ui_mainwindow.h"
#include "Controller.h"

using namespace s21;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->widget->xAxis->setRange(-10, 10);
  ui->widget->yAxis->setRange(-10, 10);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  char* str = new char(ui->lineEdit->text().length());
  QByteArray barr = ui->lineEdit->text().toLatin1();
  strlcpy(str, barr, ui->lineEdit->text().length() + 1);

  Controller controller(str);

  try {
    controller.getResult();
  } catch (std::exception& ex) {
    ui->lineEdit->setText(ex.what());
  }

  switch (controller.getStatus()) {
    case NORMAL:
      ui->lineEdit->setText(
          QString::number(controller.getDoubleResult(), 'g', 15));
      break;
    case GRAPH:

      ui->widget->addGraph();

      ui->widget->graph(0)->addData(controller.getX(), controller.getY());
      ui->widget->replot();

      ui->widget->graph(0)->data()->clear();

      break;
  }
  if (str) delete (str);
}
