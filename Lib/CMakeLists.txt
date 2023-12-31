project(GameAnimationLib)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS 
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.hxx
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.glsl
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hxx
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

add_library(${PROJECT_NAME} ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 17
)

target_link_libraries (${PROJECT_NAME}
	PUBLIC opengl::opengl
	PUBLIC fmtlog::fmtlog
	PUBLIC glfw
	PUBLIC glad::glad
	PUBLIC glm::glm
	PUBLIC stb::stb
	PUBLIC cgltf::cgltf
)

target_compile_definitions(${PROJECT_NAME} 
	PRIVATE $<$<CXX_COMPILER_ID:MSVC>:_CRT_SECURE_NO_WARNINGS>
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

target_compile_options(${PROJECT_NAME} 
	PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/W2 /wd4305 /wd4244>
	#PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/WX /W3>
	PRIVATE $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Werror>
	# -Wextra -Wpedantic 
)