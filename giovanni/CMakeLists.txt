project(giovanni)

# library
set(giovanni_library_sources
    src/game.hpp
    src/game.cpp
    src/player.hpp
    src/player.cpp
)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${giovanni_library_sources})
add_library(${PROJECT_NAME} ${giovanni_library_sources})
add_library(Gio::Giovanni ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} 
    PUBLIC 
        sfml-audio 
        sfml-graphics
    PRIVATE
        Gio::CodeCoverage
)

# executable
set(giovanni_desktop_sources
    src/main.cpp
)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${giovanni_desktop_sources})
add_executable(giovanni-desktop ${giovanni_desktop_sources})
target_link_libraries(giovanni-desktop PRIVATE Gio::Giovanni)

# tests
set (giovanni_test_src
    src/main_test.cpp
    src/game_test.cpp
)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${giovanni_test_src})
add_executable(giovanni_tests ${giovanni_test_src})
target_link_libraries(giovanni_tests 
    PRIVATE
        Gio::Giovanni
        Gio::CodeCoverage
        Catch2::Catch2
)
catch_discover_tests(giovanni_tests)