Build & Run
    g++ src/main.cpp -o denoise
    ./denoise <input.txt> <output.txt> [iterations]

Example
    ./denoise tests/test1.txt tests/out1.txt 1
    ./denoise tests/test2.txt tests/out2.txt 2 

File Structure
    MiniProject3_Higgins/
        src/
            main.cpp        # All Programing Logic
        tests/
            test1.txt       # Small matrix with spike noise
            test2.txt       # Salt and pepper noise
            test3.txt       # Border/edge test
            out1.txt        # Output from test1
            out2.txt        # Output from test2
            out3.txt        # Output from test3
        README.md
        TESTING.md

Design Notes
    Image stored as vector<vector<int>>
    Filter: Mean filter (3x3 average)
    Border policy: Ignore borders — edge pixels are copied unchanged, filter only runs on interior pixels
    Supports multiple iterations via command line argument

Terminal Demo Output
    ./denoise tests/test1.txt tests/out1.txt 1
    Done. Output saved to tests/out1.txt

Copilot Usage
    What Copilot helped with:
        Copilot helped generate the test input matrices for the tests/ folder. It also suggested the initial structure for reading the matrix from a file using ifstream.
    What I wrote/verified myself:
        I wrote the mean filter logic and the ignore borders policy myself. I also wrote the command line argument handling and verified that the output files were correctly formatted by checking them manually after running each test.
    Bug Copilot missed:
        Copilot initially suggested using the array format with curly braces and commas for the test input files, which would not be read correctly by the program. I fixed this by removing the braces and commas so the files contained plain space-separated integers as expected by the ifstream parsing logic.
