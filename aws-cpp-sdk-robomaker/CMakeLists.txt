add_project(aws-cpp-sdk-robomaker "C++ SDK for the AWS robomaker service" aws-cpp-sdk-core)

file(GLOB AWS_ROBOMAKER_HEADERS
    "include/aws/robomaker/*.h"
)

file(GLOB AWS_ROBOMAKER_MODEL_HEADERS
    "include/aws/robomaker/model/*.h"
)

file(GLOB AWS_ROBOMAKER_SOURCE
    "source/*.cpp"
)

file(GLOB AWS_ROBOMAKER_MODEL_SOURCE
    "source/model/*.cpp"
)

file(GLOB ROBOMAKER_UNIFIED_HEADERS
    ${AWS_ROBOMAKER_HEADERS}
    ${AWS_ROBOMAKER_MODEL_HEADERS}
)

file(GLOB ROBOMAKER_UNITY_SRC
    ${AWS_ROBOMAKER_SOURCE}
    ${AWS_ROBOMAKER_MODEL_SOURCE}
)

if(ENABLE_UNITY_BUILD)
    enable_unity_build("ROBOMAKER" ROBOMAKER_UNITY_SRC)
endif()

file(GLOB ROBOMAKER_SRC
    ${ROBOMAKER_UNIFIED_HEADERS}
    ${ROBOMAKER_UNITY_SRC}
)

if(WIN32)
    #if we are compiling for visual studio, create a sane directory tree.
    if(MSVC)
        source_group("Header Files\\aws\\robomaker" FILES ${AWS_ROBOMAKER_HEADERS})
        source_group("Header Files\\aws\\robomaker\\model" FILES ${AWS_ROBOMAKER_MODEL_HEADERS})
        source_group("Source Files" FILES ${AWS_ROBOMAKER_SOURCE})
        source_group("Source Files\\model" FILES ${AWS_ROBOMAKER_MODEL_SOURCE})
    endif(MSVC)
endif()

set(ROBOMAKER_INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}/include/"
)

add_library(${PROJECT_NAME} ${LIBTYPE} ${ROBOMAKER_SRC})
add_library(AWS::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_compiler_flags(${PROJECT_NAME})
set_compiler_warnings(${PROJECT_NAME})

if(USE_WINDOWS_DLL_SEMANTICS AND BUILD_SHARED_LIBS)
    target_compile_definitions(${PROJECT_NAME} PRIVATE "AWS_ROBOMAKER_EXPORTS")
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

target_link_libraries(${PROJECT_NAME} PRIVATE ${PLATFORM_DEP_LIBS} ${PROJECT_LIBS})


setup_install()

install (FILES ${AWS_ROBOMAKER_HEADERS} DESTINATION ${INCLUDE_DIRECTORY}/aws/robomaker)
install (FILES ${AWS_ROBOMAKER_MODEL_HEADERS} DESTINATION ${INCLUDE_DIRECTORY}/aws/robomaker/model)

if(PLATFORM_WINDOWS AND MSVC)
    file(GLOB NUGET_FILES "nuget/${PROJECT_NAME}.*.autopkg")
    install (FILES ${NUGET_FILES} DESTINATION nuget)
endif()

do_packaging()


