# cmake_minimum_required(VERSION <specify CMake version here>)
project(Projchampionnat)

set(CMAKE_CXX_STANDARD 14)

include_directories(class)
include_directories(class/lib)
include_directories(class/lib/termcolor)
include_directories(sqlite/sqlite)

add_executable(Projchampionnat
        class/lib/termcolor/termcolor.hpp
        class/lib/sqlite3.c
        class/lib/sqlite3.h
        class/lib/sqlite3ext.h
        class/lib/sqlite3pp.cpp
        class/lib/sqlite3pp.h
        class/lib/sqlite3ppext.cpp
        class/lib/sqlite3ppext.h
        class/Appartenir.cpp
        class/Appartenir.h
        class/Championnat.cpp
        class/Championnat.h
        class/Division.cpp
        class/Division.h
        class/Equipe.cpp
        class/Equipe.h
        class/Resultat.cpp
        class/Resultat.h
        class/Saison.cpp
        class/Saison.h
        sqlite/sqlite/shell.c
        sqlite/sqlite/sqlite3.c
        sqlite/sqlite/sqlite3.h
        sqlite/sqlite/sqlite3ext.h
        main.cpp)
