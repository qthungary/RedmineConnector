#include "IssueDetailWidget.h"
#include "ui_IssueDetailWidget.h"

IssueDetailWidget::IssueDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IssueDetailWidget)
{
    ui->setupUi(this);
    ui->date->setText(QString());
}

IssueDetailWidget::~IssueDetailWidget()
{
    delete ui;
}

void IssueDetailWidget::setAuthor(QString author)
{
    ui->author->setText(author);
}

void IssueDetailWidget::setNotes(QString notes, QList<QString> details)
{
    QString d = QString::fromUtf8("<ul>");
    foreach( QString detail, details) {
        d.append(QString::fromUtf8("<li>") + detail + QString::fromUtf8("</li>"));
    }
    d.append(QString::fromUtf8("</ul>"));

    ui->notes->setText(d + notes.replace(QString::fromUtf8("\n"), QString::fromUtf8("<br />")));
}

void IssueDetailWidget::setDateTime(QDateTime dateTime)
{
    ui->date->setText(dateTime.toString(Qt::SystemLocaleShortDate));
}

void IssueDetailWidget::setIsTopElement(bool top)
{
    QMargins margins = ui->verticalLayout->contentsMargins();
    margins.setLeft((top) ? 0 : 40);
    ui->verticalLayout->setContentsMargins(margins);
    ui->author->setVisible(!top);
    ui->date->setVisible(!top);
}
