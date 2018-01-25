Shiboken 2 - Minimal example
============================

Currently, only tested on Windows.

Steps
-----

- Install `Anaconda <https://www.anaconda.com/download/>`_ and `CMake <https://cmake.org/download/>`_.
- Add *conda-forge* channel for *pyside2* package:

::

   conda config --add channels conda-forge
    
- Create a virtual environment: 

::

   conda create -n pyside2 python=3.6 pyside2

- Activate the virtual environment:

::

   activate pyside2
   
- Test if *shiboken2* was successfully installed (by visualizing its *help*):

::

   shiboken2 --help
   
- Clone this project into a folder of your choice (e.g., *C:\shiboken2_minimal*):

::

   git clone https://github.com/giumas/shiboken2_minimal.git C:\shiboken2_minimal
   
- Create a build folder (e.g., *C:\shiboken2_minimal_build*) and execute *cmake* referencing the folder where you cloned the GitHub project:

::

   cmake -G "Visual Studio 14 2015 Win64" C:\shiboken2_minimal

- Open *pyfoo.sln* and build in *Release* mode.  

- Test the binding by running:

::

   python example.py

   
Known issues
------------

- If you get the following errors during *pyfoo* compilation, the current workaround is to manually add in *mainwindow_wrapper.h* the missing declaration:

::

    3> c:\shiboken2_minimal_build\wrap\pyfoo\mainwindow_wrapper.cpp(1378): error C2509: 'metaObject': member function not declared in 'MainWindowWrapper'
    3> c:\shiboken2_minimal_build\wrap\pyfoo\mainwindow_wrapper.h(10): note: see declaration of 'MainWindowWrapper'
    

    