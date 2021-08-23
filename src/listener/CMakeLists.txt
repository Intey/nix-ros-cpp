find_package(roscpp REQUIRED)
find_package(rosconsole REQUIRED)
find_package(roscpp_serialization REQUIRED)
add_executable(main main.cpp)
target_link_libraries(main 
  roscpp 
  rosconsole 
  roscpp_serialization
  )
