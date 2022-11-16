# Install script for directory: D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/test/gtest-1.10.0/googlemock

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/YAML_CPP")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/test/gtest-1.10.0/googlemock/include/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/lib/Debug/gmockd.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/lib/Release/gmock.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/lib/MinSizeRel/gmock.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/lib/RelWithDebInfo/gmock.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/lib/Debug/gmock_maind.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/lib/Release/gmock_main.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/lib/MinSizeRel/gmock_main.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/lib/RelWithDebInfo/gmock_main.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE OPTIONAL FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/bin/${CMAKE_INSTALL_CONFIG_NAME}/gmockd.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE OPTIONAL FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/bin/${CMAKE_INSTALL_CONFIG_NAME}/gmock.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE OPTIONAL FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/bin/${CMAKE_INSTALL_CONFIG_NAME}/gmock.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE OPTIONAL FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/bin/${CMAKE_INSTALL_CONFIG_NAME}/gmock.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE OPTIONAL FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/bin/${CMAKE_INSTALL_CONFIG_NAME}/gmock_maind.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE OPTIONAL FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/bin/${CMAKE_INSTALL_CONFIG_NAME}/gmock_main.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE OPTIONAL FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/bin/${CMAKE_INSTALL_CONFIG_NAME}/gmock_main.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE OPTIONAL FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/bin/${CMAKE_INSTALL_CONFIG_NAME}/gmock_main.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/test/prefix/googletest/generated/gmock.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/test/prefix/googletest/generated/gmock_main.pc")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/Repository/2022/C++/yaml-cpp-yaml-cpp-0.7.0 (2)/yaml-cpp-yaml-cpp-0.7.0/build/test/prefix/googletest/cmake_install.cmake")

endif()

