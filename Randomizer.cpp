#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main()
{
    // --- User Input Section ---
    int n, m, k, seed = 42;
    string targetPath = "./samples/";

    cout << "Enter number of elements per sample (n): ";
    cin >> n;
    cout << "Enter number of samples to generate (m): ";
    cin >> m;
    cout << "Enter maximum range value (k): ";
    cin >> k;

    // --- Create Target Directory if Not Exists ---
    if (!fs::exists(targetPath))
    {
        fs::create_directory(targetPath);
    }

    // --- Random Number Generator Setup ---
    mt19937 rng(seed);                            // Mersenne Twister random engine with user seed
    uniform_int_distribution<int> dist(0, k - 1); // Uniform distribution from 0 to k-1

    // --- Sample Generation Loop ---
    for (int test = 1; test <= m; ++test)
    {
        vector<int> val, wt;
        val.reserve(n);
        wt.reserve(n);
        uniform_int_distribution<int> weightDist(1, k);    // No zero weights
        uniform_int_distribution<int> valueDist(1, k * 2); // Values can be higher than weights

        // Generate random values and weights
        for (int i = 0; i < n; ++i)
        {
            val.push_back(valueDist(rng));
            wt.push_back(weightDist(rng));
        }

        int capacity = k * n / 2; // Arbitrary capacity, can be adjusted

        // Save the generated sample to a file
        string fileName = targetPath + "sample_" + to_string(test) + ".txt";
        ofstream outFile(fileName);
        if (!outFile.is_open())
        {
            cerr << "Failed to open file: " << fileName << endl;
            continue;
        }

        // Write capacity, then val array, then wt array
        outFile << capacity << "\n";
        for (int v : val)
            outFile << v << " ";
        outFile << "\n";
        for (int w : wt)
            outFile << w << " ";
        outFile << "\n";

        outFile.close();
    }

    // --- Completion Message ---
    cout << "Random samples generated successfully.\n";

    return 0;
}