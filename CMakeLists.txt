cmake_minimum_required(VERSION 3.9)

project(rateOfReturn LANGUAGES CXX C VERSION 1.0.0)

# Set C++ Standard
################################################################################
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# IMPOSE WARNINGS ON DEBUG
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic-errors")

# IMPOSE CXX FLAGS FOR WINDOWS
if (WIN32)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")
endif (WIN32)

# Add dependencies
################################################################################



## Threads
find_package(Threads REQUIRED)
list(APPEND ${rateOfReturn_LINKED_LIBRARIES} PRIVATE Threads::Threads)


# Insert Sources
################################################################################
add_subdirectory(src)

list(APPEND rateOfReturn_SOURCES ${rateOfReturn_sources})
list(APPEND rateOfReturn_HEADERS ${rateOfReturn_headers})
list(APPEND rateOfReturn_INCLUDE ${rateOfReturn_includes})

# Create executable
################################################################################
add_executable(${PROJECT_NAME}
      main.cpp src/Utils.cpp

      ${rateOfReturn_SOURCES}
      ${rateOfReturn_HEADERS})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data.txt
      DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(${PROJECT_NAME} ${rateOfReturn_LINKED_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${rateOfReturn_INCLUDE})
target_compile_options(${PROJECT_NAME} PUBLIC -fPIC)
