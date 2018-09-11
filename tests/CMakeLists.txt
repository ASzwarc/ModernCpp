include_directories(.)

FILE(GLOB HEADERS_LIST *.h)
FILE(GLOB SRC_LIST *.cpp)

add_executable(all-tests
               ${SRC_LIST}
               ${HEADERS_LIST}
              )

target_link_libraries(all-tests gmock-gtest gmock-main)
