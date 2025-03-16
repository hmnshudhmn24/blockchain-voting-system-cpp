#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <openssl/sha.h>

using namespace std;

string sha256(const string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)data.c_str(), data.size(), hash);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << (int)hash[i];
    }
    return ss.str();
}

class Block {
public:
    int index;
    time_t timestamp;
    string data;
    string previousHash;
    string hash;

    Block(int idx, string voteData, string prevHash) {
        index = idx;
        timestamp = time(0);
        data = voteData;
        previousHash = prevHash;
        hash = calculateHash();
    }

    string calculateHash() {
        string toHash = to_string(index) + to_string(timestamp) + data + previousHash;
        return sha256(toHash);
    }
};

class Blockchain {
public:
    vector<Block> chain;

    Blockchain() {
        chain.push_back(createGenesisBlock());
    }

    Block createGenesisBlock() {
        return Block(0, "Genesis Block", "0");
    }

    Block getLatestBlock() {
        return chain.back();
    }

    void addBlock(string voteData) {
        Block newBlock(chain.size(), voteData, getLatestBlock().hash);
        chain.push_back(newBlock);
    }

    void displayChain() {
        for (Block block : chain) {
            cout << "Index: " << block.index << endl;
            cout << "Timestamp: " << block.timestamp << endl;
            cout << "Vote: " << block.data << endl;
            cout << "Previous Hash: " << block.previousHash << endl;
            cout << "Hash: " << block.hash << endl;
            cout << "---------------------------------
";
        }
    }
};

int main() {
    Blockchain votingBlockchain;
    int choice;
    string vote;
    
    while (true) {
        cout << "1. Cast Vote\n2. Show Blockchain\n3. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 1) {
            cout << "Enter your vote (Candidate Name): ";
            getline(cin, vote);
            votingBlockchain.addBlock(vote);
        } else if (choice == 2) {
            votingBlockchain.displayChain();
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
