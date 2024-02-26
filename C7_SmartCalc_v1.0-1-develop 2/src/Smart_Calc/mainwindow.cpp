#include "mainwindow.h"

#include <cmath>

#include "ui_mainwindow.h"

extern "C" {
#include "../library/headers/s21_calc.h"
#include "../library/headers/s21_stack.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->plot->xAxis->setLabel("x");
  ui->plot->yAxis->setLabel("y");
  ui->plot->xAxis->setRange(ui->spinBox_min_x->value(),
                            ui->spinBox_max_x->value());
  ui->plot->yAxis->setRange(ui->spinBox_min_y->value(),
                            ui->spinBox_max_y->value());

  connect(ui->pushButton_0, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));

  connect(ui->pushButton_float, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_add, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));

  connect(ui->pushButton_left_bracket, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_right_bracket, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));

  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(pushButton_math_clicked()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_0)
    emit ui->pushButton_0->clicked();
  else if (event->key() == Qt::Key_1)
    emit ui->pushButton_1->clicked();
  else if (event->key() == Qt::Key_2)
    emit ui->pushButton_2->clicked();
  else if (event->key() == Qt::Key_3)
    emit ui->pushButton_3->clicked();
  else if (event->key() == Qt::Key_4)
    emit ui->pushButton_4->clicked();
  else if (event->key() == Qt::Key_5)
    emit ui->pushButton_5->clicked();
  else if (event->key() == Qt::Key_6)
    emit ui->pushButton_6->clicked();
  else if (event->key() == Qt::Key_7)
    emit ui->pushButton_7->clicked();
  else if (event->key() == Qt::Key_8)
    emit ui->pushButton_8->clicked();
  else if (event->key() == Qt::Key_9)
    emit ui->pushButton_9->clicked();
  else if (event->key() == Qt::Key_Backspace)
    emit ui->pushButton_erase->clicked();
  else if (event->key() == Qt::Key_Slash)
    emit ui->pushButton_div->clicked();
  else if (event->key() == Qt::Key_Minus)
    emit ui->pushButton_sub->clicked();
  else if (event->key() == Qt::Key_Return or event->key() == Qt::Key_Enter) {
    if (ui->Math->isVisible())
      emit ui->pushButton_result->clicked();
    else if (ui->Graph->isVisible())
      emit ui->pushButton_draw->clicked();
    else if (ui->Credit->isVisible())
      emit ui->pushButton_calc_credit->clicked();
    else if (ui->Deposit->isVisible())
      emit ui->pushButton_calc_deposit->clicked();
  } else if (event->key() == Qt::Key_Plus)
    emit ui->pushButton_add->clicked();
  else if (event->key() == Qt::Key_Asterisk)
    emit ui->pushButton_mult->clicked();
  else if (event->key() == Qt::Key_Period)
    emit ui->pushButton_float->clicked();
  else if (event->key() == Qt::Key_ParenLeft)
    emit ui->pushButton_left_bracket->clicked();
  else if (event->key() == Qt::Key_ParenRight)
    emit ui->pushButton_right_bracket->clicked();
  else if (event->key() == Qt::Key_AsciiCircum)
    emit ui->pushButton_pow->clicked();
}

void MainWindow::pushButton_math_clicked() {
  QString text = ui->lineEdit_math->text();
  QString new_text;

  if (sender()->objectName() == "pushButton_0")
    new_text = "0";
  else if (sender()->objectName() == "pushButton_1")
    new_text = "1";
  else if (sender()->objectName() == "pushButton_2")
    new_text = "2";
  else if (sender()->objectName() == "pushButton_3")
    new_text = "3";
  else if (sender()->objectName() == "pushButton_4")
    new_text = "4";
  else if (sender()->objectName() == "pushButton_5")
    new_text = "5";
  else if (sender()->objectName() == "pushButton_6")
    new_text = "6";
  else if (sender()->objectName() == "pushButton_7")
    new_text = "7";
  else if (sender()->objectName() == "pushButton_8")
    new_text = "8";
  else if (sender()->objectName() == "pushButton_9")
    new_text = "9";
  else if (sender()->objectName() == "pushButton_float")
    new_text = ".";
  else if (sender()->objectName() == "pushButton_pow")
    new_text = "^";
  else if (sender()->objectName() == "pushButton_mod")
    new_text = "mod";
  else if (sender()->objectName() == "pushButton_sqrt")
    new_text = "sqrt(";
  else if (sender()->objectName() == "pushButton_div")
    new_text = "/";
  else if (sender()->objectName() == "pushButton_add")
    new_text = "+";
  else if (sender()->objectName() == "pushButton_sub")
    new_text = "-";
  else if (sender()->objectName() == "pushButton_mult")
    new_text = "*";
  else if (sender()->objectName() == "pushButton_left_bracket")
    new_text = "(";
  else if (sender()->objectName() == "pushButton_right_bracket")
    new_text = ")";
  else if (sender()->objectName() == "pushButton_sin")
    new_text = "sin(";
  else if (sender()->objectName() == "pushButton_cos")
    new_text = "cos(";
  else if (sender()->objectName() == "pushButton_tan")
    new_text = "tan(";
  else if (sender()->objectName() == "pushButton_asin")
    new_text = "asin(";
  else if (sender()->objectName() == "pushButton_acos")
    new_text = "acos(";
  else if (sender()->objectName() == "pushButton_atan")
    new_text = "atan(";
  else if (sender()->objectName() == "pushButton_ln")
    new_text = "ln(";
  else if (sender()->objectName() == "pushButton_log")
    new_text = "log(";

  if (isAppend)
    text.append(new_text);
  else
    text = new_text;
  ui->lineEdit_math->setText(text);
  isAppend = true;
}

