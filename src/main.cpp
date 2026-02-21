#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<int>> meanFilter(const vector<vector<int>>& img, int rows, int cols) 
{
    vector<vector<int>> out = img;
    for (int i = 1; i < rows - 1; i++) // Loop through the inner rows (skip borders)
    {
        for (int j = 1; j < cols - 1; j++) // Loop through the inner columns (skip borders)
        {
            int sum = 0;
            for (int ni = -1; ni <= 1; ni++) // Loop through the neighborhood rows
            {
                for (int nj = -1; nj <= 1; nj++) // Loop through the neighborhood columns
                {
                    sum += img[i + ni][j + nj]; // Sums the values in the 3x3 neighborhood around (i, j)
                }
            }
            out[i][j] = sum / 9;
        }
    }
    return out;
}

int main(int argc, char* argv[]) 
{
    if (argc < 3) 
    {
        cout << "Usage: ./denoise <input.txt> <output.txt> [iterations]\n";
        return 1;
    }

    // Read command line arguments
    string inFile  = argv[1];
    string outFile = argv[2];
    int iters      = (argc >= 4) ? stoi(argv[3]) : 1;

    // Read the input image from the file
    int rows, cols;
    ifstream fin(inFile);
    fin >> rows >> cols;
    vector<vector<int>> img(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            fin >> img[i][j];
    fin.close();

    // Apply the mean filter for the specified number of iterations
    for (int k = 0; k < iters; k++)
        img = meanFilter(img, rows, cols);

    // Write the output image to the file
    ofstream fout(outFile);
    fout << rows << " " << cols << "\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fout << img[i][j];
            if (j < cols - 1) fout << " ";
        }
        fout << "\n";
    }
    fout.close();

    cout << "Done. Output saved to " << outFile << "\n";
    return 0;
}