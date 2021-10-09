# EXCEL AND PYTHON INTEGRATION


### XLRD
xlrd is a library for reading data and formatting information from Excel files, whether they are .xls or .xlsx files.


Installation Instructions
If you want to experiment with xlrd, the easiest way to install it is to do the following in a virtualenv:
```
pip install xlrd
```

If your package uses setuptools and you decide to use xlrd, then you should add it as a requirement by adding an install_requires parameter in your call to setup as follows:
```
setup(
    # other stuff here
    install_requires=['xlrd'],
    )
```
