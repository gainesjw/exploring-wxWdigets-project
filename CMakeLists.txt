cmake_minimum_required(VERSION 3.15.0)
project(testApplication001 VERSION 0.1.0 LANGUAGES C CXX)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Option to build shared libraries
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Find wxWidgets components
find_package(wxWidgets COMPONENTS core base REQUIRED)

# set sources
set(SOURCES
    src/main.cpp
)

# Include wxWidgets headers
include(${wxWidgets_USE_FILE})

# Add your executable and link against wxWidgets
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)