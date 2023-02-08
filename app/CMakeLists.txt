set(EXE_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

add_executable(${EXECUTABLE_NAME} ${EXE_SOURCES})

target_link_libraries(${EXECUTABLE_NAME} PUBLIC 
    ${LIBRARY_NAME})

target_set_warnings(
    TARGET
    ${EXECUTABLE_NAME}
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS})

add_linter_tool_to_target(${EXECUTABLE_NAME})

if(${ENABLE_LTO})
    target_enable_lto(${EXECUTABLE_NAME} optimized)
endif()
