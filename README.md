# PCSimulatorScript
A tool for converting .pc save files to .json format and back.
Allows you to view and edit save data from the PC Simulator game on Android.

# 📦 Build Instructions
To build the program, first clone the repository:
```
git clone https://github.com/minerpe1234/PCSimulatorScript.git
cd PCSimulatorScript
```
Create a build directory:
```
mkdir build && cd build
```
Then compile the project using CMake:
```
cmake .. && cmake --build .
```
# ⚙️ How to Use
The program has two modes:

1) Convert from .pc to .json

2) Convert from .json to .pc

You can find your .pc save files on Android at:
/sdcard/Android/data/com.Yiming.pc/files/saves/

# ⚠️ Important Before Exporting to .pc
Before converting your .json file back to .pc,
make sure to remove all line breaks (\n) that were added during formatting.
Leaving them in the file may cause the game to reject or crash on the save.