void MainWindow::on_pushButton_clear_clicked() {
  isAppend = false;
  ui->lineEdit_math->clear();
  ui->statusbar->clearMessage();
}

void MainWindow::on_pushButton_erase_clicked() {
  QString text = ui->lineEdit_math->text();
  text.chop(1);
  ui->lineEdit_math->setText(text);
  ui->statusbar->clearMessage();
}

void MainWindow::on_pushButton_result_clicked() {
  ui->statusbar->clearMessage();
  isAppend = false;
  QString text = ui->lineEdit_math->text();
  char *input;
  std::string fname = text.toStdString();
  input = new char[fname.size() + 10];
  strlcpy(input, fname.c_str(), sizeof(fname));
  size_t len = strlen(input);
  if (len > 0 && input) {
    double res = 0;
    int ret_code = 0;
    ret_code = validation(input);
    if (ret_code == 0) {
      res = calculation(input, 0);
      if (isnan(res) || isinf(res)) {
        ret_code = 2;
        show_message_in_bar(ret_code);
      } else {
        ui->lineEdit_math->setText(
            QString::number(round(res * 1000000) / 1000000, 'g', 10));
      }
    }
    show_message_in_bar(ret_code);
  }
  delete[] input;
}

void MainWindow::on_pushButton_draw_clicked() {
  ui->plot->clearGraphs();
  x.clear();
  y.clear();
  arrx.clear();
  arry.clear();
  ui->statusbar->clearMessage();

  double min_x = ui->spinBox_min_x->value();
  double min_y = ui->spinBox_min_y->value();
  double max_x = ui->spinBox_max_x->value();
  double max_y = ui->spinBox_max_y->value();
  double step = ui->spinBox_step->value();
  int error = 0;
  QString text = ui->lineEdit_graph->text();
  char *input;
  std::string fname = text.toStdString();
  input = new char[fname.size() + 1];
  strlcpy(input, fname.c_str(), sizeof(fname));
  size_t len = strlen(input);
  for (int i = 4; i < ((int)strlen(input)); i++) {
    input[i - 4] = input[i];
  }
  input[len - 4] = 0;
  if (len > 0) {
    error = validation(input);
    if (error == 0) {
      double tmp_x = min_x, tmp_y = 0;
      while (tmp_x <= max_x) {
        tmp_y = calculation(input, tmp_x);
        if (tmp_y == S21_NAN) {
          error = 0;
          continue;
        }
        if ((tmp_y < min_y or tmp_y > max_y) and !x.empty()) {
          arrx.push_back(x);
          arry.push_back(y);
          x.clear();
          y.clear();
        } else {
          x.push_back(tmp_x);
          y.push_back(tmp_y);
        }
        tmp_x += step;
      }
    }
    if (!x.empty()) {
      arrx.push_back(x);
      arry.push_back(y);
    }

    if (error == 0) {
      ui->plot->clearGraphs();
      ui->plot->xAxis->setRange(min_x, max_x);
      ui->plot->yAxis->setRange(min_y, max_y);

      size_t i = 0;
      auto iter2 = arrx.begin();
      for (const auto &val : arry) {
        ui->plot->addGraph();
        ui->plot->graph()->setPen(QPen(Qt::blue, 2));
        ui->plot->graph(i++)->addData(*iter2++, val, true);
        ui->plot->replot();
      }
    } else
      show_message_in_bar(error);
  }
  delete[] input;
}

void MainWindow::show_message_in_bar(int code) {
  if (code == 1) {
    ui->statusbar->showMessage("Ошибка ввода выражения");
    ui->lineEdit_math->setText("Error");
  } else if (code == 2) {
    ui->statusbar->showMessage("Ошибка вычислений");
    ui->lineEdit_math->setText("Error");
  }
}

