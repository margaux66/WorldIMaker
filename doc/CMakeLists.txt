find_package(Doxygen)

if (DOXYGEN_FOUND)

    message("Version of Doxygen : " ${DOXYGEN_VERSION})

    if(DOXYGEN_FOUND)
        configure_file (${WorldIMaker_SOURCE_DIR}/doc/Doxyfile-html.cmake ${WorldIMaker_BINARY_DIR}/doc/Doxyfile-html)
        add_custom_target (html ${DOXYGEN_EXECUTABLE} ${WorldIMaker_BINARY_DIR}/doc/Doxyfile-html)
    endif (DOXYGEN_FOUND)

else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)