project(GameAnimationApp)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS 
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.c
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.h 
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.cxx
	${CMAKE_CURRENT_SOURCE_DIR}/source/*.hxx
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

add_executable (${PROJECT_NAME} ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 17
)

target_link_libraries (${PROJECT_NAME}
    PRIVATE GameAnimationLib
	PRIVATE opengl::opengl
	PRIVATE fmtlog::fmtlog
	PRIVATE glfw
	PRIVATE glad::glad
	PRIVATE glm::glm
)

target_compile_definitions(${PROJECT_NAME} 
	PRIVATE $<$<CXX_COMPILER_ID:MSVC>:_CRT_SECURE_NO_WARNINGS>
)

target_include_directories(${PROJECT_NAME}
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/
)

target_compile_options(${PROJECT_NAME} 
	PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/W2 /wd4305 /wd4244>
	#PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/WX /W3>
	PRIVATE $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Werror>
	# -Wextra -Wpedantic 
)

file (COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})