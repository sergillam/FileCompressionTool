cmake_minimum_required(VERSION 3.10)
project(FileCompressionTool C)

# Use o padrão C99
set(CMAKE_C_STANDARD 99)

# Inclui os headers personalizados
include_directories(header_files)

# Adiciona todos os arquivos fonte da pasta src
file(GLOB SOURCES "src/*.c")

# Cria o executável com todos os arquivos fonte
add_executable(fileCompressor ${SOURCES})
