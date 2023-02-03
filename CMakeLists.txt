cmake_minimum_required(VERSION 3.17)
project(pizzaTracking)

set(CMAKE_CXX_STANDARD 14)

#add_executable(pizzaTracking timeTest.cpp Time.cpp Time.h )
#add_executable(pizzaTracking orderTest.cpp Order.cpp Order.h Time.cpp Time.h)
#add_executable(pizzaTracking driverTest.cpp Driver.cpp Driver.h Order.cpp Order.h Time.cpp Time.h)
#add_executable(pizzaTracking restaurantTest.cpp Restaurant.cpp Restaurant.h Driver.cpp Driver.h Order.cpp Order.h Time.cpp Time.h)
add_executable(pizzaTracking main.cpp Restaurant.cpp Restaurant.h Driver.cpp Driver.h Order.cpp Order.h Time.cpp Time.h HelperFunctions.cpp HelperFunctions.h)
