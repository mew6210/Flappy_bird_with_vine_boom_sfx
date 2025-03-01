﻿# CMakeList.txt : CMake project for Flappy_bird_with_vine_boom_sfx, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Flappy_bird_with_vine_boom_sfx")

include(FetchContent)

FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG        32fcfd354908614f2aaa9d37016b35e9fbfcbe68 
)

FetchContent_MakeAvailable(raylib)

# Add source to this project's executable.
add_executable (Flappy_bird_with_vine_boom_sfx "main.cpp" "stuff.h" "implementations.cpp")
target_link_libraries(Flappy_bird_with_vine_boom_sfx PRIVATE raylib)
target_include_directories(Flappy_bird_with_vine_boom_sfx PRIVATE ${raylib_SOURCE_DIR}/src)



set(AUDIO_SOURCE ${CMAKE_SOURCE_DIR}/audio/vine-boom-sound-effect.wav)
set(AUDIO_DESTINATION ${CMAKE_BINARY_DIR}/audio/vine-boom-sound-effect.wav)


add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${AUDIO_SOURCE} ${AUDIO_DESTINATION}
    COMMENT "Copying audio to the audio directory"
)





if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Flappy_bird_with_vine_boom_sfx PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
