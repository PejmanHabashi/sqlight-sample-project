cmake_minimum_required(VERSION 2.6)

Project (solution CXX)

set( EXTRA_LIBS ${EXTRA_LIBS} sqlite3 )

add_executable          (   ${PROJECT_NAME} main.cpp                    )
set_target_properties   (   ${PROJECT_NAME} PROPERTIES CXX_STANDARD 14  )
target_link_libraries   (   ${PROJECT_NAME} ${EXTRA_LIBS}               )
