// validatingcomboboxdelegate.cpp
#include "validatingcomboboxdelegate.h"
#include <QComboBox>
#include <QMessageBox>

ValidatingComboBoxDelegate::ValidatingComboBoxDelegate(const QStringList &items, QObject *parent)
    : QItemDelegate(parent), m_items(items) {
}

QWidget *ValidatingComboBoxDelegate::createEditor(QWidget *parent,
                                                  const QStyleOptionViewItem &,
                                                  const QModelIndex &) const {
    QComboBox *editor = new QComboBox(parent);
    editor->addItems(m_items);
    return editor;
}

void ValidatingComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                              const QModelIndex &index) const {
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    QString value = comboBox->currentText();
    if (!m_items.contains(value)) {
        QMessageBox::warning(nullptr, "Неверное значение", "Введенное значение не найдено в списке.");
        return;
    }
    model->setData(index, value, Qt::EditRole);
}
