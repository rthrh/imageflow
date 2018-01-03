set(SOURCE_FILES
    main.cc
    mainwindow.cc
    mainwindow.ui
)

add_executable(${PROJECT_NAME} ${OS_BUNDLE} # Expands to WIN32 or MACOS_BUNDLE depending on OS
    ${SOURCE_FILES} ${META_FILES_TO_INCLUDE} ${RESOURCE_FILES}
)

#qt5_use_modules(${PROJECT_NAME} Widgets)
