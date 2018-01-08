# Reference: http://qt-project.org/doc/qt-5.0/qtdoc/cmake-manual.html

cmake_minimum_required(VERSION 3.0)

# Set autos
set(CMAKE_AUTOMOC ON) # For meta object compiler
set(CMAKE_AUTORCC ON) # Resource files
set(CMAKE_AUTOUIC ON) # UI files

# Add folder where are supportive functions
#set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_FLAGS "-std=c++11")
SET(OpenCV_DIR "/usr/local/share/OpenCV")
project(imageflow VERSION 1.0)

set(SOURCES
    src/definitions.hpp

    src/imagepipeline/imagepipeline.cpp

    src/components/factory/inputcomponentfactory.cpp
    src/components/factory/outputcomponentfactory.cpp
    src/components/factory/imageproccomponentfactory.cpp
    src/components/factory/plotcomponentfactory.cpp
    src/components/factory/machinelearncomponentfactory.cpp
    src/components/factory/cudacomponentfactory.cpp
    src/components/factory/usercomponentfactory.cpp
    src/components/factory/featurecomponentfactory.cpp
    #src/gui/graph/node.cpp
    #src/gui/graph/edge.cpp
    #src/gui/graph/graphwidget.cpp

    src/components/cuda/cudacomp.cpp
    src/components/feature/featurecomp.cpp
    src/components/input/inputcomp.cpp
    src/components/output/outputcomp.cpp
    src/components/machinelearn/machinelearncomp.cpp
    src/components/plot/plotcomp.cpp
    src/components/user/usercomp.cpp
    src/components/imageproc/imageproccomp.cpp


    src/main.cpp
    src/gui/mainwindow/mainwindow.cpp
    src/gui/mainwindow/mainwindow.ui
)

set(HEADERS
    src/components/factory/icomponentfactory.h
    src/components/icomponent.h

    #src/components/imageproc/imageproc.h
    #src/gui/graph/node.h
    #src/gui/graph/edge.h
    #src/gui/graph/graphwidget.h
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
