set(NAME foreach_test)

add_executable(${NAME} ${NAME})
target_link_libraries(${NAME} ${Boost_LIBRARIES})
