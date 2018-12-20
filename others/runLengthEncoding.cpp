/*************************************************************************
 Run-Length Encoding Algorithm (RLE)
 * Purpose:
 * RLE encodes binary source texts to binary coded texts.
 *
 * Description:
 * Source text S is encoded as the first bit of S (either 0 or 1)
 * followed by a sequence of integers indicating run lengths.
 * The encoding of run-length k is prefix-free in this algorithm
 * because the decoder has to know when to stop reading k.
 * RLE encodes the binary length of k in unary, followed by the actual
 * value of k in binary.
 * 
 * Examples:
 *   1 -> 11
 *   100011 -> 11011010
 *   1111111001 -> 1001110101
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

//calculate the floor of log2(n)
int binaryLen(int n){
    int r = 0;
    while (n = n/2){
        r++;
        if (n == 0)  break;
    }
    return r;    
}

void encodeSequence(vector<int>& eText, int k){
    //encode the binary length of count in unary
    int binLen = binaryLen(k);
    for (int j=0; j<binLen; j++){
        eText.push_back(0);
    }

    //actual value of k in binary
    std::bitset<32> bin (k);
    bool skippedLeadingZero = false;
    for (int j=31; j>=0; j--){
        if (bin[j] == 1){
            skippedLeadingZero = true;
        }
        if (skippedLeadingZero){
            eText.push_back(bin[j]);
        }
    }
}

void RLE(string sText){
    vector<int> eText;

    //first bit of source text in Int
    eText.push_back(sText[0] - 48);

    char previousBit = sText[0];
    int len = sText.length();
    int k = 1;

    for (int i=1; i<len; i++){
        if (sText[i] == previousBit){
            k++;
        }
        else{
            encodeSequence(eText, k);

            //reset previousBit and k
            previousBit = sText[i];
            k = 1;
        }
    }
    //encode the last sequence in the source text
    encodeSequence(eText, k);

    //print encoded text
    for (vector<int>::iterator it=eText.begin(); it!=eText.end(); ++it){
        cout << *it;
    }
    cout << endl;
}

int main(){
    string sText;

    while (getline(cin, sText)){
        cout << "Encoded text: ";
        RLE(sText);
    }
}