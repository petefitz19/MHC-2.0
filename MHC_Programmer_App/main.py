import sys
from AppManagerSingleton import AppManagerSingleton
from PyQt6.QtWidgets import QApplication, QWidget, QPushButton
from PyQt6.QtCore import Qt


def main():
    app = QApplication(sys.argv)

    app_manager_singleton = AppManagerSingleton()
    app_manager_singleton.start()
    sys.exit(app.exec())

if __name__ == "__main__":
    main()