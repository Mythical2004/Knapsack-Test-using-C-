#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <filesystem>
#include "algorithm1.cpp" // Contains knapsack function
using namespace std;
using namespace std::chrono;
namespace fs = std::filesystem;

int main()
{
    string samplesPath = "./samples/";
    ofstream logFile("log.txt");
    if (!logFile.is_open())
    {
        cerr << "Failed to create log.txt\n";
        return 1;
    }

    int testNumber = 0;

    for (const auto &entry : fs::directory_iterator(samplesPath))
    {
        if (entry.is_regular_file())
        {
            testNumber++;
            ifstream file(entry.path());
            if (!file.is_open())
            {
                cerr << "Failed to open file: " << entry.path() << endl;
                continue;
            }

            int W;
            file >> W;

            string line;
            vector<int> val, wt;
            int num;

            // Read values line
            getline(file, line);
            getline(file, line);
            istringstream valStream(line);
            while (valStream >> num)
                val.push_back(num);

            // Read weights line
            getline(file, line);
            istringstream wtStream(line);
            while (wtStream >> num)
                wt.push_back(num);

            file.close();

            auto start = high_resolution_clock::now();
            int result = knapsack(W, val, wt);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);

            logFile << "Test Number: " << testNumber << "\n";
            logFile << "Sample File: " << entry.path().filename().string() << "\n";
            logFile << "Capacity (W): " << W << "\n";
            logFile << "Values: ";
            for (int v : val)
                logFile << v << " ";
            logFile << "\nWeights: ";
            for (int w : wt)
                logFile << w << " ";
            logFile << "\nMaximum Value: " << result << "\n";
            logFile << "Computation Time: " << duration.count() / 1000 << " ms\n";
            logFile << "------------------------------------------------------------\n";
        }
    }

    logFile.close();
    cout << "All files tested and logged successfully.\n";
    return 0;
}
