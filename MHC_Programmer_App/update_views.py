import os
current_path = os.path.dirname(os.path.abspath(__file__))
print(current_path)

ui_path = os.path.join(current_path, "Views", "UI")
print(ui_path)

dir_list = os.listdir(ui_path)
print(dir_list)

for file in dir_list:
    if ".ui" in file:
        print(file)
        name = file.split(".")[0]
        print(name)
        command = "pyuic6 -x {} -o {}".format(
            os.path.join(ui_path, file), os.path.join(ui_path, name + ".py")
        )

        os.system(command)