void MainWindow::on_pushButton_add_plus_clicked() {
  QTableWidgetItem *dateItem = new QTableWidgetItem();
  QTableWidgetItem *sumItem = new QTableWidgetItem();

  // Добавляем новую строку в конец таблицы
  ui->tableWidget_add->insertRow(ui->tableWidget_add->rowCount());

  // Устанавливаем элементы в ячейках
  ui->tableWidget_add->setItem(ui->tableWidget_add->rowCount(), 0, dateItem);
  ui->tableWidget_add->setItem(ui->tableWidget_add->rowCount(), 1, sumItem);
}

void MainWindow::on_pushButton_sub_plus_clicked() {
  QTableWidgetItem *dateItem = new QTableWidgetItem();
  QTableWidgetItem *sumItem = new QTableWidgetItem();

  // Добавляем новую строку в конец таблицы
  ui->tableWidget_sub->insertRow(ui->tableWidget_sub->rowCount());

  // Устанавливаем элементы в ячейках
  ui->tableWidget_sub->setItem(ui->tableWidget_sub->rowCount(), 0, dateItem);
  ui->tableWidget_sub->setItem(ui->tableWidget_sub->rowCount(), 1, sumItem);
}

void MainWindow::on_pushButton_add_minus_clicked() {
  ui->tableWidget_add->removeRow(ui->tableWidget_add->rowCount() - 1);
}

void MainWindow::on_pushButton_sub_minus_clicked() {
  ui->tableWidget_sub->removeRow(ui->tableWidget_sub->rowCount() - 1);
}

void MainWindow::on_pushButton_calc_deposit_clicked() {
  ui->label_interest->clear();
  ui->label_tax->clear();
  ui->label_deposit_result->clear();
  ui->statusbar->clearMessage();

  double initial_sum = ui->spinBox_deposit_sum->value();
  double interest_rate = ui->spinBox_interest_rate->value();
  double tax_rate = ui->spinBox_tax_rate->value();

  int error = 0;
  int term = ui->spinBox_term->value();
  int capitalization = ui->checkBox_capitalization->isChecked();

  QDate today = QDate::currentDate();
  QDate futureDate = today.addMonths(term);
  int days = abs(futureDate.daysTo(today));

  double *add_sum = (double *)malloc(sizeof(double) * (days + 1));
  double *sub_sum = (double *)malloc(sizeof(double) * (days + 1));

  for (int i = 0; i <= days; i++) add_sum[i] = sub_sum[i] = 0;

  for (int row = 0; row < ui->tableWidget_add->rowCount(); row++) {
    QTableWidgetItem *dateItem = ui->tableWidget_add->item(row, 0);
    QTableWidgetItem *sumItem = ui->tableWidget_add->item(row, 1);
    if (dateItem && sumItem) {
      QString date_string_on_db = dateItem->data(Qt::EditRole).toString();
      QDate date = QDate::fromString(date_string_on_db, "dd.MM.yyyy");
      double sum = sumItem->data(Qt::EditRole).toDouble();
      int day = abs(today.daysTo(date));
      if (day > days)
        error = 2;
      else
        add_sum[day] = sum;
    }
  }

  for (int row = 0; row < ui->tableWidget_sub->rowCount(); row++) {
    QTableWidgetItem *dateItem = ui->tableWidget_sub->item(row, 0);
    QTableWidgetItem *sumItem = ui->tableWidget_sub->item(row, 1);
    if (dateItem && sumItem) {
      QString date_string_on_db = dateItem->data(Qt::EditRole).toString();

      QDate date = QDate::fromString(date_string_on_db, "dd.MM.yyyy");
      double sum = sumItem->data(Qt::EditRole).toDouble();
      int day = abs(today.daysTo(date));
      if (day > days) {
        error = 3;
      } else {
        sub_sum[day] = sum;
      }
    }
  }

  int year_days = 366;
  double total = initial_sum;
  double interest = 0.000000;
  today = today.addDays(1);
  int per_day = 1;
  int flag = 1;
  for (int i = 1; i <= days; i++) {
    if (add_sum[i] || add_sum[i]) {
      total += add_sum[i];
      initial_sum += add_sum[i];
    } else if (sub_sum[i]) {
      if (total - sub_sum[i] > 0) {
        total -= sub_sum[i];
        initial_sum -= sub_sum[i];
      } else {
        error = 1;
      }
    }
    if (capitalization) {
      switch (ui->comboBox_payment_period->currentIndex()) {
        case 0:
          total += total * interest_rate * 0.01 / year_days;
          futureDate = futureDate.addDays(-1);
          break;
        case 1:
          if (i % 7 == 0) {
            interest += total * interest_rate * 0.01 / year_days;
            futureDate = futureDate.addDays(-7);
            total += interest;
            interest = 0;
          } else {
            interest += total * interest_rate * 0.01 / year_days;
          }
          break;
        case 2:
          per_day = abs(today.daysTo(today.addMonths(flag)));
          if (i % per_day == 0) {
            interest += total * interest_rate * 0.01 / year_days;
            futureDate = futureDate.addMonths(-1);
            total += interest;
            interest = 0;
            flag += 1;
          } else {
            interest += total * interest_rate * 0.01 / year_days;
          }
          break;
        case 3:
          per_day = abs(today.daysTo(today.addMonths(flag + 2)));
          if (i % per_day == 0) {
            interest += total * interest_rate * 0.01 / year_days;
            futureDate = futureDate.addMonths(-3);
            total += interest;
            interest = 0;
            flag += 3;
          } else {
            interest += total * interest_rate * 0.01 / year_days;
          }
          break;
        case 4:
          per_day = abs(today.daysTo(today.addMonths(flag + 5)));
          if (i % per_day == 0) {
            interest += total * interest_rate * 0.01 / year_days;
            futureDate = futureDate.addMonths(-6);
            total += interest;
            interest = 0;
            flag += 6;
          } else {
            interest += total * interest_rate * 0.01 / year_days;
          }
          break;
        case 5:
          per_day = abs(today.daysTo(today.addMonths(flag + 11)));
          if (i % per_day == 0) {
            interest += total * interest_rate * 0.01 / year_days;
            futureDate = futureDate.addMonths(-12);
            total += interest;
            interest = 0;
            flag += 12;
          } else {
            interest += total * interest_rate * 0.01 / year_days;
          }
          break;
      }

    } else {
      interest += initial_sum * interest_rate * 0.01 / year_days;
    }
  }
  if (today.daysTo(futureDate) > 0) {
    total = total * pow(1 + (interest_rate * 0.01) / year_days,
                        today.daysTo(futureDate));
  }
  if (capitalization) {
    interest = total - initial_sum;
  } else {
    total = interest + initial_sum;
  }

  double tax_free = 1000000 * (tax_rate * 0.01);
  double tax = 0;
  if (interest > tax_free) {
    tax = (interest - tax_free) * 0.13;
  }
  total = total - tax;

  if (error == 0) {
    ui->label_interest->setText(
        QString::number(round(interest * 100) / 100, 'g', 10));
    ui->label_tax->setText(QString::number(round(tax * 100) / 100, 'g', 10));
    ui->label_deposit_result->setText(
        QString::number(round(total * 100) / 100, 'g', 10));
  } else if (error == 1) {
    ui->statusbar->showMessage("Ошибка: списание суммы больше суммы депозита");
  } else if (error == 2) {
    ui->statusbar->showMessage(
        "Ошибка: дата пополнения выходит за срок депозита");
  } else if (error == 3) {
    ui->statusbar->showMessage(
        "Ошибка: дата списания выходит за срок депозита");
  }

  free(add_sum);
  free(sub_sum);
}

