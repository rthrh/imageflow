project(imageflow CXX)
cmake_minimum_required(VERSION 3.1) # CMake 3.1 is recommended for Qt5
set(VERSION_STRING 0.0.1)

#set module path
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules )

#include imageflow src dir
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# set additional options
option(COLOR_OUTPUT "Use color ouput in terminal" ON)

# Qt 5 settings
set(CMAKE_AUTOMOC ON) # For meta object compiler
set(CMAKE_AUTORCC ON) # Resource files
set(CMAKE_AUTOUIC ON) # UI files
set(CMAKE_CXX_STANDARD 14) # C++14

# *.cpp source files
set(imageflow_SOURCES
#    src/components/cuda/cudacomp.cpp
#    src/components/factory/cudacomponentfactory.cpp
#    src/components/factory/featurecomponentfactory.cpp
#    src/components/factory/imageproccomponentfactory.cpp
#    src/components/factory/inputcomponentfactory.cpp
#    src/components/factory/machinelearncomponentfactory.cpp
#    src/components/factory/outputcomponentfactory.cpp
#    src/components/factory/plotcomponentfactory.cpp
#    src/components/factory/usercomponentfactory.cpp
#    src/components/feature/featurecomp.cpp
    src/components/functor.cpp
    src/components/imageproc/imageproccomp.cpp
    src/components/imageproc/medianblur.cpp
    src/components/input/imageinputcomp.cpp
    src/components/input/inputcomp.cpp
#    src/components/machinelearn/machinelearncomp.cpp
    src/components/output/imageshowcomp.cpp
    src/components/output/outputcomp.cpp
#    src/components/plot/plotcomp.cpp
#    src/components/user/usercomp.cpp
    src/gui/graph/edge.cpp
    src/gui/graph/graphwidget.cpp
    src/gui/graph/node.cpp
    src/gui/mainwindow/mainwindow.cpp
    src/imagepipeline/imagepipeline.cpp
    src/main.cpp
)

# *.h moc files
set(imageflow_HEADERS_MOC

    )

# *.h plain c++ header files
set(imageflow_HEADERS
    src/definitions.hpp
#    src/components/cuda/cudacomp.h
#    src/components/factory/cudacomponentfactory.h
#    src/components/factory/featurecomponentfactory.h
#    src/components/factory/icomponentfactory.h
#    src/components/factory/imageproccomponentfactory.h
#    src/components/factory/inputcomponentfactory.h
#    src/components/factory/machinelearncomponentfactory.h
#    src/components/factory/outputcomponentfactory.h
#    src/components/factory/plotcomponentfactory.h
#    src/components/factory/usercomponentfactory.h
#    src/components/feature/featurecomp.h
#    src/components/icomponent.h
#    src/components/imageproc/imageproccomp.h
    src/components/input/inputcomp.h
#    src/components/machinelearn/machinelearncomp.h
    src/components/output/outputcomp.h
#    src/components/plot/plotcomp.h
#    src/components/user/usercomp.h
    src/gui/graph/edge.h
    src/gui/graph/graphwidget.h
    src/gui/graph/node.h
    src/gui/mainwindow/mainwindow.h
    src/imagepipeline/imagepipeline.h
)

# *.ui files
set(imageflow_FORMS
    src/gui/mainwindow/mainwindow.ui
)

# *.qrc files
set(imageflow_RESOURCES

)

if(COLOR_OUTPUT)
    add_definitions(-DCOLOR_OUTPUT=1)
endif(COLOR_OUTPUT)

# add version string
add_definitions(-DVERSION="${VERSION_STRING}")

# find QT5 libs
find_package(Qt5Widgets REQUIRED)
set(REQUIRED_LIBS ${REQUIRED_LIBS}
    Qt5::Widgets
)

# find OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(REQUIRED_LIBS ${REQUIRED_LIBS}
    ${OpenCV_LIBS}
)

# include headers produced by uic
include_directories( ${CMAKE_BINARY_DIR} )

add_executable( imageflow WIN32 MACOSX_BUNDLE ${imageflow_SOURCES} ${imageflow_HEADERS} ${imageflow_SOURCES_MOC} ${imageflow_SOURCES_RC} ${imageflow_FORMS_HEADERS}  )

target_link_libraries( imageflow ${REQUIRED_LIBS})

#enable warnings
if(CMAKE_COMPILER_IS_GNUCC)
    set_property( TARGET imageflow APPEND_STRING PROPERTY COMPILE_FLAGS -Wall )
endif(CMAKE_COMPILER_IS_GNUCC)
if(MSVC)
    set_property( TARGET imageflow APPEND_STRING PROPERTY COMPILE_FLAGS /W3 )
endif( MSVC )

#set version of binary
set_target_properties(imageflow PROPERTIES VERSION ${VERSION_STRING})
