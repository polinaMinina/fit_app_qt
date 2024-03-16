// validatingcomboboxdelegate.h
#ifndef VALIDATINGCOMBOBOXDELEGATE_H
#define VALIDATINGCOMBOBOXDELEGATE_H

#include <QItemDelegate>
#include <QStringList>

class ValidatingComboBoxDelegate : public QItemDelegate {
    Q_OBJECT

public:
    ValidatingComboBoxDelegate(const QStringList &items, QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

private:
    QStringList m_items;
};

#endif // VALIDATINGCOMBOBOXDELEGATE_H
