#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // set the window title
    this->setWindowTitle("Тренажёр полезных привычек");
    // set the main label
    ui->lbl_mainName->setText("Добро пожаловать в тренажёр привычек!");
    // set radio buttons names
    ui->rbtn_study->setText("Обучение");
    ui->rbtn_sports->setText("Спорт");
    // set active radio button
    ui->rbtn_study->setChecked(true);
    // progress bar
    ui->pb_progress->setMinimum(0);
    ui->pb_progress->setMaximum(100);
    ui->pb_progress->setValue(0);
    // set button name
    ui->btn_result->setText("Выполнить действие");
    // set the button as toggle
    ui->btn_result->setCheckable(true);
    ui->btn_result->setChecked(false);
    // set dropdown list with initial values
    updateExercisesList();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_result_clicked()
{
    // get current value of progress bar
    int currentValue = ui->pb_progress->value();

    // increase it
    int newValue = currentValue + 10;

    // process a new value
    if (newValue > 100) {
        ui->pb_progress->setValue(0);
    } else if (newValue == 100) {
        ui->pb_progress->setValue(newValue);
        // create a window with congrats
        QMessageBox congrats;
        congrats.setWindowTitle("🏆 Достижение!");
        congrats.setText("<h2>Отличная работа! 🎉</h2>"
                         "<p>Вы выполнили:</p>"
                         "<h3><b>" + ui->dpdl_taskList->currentText() + "</b></h3>"
                         "<p>Прогресс достиг 100%!</p>"
                         "<p>Продолжайте в том же духе!</p>");
        congrats.setIcon(QMessageBox::Information);
        congrats.setStandardButtons(QMessageBox::Ok);
        congrats.exec();
    } else {
        ui->pb_progress->setValue(newValue);
    }
}

void MainWindow::updateExercisesList()
{
    // clear list
    ui->dpdl_taskList->clear();

    // fill it again depending on radio button
    // sport
    if (ui->rbtn_sports->isChecked()) {
        ui->dpdl_taskList->addItem("Отжимания");
        ui->dpdl_taskList->addItem("Приседания");
        ui->dpdl_taskList->addItem("Планка");
        ui->dpdl_taskList->addItem("Подтягивания");
        ui->dpdl_taskList->addItem("Подпрыгивания");
        ui->dpdl_taskList->addItem("Выпады");
        ui->dpdl_taskList->addItem("Скручивания");
    }
    // study
    else if (ui->rbtn_study->isChecked()) {
        ui->dpdl_taskList->addItem("Чтение книги");
        ui->dpdl_taskList->addItem("Написание кода");
        ui->dpdl_taskList->addItem("Конспект");
        ui->dpdl_taskList->addItem("Решение задач");
        ui->dpdl_taskList->addItem("Просмотр лекции");
        ui->dpdl_taskList->addItem("Тестирование");
        ui->dpdl_taskList->addItem("Изучение документации");
    }

    // reset progress
    ui->pb_progress->setValue(0);
}

void MainWindow::on_rbtn_study_clicked(bool checked)
{
    if (checked) {
        updateExercisesList();
    }
}

void MainWindow::on_rbtn_sports_clicked(bool checked)
{
    if (checked) {
        updateExercisesList();
    }
}

void MainWindow::on_dpdl_taskList_currentIndexChanged(int index)
{
    ui->pb_progress->setValue(0);
}
