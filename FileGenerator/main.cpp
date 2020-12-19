#include <fstream>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

vector<string> sections = {};
const string FILE_NAME = "../FileGenerator/TTTMoves.txt";
const int FILE_TYPE  = 164;

struct Header {
    uint32_t movesStart; // start of game moves record
    uint32_t movesLength; // length of game moves record
    uint32_t playerXNameStart; // start of name of player X
    uint32_t playerXNameLength; // length of name of player X
    uint32_t playerONameStart; // start of name of player O
    uint32_t playerONameLength; // length of name of player O
};

struct Record {
    uint32_t location;
    uint32_t length;
    string PlayerXName;
    string PlayerOName;
};

void WriteHeader(Header &header, ofstream &file) {
    file.seekp(0);
    file.write((char *)&header, sizeof(header));
}

void WriteRecord(int index, Record &record, ofstream &file) {
    file.seekp(sizeof(Header) + index * sizeof(record));
    file.write((char *)&record, sizeof(record));
}

int WriteSection(int start, string &text, ofstream &file) {
    file.seekp(start);
    file << text;
    return (int)file.tellp() - start;
}

int main(int argc, char *argv[]) {
    ofstream file;
    Header header;
    Record record;
    uint32_t nextLocation;
    int bytesWritten;

    file.open(FILE_NAME, ios::out | ios::binary);
    cout<<"Input Player X name"<<endl;
    cin>>record.PlayerXName;
    cout<<"Input Player O name"<<endl;
    header.movesStart = FILE_TYPE;
    header.movesLength = sections.size();
    WriteHeader(header, file);

    nextLocation = sizeof(Header) + sections.size() * sizeof(Record);
    for (int i = 0; i < sections.size(); i++) {
        bytesWritten = WriteSection(nextLocation, sections[i], file);
        record.location = nextLocation;
        record.length = bytesWritten;
        nextLocation = file.tellp();
        WriteRecord(i, record, file);
    }

    return 0;
}
