set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.hpp *.cpp)

# set(TEST_SOURCES ${TEST_SOURCES}
#    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
#    ${CMAKE_CURRENT_SOURCE_DIR}/ft_equal.cpp
#    ${CMAKE_CURRENT_SOURCE_DIR}/ft_is_integral.cpp
#    ${CMAKE_CURRENT_SOURCE_DIR}/ft_lexicographical_compare.cpp
#    ${CMAKE_CURRENT_SOURCE_DIR}/ft_make_pair.cpp
#    ${CMAKE_CURRENT_SOURCE_DIR}/ft_pair.cpp
#    )
add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC gtest)