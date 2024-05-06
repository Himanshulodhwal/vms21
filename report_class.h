#ifndef REPORT_CLASS_H
#define REPORT_CLASS_H

#include <QWidget>
#include <sql_helper.h>
#include <clickable_report_label.h>
#include <mainwindow.h>
namespace Ui {
class Report_class;
}

class Report_class : public QWidget
{
    Q_OBJECT

public:
    explicit Report_class(QWidget *parent = nullptr);
    ~Report_class();
    QString convertTimestamp(const QString& timestamp);

private slots:
    void on_pushButton_search_clicked();

    void on_pushButton_export_clicked();
    void updateadd_deviceComboBox();
    void handleLabelClicked();
    void showPreviousPage();
    void showNextPage();
private:
    void updateTableDisplay();
private:
    Ui::Report_class *ui;
    sql_helper& sql_help = sql_helper::getInstance();
    Clickable_report_label *clickableLabel;
    MainWindow mainwindow;
    int  currentPageIndex=0;
    int pageSize=10; // Example: 10 rows per page

};

#endif // REPORT_CLASS_H
