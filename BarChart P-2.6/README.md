#Console Bar Chart
This program will read a file, whose path will be provided by you, and it will process it to see how many characters are present in the file and how many times a character is used. Then it will prompt you to enter a sequence of characters. You will input the characters which you want to compare.  Then it will generate a simple bar to show the frequency of the characters. The bar will be created relatively, according to the frequency of the characters that you typed.

#Installation
I have only provided the source code of the program, so you have to download these files and manually import them in the IDE or project of your own choice.

###List of Files :
* BarChart.cpp   (Implementation of the BarChart class)
* BarChart.h     (Declarations of the BarChart class)
* main.cpp       (Driver)
* file.txt       (Sample file for testing)
* CMakeLists.txt (CMake Project file)

#Features
* This program will create Bars chart relatively i.e. according to the currently selected characters or the number of frequency of these characters. e.g Suppose I have file in which the letters 'A', 'B' and 'a' are present in the frequency 10, 5, and 50, respectively. Now, when I compare the two characters 'A' and 'B', there chart will be like :  
`  A : =========================================  10`  
`  B : =====================                      5`  
But when I compare the characters 'A' and 'a', its chart will be like :  
`  A : ============                               10`  
`  a : =========================================  50`  
Now you can clearly see that the bar responds to the characters we are comparing, it is not static.
* You can provide the path to the file using two methods :
    - Using setPath() :  
    If you use this method, it will **prompt** you to enter the path to the file during **runtime**. You just have to provide it the path and it will automatically format it appropriately.
    - Using setPath ("path\\\\to\\\\the\\\\file.txt")  
    If you use this method, you will have to provide the path as an argument to the function.  
    **Remember to put double '\\\\' between the paths. e.g  
    setPath (D:\\\\Workspace\\\\Clion\\\\file.txt)**
    
#Usage Instructions
When you provide the path of the file using setPath(string) ,remember to put double '\\\\' between the paths. e.g setPath (D:\\\\Workspace\\\\Clion\\\\file.txt).

#Author
**Aadam**
