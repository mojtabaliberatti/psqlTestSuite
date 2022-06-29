message("Start Complie translator agent ...")

find_package(PostgreSQL REQUIRED)


add_executable(psqlTestSuite 
              main.cpp)

target_include_directories(
  psqlTestSuite PRIVATE
  ./inc
  )

target_link_libraries(
    psqlTestSuite
    PostgreSQL::PostgreSQL
    )  


