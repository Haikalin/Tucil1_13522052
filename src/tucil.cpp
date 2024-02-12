#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <random>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

bool ceksama(vector<int> angka_penyusun_1, vector<int> angka_penyusun_2) {
    int sama = 0;
    int ukuranarray1 = angka_penyusun_1.size();
    int ukuranarray2 = angka_penyusun_2.size();
    for (int i = 0; i < ukuranarray1; i++) {
        for (int j = 0; j < ukuranarray2; j++) {
            if (angka_penyusun_1[i] == angka_penyusun_2[j]) {
                sama += 1;
            }
        }
    }
    if (sama > 0) {
        return false;
    }
    else {
        return true;
    }
}

bool cekduplicatesequence(vector<string> sequence1, vector<string> sequence2) {
    int sama = 0;
    for (int i = 0; i < sequence1.size(); i++) {
        if(sequence1[i] == sequence2[i]) {
            sama += 1;
        }
    }
    if (sama == sequence1.size()) {
        return true;
    }
    else {
        return false;
    }
}

vector<string> parsespace(string kode) {
    vector<string> array;
    string temp;
    for (int i = 0; i < kode.length(); i++) {
        if(kode[i] != ' ') {
            temp += kode[i];
        }
        else {
            array.push_back(temp);
            temp = "";
        }
        if (i == kode.length()-1) {
            array.push_back(temp);
        }
    }
    return array;
}

vector<vector<string> > intersection(vector<string> sequence1, vector<string> sequence2) {
    vector<vector<string> > collection;
    for(int i = 0; i < sequence1.size(); i++) {
        vector<string> section;
        if(sequence1[i] == sequence2[0]) {
            int idx1 = i;
            int idx2 = 0;
            bool same = true;
            while(same == true and idx1 < sequence1.size()) {
                if(sequence1[idx1] == sequence2[idx2]) {
                    idx1 += 1;
                    idx2 += 1;
                }
                else {
                    same = false;
                }
            }
            if (same == true) {
                for(int j = 0; j < sequence1.size(); j++) {
                    section.push_back(sequence1[j]);
                }
                for(int k = idx2; k < sequence2.size(); k++) {
                    section.push_back(sequence2[k]);
                }
                collection.push_back(section);
            }
        }
    }
    return collection;
}

bool checkhistory(int baris, int kolom, vector<vector<vector<int> > > history, int idx) {
    int sama = 0;
    for(int i = 0; i < history[idx].size(); i++) {
        if(history[idx][i][0] == baris and history[idx][i][1] == kolom) {
            sama += 1;
        }
    }   
    if (sama > 0) {
        return false;
    }
    else {
        return true;
    }
}

void cetakhistory(vector<vector<vector<int> > > history) {
    for(int i = 0; i < history.size(); i++) {
        cout << i << " ";
        for(int j = 0; j < history[i].size(); j++) {
            for(int k = 0; k < history[i][j].size(); k++) {
                cout << history[i][j][k] << " ";
            }
        }
        cout << endl;
    }
}

