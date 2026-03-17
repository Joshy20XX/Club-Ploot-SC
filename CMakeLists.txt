cmake_minimum_required(VERSION 3.16)
project(clubploot LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

#Project files
set(SOURCE_FILES 
    src/cp_main.cpp 
    src/ploot.cpp
    src/mainmenu.ui
    resources/img_resource.qrc)

qt_add_executable(clubploot ${SOURCE_FILES})

target_link_libraries(clubploot PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
)   