#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_result_clicked();

    void on_rbtn_study_clicked(bool checked);

    void on_rbtn_sports_clicked(bool checked);

    void on_dpdl_taskList_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    void updateExercisesList();
};
#endif // MAINWINDOW_H