void MainWindow::on_pushButton_calc_credit_clicked() {
  ui->label_monthpay->clear();
  ui->label_overpayment->clear();
  ui->label_overpayment_rate->clear();
  ui->label_total->clear();
  ui->statusbar->clearMessage();

  QString text;

  int term = ui->spinBox_credit_term->value();
  int debt = ui->spinBox_credit_sum->value();
  double rate = ui->spinBox_rate->value();

  double overpayment = 0;
  double total = 0;
  double debt_copy = debt;

  if (ui->radioButton_annu->isChecked()) {
    double monthpay = 0;
    rate = rate / 100 / 12;
    monthpay = debt * (rate + (rate / (pow(1 + rate, term) - 1)));
    total = monthpay * term;
    overpayment = total - debt;
    text = QString::number(round(monthpay * 100) / 100, 'g', 10);
  } else if (ui->radioButton_diff->isChecked()) {
    double *monthpay = (double *)malloc(sizeof(double) * term);
    QString row;
    double part_debt = debt / term;
    for (int i = 0; i < term; i++) {
      double interest_month = debt * rate * 0.01 / 12;
      monthpay[i] = interest_month + part_debt;
      overpayment += interest_month;
      debt -= part_debt;
      row = QString::number(i + 1, 'g', 3) + " month: " +
            QString::number(round(monthpay[i] * 100) / 100, 'g', 10) + "\n";
      text.append(row);
      if (i == term - 1) {
        text.chop(1);
      }
    }
    total = debt_copy + overpayment;
    free(monthpay);
  }
  ui->label_overpayment_rate->setText(QString::number(
      round((overpayment / debt_copy * 100) * 100) / 100, 'g', 10));
  ui->label_monthpay->setText(text);
  ui->label_overpayment->setText(
      QString::number(round(overpayment * 100) / 100, 'g', 10));
  ui->label_total->setText(QString::number(round(total * 100) / 100, 'g', 10));
}
