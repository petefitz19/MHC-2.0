"""Module to contain the PresetIOController Class"""


import csv

class PresetIOController():

    """Class to handle the Preset File Input/Output functionality"""

    column_labels = ['', 'Type', 'Byte 1', 'Byte 2', 'Channel']
    row_labels = ['Button On', 'Button Off', 'Five Way Up On', 'Five Way Up Off', 
                  'Five Way Down On', 'Five Way Down Off', 'Five Way Left On', 
                  'Five Way Left Off', 'Five Way Right On', 'Five Way Right Off', 
                  'Five Way Click On', 'Five Way Click Off', 'Slider', 
                  'Joystick X Direction', 'Joystick Y Direction']

    def __init__(self):

        """Constructor"""

        pass

    def save_preset_file(self, preset_list, file_path):
        """
        Method to save the passed in preset file as a csv to the passed in file path
        """

        with open(file_path, 'w') as f:

            writer = csv.DictWriter(f, fieldnames=self.column_labels)
            writer.writeheader()
            writer.writerows(preset_list)

            return True
        
        return False

    def open_preset_file(self, file_path):
        """
        Method to parse the csv file at the passed in file path to a list of dicts
        """
        preset_list = list()
        with open(file_path, 'r') as csvfile:
            preset_reader = csv.DictReader(csvfile)
            preset_list = list(preset_reader)
        csvfile.close()

        return preset_list

    def is_preset_valid(self, preset_list):
        """
        Method to verify if the passed in preset list is compatible with the MHC
        """

        # TODO: Check for limits
        if(len(preset_list) != len(self.row_labels)):
            print("Size incorrect")
            return False
        
        if not all(name in self.column_labels for name in preset_list[0]):
            print("Columns incorrect")
            return False
        
        idx = 0
        for dct in preset_list:
            if dct[''] != self.row_labels[idx]:
                print("Row incorrect")
                return False
            if not all(name in self.column_labels for name in preset_list[idx]):
                print("Columns incorrect")
                return False
            idx += 1

        return True
