# Simple Qt GUI Application

<b>Task: A (simple) GUI interface that enables users to</b>

a. to select one or more options (Voltage, Calcium, CalciumER) from drop-down list

b. to input a number in 'how many BRANCHTYPE' (acceptable value in the range 1-7)

c. a 'Generate' button: once user presses the button 'Generate', it creates an output file: CptParams.par

    Options (label) : [ dropdown list]

    How many BRANCHTYPE (label): [textbox input] (with code to check valid input)

    Generate (button)

d. Once 'Generate' button is clicked, the GUI now enables users to add one or more items with 3 inputs and 1 button.

    ChannelName (label): [textbox]

    Input (label): [dropdown list with available values are those selected in (a)]

    Output (label): [dropdown list with available values are those selected in (a)]

    ChannelType (label): [dropdown list with values from 1-7]

    Add (button)
    
<b>*INSTRUCTION TO COMPILE AND RUN*</b>

<b>Step 1:</b> You need to install Qt5 or above (Qt4 may NOT work correctly). To install, please go to: http://info.qt.io/download-qt-for-application-development

<b>Step 2:</b> Download this sourcecode manually or using git to clone it to your local repository.

    git clone https://github.com/lenhattu/simple-qt-gui.git
    
<b>Step 3:</b> Make sure that you set the PATH environment variable for Qt. This step depends on which OS you are using and where your Qt is installed.

    MacOS/Linux: http://doc.qt.io/qt-4.8/install-mac.html#step-3-set-the-environment-variables
    Windows: http://doc.qt.io/qt-4.8/install-win.html#step-3-set-the-environment-variables

<b>Step 4:</b> Use 'qmake' to create Makefile for your machine and run 'make' to compile the sourcecode.

Syntax: (use Terminal for MacOS/Linux or Powershell for Windows)

    cd path/to/simple-qt-gui/
    
    qmake simple-qt-gui.pro
    
    make
    
<b>For Windows user, you may want to use QtCreator (installed along with Qt in Step 1) to open simple-qt-gui.pro and compile if you are not familiar with Powershell.</b>
    
<b>Step 5:</b> Run the executable file.

    MacOS (Terminal): open -a simple-qt-gui.app

    Linux (Terminal): ./simple-qt-gui

    Windows: simple-qt-gui.exe
