# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/artem/Documents/База знаний 2.0/МП/mp_HW03/build/_deps/googletest-src"
  "/Users/artem/Documents/База знаний 2.0/МП/mp_HW03/build/_deps/googletest-build"
  "/Users/artem/Documents/База знаний 2.0/МП/mp_HW03/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/artem/Documents/База знаний 2.0/МП/mp_HW03/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/artem/Documents/База знаний 2.0/МП/mp_HW03/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/artem/Documents/База знаний 2.0/МП/mp_HW03/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/artem/Documents/База знаний 2.0/МП/mp_HW03/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/artem/Documents/База знаний 2.0/МП/mp_HW03/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/artem/Documents/База знаний 2.0/МП/mp_HW03/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
