
if [ "$#" -eq 0 ]; then
   mkdir build
   cd build
   cmake ..
   make
fi

if [[ "$#" -eq 1 && "$1" = "clean" ]]; then
   rm -r build
   rm -r bin
   echo "Deleted build and bin directories"
fi
