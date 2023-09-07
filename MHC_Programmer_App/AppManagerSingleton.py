# Controller imports


# Model imports


# View imports


# Common imports


from PyQt6.QtCore import pyqtSlot, QObject
from Views.UploadWindowView import UploadWindowView
from Views.MainWindowView import MainWindowView

class AppManagerSingleton(QObject):
    def __init__(self):

        QObject.__init__(self)


    def start(self):
        # --Controllers----------------------------------------

        # -----------------------------------------------------

        # --Models---------------------------------------------
        
        # -----------------------------------------------------

        # --Views----------------------------------------------
        self.__upload_window_view = UploadWindowView()
        self.__main_window_view = MainWindowView(self.__upload_window_view)

        # -----------------------------------------------------

        # --Signals and Slots----------------------------------
        self.__main_window_view.actionOpen.triggered.connect(self.__upload_window_view.on_open_csv)
        self.__main_window_view.actionSave.triggered.connect(self.__upload_window_view.on_save_csv)

        # -----------------------------------------------------

        self.__main_window_view.show()

        return True


    def stop(self):
        return True