build_debug:
  cmake -B build/Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -G Ninja -DCMAKE_BUILD_TYPE=Debug && cmake --build build/Debug

run_debug: 
  ./build/Debug/septem_maria
