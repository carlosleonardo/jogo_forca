cmake_minimum_required(VERSION 4.3)
project(jogo_forca)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v7.0.1
)
FetchContent_MakeAvailable(ftxui)
add_executable(jogo_forca main.cpp
        Jogo.cpp
        Jogo.h)
target_link_libraries(jogo_forca PRIVATE ftxui::screen ftxui::dom)