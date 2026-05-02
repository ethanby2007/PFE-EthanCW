How to run my program:

Option 1 (Using CLion) Recommended:
1. Launch CLion and select open. Navigate to the folder where you saved the .c and .h files. Select the entire folder (Make sure CMakeLists.txt is inside) and click ok.
2. If prompted, select trust project.
3. Press the hammer icon in the top right to build the project.
4. Place the downloaded power_quality_log.csv file inside the project folder, if this doesn't work then place inside the cmake-build-debug folder inside the project file.
5. Go to the top menu (the three dots next to debug in the top right) and edit configurations.
6. Find the program arguments box and type: 'power_quality_log.csv' Then click apply and OK.
7. Click the green button in the top right to compile.
8. If you placed the CSV file in the cmake-build-debug file then you will find the results.txt file inside that folder.

Option 2 (GCC):
1.
