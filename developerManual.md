# Developer Manual

## 1. Environment
- To compile this code you will need [Visual Studio](https://visualstudio.microsoft.com/downloads/) and OpenCV.
- On how to install OpenCV check out my [How to install OpenCV](https://github.com/sanyi0411/Tutorials/tree/master/How%20to%20install%20OpenCV) generic tutorial

## 2. Compilation
- If you are reading this page I assume you have some knowledge in coding so I won't describe everything to the deepest details
- Clone the repo using *git clone [url]*

![](images/d1.png)

- Open the *SpeedSignRecognitionSolution.sln* file with Visual Studio
- Press *Ctrl + Shift + B* to build the solution
- This will generate an *.exe* file
- You will need to supply argument from the command line (these will be described later)
- If you don't want to always run this exe from command line, you can supply arguments from Visual Studio, just like if you were from command line. Check out [this](https://dailydotnettips.com/how-to-pass-command-line-arguments-using-visual-studio/) site

## 3. How it works
- We are using the open-source computer vision library, called OpenCV
- The program has 3 main parts, which you can see in the *main.cpp*

### 3.1 Read the commands (and what commands you can give)
- In *user mode* the program needs only one argument: the path to the images
- This needs to be a folder. If you want to read only one image, put it in a separate folder
- You can switch to *developer mode* with the `-dev` flag
- In this case you can tell the program what number should it see on the image(s) with the `-limit` flag
- For example: if you put a 100 images in a folder, and in all of them there is a `30` speed limit sign, type `-limit=30` after the `-dev` flag and at the end you will get a percentage telling you how accurate the program is
- For debugging purposes you can use the `-show` flag. This will print out all the intermediate pictures that are made while the program is running.

### 3.2 Detect circles
- The *DetectCircles* class receives one image and tries to detect any RED circles on the image
- Usually it finds more than one, because the pictures are not perfect, so it will return several cropped images, containing only what is inside the circle
- If you run the program with the `-show` flag, you will see these cropped image

### 3.3 Read text
- The *ReadText* class receives these cropped images and tries to read anything that's written in them, using the Tesseract library
- After collecting these texts, it compares against the text you provided with the `-limit` flag and calculates a percentage of how accurate this run was
