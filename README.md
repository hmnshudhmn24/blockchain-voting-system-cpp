# Blockchain-Based Voting System

A secure, decentralized voting system implemented in C++ using a simple blockchain structure.

## Features
- Secure vote recording using blockchain technology
- SHA-256 hashing for tamper-proof records
- Simple command-line interface for voting and verification

## Requirements
- g++ compiler
- OpenSSL library (for SHA-256 hashing)

## Installation & Usage

### 1. Compile the Program
```sh
g++ blockchain_voting.cpp -o voting -lssl -lcrypto
```

### 2. Run the Program
```sh
./voting
```

### 3. Voting Options
- `1`: Cast a vote by entering a candidate's name.
- `2`: Display the blockchain to verify votes.
- `3`: Exit the program.

## How It Works
- Each vote is stored as a block in the blockchain.
- The system generates a cryptographic hash for each vote.
- The blockchain ensures votes cannot be altered.

## Future Enhancements
- Implement digital signatures for voter authentication.
- Introduce networking for a decentralized peer-to-peer system.
- Add encryption for better security.

## License
This project is open-source and can be modified freely.
