cmake_minimum_required(VERSION 3.10)
project(TPO_lab1)

# Указание исполняемого файла и исходных файлов
add_executable(${PROJECT_NAME} bin/main.cpp)

# Добавление библиотеки lr1_lib
add_library(lr1_lib lib/lr1.cpp)

# Привязка библиотеки lr1_lib к исполняемому файлу
target_link_libraries(${PROJECT_NAME} PUBLIC lr1_lib)

# Указание директорий для включаемых файлов
target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/lib
        ${PROJECT_SOURCE_DIR}/nlohmann
        ${PROJECT_SOURCE_DIR}/boost # Предполагается, что заголовочные файлы находятся здесь
)
