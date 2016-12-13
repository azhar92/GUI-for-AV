cmake_minimum_required(VERSION 2.8.3)
project(rqt_test1)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rqt_gui
  rqt_gui_cpp
  std_msgs
)

###################################
## catkin specific configuration ##
###################################

catkin_package(
  INCLUDE_DIRS include ${rqt_test1_INCLUDE_DIRECTORIES}
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp rqt_gui rqt_gui_cpp std_msgs
#  DEPENDS system_lib
)

####################
## Lists of Qt files
####################

set (rqt_test1_SRCS
  src/rqt_test1/main.cpp
  src/rqt_test1/mainwindow.cpp

)

set(rqt_test1_HDRS
  include/rqt_test1/mainwindow.h

)

set(rqt_test1_UIS
  src/rqt_test1/mainwindow.ui
)

set(rqt_test1_INCLUDE_DIRECTORIES
  include
  ${CMAKE_CURRENT_BINARY_DIR}
)

##############
## Qt wrapping
##############


if("${qt_gui_cpp_USE_QT_MAJOR_VERSION} " STREQUAL "5 ")
  find_package(Qt5Widgets REQUIRED)
  qt5_wrap_cpp(rqt_test1_MOCS ${rqt_test1_HDRS})
  qt5_wrap_ui(rqt_test1_UIS_H ${rqt_test1_UIS})
  set(qt_LIBRARIES Qt5::Widgets)
else()
  find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
  include(${QT_USE_FILE})
  qt4_wrap_cpp(rqt_test1_MOCS ${rqt_test1_HDRS})
  qt4_wrap_ui(rqt_test1_UIS_H ${rqt_test1_UIS})
  set(qt_LIBRARIES ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
endif()

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${CMAKE_CURRENT_BINARY_DIR}/..
  ${catkin_INCLUDE_DIRS}
  ${rqt_test1_INCLUDE_DIRECTORIES}
)

## The library that defines the Qt stuff
add_library(mainwindow SHARED src/rqt_test1/mainwindow.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(mainwindow
  ${catkin_LIBRARIES}
  ${qt_LIBRARIES}
)

## Declare a cpp library
add_library(${PROJECT_NAME}
    ${rqt_test1_SRCS}
    ${rqt_test1_MOCS}
    ${rqt_test1_UIS_H}
    )

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}
  mainwindow
  ${catkin_LIBRARIES}
  ${qt_LIBRARIES}
)

#############
## Install ##
#############

install(FILES plugin.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(PROGRAMS scripts/${PROJECT_NAME}/gauge_script.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)
