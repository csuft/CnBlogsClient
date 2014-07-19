#include "customitemmodel.h"

CustomItemModel::CustomItemModel(int r, int c, QObject* parent)
	: QStandardItemModel(r, c, parent), m_columnsAlignCenter(), m_columnsAlignRight()
{
	// NOTHING to do
}


CustomItemModel::CustomItemModel(QVector<int>& colsAlignCenter, QVector<int>& colsAlignRight, int row, int col, QObject* parent)
	: QStandardItemModel(row, col, parent), m_columnsAlignCenter(colsAlignCenter), m_columnsAlignRight(colsAlignRight)
{
	// Nothing to do
}
/*
 * Since the text alignment defaults to Qt::AlignLeft, we only need to reimplement the other
 * two alignments.
 */
QVariant CustomItemModel::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DecorationRole)
	{
		QPixmap icon;
		if (1 == QStandardItemModel::index(index.row(), 0).data(Qt::EditRole).toInt())
		{
			icon.load(":/syspic/unread");
		}
		else
		{
			icon.load(":/syspic/read");
		}
		return icon;
	}

	if (role == Qt::TextAlignmentRole)
	{
		if (m_columnsAlignCenter.contains(index.column()))
		{
			return Qt::AlignCenter;
		}
		if (m_columnsAlignRight.contains(index.column()))
		{
			return Qt::AlignRight;
		}
	}
	return QStandardItemModel::data(index, role);
}