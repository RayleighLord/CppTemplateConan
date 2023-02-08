set(LIBRARY_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/math_lib.cpp")
set(LIBRARY_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/math_lib.h")

set(LIBRARY_INCLUDES 
    "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_library(${LIBRARY_NAME} STATIC 
    ${LIBRARY_SOURCES} 
    ${LIBRARY_HEADERS})
target_include_directories(${LIBRARY_NAME} PUBLIC 
    ${LIBRARY_INCLUDES})
target_link_libraries(${LIBRARY_NAME} PUBLIC 
    fmt::fmt
    OpenBLAS::OpenBLAS)

target_set_warnings(
    TARGET
    ${LIBRARY_NAME}
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS})

add_linter_tool_to_target(${LIBRARY_NAME})

if(${ENABLE_LTO})
    target_enable_lto(${LIBRARY_NAME} optimized)
endif()
