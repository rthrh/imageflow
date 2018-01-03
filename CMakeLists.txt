# Reference: http://qt-project.org/doc/qt-5.0/qtdoc/cmake-manual.html

cmake_minimum_required(VERSION 3.0)

# Set autos
set(CMAKE_AUTOMOC ON) # For meta object compiler
set(CMAKE_AUTORCC ON) # Resource files
set(CMAKE_AUTOUIC ON) # UI files

# Add folder where are supportive functions
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


project(imageflow VERSION 1.0)

set(SOURCES
    src/definitions.hpp
    src/main.cpp
    src/gui/mainwindow.cpp
    src/gui/mainwindow.ui
    src/imagepipeline.cpp
    src/component/opencvcomponent.cpp
    src/component/inputcomponentfactory.cpp


)

set(HEADERS
    src/component/icomponentfactory.h
    src/component/component.h
    )


#set(RESOURCE_FILES example.qrc)

find_package(Qt5Widgets REQUIRED)
find_package(OpenCV REQUIRED)

# source_group("UI Files" FILES ${UI_FILES})

##to be added
#add_subdirectory(src)


#to be cleaned
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

qt5_use_modules(${PROJECT_NAME} Widgets)
