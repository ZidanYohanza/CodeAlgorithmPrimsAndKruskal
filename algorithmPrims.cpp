#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999

// jumlah simpul dalam grafik
#define V 9

// membuat array 2d ukuran 9x9
// untuk matriks adjacenckolom untuk mewakili grafik

int graph[V][V] = { { 0, 4, 9, 0, 0, 0, 0, 0, 0  },
				    { 4, 0, 11, 0, 8, 0, 0, 0, 0 },
                    { 9, 11, 0, 7, 0, 1, 0, 0, 0 },
                    { 0, 0, 7, 0, 2, 6, 0, 0, 0  },
                    { 0, 8, 0, 2, 0, 0, 7, 4, 0  },
                    { 0, 0, 1, 6, 0, 0, 0, 2, 0  },
                    { 0, 0, 0, 0, 7, 0, 0, 14, 9 },
                    { 0, 0, 0, 0, 4, 2, 14, 0, 10},
                    { 0, 0, 0, 0, 0, 0, 9, 10, 0 } 
                };

int main() {
    int no_edge;  // jumlah sisi

    // buat array untuk melacak simpul yang dipilih
    // pemilihan akan menjadi benar jika tidak salah
    int key[V];

    // inisiasi false yang dipilih pada awalnya
    memset(key, false, sizeof(key));

    // inisiasi jumlah tepi ke 0
    no_edge = 0;

    // jumlah sisi dalam MST akan 
    // selalu lebih kecil dari (V -1), dimana V adalah jumlah simpul dalam 
    //grafik

    // pilih simpul ke-0 dan jadikan itu benar
    key[0] = true;

    int baris;  //  Baris
    int kolom;  //  Kolom

    // print for edge and weight
    cout << "Sisi" << " : " << "Bobot" << endl;

    while (no_edge < V - 1) {
        //Untuk setiap simpul di himpunan S, temukan semua simpul yang bertetangga
        // , hitung jarak dari simpul yang dipilih pada langkah 1.
        // jika vertex sudah ada di set S, buang jika tidak
        //pilih simpul lain yang terdekat dengan simpul terpilih pada langkah 1.

        int min = INF;
        baris = 0;
        kolom = 0;

        for (int i = 0; i < V; i++) {
            if (key[i]) {
                for (int j = 0; j < V; j++) {
                    if (!key[j] && graph[i][j]) {  // tidak dipilih dan ada sisi
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            baris = i;
                            kolom = j;
                        }
                    }
                }
            }
        }
        cout << baris << " - " << kolom << " :  " << graph[baris][kolom];
        cout << endl;
        key[kolom] = true;
        no_edge++;
    }

    return 0;
}