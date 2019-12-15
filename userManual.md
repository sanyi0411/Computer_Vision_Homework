# User manual for this computer vision application

**Note**: This is only the source code for the application, which needs to be compiled. If you don't know how to do it, ask someone to help you out. If you can do it here is the [Developer Manual](developerManual.md) to guide you.

### How to run the program
- After compilation you should have a *SpeedSignRecognition.exe* file under the following folders:
- **SpeedSignRecognitionSolution/x64/Debug** or **SpeedSignRecognitionSolution/x64/Release** depending on which version you choose to compile
- You will have to run this *.exe* file from command line, for which there are two ways
- Also find the folder, which contains the image(s) which you want to run the program on

### 1. If you have TotalCommander
    * 1.1 Navigate to the aforementioned folder in TotalCommander
    * 1.2 Type *cmd* and press enter
    * 1.3 This will open up a command line window in the folder where you were
    * 1.4 Type *SpeedSignRecognition [path to folder of the image(s)]*
    * 1.5 For example:
```
C:\Users\JohnDoe\Computer_Vision_Homework\SpeedSignRecognitionSolution\x64\Debug> SpeedSignRecognition D:/Pictures/OpenCV_samples
```
    * 1.6 The program will run and you will see a number telling you what number was on the sign

### 2. If you don't have TotalCommander
    * 2.1 Press the windows key (On Mac open up a terminal and jump to 2.4)
    * 2.2 Type *cmd* and press enter
    * 2.3 This will open up a command line window
    * 2.4 Now you will have to navigate to the folder containing the *.exe* file. You can do this by typing *cd [path to the folder]*. If it is in a different drive than the one it is currently showing you, first you will have to change drive:
    * 2.5 For example if you are on your C drive but want to change to the D drive: Type the letter of the desired drive followed by a colon
```
C:\> d:
```
    * 2.6 Now follow instructions from 1.4