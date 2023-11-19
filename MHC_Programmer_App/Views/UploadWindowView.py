import serial
import time
from serial.tools.list_ports import comports
from enum import Enum

from PyQt6 import QtWidgets
from PyQt6.QtCore import pyqtSlot
from Views.UI.UploadWindowViewGenerated import Ui_uploadWidget
from Controllers.PresetIOController import PresetIOController

class MessageType(Enum):
    PC = 0xC0
    CC = 0xB0
    NoteOn = 0x90
    NoteOff = 0x80


class UploadWindowView(QtWidgets.QWidget, Ui_uploadWidget):

    """Class to serve as a container for all of the Views making up the UploadWindow"""

    def __init__(self, parent = None):
        """
        Constructor
        """
        super(UploadWindowView, self).__init__(parent)
        self.setupUi(self)

        for port in comports():
            self.serialPortComboBox.addItem(str(port))

        for j in range(self.tableWidget.rowCount()):
            comboBox = QtWidgets.QComboBox()
            comboBox.addItems(["PC", "CC", "NoteOn", "NoteOff"])
            self.tableWidget.setCellWidget(j, 0, comboBox)

            spinBox1 = QtWidgets.QSpinBox()
            spinBox1.setRange(0, 127)
            self.tableWidget.setCellWidget(j, 1, spinBox1)

            spinBox2 = QtWidgets.QSpinBox()
            spinBox2.setRange(0, 127)
            self.tableWidget.setCellWidget(j, 2, spinBox2)

            spinBox3 = QtWidgets.QSpinBox()
            spinBox3.setRange(0, 15)
            self.tableWidget.setCellWidget(j, 3, spinBox3)

        self.__preset_io_controller = PresetIOController()

        self.uploadButton.clicked.connect(self.on_write_to_device)
        self.refreshButton.clicked.connect(self.on_refresh_ports)
        self.tableWidget.horizontalHeader().setSectionResizeMode(QtWidgets.QHeaderView.ResizeMode.Stretch)
        self.tableWidget.verticalHeader().setSectionResizeMode(QtWidgets.QHeaderView.ResizeMode.Stretch)

    
    def on_write_to_device(self):
        # dlg = QtWidgets.QFileDialog()
        # dlg.setNameFilter("Spreadsheet (*.csv)")

        # if dlg.exec():
        #     filenames = dlg.selectedFiles()

        #     print(filenames[0])

        try:
            ser = serial.Serial(self.serialPortComboBox.currentText().split(" ")[0], 115200, timeout=1)  # open serial port
            values = bytearray([])
            values.append(int(self.bankSpinBox.value() - 1))

            # for j in range(self.tableWidget.rowCount()):
            #     values.append(MessageType[self.tableWidget.cellWidget(j, 0).currentText()].value)
            #     values.append(int(self.tableWidget.cellWidget(j, 1).value()))
            #     values.append(int(self.tableWidget.cellWidget(j, 2).value()))
            #     values.append(int(self.tableWidget.cellWidget(j, 3).value()))

            # TODO: Revert back to above code once fix can be added in FW
            # Issue is that logic is flipped for binary midi components
            # Button On
            values.append(MessageType[self.tableWidget.cellWidget(1, 0).currentText()].value)
            values.append(int(self.tableWidget.cellWidget(1, 1).value()))
            values.append(int(self.tableWidget.cellWidget(1, 2).value()))
            values.append(int(self.tableWidget.cellWidget(1, 3).value()))

            # Button Off
            values.append(MessageType[self.tableWidget.cellWidget(0, 0).currentText()].value)
            values.append(int(self.tableWidget.cellWidget(0, 1).value()))
            values.append(int(self.tableWidget.cellWidget(0, 2).value()))
            values.append(int(self.tableWidget.cellWidget(0, 3).value()))

            # Five Way Up On
            values.append(MessageType[self.tableWidget.cellWidget(3, 0).currentText()].value)
            values.append(int(self.tableWidget.cellWidget(3, 1).value()))
            values.append(int(self.tableWidget.cellWidget(3, 2).value()))
            values.append(int(self.tableWidget.cellWidget(3, 3).value()))

            # Five Way Up Off
            values.append(MessageType[self.tableWidget.cellWidget(2, 0).currentText()].value)
            values.append(int(self.tableWidget.cellWidget(2, 1).value()))
            values.append(int(self.tableWidget.cellWidget(2, 2).value()))
            values.append(int(self.tableWidget.cellWidget(2, 3).value()))

            # Five Way Down On
            values.append(MessageType[self.tableWidget.cellWidget(5, 0).currentText()].value)
            values.append(int(self.tableWidget.cellWidget(5, 1).value()))
            values.append(int(self.tableWidget.cellWidget(5, 2).value()))
            values.append(int(self.tableWidget.cellWidget(5, 3).value()))

            # Five Way Down Off
            values.append(MessageType[self.tableWidget.cellWidget(4, 0).currentText()].value)
            values.append(int(self.tableWidget.cellWidget(4, 1).value()))
            values.append(int(self.tableWidget.cellWidget(4, 2).value()))
            values.append(int(self.tableWidget.cellWidget(4, 3).value()))

            # Five Way Left On
            values.append(MessageType[self.tableWidget.cellWidget(7, 0).currentText()].value)
            values.append(int(self.tableWidget.cellWidget(7, 1).value()))
            values.append(int(self.tableWidget.cellWidget(7, 2).value()))
            values.append(int(self.tableWidget.cellWidget(7, 3).value()))

            # Five Way Left Off
            values.append(MessageType[self.tableWidget.cellWidget(6, 0).currentText()].value)
            values.append(int(self.tableWidget.cellWidget(6, 1).value()))
            values.append(int(self.tableWidget.cellWidget(6, 2).value()))
            values.append(int(self.tableWidget.cellWidget(6, 3).value()))

            # Five Way Right On
            values.append(MessageType[self.tableWidget.cellWidget(9, 0).currentText()].value)
            values.append(int(self.tableWidget.cellWidget(9, 1).value()))
            values.append(int(self.tableWidget.cellWidget(9, 2).value()))
            values.append(int(self.tableWidget.cellWidget(9, 3).value()))

            # Five Way Right Off
            values.append(MessageType[self.tableWidget.cellWidget(8, 0).currentText()].value)
            values.append(int(self.tableWidget.cellWidget(8, 1).value()))
            values.append(int(self.tableWidget.cellWidget(8, 2).value()))
            values.append(int(self.tableWidget.cellWidget(8, 3).value()))

            # Five Way Click On
            values.append(MessageType[self.tableWidget.cellWidget(11, 0).currentText()].value)
            values.append(int(self.tableWidget.cellWidget(11, 1).value()))
            values.append(int(self.tableWidget.cellWidget(11, 2).value()))
            values.append(int(self.tableWidget.cellWidget(11, 3).value()))

            # Five Way Click Off
            values.append(MessageType[self.tableWidget.cellWidget(10, 0).currentText()].value)
            values.append(int(self.tableWidget.cellWidget(10, 1).value()))
            values.append(int(self.tableWidget.cellWidget(10, 2).value()))
            values.append(int(self.tableWidget.cellWidget(10, 3).value()))

            # Slider
            values.append(MessageType[self.tableWidget.cellWidget(12, 0).currentText()].value)
            values.append(int(self.tableWidget.cellWidget(12, 1).value()))
            values.append(int(self.tableWidget.cellWidget(12, 2).value()))
            values.append(int(self.tableWidget.cellWidget(12, 3).value()))

            #Joystick X
            values.append(MessageType[self.tableWidget.cellWidget(13, 0).currentText()].value)
            values.append(int(self.tableWidget.cellWidget(13, 1).value()))
            values.append(int(self.tableWidget.cellWidget(13, 2).value()))
            values.append(int(self.tableWidget.cellWidget(13, 3).value()))

            # Joystick Y
            values.append(MessageType[self.tableWidget.cellWidget(14, 0).currentText()].value)
            values.append(int(self.tableWidget.cellWidget(14, 1).value()))
            values.append(int(self.tableWidget.cellWidget(14, 2).value()))
            values.append(int(self.tableWidget.cellWidget(14, 3).value()))

            values.append(0xFF)
            ser.write(values)
            # print("Writing values: " + str(values))


            cc=str(ser.readline())
            print(cc)

            ser.close()             # close port
        except serial.SerialException:
            print("Error Writing to Serial Port")


    def on_refresh_ports(self):
        self.serialPortComboBox.clear()
        for port in comports():
            self.serialPortComboBox.addItem(str(port))

    def on_open_csv(self):
        dlg = QtWidgets.QFileDialog()
        dlg.setNameFilter("Spreadsheet (*.csv)")

        if dlg.exec():
            filenames = dlg.selectedFiles()

            print(filenames[0])
            preset_list = self.__preset_io_controller.open_preset_file(filenames[0])

            if(self.__preset_io_controller.is_preset_valid(preset_list)):

                self.populate_ui_from_dicts(preset_list)

            # TODO: Add Error handling here

    def on_save_csv(self):

        fileName = QtWidgets.QFileDialog.getSaveFileName(self, 
            "Save File", "", "CSV Files(*.csv)")
        if fileName and fileName[0] != "":
            preset_list = self.populate_dicts_from_ui()
            self.__preset_io_controller.save_preset_file(preset_list, fileName[0])

    def populate_ui_from_dicts(self, preset_list):
        for dict in preset_list:
            self.populate_row_from_dict(dict)

    def populate_row_from_dict(self, dict):
        row_num = self.__preset_io_controller.row_labels.index(dict[''])
        self.tableWidget.cellWidget(row_num, self.__preset_io_controller.column_labels.index('Type') - 1).setCurrentText(dict['Type'])
        self.tableWidget.cellWidget(row_num, self.__preset_io_controller.column_labels.index('Byte 1') - 1).setValue(int(dict['Byte 1']))
        self.tableWidget.cellWidget(row_num, self.__preset_io_controller.column_labels.index('Byte 2') - 1).setValue(int(dict['Byte 2']))
        self.tableWidget.cellWidget(row_num, self.__preset_io_controller.column_labels.index('Channel') - 1).setValue(int(dict['Channel']))

    def populate_dicts_from_ui(self):
        preset_list = list()
        for row_num in range(0, len(self.__preset_io_controller.row_labels)):
            preset_list.append(self.populate_dict_from_row(row_num))

        return preset_list

    def populate_dict_from_row(self, row_num):
        preset_dict = dict()
        preset_dict[''] = self.tableWidget.verticalHeaderItem(row_num).text()
        preset_dict['Type'] = self.tableWidget.cellWidget(row_num, 0).currentText()
        preset_dict['Byte 1'] = str(self.tableWidget.cellWidget(row_num, 1).value())
        preset_dict['Byte 2'] = str(self.tableWidget.cellWidget(row_num, 2).value())
        preset_dict['Channel'] = str(self.tableWidget.cellWidget(row_num, 3).value())
        return preset_dict