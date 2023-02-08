function(add_linter_tool_to_target target)
    if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        message(
            "==> Cppcheck, IWYU and Clang-Tidy Targets do not work with MSVC")
        return()
    endif()
    get_target_property(TARGET_SOURCES ${target} SOURCES)
    list(
        FILTER
        TARGET_SOURCES
        INCLUDE
        REGEX
        ".*.(cc|h|cpp|hpp)")

    if(ENABLE_CPPCHECK)
        find_program(CPPCHECK cppcheck)
        if(CPPCHECK)
            message("==> Added Cppcheck for Target: ${target}")
            add_custom_target(
                ${target}_cppcheck
                COMMAND
                    ${CPPCHECK} ${TARGET_SOURCES} --enable=all
                    --suppress=unusedFunction --suppress=unmatchedSuppression
                    --suppress=missingIncludeSystem --suppress=toomanyconfigs
                    --project=${CMAKE_BINARY_DIR}/compile_commands.json
                    -i${CMAKE_BINARY_DIR}/ -i${CMAKE_SOURCE_DIR}/external/
                USES_TERMINAL)
        else()
            message("==> CPPCHECK NOT FOUND")
        endif()
    endif()

    find_package(Python3 COMPONENTS Interpreter)
    if(NOT ${Python_FOUND})
        message("==> Python3 needed for IWYU and Clang-Tidy")
        return()
    endif()

    if(ENABLE_INCLUDE_WHAT_YOU_USE)
        if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
            find_program(INCLUDE_WHAT_YOU_USE include-what-you-use)
            if(INCLUDE_WHAT_YOU_USE)
                add_custom_target(
                    ${target}_iwyu
                    COMMAND
                        ${Python3_EXECUTABLE}
                        ${CMAKE_SOURCE_DIR}/tools/iwyu_tool.py -p
                        ${CMAKE_BINARY_DIR} ${TARGET_SOURCES}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
            else()
                message("==> INCLUDE_WHAT_YOU_USE NOT FOUND")
            endif()
        else()
            message("==> INCLUDE_WHAT_YOU_USE NEEDS CLANG COMPILER")
        endif()
    endif()

    if(ENABLE_CLANG_TIDY)
        find_program(CLANGTIDY clang-tidy)
        if(CLANGTIDY)
            message("==> Added Clang Tidy for Target: ${target}")
            add_custom_target(
                ${target}_clangtidy
                COMMAND
                    ${Python3_EXECUTABLE}
                    ${CMAKE_SOURCE_DIR}/tools/run-clang-tidy.py
                    ${TARGET_SOURCES}
                    -config-file=${CMAKE_SOURCE_DIR}/.clang-tidy
                    -extra-arg-before=-std=${CMAKE_CXX_STANDARD}
                    -header-filter="\(src|app\)\/*.\(h|hpp\)"
                    -p=${CMAKE_BINARY_DIR}
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                USES_TERMINAL)
        else()
            message("==> CLANGTIDY NOT FOUND")
        endif()
    endif()
endfunction()