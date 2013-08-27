add_definitions( -DJSON_CONFIG_FILE="${PROJECT_SOURCE_DIR}/opm/parser/share/parser_config.json")
add_definitions( -DKEYWORD_DIRECTORY="${PROJECT_SOURCE_DIR}/opm/parser/share/keywords")

add_executable(runIntegrationTests IntegrationTests.cpp)
target_link_libraries(runIntegrationTests Parser ${Boost_LIBRARIES})
add_test(NAME runIntegrationTests WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH} COMMAND runIntegrationTests)
set_property(SOURCE IntegrationTests.cpp PROPERTY COMPILE_FLAGS "-Wno-error")


add_executable(runParseWCONHIST ParseWCONHIST.cpp)
target_link_libraries(runParseWCONHIST Parser ${Boost_LIBRARIES})
add_test(NAME runParseWCONHIST WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH} COMMAND runParseWCONHIST)


add_executable(runParseEQUIL ParseEQUIL.cpp)
target_link_libraries(runParseEQUIL Parser ${Boost_LIBRARIES})
add_test(NAME runParseEQUIL 
         WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH} 
         COMMAND ${EXECUTABLE_OUTPUT_PATH}/runParseEQUIL)


add_executable(runIntegrationTestsInternalData IntegrationTestsInternalData.cpp)
target_link_libraries(runIntegrationTestsInternalData Parser ${Boost_LIBRARIES})
add_test(NAME runIntegrationTestsInternalData WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH} COMMAND ${EXECUTABLE_OUTPUT_PATH}/runIntegrationTestsInternalData )
set_property(TEST runIntegrationTestsInternalData PROPERTY LABELS Statoil)