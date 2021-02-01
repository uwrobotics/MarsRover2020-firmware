add_executable(test-currentsensor.${TARGET}-board.elf)
target_sources(test-currentsensor.${TARGET}-board.elf PRIVATE src/main.cpp)
target_link_libraries(test-currentsensor.${TARGET}-board.elf PRIVATE CurrentSensor)
target_set_firmware_properties(test-currentsensor.${TARGET}-board.elf)
