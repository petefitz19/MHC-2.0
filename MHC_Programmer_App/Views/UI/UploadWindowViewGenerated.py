# Form implementation generated from reading ui file '/Users/pjfitz7e/Documents/Github/MHC-2.0/MHC_Programmer_App/Views/UI/UploadWindowViewGenerated.ui'
#
# Created by: PyQt6 UI code generator 6.4.2
#
# WARNING: Any manual changes made to this file will be lost when pyuic6 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt6 import QtCore, QtGui, QtWidgets


class Ui_uploadWidget(object):
    def setupUi(self, uploadWidget):
        uploadWidget.setObjectName("uploadWidget")
        uploadWidget.resize(572, 430)
        self.gridLayout_2 = QtWidgets.QGridLayout(uploadWidget)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        self.uploadButton = QtWidgets.QPushButton(parent=uploadWidget)
        self.uploadButton.setObjectName("uploadButton")
        self.gridLayout.addWidget(self.uploadButton, 1, 1, 1, 1)
        self.subGridLayout = QtWidgets.QGridLayout()
        self.subGridLayout.setObjectName("subGridLayout")
        spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Policy.Expanding, QtWidgets.QSizePolicy.Policy.Minimum)
        self.subGridLayout.addItem(spacerItem, 2, 1, 1, 1)
        self.serialPortComboBox = QtWidgets.QComboBox(parent=uploadWidget)
        self.serialPortComboBox.setObjectName("serialPortComboBox")
        self.subGridLayout.addWidget(self.serialPortComboBox, 0, 1, 1, 3)
        self.serialPortLabel = QtWidgets.QLabel(parent=uploadWidget)
        self.serialPortLabel.setObjectName("serialPortLabel")
        self.subGridLayout.addWidget(self.serialPortLabel, 0, 0, 1, 1)
        self.bankLabel = QtWidgets.QLabel(parent=uploadWidget)
        self.bankLabel.setObjectName("bankLabel")
        self.subGridLayout.addWidget(self.bankLabel, 2, 2, 1, 1)
        self.refreshButton = QtWidgets.QPushButton(parent=uploadWidget)
        self.refreshButton.setObjectName("refreshButton")
        self.subGridLayout.addWidget(self.refreshButton, 0, 4, 1, 1)
        self.tableWidget = QtWidgets.QTableWidget(parent=uploadWidget)
        self.tableWidget.setShowGrid(True)
        self.tableWidget.setCornerButtonEnabled(True)
        self.tableWidget.setObjectName("tableWidget")
        self.tableWidget.setColumnCount(4)
        self.tableWidget.setRowCount(15)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setVerticalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setVerticalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setVerticalHeaderItem(2, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setVerticalHeaderItem(3, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setVerticalHeaderItem(4, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setVerticalHeaderItem(5, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setVerticalHeaderItem(6, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setVerticalHeaderItem(7, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setVerticalHeaderItem(8, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setVerticalHeaderItem(9, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setVerticalHeaderItem(10, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setVerticalHeaderItem(11, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setVerticalHeaderItem(12, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setVerticalHeaderItem(13, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setVerticalHeaderItem(14, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setHorizontalHeaderItem(2, item)
        item = QtWidgets.QTableWidgetItem()
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        item.setFont(font)
        self.tableWidget.setHorizontalHeaderItem(3, item)
        self.tableWidget.horizontalHeader().setVisible(True)
        self.tableWidget.horizontalHeader().setCascadingSectionResizes(True)
        self.tableWidget.horizontalHeader().setStretchLastSection(False)
        self.tableWidget.verticalHeader().setVisible(True)
        self.tableWidget.verticalHeader().setStretchLastSection(False)
        self.subGridLayout.addWidget(self.tableWidget, 1, 0, 1, 5)
        self.bankSpinBox = QtWidgets.QSpinBox(parent=uploadWidget)
        self.bankSpinBox.setMinimum(1)
        self.bankSpinBox.setMaximum(10)
        self.bankSpinBox.setObjectName("bankSpinBox")
        self.subGridLayout.addWidget(self.bankSpinBox, 2, 3, 1, 2)
        self.gridLayout.addLayout(self.subGridLayout, 0, 1, 1, 1)
        self.gridLayout_2.addLayout(self.gridLayout, 0, 0, 1, 1)

        self.retranslateUi(uploadWidget)
        QtCore.QMetaObject.connectSlotsByName(uploadWidget)

    def retranslateUi(self, uploadWidget):
        _translate = QtCore.QCoreApplication.translate
        uploadWidget.setWindowTitle(_translate("uploadWidget", "Form"))
        self.uploadButton.setText(_translate("uploadWidget", "Write to Device"))
        self.serialPortLabel.setText(_translate("uploadWidget", "Serial Port:"))
        self.bankLabel.setText(_translate("uploadWidget", "Bank:"))
        self.refreshButton.setText(_translate("uploadWidget", "Refresh"))
        item = self.tableWidget.verticalHeaderItem(0)
        item.setText(_translate("uploadWidget", "Button On"))
        item = self.tableWidget.verticalHeaderItem(1)
        item.setText(_translate("uploadWidget", "Button Off"))
        item = self.tableWidget.verticalHeaderItem(2)
        item.setText(_translate("uploadWidget", "Five Way Up On"))
        item = self.tableWidget.verticalHeaderItem(3)
        item.setText(_translate("uploadWidget", "Five Way Up Off"))
        item = self.tableWidget.verticalHeaderItem(4)
        item.setText(_translate("uploadWidget", "Five Way Down On"))
        item = self.tableWidget.verticalHeaderItem(5)
        item.setText(_translate("uploadWidget", "Five Way Down Off"))
        item = self.tableWidget.verticalHeaderItem(6)
        item.setText(_translate("uploadWidget", "Five Way Left On"))
        item = self.tableWidget.verticalHeaderItem(7)
        item.setText(_translate("uploadWidget", "Five Way Left Off"))
        item = self.tableWidget.verticalHeaderItem(8)
        item.setText(_translate("uploadWidget", "Five Way Right On"))
        item = self.tableWidget.verticalHeaderItem(9)
        item.setText(_translate("uploadWidget", "Five Way Right Off"))
        item = self.tableWidget.verticalHeaderItem(10)
        item.setText(_translate("uploadWidget", "Five Way Click On"))
        item = self.tableWidget.verticalHeaderItem(11)
        item.setText(_translate("uploadWidget", "Five Way Click Off"))
        item = self.tableWidget.verticalHeaderItem(12)
        item.setText(_translate("uploadWidget", "Slider"))
        item = self.tableWidget.verticalHeaderItem(13)
        item.setText(_translate("uploadWidget", "Joystick X Direction"))
        item = self.tableWidget.verticalHeaderItem(14)
        item.setText(_translate("uploadWidget", "Joystick Y Direction"))
        item = self.tableWidget.horizontalHeaderItem(0)
        item.setText(_translate("uploadWidget", "Type"))
        item = self.tableWidget.horizontalHeaderItem(1)
        item.setText(_translate("uploadWidget", "Byte 1"))
        item = self.tableWidget.horizontalHeaderItem(2)
        item.setText(_translate("uploadWidget", "Byte 2"))
        item = self.tableWidget.horizontalHeaderItem(3)
        item.setText(_translate("uploadWidget", "Channel"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    uploadWidget = QtWidgets.QWidget()
    ui = Ui_uploadWidget()
    ui.setupUi(uploadWidget)
    uploadWidget.show()
    sys.exit(app.exec())