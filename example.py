import sys
from PySide2 import QtWidgets
from pyfoo import MainWindow

app = QtWidgets.QApplication(sys.argv)

window = MainWindow()
window.show()
window.testFunction1()

sys.exit(app.exec_())
