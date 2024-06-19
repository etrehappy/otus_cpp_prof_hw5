cmake_minimum_required(VERSION 3.26)

project(editor_prj)

set(main_files main.cpp 
)

set(Model 
editor_model.h  editor_model.cpp 
)
set(View 
editor_view.h   editor_view.cpp 
)
set(Controller 
editor_controller.h     editor_controller.cpp 
menu_enums.h
)
set(Shapes
shape.h     
line.h      line.cpp
circle.h    circle.cpp
)

add_executable(editor ${main_files} ${Model} ${View} ${Controller} ${Shapes})

if(MSVC)
		set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT editor)
        source_group("Main" FILES ${main_files})
        source_group("Model" FILES ${Model})
        source_group("View" FILES ${View})
        source_group("Controller" FILES ${Controller})
        source_group("Shapes" FILES ${Shapes})
endif ()


target_compile_options(editor PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX >
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
        )

set_target_properties(editor PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

