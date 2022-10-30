# BackdropQT

A "simple" animated background setter for linux. 
Written in C++ and built on the QT framework. (For the time being)

## *NOTE:* This project is in early development, a lot of breaking changes might occur. 

## Dependencies

### Qt5: *NOTE: QT will be probably swapped out for something else*  
* Qt5 Widgets 
* Qt5 WebEngine


## Building 

* Clone the repository and navigate to that folder
* Execute
```bash
mkdir build 
cd build
cmake .. 
make -j4
```
* Copy the BackdropQT executable somewhere on your $PATH
* To run: 
```
    BackdropQT <URL> [SCREEN_NUM] 
```
* If you want to run local html files instead, you can use the file:// protocol. Just make sure you use an absolute path

