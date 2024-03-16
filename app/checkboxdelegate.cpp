#include "checkboxdelegate.h"
#include <QCheckBox>
#include <QApplication>
#include <QMouseEvent>

QWidget *CheckBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &,
                                        const QModelIndex &) const {
    QCheckBox *editor = new QCheckBox(parent);
    // Здесь можно настроить чекбокс, если нужно
    return editor;
}

void CheckBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    QCheckBox *checkBox = qobject_cast<QCheckBox *>(editor);
    if (checkBox) {
        bool value = index.data(Qt::EditRole).toBool();
        checkBox->setChecked(value);
    }
}

void CheckBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const {
    QCheckBox *checkBox = qobject_cast<QCheckBox *>(editor);
    if (checkBox) {
        model->setData(index, checkBox->isChecked(), Qt::EditRole);
    }
}

void CheckBoxDelegate::updateEditorGeometry(QWidget *editor,
                                            const QStyleOptionViewItem &option, const QModelIndex &) const {
    editor->setGeometry(option.rect);
}
