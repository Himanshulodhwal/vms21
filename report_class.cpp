#include "report_class.h"
#include "ui_report_class.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlField>
#include <QFile>
#include <QPrinter>
#include <QPainter>
#include <QBuffer>
#include <QFileDialog>
#include <QTextDocument>
Report_class::Report_class(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Report_class)
{
    ui->setupUi(this);
    QDateTime current_start_date= ui->dateEdit_start_date->dateTime().currentDateTime();
    ui->dateEdit_start_date->setDisplayFormat("yyyy-MM-dd HH:mm");
    ui->dateEdit_start_date->setDateTime(current_start_date);

    QDateTime current_end_date = ui->dateEdit_end_date->dateTime().currentDateTime();
    ui->dateEdit_end_date->setDisplayFormat("yyyy-MM-dd HH:mm");
    ui->dateEdit_end_date->setDateTime(current_end_date);

    for (const sql_helper::server &item : sql_help.serverlist) {
        ui->comboBox_server->addItem(item.server_name); // Assuming you want to set the item's text as the name and item's data as the id
    }
    // Connect the currentIndexChanged signal of the parentComboBox to a slot
    connect(ui->comboBox_server, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Report_class::updateadd_deviceComboBox);

    int cols=8;
    ui->tableWidget_report->setColumnCount(cols);
    QStringList column_names ;
    column_names <<"SrNo"  <<"CamName" <<"Server Name" <<"Date Time"
                 <<"OCR Number" <<"Vehicle Class"
                 <<"Plate Image" <<"View";
    ui->tableWidget_report->setHorizontalHeaderLabels(column_names);
    // QHeaderView *header2 = ui->tableWidget_report->horizontalHeader();
    // Set the width of the header for the specified column
    ui->tableWidget_report->setColumnWidth(0, 80);
    ui->tableWidget_report->setColumnWidth(1, 150);
    ui->tableWidget_report->setColumnWidth(2, 150);
    ui->tableWidget_report->setColumnWidth(3, 220);
    ui->tableWidget_report->setColumnWidth(4, 150);
    ui->tableWidget_report->setColumnWidth(5, 150);
    ui->tableWidget_report->setColumnWidth(6, 220);
    ui->tableWidget_report->setColumnWidth(7, 80);


    // // Set the resize mode for each section to stretch
    // for (int i = 0; i < header2->count(); ++i) {
    //     header2->setSectionResizeMode(i, QHeaderView::Stretch);
    // }

    connect(ui->pushButton_Prev, &QPushButton::clicked, this, &Report_class::showPreviousPage);
    connect(ui->pushButton_Next, &QPushButton::clicked, this, &Report_class::showNextPage);
    // Initialize pagination state
}

Report_class::~Report_class()
{
    delete ui;
}

