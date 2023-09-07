"""Module to contain the MainWindowView"""

from PyQt6 import QtWidgets
from PyQt6.QtCore import Qt
from Views.UI.EmptyWindowGenerated import Ui_MainWindow

class MainWindowView(QtWidgets.QMainWindow, Ui_MainWindow):
    """Class to serve as a container for all of the Views making up the MainWindow"""

    def __init__(self, upload_window_view, parent=None):
        """
        Constructor
        """
        super(MainWindowView, self).__init__(parent)
        self.setupUi(self)

        # Create an instance of each of the necessary views
        self.__upload_window_view = upload_window_view

        # Add the views to the MainWindow
        self.gridLayout.addWidget(self.__upload_window_view)