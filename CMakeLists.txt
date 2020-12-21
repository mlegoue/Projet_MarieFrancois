cmake_minimum_required(VERSION 3.17)
project(ProjetC__MarieFrancois)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS
        Bibliotheque.h
        Livre.h
        BandeDessinee.h
        Roman.h
        RecueilPoesie.h
        PieceTheatre.h
        Adherent.h)

set(PROJECT_SOURCES
        main.cpp
        Bibliotheque.cpp
        Livre.cpp
        BandeDessinee.cpp
        Roman.cpp
        RecueilPoesie.cpp
        PieceTheatre.cpp
        Album.cpp
        Adherent.cpp)


add_executable(ProjetC__MarieFrancois ${PROJECT_SOURCES} ${PROJECT_HEADERS})