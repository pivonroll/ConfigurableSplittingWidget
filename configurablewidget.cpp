#include "configurablewidget.h"

#include <QMenu>
#include <QVBoxLayout>
#include <QSplitter>
#include <QSplitterHandle>

#include "common.h"

ConfigurableWidget::ConfigurableWidget(QWidget *parent) :
    QWidget(parent),
    m_splitter(0)
{  
    setContextMenuPolicy(Qt::CustomContextMenu);
    m_contextMenu = new QMenu(this);

    m_contextMenu->addAction(tr("Split Horizontaly"), this, SLOT(splitHorizontal()));
    m_contextMenu->addAction(tr("Split Verticaly"), this, SLOT(splitVertical()));

    ConfigurableWidget *parentConf = qobject_cast<ConfigurableWidget *>(parent);

    if (parentConf)
        m_contextMenu->addAction(tr("Remove"), parentConf, SLOT(childRemoveRequested()));

    connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showContextMenuEvent(const QPoint&)));
}

void ConfigurableWidget::showContextMenuEvent(const QPoint &point)
{
    m_contextMenu->exec(mapToGlobal(point));
}

void ConfigurableWidget::splitHorizontal()
{
    m_layout = new QVBoxLayout;
    m_splitter = new QSplitter(Qt::Horizontal);

    ConfigurableWidget *widget1 = new ConfigurableWidget(this);
    ConfigurableWidget *widget2 = new ConfigurableWidget(this);

    m_splitter->addWidget(widget1);
    m_splitter->addWidget(widget2);

    m_layout->addWidget(m_splitter);
    setLayout(m_layout);
}

void ConfigurableWidget::splitVertical()
{
    m_layout = new QVBoxLayout;
    m_splitter = new QSplitter(Qt::Vertical);

    ConfigurableWidget *widget1 = new ConfigurableWidget(this);
    ConfigurableWidget *widget2 = new ConfigurableWidget(this);

    m_splitter->addWidget(widget1);
    m_splitter->addWidget(widget2);

    m_layout->addWidget(m_splitter);
    setLayout(m_layout);
}

void ConfigurableWidget::childRemoveRequested()
{
    m_layout->removeWidget(m_splitter);
    m_splitter->deleteLater();
    m_splitter = 0;

    m_layout->deleteLater();
    m_layout = 0;
}
