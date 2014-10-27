#ifndef CONFIGURABLEWIDGET_H
#define CONFIGURABLEWIDGET_H

#include <QWidget>
#include <QPalette>

QT_BEGIN_NAMESPACE
class QMenu;
class QSplitter;
QT_END_NAMESPACE

class ConfigurableWidget : public QWidget
{
    Q_OBJECT
public:
    enum Mode {
        Normal,
        Edit
    };

    explicit ConfigurableWidget(QWidget *parent = 0);
    void setMode(Mode mode);
    void paintEvent(QPaintEvent *);

private slots:
    void splitHorizontal();
    void splitVertical();
    void childRemoveRequested();
    void showContextMenuEvent(const QPoint &point);

private:
    void updateWidgetMode();

    QMenu *m_contextMenu;
    QLayout *m_layout;
    QSplitter *m_splitter;
    Mode m_mode;
    QPalette m_normalPalette;
};

#endif // CONFIGURABLEWIDGET_H
