cmake_minimum_required(VERSION 3.10)
project(BankAccountManagementSystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(BankSystem main.cpp)

# Optional: Add include directories
# target_include_directories(BankSystem PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Optional: Link libraries
# target_link_libraries(BankSystem someLibrary)
