cmake_minimum_required(VERSION 3.16)

# Project setup
project(Project VERSION 0.1 LANGUAGES CXX)

# Enable Qt's automatic handling of UI, MOC, and RCC files
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt and Widgets modules
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Add all sources, headers, and UI files
set(PROJECT_SOURCES
    main.cpp
    matrix.cpp
    matrix.h
    matrix.ui
    newuser.h newuser.cpp newuser.ui
    tabs.h tabs.cpp tabs.ui
    taskmanager.h taskmanager.cpp taskmanager.ui
    worktask.h worktask.cpp worktask.ui
    personaltask.h personaltask.cpp personaltask.ui
    notification.h
    notification.cpp
    task.h
    task.cpp
    dietmanagement.h dietmanagement.cpp dietmanagement.ui
)

# Ensure compatibility with Qt 6 and higher
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Project
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        dietmanagement.h dietmanagement.cpp dietmanagement.ui
        breakfastplan.h breakfastplan.cpp breakfastplan.ui
        lunchplan.h lunchplan.cpp lunchplan.ui
        dinnerplan.h dinnerplan.cpp dinnerplan.ui
        dietplan.h
        dietplan.cpp
        mentalhealth.h mentalhealth.cpp mentalhealth.ui
        fitnessroutine.h fitnessroutine.cpp fitnessroutine.ui
        vitalstats.h vitalstats.cpp vitalstats.ui
    )
else()
    # For older Qt versions or Android platforms
    if(ANDROID)
        add_library(Project SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Project
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Link the Qt Widgets library to the project
target_link_libraries(Project PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# macOS/iOS-specific settings
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Project)
endif()

set_target_properties(Project PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Installation rules
include(GNUInstallDirs)
install(TARGETS Project
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalize for Qt 6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Project)
endif()
