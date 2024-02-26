#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void pushButton_math_clicked();
  void on_pushButton_clear_clicked();
  void on_pushButton_result_clicked();
  void on_pushButton_erase_clicked();
  void on_pushButton_add_plus_clicked();
  void on_pushButton_add_minus_clicked();
  void on_pushButton_sub_minus_clicked();
  void on_pushButton_calc_deposit_clicked();
  void on_pushButton_sub_plus_clicked();
  void on_pushButton_calc_credit_clicked();
  void on_pushButton_draw_clicked();

 private:
  Ui::MainWindow *ui;
  bool isAppend = true;
  void keyPressEvent(QKeyEvent *event);
  void show_message_in_bar(int code);

  QVector<double> x, y;
  QVector<QVector<double>> arrx, arry;
};
#endif  // MAINWINDOW_H