void Report_class::on_pushButton_search_clicked()
{

    // ui->tableWidget_report->clear();
    ui->tableWidget_report->clearContents();
    // Get the number of rows (excluding the header row)
    int numRows = ui->tableWidget_report->rowCount();

    // Remove each row except for the header row
    for (int i = numRows-1; i >= 0; --i) {
        ui->tableWidget_report->removeRow(i);
    }
    QString start_date=  ui->dateEdit_start_date->dateTime().toString();
    QString date_start = convertTimestamp(start_date);
    QString end_date= ui->dateEdit_end_date->dateTime().toString();
    QString date_end = convertTimestamp(end_date);

    QString servername=ui->comboBox_server->currentText();
    QString add_devicename=ui->comboBox_add_devices->currentText();
    bool db_status = sql_help.ckeck_db_status();
    if(db_status)
    {
        QSqlQuery query;
        query.prepare("SELECT SrNo,camname,plateimgpath,ocrnumber,vehicleclass,datetime FROM anpr4 "
                      "WHERE (datetime BETWEEN :start_date AND :end_date) AND (camname=:add_devicename)");
        query.bindValue(":start_date", date_start);
        query.bindValue(":end_date", date_end);
        query.bindValue(":add_devicename", add_devicename);
        if (!query.exec()) {
            qDebug() << "Failed to execute select query from anpr4 table:" << query.lastError().text();
            return;
        }

    //     ////////
        int row = 0;
        while (query.next()) {
            ui->tableWidget_report->insertRow(row);
            ui->tableWidget_report->setItem(row,0,new QTableWidgetItem(QString::number(query.value(0).toInt())));
            ui->tableWidget_report->setItem(row,1,new QTableWidgetItem(query.value("camname").toString()));
            QString dateString = query.value("datetime").toString();
            QString datetime =sql_help.convertTimestamp(dateString);
            ui->tableWidget_report->setItem(row,2,new QTableWidgetItem(servername));

            ui->tableWidget_report->setItem(row,3,new QTableWidgetItem(datetime));
            ui->tableWidget_report->setItem(row,4,new QTableWidgetItem(query.value("ocrnumber").toString()));
            ui->tableWidget_report->setItem(row,5,new QTableWidgetItem(query.value("vehicleclass").toString()));

            QString filepath= "://views/view_icon.png";
            QPixmap viewpixmap(filepath);

            // Create a clickable label
            clickableLabel = new Clickable_report_label;
            clickableLabel->setPixmap(viewpixmap.scaled(ui->tableWidget_report->columnWidth(5), ui->tableWidget_report->rowHeight(row), Qt::KeepAspectRatio));
            clickableLabel->setAlignment(Qt::AlignCenter);
            QTableWidgetItem* viewitem = new QTableWidgetItem;
            ui->tableWidget_report->setItem(row, 7, viewitem);
            ui->tableWidget_report->setCellWidget(row, 7, clickableLabel);
            connect(clickableLabel, &Clickable_report_label::clicked, this, &Report_class::handleLabelClicked);

            QString imagepath= query.value("plateimgpath").toString();
            if(imagepath.contains("\\")){
                imagepath.replace("\\", "/"); // Replace double backslashes with single backslashes
            }
            QPixmap pixmap(imagepath);

            // Create a QLabel and set the pixmap as its pixmap
            QLabel* label = new QLabel;
            label->setPixmap(pixmap.scaled(ui->tableWidget_report->columnWidth(6), ui->tableWidget_report->rowHeight(row), Qt::KeepAspectRatio));
            label->setAlignment(Qt::AlignCenter);
            QTableWidgetItem* item = new QTableWidgetItem;
            ui->tableWidget_report->setItem(row, 6, item);
            ui->tableWidget_report->setCellWidget(row, 6, label);

            row++;
        }
    }
    sql_help.db_close();
    ui->tableWidget_report->hide();

    updateTableDisplay();
}
QString Report_class:: convertTimestamp(const QString& timestamp) {
    // convert Thu Apr 18 11:37:55 2024 to 2024-03-04 14:24:42
    // Convert the timestamp string to a QDateTime object
    QDateTime dateTime = QDateTime::fromString(timestamp, "ddd MMM d HH:mm:ss yyyy");

    // Convert the QDateTime object to the desired format
    QString formattedDateTime = dateTime.toString("yyyy-MM-d HH:mm:ss");

    return formattedDateTime;
}

