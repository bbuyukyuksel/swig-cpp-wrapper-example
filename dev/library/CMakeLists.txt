# CMake en az 3.10 sürümünü gerektirir
cmake_minimum_required(VERSION 3.10)

# Proje adını tanımlayın
project(MyMathLibrary)
set(CMAKE_CXX_STANDARD 17)

# CMake, dinamik bir kütüphane oluşturmasını söyleyin
add_library(mylib SHARED
    src/mylib.cpp
)

# Hedefin çıktı adını belirtin (libmylib.so)
set_target_properties(mylib PROPERTIES OUTPUT_NAME "mylib")

# Kütüphaneyi projeye dahil edin
target_include_directories(mylib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# # İstemci uygulamalarının kütüphaneyi kullanabilmesi için yolu belirtin
# install(TARGETS my_math
#     LIBRARY DESTINATION /usr/local/lib
# )
