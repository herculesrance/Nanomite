/*
 * 	This file is part of Nanomite.
 *
 *    Nanomite is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    Nanomite is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with Nanomite.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef QTDLGCALLSTACK_H
#define QTDLGCALLSTACK_H

#include <Windows.h>

#include <QDockWidget>
#include <QString>

#include "ui_qtDLGCallstack.h"

#include "clsCallstackWorker.h"

/**
* @file qtDLGCallstack.h
* @brief Displaying the callstack widget
*/
class qtDLGCallstack : public QDockWidget, public Ui_qtDLGCallstack
{
	Q_OBJECT

public:
	/**
	* @brief Responsible for initializing and showing the GUI of the callstack widget
	* @param parent Takes the a QWidget pointer of the calling QObject
	*
	* @return no
	*/
	qtDLGCallstack(QWidget *parent = 0);
	/**
	* @brief Does not need to do something at the current stage
	*
	* @return no
	*/
	~qtDLGCallstack();

	/**
	* brief Does get the call when the debugger breaks and enums the callstack
	*/
	void ShowCallStack();

public slots:
	/**
	* @brief A Qt slot which is called when the user wants to display the source code
	* @param pItem A pointer to the selected QTableWidgetItem to extract the data
	*
	* @return no
	*/
	void OnDisplaySource(QTableWidgetItem *pItem);
	/**
	* @brief A Qt slot which is called when the user wants to display the context menu
	* @param QPoint A QPoint indicating the position where the user clicked
	*
	* @return no
	*/
	void OnContextMenu(QPoint);
	/**
	* @brief A Qt slot which is called when the user selected an item from the context menu
	* @param pAction A pointer to the QAction which was selected by the user
	*
	* @return no
	*/
	void MenuCallback(QAction* pAction);

	/**
	* @brief Get called from "ShowCallStack" and prints a line each time
	* @param callstackDisplayData The new data which will be displayed
	*
	* @return no 
	*/
	void OnCallstack(QList<callstackDisplay> callstackDisplayData);

signals:
	/**
	* @brief A Qt signal which is send when the user selected an offset to show in disassembler
	* @param selectedOffset The selected offset
	*
	* @return no
	*/
	void OnDisplayDisassembly(quint64 selectedOffset);

private:
	clsCallstackWorker *p_ctWorker; /* pointer to the worker thread */

	int m_selectedRow; /* contains the selected row when the users opens a context menu*/
};

#endif // QTDLGCALLSTACK_H
