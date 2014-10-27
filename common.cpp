#include "common.h"

#include <QWidget>
#include <QFile>

void loadStyleSheetForWidget(QWidget &widget, const QString &styleAlias)
{
    QFile file(styleAlias);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        widget.setStyleSheet(file.readAll());
        file.close();
    }
}


