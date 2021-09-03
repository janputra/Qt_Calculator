from PyQt5 import QtWidgets
from ui_calculator import Ui_Calculator

class CalculatorWindow(QtWidgets.QMainWindow,Ui_Calculator):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.show()
    
        #connecy buttons
        self.pushButton_0.clicked.connect(self.digit_pressed)
        self.pushButton_1.clicked.connect(self.digit_pressed)
        self.pushButton_2.clicked.connect(self.digit_pressed)
        self.pushButton_3.clicked.connect(self.digit_pressed)
        self.pushButton_4.clicked.connect(self.digit_pressed)
        self.pushButton_5.clicked.connect(self.digit_pressed)
        self.pushButton_6.clicked.connect(self.digit_pressed)
        self.pushButton_7.clicked.connect(self.digit_pressed)
        self.pushButton_8.clicked.connect(self.digit_pressed)
        self.pushButton_9.clicked.connect(self.digit_pressed)

    def digit_pressed(self):
        button= self.sender()
        newLabel = format(float(self.label.text() + button.text()),'.15g')
        self.label.setText(newLabel)

        

