#include "configurablewidget.h"

#include <QMenu>
#include <QVBoxLayout>
#include <QSplitter>
#include <QSplitterHandle>
#include <QStyleOption>
#include <QPainter>

#include "common.h"

ConfigurableWidget::ConfigurableWidget(QWidget *parent) :
    QWidget(parent),
    m_splitter(0),
    m_mode(Edit)
{
    setObjectName("ConfigurableWidget");

    m_normalPalette = palette();
    updateWidgetMode();

    setContextMenuPolicy(Qt::CustomContextMenu);
    m_contextMenu = new QMenu(this);

    m_contextMenu->addAction(tr("Split Horizontaly"), this, SLOT(splitHorizontal()));
    m_contextMenu->addAction(tr("Split Verticaly"), this, SLOT(splitVertical()));

    ConfigurableWidget *parentConf = qobject_cast<ConfigurableWidget *>(parent);

    if (parentConf)
        m_contextMenu->addAction(tr("Remove"), parentConf, SLOT(childRemoveRequested()));

    connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showContextMenuEvent(const QPoint&)));
}

void ConfigurableWidget::setMode(ConfigurableWidget::Mode mode)
{
    m_mode = mode;
    updateWidgetMode();
}

void ConfigurableWidget::showContextMenuEvent(const QPoint &point)
{
    m_contextMenu->exec(mapToGlobal(point));
}

void ConfigurableWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void ConfigurableWidget::updateWidgetMode()
{
    switch (m_mode) {
    case Normal:
    {
        setPalette(m_normalPalette);
        update();
    }
        break;
    case Edit:
    {
        loadStyleSheetForWidget(*this, ":/stylesheets/config_widget_stylesheet.qss");
    }
    default:
        break;
    }
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
