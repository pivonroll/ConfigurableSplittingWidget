#ifndef CONFIGURABLEWIDGET_H
#define CONFIGURABLEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QMenu;
class QSplitter;
QT_END_NAMESPACE

class ConfigurableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ConfigurableWidget(QWidget *parent = 0);

private slots:
    void splitHorizontal();
    void splitVertical();
    void childRemoveRequested();
    void showContextMenuEvent(const QPoint &point);

private:
    QMenu *m_contextMenu;
    QLayout *m_layout;
    QSplitter *m_splitter;
};

#endif // CONFIGURABLEWIDGET_H
