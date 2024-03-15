cmake_minimum_required(VERSION 3.22.1)

project("algorithm_test")

add_executable(${PROJECT_NAME} ./test.cpp)

set(IF_REVIEW off) # 初始化变量

# 目标包含目录，根据IF_REVIEW的值选择不同的目录
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/SortTestHelper
)

# 如果IF_REVIEW被设置为ON，则添加review目录
if(IF_REVIEW)
    message("")
    message("/////////////////////////////")
    message("//   This is the review mode.")
    message("")
    target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/review
    )
endif()

# 如果IF_REVIEW未设置，或者设置为OFF，则添加实现目录
if(NOT IF_REVIEW)
    message("")
    message("//////////////////////////////////////")
    message("//    This is the implementation mode.")
    message("")
    target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/algorithm_implemention_dir
    )
endif()
