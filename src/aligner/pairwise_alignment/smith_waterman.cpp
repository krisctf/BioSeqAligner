#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to calculate the maximum of three integers
int max(int a, int b, int c) {
    return max(max(a, b), c);
}

// Function to perform pairwise sequence alignment using Smith-Waterman algorithm
int smithWaterman(string seq1, string seq2) {
    int m = seq1.length();
    int n = seq2.length();

    // Create a matrix to store the alignment scores
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize variables to store the maximum score and its position
    int maxScore = 0;
    pair<int, int> maxPos;

    // Fill in the matrix and find the maximum score
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 0;
            }

            // Update the maximum score and its position
            if (dp[i][j] > maxScore) {
                maxScore = dp[i][j];
                maxPos = make_pair(i, j);
            }
        }
    }

    // Extract the aligned sequences
    string alignedSeq1 = "";
    string alignedSeq2 = "";

    int i = maxPos.first;
    int j = maxPos.second;

    while (i > 0 && j > 0 && dp[i][j] > 0) {
        alignedSeq1 = seq1[i - 1] + alignedSeq1;
        alignedSeq2 = seq2[j - 1] + alignedSeq2;

        i--;
        j--;
    }

    // Print the aligned sequences
    cout << "Aligned Sequence 1: " << alignedSeq1 << endl;
    cout << "Aligned Sequence 2: " << alignedSeq2 << endl;

    return maxScore;
}

int main() {
    string sequence1 = "AGTCAGT";
    string sequence2 = "AGTTCAGT";

    int alignmentScore = smithWaterman(sequence1, sequence2);

    cout << "Alignment Score: " << alignmentScore << endl;

    return 0;
}
