// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Fungsi untuk membuat set graf tanpa cycle
 *        DSU --> Disjoint Set Data
 * 
 */
class DSU {
    // Pointer ke node parent dari node
    // Jika Minus 
    //      Minus menandakan bahwa ia adalah parent
    //      Angka mennunjukan jumlah elemen dalam subset yang merujuk ke elemen tersebut sebagai parent
    // Jika Positif
    //      Angka menunjukan parent rujukan
	int* parent;
    // Menentukan tingkat kedalaman dalam subset
    // Makin besar rank, makin dalam node
	int* rank;

    public:
        DSU(int n) {
            parent = new int[n];
            rank = new int[n];

            for (int i = 0; i < n; i++) {
                // Assign awal bahwa masing2 elemen menjadi subset tersendiri
                parent[i] = -1;
                // Assign awal bahwa rank atau kedalaman masing2 subset adalah 1
                rank[i] = 1;
            }
        }

        /**
         * @brief Tentukan di subset mana elemen tertentu berada. Ini dapat digunakan untuk menentukan apakah dua elemen berada di subset yang sama.
         * 
         * @param i 
         * @return int 
         */
        int find(int i) {
            if (parent[i] == -1)
                return i;

            return parent[i] = find(parent[i]);
        }

        /**
         * @brief Menggabungkan dua buah subset
         * 
         * @param x 
         * @param y 
         */
        void unite(int x, int y) {
            int s1 = find(x);
            int s2 = find(y);

            if (s1 != s2) {
                if (rank[s1] < rank[s2]) {
                    parent[s1] = s2;
                }
                else if (rank[s1] > rank[s2]) {
                    parent[s2] = s1;
                }
                else {
                    parent[s2] = s1;
                    rank[s1] += 1;
                }
            }
        }
};

class Graph {
	vector<vector<int> > edgelist;
    // Jumlah vertex
	int V;

    public:
        Graph(int V) { 
            this->V = V; 
        }

        /**
         * @brief Menambahkan daftar edge dalam vector
         * 
         * @param x node 1
         * @param y node 2
         * @param w cost edge
         */
        void addEdge(int x, int y, int w) {
            edgelist.push_back({ w, x, y });
        }

        /**
         * @brief Algoritma kruskal
         * 
         */
        void kruskals_mst() {
            int ans = 0;
            
            // Inisiasi pembuatan DSU
            DSU s(V);

            // Sort semua edge yang ada dari terkecil ke terbesar
            sort(edgelist.begin(), edgelist.end());

            cout << "Edges yang terbentuk sebagai MST :\n";

            for (auto edge : edgelist) {
                int w = edge[0];
                int x = edge[1];
                int y = edge[2];

                /**
                 * @brief Masukkan edge tersebut ke MST jika tidak menghasilkan cycle subset    
                 */
                // Jika parent utama kedua elemen berbeda, artinya kedua elemen berada di subset yang berbeda
                if (s.find(x) != s.find(y)) {
                    // Maka lakukan union kedua subset
                    s.unite(x, y);
                    ans += w;
                    cout << x << " -- " << y << " == " << w << endl;
                }
            }
            cout << "Minimum Cost Spanning Tree : " << ans;
        }
};

int main() {
	Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 7);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 4, 6);
    g.addEdge();
    g.addEdge();
    g.addEdge();
    g.addEdge();


	// Function call
	g.kruskals_mst();

	return 0;
}