// Driver Code
int main()
{
    // Print standard output
    // on the screen
    // Matrix pakai line dan map
    //
    int max = 0; // Poin maksimal
    int input;  // Cara Input
    int buffer_size, map_width, map_height; // Ukuran buffer, lebar map dan tinggi map
    vector<string> finalkode; // Kode terakhir
    vector<string> line; // Baris map
    vector<vector<string> > map; 
    int total_sequence;
    string kode;
    vector<vector<string> > kumpulankode;
    int angka;
    vector<int> poin;
    cout << "Pilih cara input: \n1. File \n2. CLI" << endl;
    cout << "Masukkan cara input: ";
    cin >> input;
    // Input file
    if(input == 1) {
        string path = "../src/";
        string namafile; 
        cout << "Masukkan nama file yang akan diinput: ";
        cin >> namafile;
        path += namafile;
        ifstream file(path);
        while (file >> buffer_size) {
            file >> map_width >> map_height;
            for(int i = 0; i < map_height; i++) {
                line = { };
                for(int j = 0; j < map_width; j++) {
                    file >> kode;
                    file >> ws;
                    line.push_back(kode);
                }
                map.push_back(line);
            }
            string token; // Sequence
            file >> total_sequence;
            file >> ws;
            int ulang = total_sequence;
            for(int i = 0; i < ulang; i++) {
                getline(file,token);
                vector<string> parsetoken = parsespace(token);
                kumpulankode.push_back(parsetoken);
                file >> angka;
                poin.push_back(angka);
                file >> ws;
            }
        }
    }

    // Input CLI
    else if(input == 2){
        int batasbawah = 0;
        int bataspoinatas = 100;
        random_device rand_dev;
        mt19937 generator(rand_dev());
        int jumlahtoken;    
        cin >> jumlahtoken;
        string token_unik;
        vector<string> kumpulan_token_unik;
        // Save Token
        for(int i = 0; i < jumlahtoken; i++) {
            cin >> token_unik;
            kumpulan_token_unik.push_back(token_unik);
        }
        cin >> buffer_size;
        cin >> map_width >> map_height;
        for(int i = 0; i < map_height; i++) {
            line = { };
            for(int j = 0; j < map_width; j++) {
                uniform_int_distribution<int> map(batasbawah,jumlahtoken-1);
                line.push_back(kumpulan_token_unik[map(generator)]);
            }
            map.push_back(line);
        }
        int panjang_maksimal;
        int panjangsequence;
        cin >> total_sequence;
        cin >> panjang_maksimal;
        for(int i = 0; i < total_sequence; i++) {
            line = {};
            uniform_int_distribution<int> panjangseq(2,panjang_maksimal);
            uniform_int_distribution<int> map(batasbawah,jumlahtoken-1);
            uniform_int_distribution<int> poinrand(batasbawah,bataspoinatas);
            panjangsequence = panjangseq(generator);
            for(int i = 0; i < panjangsequence; i++) {
                line.push_back(kumpulan_token_unik[map(generator)]);
            }
            kumpulankode.push_back(line);
            poin.push_back(poinrand(generator));
        }
        cout << "Matriks permainan: " << endl;
        for(int i = 0; i < map_height; i++) {
            for(int j = 0; j < map_width; j++) {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Sequence: " << endl;
        for(int i = 0; i < kumpulankode.size(); i++) {
            for(int j = 0; j < kumpulankode[i].size(); j++) {
                cout << kumpulankode[i][j] << " ";
            }
            cout << endl;
            cout << poin[i] << endl;
        }
    }

    auto start = chrono::high_resolution_clock::now();
    // for (int i = 0; i < kumpulankode.size(); i++) {
    //     for(int j = 0; j < kumpulankode[i].size(); j++) {
    //         cout << kumpulankode[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    vector<int> num;
    vector<vector<int> > angka_penyusun;
    vector<vector<string> > sequence;
    // INPUT KE 1
    for (int i = 0; i < total_sequence; i++) {
        if(kumpulankode[i].size() <= buffer_size) {
            num = {};
            num.push_back(i);
            sequence.push_back(kumpulankode[i]);
            angka_penyusun.push_back(num);
        }
    }
    // cout << angka_penyusun.size();
    // cout << angka_penyusun[0]
    // Cek Angka Penyusun

    for (int i = 2; i <= total_sequence; i++) { // Membentuk digit sequence
        int kemungkinan_Sequences = sequence.size();
        for (int j = 0; j < kemungkinan_Sequences; j++) {
            for (int k = 0; k < kemungkinan_Sequences; k++) {
                bool sama = ceksama(angka_penyusun[j],angka_penyusun[k]);
                if (sama == true) {
                    vector<string> unionsequence = {};
                    vector<string> sequence1 = sequence[j];
                    vector<string> sequence2 = sequence[k];
                    vector<int> angka_penyusun1 = angka_penyusun[j];
                    vector<int> angka_penyusun2 = angka_penyusun[k];
                    vector<int> unionangka_penyusun = {};                    
                    for (int l = 0; l < sequence1.size(); l++) {
                        unionsequence.push_back(sequence1[l]);
                    }
                    for(int m = 0; m < sequence2.size(); m++) {
                        unionsequence.push_back(sequence2[m]);
                    }
                    for (int n = 0; n < angka_penyusun1.size(); n++) {
                        unionangka_penyusun.push_back(angka_penyusun1[n]);
                    }
                    for (int o = 0; o < angka_penyusun2.size(); o++) {
                        unionangka_penyusun.push_back(angka_penyusun2[o]);
                    }
                    int dupe = 0; 
                    for (int p = 0; p < sequence.size(); p++) {
                        if(unionsequence.size() == sequence[p].size()) {
                            bool duplicate = cekduplicatesequence(unionsequence, sequence[p]);
                            if (duplicate == true) {
                                dupe += 1;
                            }
                        }
                    }
                    if (dupe == 0 and unionsequence.size() <= buffer_size) {
                        sequence.push_back(unionsequence);
                        angka_penyusun.push_back(unionangka_penyusun);
                    }

                    // Kemungkinan terjadi interse
                    vector<vector<string> > shortener = intersection(sequence1,sequence2);
                    for (int a = 0; a < shortener.size(); a++) {
                        if(shortener[a].size() <= buffer_size) {
                            sequence.push_back(shortener[a]);
                            angka_penyusun.push_back(unionangka_penyusun);
                        }
                    }
                }
            }
        }
    }

    vector<int> kumpulanpoin;
    for(int i = 0; i < angka_penyusun.size(); i++) {
        int skor = 0;
        for(int j = 0; j < angka_penyusun[i].size(); j++) {
            skor += poin[angka_penyusun[i][j]];
        }
        kumpulanpoin.push_back(skor);
    }

    // Sort anggota
    for(int i = 0; i < sequence.size(); i++) {
        for(int j = i+1; j < sequence.size(); j++) {
            vector<string> tempseq;
            int tempint;
            if(kumpulanpoin[j] > kumpulanpoin[i]) {
                tempseq = sequence[i];
                sequence[i] = sequence[j];
                sequence[j] = tempseq;
                tempint = kumpulanpoin[i];
                kumpulanpoin[i] = kumpulanpoin[j];
                kumpulanpoin[j] = tempint;
            }
            else if(kumpulanpoin[i] == kumpulanpoin[j]) {
                if(sequence[i].size() > sequence[j].size()) {
                    tempseq = sequence[i];
                    sequence[i] = sequence[j];
                    sequence[j] = tempseq;
                    tempint = kumpulanpoin[i];
                    kumpulanpoin[i] = kumpulanpoin[j];
                    kumpulanpoin[j] = tempint;
                }
            }
        }
    }


    // Mencari langkah paling optimal
    bool found = false;
    int row = 0;
    vector<int> step;
    vector<int> buntu;
    vector<vector<int> > jejakkaki;
    int i = 0;
    // Ex : sequence ada 4
    while (found == false and i < sequence.size()) {
        int row = 0;
        bool change = false;
        while (change == false and row < map_width) {
            vector<vector<vector<int> > > history;  //Menyimpan lagkah
            vector<vector<int> > jejak;
            vector<int> posisi = {0,0};
            for(int j = 0; j < sequence[i].size(); j++) {
                history.push_back({{-1,-1}});
            }
            posisi[1] = row;
            int idx = 0; // Banyaknya indeks yang telah diolah
            bool optimal = true; // Cek jalan buntu
            int ver = 0; // Mengetahui vertikal atau horizontal
            if(sequence[i][idx] == map[0][posisi[1]]) { // Error ketika row == elemen
                idx += 1;
                jejak.push_back({0,row});
            }
            while (optimal == true and idx < sequence[i].size()) {
                if(ver % 2 == 0) {
                    for(int start = 0; start < map.size(); start++) {
                        if(sequence[i][idx] == map[start][posisi[1]] and checkhistory(start,posisi[1],history,idx) and start != posisi[0]) {
                            idx += 1;
                            ver += 1;
                            posisi[0] = start;
                            jejak.push_back(posisi);
                            break;
                        }
                        else if(ver == 0  and (sequence[i][idx] != map[start][posisi[1]] or checkhistory(start,posisi[1],history,idx) == false) and start == map.size()-1) {
                            optimal = false;
                        }
                        else if((sequence[i][idx] != map[start][posisi[1]] or checkhistory(start,posisi[1],history,idx == false)) and start == map.size()-1) { //Error
                            if(idx == 0) {
                                optimal = false;
                                break;
                            }
                            history[idx-1].push_back(posisi);
                            // cetakhistory(history);
                            idx -= 1;
                            ver -= 1;
                            jejak.pop_back();
                            posisi = jejak[idx];
                            break;
                        }
                    }
                }
                else if(ver % 2 == 1) {
                    for(int start = 0; start < map.size(); start++) {
                        // cout << start << " " << map[0].size() << endl;
                        // cout << idx << endl;
                        if(sequence[i][idx] == map[posisi[0]][start] and checkhistory(posisi[0],start,history,idx) and start != posisi[1]) {
                            idx += 1;
                            ver += 1;
                            posisi[1] = start;
                            jejak.push_back(posisi);
                            break;
                        }
                        else if(ver == 0  and (sequence[i][idx] != map[posisi[0]][start] or checkhistory(posisi[0],start,history,idx) == false) and start == map[0].size()-1) {
                            optimal = false;
                        }
                        else if((sequence[i][idx] != map[posisi[0]][start] or checkhistory(posisi[0],start,history,idx) == false) and start == map[0].size()-1) {
                            if(idx == 0) {
                                optimal = false;
                                break;
                            }
                            else {
                                history[idx-1].push_back(posisi);
                                // cetakhistory(history);
                                idx -= 1;
                                ver -= 1;
                                jejak.pop_back();
                                posisi = jejak[idx];
                                break;
                            }
                        }
                        // else if(start == map[0].size()-1) {
                        //     cout << posisi[0] << " " << start << endl;
                        //     cout << (checkhistory(posisi[0],start,history,idx) == false) << endl;
                        // }
                    }
                }
                if(idx == sequence[i].size() and kumpulanpoin[i] > max) {
                    found = true;
                    change = true;
                    max = kumpulanpoin[i];
                    cout << "Poin maksimal " << kumpulanpoin[i] << endl;
                    finalkode = sequence[i];
                    jejakkaki = jejak;
                }    
            }
            row += 1;
        }
        i += 1;
    }

    auto end = chrono::high_resolution_clock::now();
    double elapsed_time_ms = chrono::duration<double, milli>(end - start).count();

    if(max == 0) {
        cout << "Poin maksimal " << max << endl;
        cout << endl;
    }
    for(int i = 0; i < finalkode.size(); i++) {
        cout << finalkode[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < jejakkaki.size(); i++) {
        cout << jejakkaki[i][1]+1 << ", " << jejakkaki[i][0]+1 << endl;
    }
    cout << time << " ms" << endl;
    char yorn;
    cout << "Apakah ingin disimpan di file txt? (y/n) ";
    cin  >> yorn;
    if(yorn == 'y') {
        string pathinput = "../test/";
        string fileinput;
        cout << "Masukkan nama file: ";
        cin >> fileinput;
        pathinput += fileinput;
        ofstream infile;
        infile.open(pathinput);
        infile << max << "\n";
        for(int i = 0; i < finalkode.size(); i++) {
            infile << finalkode[i] << " ";
        }
        infile << "\n";   
        for (int i = 0; i < jejakkaki.size(); i++) {
            infile << jejakkaki[i][1] + 1 << ", " << jejakkaki[i][0] + 1;
            infile << "\n";
        }
        infile << time << " ms";
    }

    // yang kurang:
    // Titik yang dilalui
    //  Random
    // Waktu
    return 0;
}
