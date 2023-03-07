cmake_minimum_required(VERSION 3.24)
project(lvalue_rvalue_move_semantic)

set(CMAKE_CXX_STANDARD 23)
add_custom_target(cpplint
        COMMAND cpplint --recursive --extensions=cpp,h --filter=-build/include_order,-build/header_guard,-build/c++11,-readability/alt_tokens,-readability/braces,-readability/casting,-readability/check,-readability/fn_size,-readability/multiline_comment,-readability/nolint,-readability/todo,-runtime/arrays,-runtime/indentation_namespace,-runtime/int,-runtime/member_string_references,-runtime/printf,-runtime/references,-runtime/string,-runtime/threadsafe_fn,-whitespace/blank_line,-whitespace/braces,-whitespace/comma,-whitespace/comments,-whitespace/empty_conditional_body,-whitespace/empty_loop_body,-whitespace/ending_newline,-whitespace/forcolon,-whitespace/indent,-whitespace/line_length,-whitespace/newline,-whitespace/operators,-whitespace/parens,-whitespace/tab,-whitespace/todo ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_target(cppcheck
        COMMAND cppcheck --enable=all --suppress=missingIncludeSystem -j 4 ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(lvalue_rvalue_move_semantic main.cpp)