void Report_class::on_pushButton_export_clicked()
{
    // Open a file dialog for saving files
    QString filePath;
    if(ui->radioButton_csv->isChecked() || ui->radioButton_pdf->isChecked())
    {
     filePath = QFileDialog::getSaveFileName(nullptr, "Save File", QDir::homePath(), "PDF Files (*.pdf);;CSV Files (*.csv)");
    }
    // Check if the user canceled the dialog
    if (!filePath.isEmpty()) {
        // User selected a file, filePath contains the path to save the file
        qDebug() << "Selected file path:" << filePath;
    } else {
        // User canceled the dialog
        qDebug() << "User canceled the save operation";
    }
    if(ui->radioButton_csv->isChecked()){
        QFile f(filePath);

        if (f.open(QFile::WriteOnly | QFile::Truncate))
        {
            QTextStream data( &f );
            // QStringList strList;

            // Write headers
            for (int col = 0; col < ui->tableWidget_report->columnCount(); ++col) {
                data << "\"" << ui->tableWidget_report->horizontalHeaderItem(col)->text() << "\",";
            }
            data << "\n";

            // Write data
            for (int row = 0; row < ui->tableWidget_report->rowCount(); ++row) {
                for (int col = 0; col < ui->tableWidget_report->columnCount(); ++col) {
                    data << "\"" << ui->tableWidget_report->item(row, col)->text() << "\",";
                }
                data << "\n";
            }
            f.close();
        }
    }


    if(ui->radioButton_pdf->isChecked()){
        qDebug()<<"radioButton_pdf======";
        // // Create a QPrinter object for PDF output
        //    QPrinter printer(QPrinter::PrinterResolution);
        //    printer.setOutputFormat(QPrinter::PdfFormat);
        //    printer.setPaperSize(QPrinter::A4);
        //    printer.setOrientation(QPrinter::Landscape);
        //    printer.setOutputFileName(filePath);

        //    // Create a QTextDocument to hold the content
        //    QTextDocument doc;
        //    // Calculate page dimensions
        //    const int pageWidth = printer.pageRect().width();
        //    const int pageHeight = printer.pageRect().height();

        //    // Calculate font metrics to estimate row height
        //    QFontMetrics fontMetrics(doc.defaultFont());
        //    const int rowHeight = fontMetrics.height();

        //    // Calculate how many rows fit on a page
        //    const int headerRowCount = 1; // Assuming 1 row for header
        //    const int maxRowCountPerPage = (pageHeight - headerRowCount * rowHeight) / rowHeight;

        //    // Set up variables for pagination
        //    int currentPage = 0;
        //    int currentRow = 0;


        //    // HTML content for the table
        //    QString html = "<html><head></head><body>Report Generted<table border='1' cellspacing='1'>";

        //    // Add table headers
        //    html += "<thead><tr>";
        //    for (int i = 0; i < ui->tableWidget_report->columnCount(); ++i) {
        //        if (i != 7) { // Check if the column should be hidden
        //        html += "<th>" + ui->tableWidget_report->horizontalHeaderItem(i)->text() + "</th>";

        //        }
        //    }
        //    html += "</tr></thead>";

        //    // Loop through rows of the table
        //    while (currentRow < ui->tableWidget_report->rowCount()) {
        //        // Start a new page if necessary
        //        if (currentRow % maxRowCountPerPage == 0) {
        //            if (currentPage > 0) {
        //                printer.newPage();
        //            }
        //            ++currentPage;
        //        }
        //    // Add table data
        //    html += "<tbody>";
        //    for (int i = 0; i < ui->tableWidget_report->rowCount(); ++i) {
        //        html += "<tr>";
        //        for (int j = 0; j < ui->tableWidget_report->columnCount(); ++j) {
        //            if (j != 7) { // Check if the column should be hidden
        //            QTableWidgetItem *item = ui->tableWidget_report->item(i, j);
        //            if (item) {
        //                html += "<td>";
        //                // Check if the item has a widget
        //                if (QWidget *widget = ui->tableWidget_report->cellWidget(i, j)) {
        //                    if (QLabel *label = qobject_cast<QLabel*>(widget)) {
        //                        // Retrieve the pixmap from the label
        //                        QPixmap pixmap = label->pixmap()->scaledToWidth(100); // Adjust width as needed
        //                        // Convert pixmap to base64
        //                        QByteArray byteArray;
        //                        QBuffer buffer(&byteArray);
        //                        buffer.open(QIODevice::WriteOnly);
        //                        pixmap.save(&buffer, "PNG");
        //                        QString base64Image = QString::fromLatin1(byteArray.toBase64().data());
        //                        // Embed the image into HTML
        //                        html += "<img src='data:image/png;base64," + base64Image + "'/>";                    }
        //                } else {
        //                    // If no widget found, simply add the text
        //                    html += item->text();
        //                }
        //                html += "</td>";
        //            }
        //        }
        //        }
        //        html += "</tr>";
        //    }
        //    // Move to the next set of rows
        //    currentRow += maxRowCountPerPage;
        //    }
        //    //

        //    html += "</tbody>";

        //    // Close the table and body
        //    html += "</table></body></html>";

        //    // Set HTML content to the QTextDocument
        //    doc.setHtml(html);

        //    // Create a QPainter object for PDF rendering
        //    QPainter painter(&printer);

        //    // Render the QTextDocument onto the PDF
        //    doc.drawContents(&painter);

        //    // End painting
        //    painter.end();


        //////////////////////////////////////



        // Create a QPrinter object for PDF output
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOrientation(QPrinter::Landscape);
        printer.setOutputFileName(filePath);

        // Create a QPainter object for PDF rendering
        QPainter painter(&printer);

        // Calculate page dimensions
        const int pageWidth = printer.pageRect().width();
        const int pageHeight = printer.pageRect().height();
        // Calculate font metrics to estimate row height
        QFontMetrics fontMetrics(QApplication::font());

        // Initialize rowHeight to a minimum value
        int rowHeight=0; // Assuming a minimum row height

        // Calculate how many rows fit on a page
        const int headerRowCount = 1; // Assuming 1 row for header
        int maxRowCountPerPage;// = (pageHeight - headerRowCount * rowHeight) / rowHeight;
        // qDebug()<<"======maxRowCountPerPage====="<<maxRowCountPerPage;
        // Set up variables for pagination
        int currentRow = 0;
        int currentPrintedRows = 0;

        // HTML content for the table
        QString html = "<html><head></head><body>";

        // Add table headers
        html += "Report Generated<table border='1' cellspacing='1'><thead><tr>";
        for (int i = 0; i < ui->tableWidget_report->columnCount(); ++i) {
            if (i != 7) { // Check if the column should be hidden
                html += "<th>" + ui->tableWidget_report->horizontalHeaderItem(i)->text() + "</th>";
            }
        }
        html += "</tr></thead><tbody>";


        while (currentRow < ui->tableWidget_report->rowCount()) {
            // Add table data
            html += "<tr>";

            // Track the maximum image height in the row
            int rowMaxImageHeight = 0;

            for (int j = 0; j < ui->tableWidget_report->columnCount(); ++j) {
                if (j != 7) { // Check if the column should be hidden
                    QTableWidgetItem *item = ui->tableWidget_report->item(currentRow, j);
                    if (item) {
                        html += "<td>";
                        // Check if the item has a widget
                        if (QWidget *widget = ui->tableWidget_report->cellWidget(currentRow, j)) {
                            if (QLabel *label = qobject_cast<QLabel*>(widget)) {
                                // Retrieve the pixmap from the label
                                QPixmap pixmap = label->pixmap()->scaledToWidth(100); // Adjust width as needed
                                int imageHeight = pixmap.height();
                                if (imageHeight > rowMaxImageHeight) {
                                    rowMaxImageHeight = imageHeight;
                                }
                                // Convert pixmap to base64
                                QByteArray byteArray;
                                QBuffer buffer(&byteArray);
                                buffer.open(QIODevice::WriteOnly);
                                pixmap.save(&buffer, "PNG");
                                QString base64Image = QString::fromLatin1(byteArray.toBase64().data());
                                // Embed the image into HTML
                                html += "<img src='data:image/png;base64," + base64Image + "'/>";
                            }
                        } else {
                            // If no widget found, simply add the text
                            html += item->text();
                        }
                        html += "</td>";
                    }
                }
            }
            html += "</tr>";

            // Update the maximum image height for the row
            if (rowMaxImageHeight > 0) {
                // Calculate the row height based on the maximum image height
                rowHeight = rowMaxImageHeight + 2; // Add extra padding
                qDebug()<<"====rowHeight===="<<rowHeight;
                // Check if the current row height exceeds the maximum row height
                if (rowHeight > printer.paperRect().height()) {
                    // Start a new page
                    printer.newPage();
                    // Reset current row height for the new page
                    rowHeight = rowMaxImageHeight + 2; // Add extra padding
                }
            }

            ++currentRow;
            ++currentPrintedRows;
            maxRowCountPerPage = (pageHeight - headerRowCount * rowHeight) / rowHeight;
            qDebug()<<"======maxRowCountPerPage====="<<maxRowCountPerPage;

            // Check if a new page is needed
            if (currentPrintedRows >= maxRowCountPerPage && currentRow < ui->tableWidget_report->rowCount()) {
                // End the current table
                html += "</tbody></table></body></html>";

                // Set HTML content to the QTextDocument
                QTextDocument doc;
                doc.setHtml(html);

                // Render the QTextDocument onto the PDF
                doc.drawContents(&painter);

                // Start a new page
                printer.newPage();

                // Reset printed row count and HTML content for the next page
                currentPrintedRows = 0;
                html = "<html><head></head><body>";

                // Add table headers for the new page
                html += "<table border='1' cellspacing='1'><thead><tr>";
                for (int i = 0; i < ui->tableWidget_report->columnCount(); ++i) {
                    if (i != 7) { // Check if the column should be hidden
                        html += "<th>" + ui->tableWidget_report->horizontalHeaderItem(i)->text() + "</th>";
                    }
                }
                html += "</tr></thead><tbody>";
            }
        }
        // End the last table
        html += "</tbody></table></body></html>";

        // Set HTML content to the QTextDocument
        QTextDocument doc;
        doc.setHtml(html);

        // Render the QTextDocument onto the PDF
        doc.drawContents(&painter);

        // End painting
        painter.end();

    }
}
void Report_class::updateadd_deviceComboBox()
{
    qDebug()<<"====updateadd_deviceComboBox=====";
    // Clear the existing items in the childComboBox
    ui->comboBox_add_devices->clear();

    // Get the selected parent item
    QString selectedParentItem = ui->comboBox_server->currentText();
    int id=sql_help.getIdByServerName(sql_help.serverlist,selectedParentItem);
    QStringList device_name_list=sql_help.get_device_name_from_server_id(sql_help.add_devices_list,id);
    for(int i=0;i<device_name_list.size();i++)
    {
        ui->comboBox_add_devices->addItem(device_name_list[i]);
    }

}
void Report_class::handleLabelClicked()
{
    qDebug() << "Label clicked!";
    // Get the sender of the signal
    clickableLabel = qobject_cast<Clickable_report_label*>(sender());
    if (!clickableLabel) {
        return;
    }
    // Get the row index corresponding to the clicked label
    int rowIndex = ui->tableWidget_report->rowAt(clickableLabel->pos().y());
    // Retrieve data from the table widget based on the row index
    QString rowData;
    QTableWidgetItem* item = ui->tableWidget_report->item(rowIndex, 0);
    rowData =item->text();
    qDebug()<<"=====rowData===="<<rowData;
    bool db_status = sql_help.ckeck_db_status();
    QString camname,plateimagepath,ocrnumber,vehicleclass,datetime,vehicleimagepath;

    if(db_status)
    {
        QSqlQuery query;
        query.prepare("SELECT SrNo,camname,plateimgpath,vehicleImagePath,ocrnumber,vehicleclass,datetime FROM anpr4 "
                      "WHERE SrNo="+rowData+"");
        if (!query.exec()) {
            qDebug() << "Failed to execute select query from anpr4 table:" << query.lastError().text();
            return;
        }
        while (query.next()) {
            camname=query.value("camname").toString();
            plateimagepath=query.value("plateimgpath").toString();
            vehicleimagepath=query.value("vehicleImagePath").toString();
            ocrnumber=query.value("ocrnumber").toString();
            vehicleclass=query.value("vehicleclass").toString();
            QString dateString = query.value("datetime").toString();
            QString converted_datetime =sql_help.convertTimestamp(dateString);

            datetime=converted_datetime;
        }
    }
    sql_help.db_close();

    mainwindow.ShowCard(camname,plateimagepath,vehicleimagepath,ocrnumber,datetime,vehicleclass);

}
void Report_class:: showPreviousPage() {
    if (currentPageIndex > 0) {
        --currentPageIndex;
        updateTableDisplay();
    }
}

void Report_class::showNextPage() {
    int maxPageIndex = ui->tableWidget_report->rowCount() / pageSize;
    if (currentPageIndex < maxPageIndex) {
        ++currentPageIndex;
        updateTableDisplay();
    }
}
void Report_class::updateTableDisplay() {
    qDebug()<<"=====pageSize===="<<pageSize;

    int startIndex = currentPageIndex * pageSize;
    int endIndex = qMin(startIndex + pageSize, ui->tableWidget_report->rowCount());
    qDebug()<<"====startIndex===="<<startIndex<<"===endIndex==="<<endIndex;

    for (int i = 0; i < ui->tableWidget_report->rowCount(); ++i) {
        ui->tableWidget_report->setRowHidden(i, i < startIndex || i >= endIndex);
    }

    ui->tableWidget_report->show();

}
