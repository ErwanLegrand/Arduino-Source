del .qmake.stash
del *.log
del Makefile*
del object_script.*
del users*
del SerialPrograms.pro.user*
del Settings.json
del *.png
del *.jpg
del CMakeLists.txt.user

copy CMakeLists.txt CMakeLists.txt.tmp
del *.txt
move CMakeLists.txt.tmp CMakeLists.txt

rd /s /q "debug\"
rd /s /q "release\"
rd /s /q "SerialPrograms\"
rd /s /q "ErrorDumps\"

rd /s /q "..\build-SerialPrograms-Desktop_Qt_5_12_10_MSVC2017_64bit-Release"
rd /s /q "..\build-SerialPrograms-Desktop_Qt_5_12_10_MSVC2017_64bit-RelWithDebInfo"
