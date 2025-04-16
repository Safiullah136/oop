#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
using namespace std::filesystem;

void char_example() {

    // My Code
    path directory = "res";

    if(!exists(directory)) {
        create_directory(directory);
        cout << "Directory created : " << directory << endl;
    }

    path filename = directory / "sample.txt";
    cout << "File Created : " << filename << endl; 
    // End

    ofstream fout;
    string line = "My test line ...\n";

    fout.open(filename, ios::app);
    fout << line;
    // for(int i = 0; i < 4; i++) {
    //     fout << line;
    // }

    fout.close();

    ifstream fin;
    fin.open(filename);

    while(fin) { 
        getline(fin, line);
        cout << line << endl; 
    }

    fin.close();
} 

void output_matrix(int matrix[][3], int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void bin_example() {
    int pixels[3][3];
    for(int i = 0; i < 3; i++) 
        for(int j = 0; j < 3; j++)
            pixels[i][j] = 1 + i * j;

    output_matrix(pixels, 3, 3);

    ofstream fout("data.bin", ios::binary);
    for(int i = 0; i < 3; i++) 
        for(int j = 0; j < 3; j++)
            fout.write((char *)&pixels[i][j], sizeof(int));
    
    fout.close();  
    
    cout << "Resetting pixels : " << endl;
    for(int i = 0; i < 3; i++) 
        for(int j = 0; j < 3; j++)
            pixels[i][j] = 0;

    output_matrix(pixels, 3, 3);

    cout << "Reading again ... " << endl;
    ifstream fin("data.txt", ios::binary); // try missing file

    if(fin.fail()) {
        cout << "File reading failed!" << endl;
    } else
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) 
                fin.read((char *)&pixels[i][j], sizeof(int));

    fin.close();

    output_matrix(pixels, 3, 3);
}

int main() {

    // char_example();
    bin_example();

    return 0;
}