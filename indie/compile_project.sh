rm -rf build
mkdir build
cd build
cmake ..
make -j
LD_LIBRARY_PATH=/usr/local/lib64 ./bomberman