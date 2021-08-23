find_package(roscpp REQUIRED)
find_package(rosconsole REQUIRED)
find_package(roscpp_serialization REQUIRED)

add_executable(main main.cpp)

set_property(TARGET main PROPERTY CXX_STANDARD 20)
target_compile_options(main PRIVATE -pedantic -Wall)

target_link_libraries(main 
  roscpp 
  rosconsole 
  roscpp_serialization
  )
