cmake_minimum_required(VERSION 3.26.0)
project(${CMAKE_PROJECT_NAME} CXX C)

set(SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/Application.cpp
    ${CMAKE_SOURCE_DIR}/src/Renderer.cpp
    ${CMAKE_SOURCE_DIR}/src/Camera.cpp
    ${CMAKE_SOURCE_DIR}/src/Ray.cpp
    ${CMAKE_SOURCE_DIR}/src/Scene.cpp
    ${CMAKE_SOURCE_DIR}/src/Interval.cpp
    ${CMAKE_SOURCE_DIR}/src/Random.cpp
    ${CMAKE_SOURCE_DIR}/src/shapes/Sphere.cpp
)

set(INCLUDE_DIRECTORIES
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/vendor/fmt/include
    ${CMAKE_SOURCE_DIR}/vendor/glm
)

set(PCH
    ${CMAKE_SOURCE_DIR}/src/pch/pch.h
    ${CMAKE_SOURCE_DIR}/src/pch/pch.cpp
)

add_executable(${CMAKE_PROJECT_NAME}
    ${SOURCE_FILES}
)

target_precompile_headers(${CMAKE_PROJECT_NAME} PRIVATE ${PCH})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${INCLUDE_DIRECTORIES})

target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/lib
)
target_link_libraries(${CMAKE_PROJECT_NAME}
    fmt::fmt
    gdi32
    user32
    kernel32
    shell32
)