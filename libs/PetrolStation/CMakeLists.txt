SET(HEADERS_LIST Client.h
                 Depot.h
                 Employee.h
                 PetrolStation.h
                 Till.h
                 TillList.h
)

SET(SOURCES_LIST Client.cpp
                 Depot.cpp
                 Employee.cpp
                 PetrolStation.cpp
                 Till.cpp
                 TillList.cpp
)

add_library(petrol_station_lib STATIC ${SOURCES_LIST})
include_directories(petrol_station {CMAKE_CURRENT_SOURCE_DIR})

add_executable(petrol_station main.cpp)
target_link_libraries(petrol_station petrol_station_lib)