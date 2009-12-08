set(NAME list_test)

add_executable(${NAME} ${NAME}.cpp)
target_link_libraries(${NAME} ${Boost_LIBRARIES})
