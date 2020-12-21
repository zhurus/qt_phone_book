cmake_minimum_required(VERSION 3.10.2)
project(phone_book)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
file(GLOB SOURCES *.h *.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME}
	Qt5::Widgets
	)
