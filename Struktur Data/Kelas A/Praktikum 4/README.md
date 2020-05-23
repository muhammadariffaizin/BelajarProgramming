# Soal Praktikum 4 Kelas A
## Daftar Isi
- [Altitudo Finita Quaerere](#altitudo-finita-quaerere)
- [Berkeliling Perumahan Syeky](#berkeliling-perumahan-syeky)
- [Flow Free](#flow-free)
- [Jarak Terjauh](#jarak-terjauh)

## Altitudo Finita Quaerere
Kucnaj kehabisan ide untuk membuat game. Ia teringat akan assignment nya di minggu ke-4 semester ini. Dia tidak tahu apakah soal yang akan dibuatnya sulit atau tidak, namun dia yakin soal ini akan menjadi sneak peek bagus untuk Kecerdasan Buatan.

Terdapat sebuah weighted undirected graph dengan V vertex dan E edge. Kalian disuruh menghitung jarak dari titik X ke semua titik V dengan batas kedalaman L. Apabila ditemukan jarak yang lebih pendek dari sebelumnya, maka keluarkan jarak yang lebi pendek tersebut. Bila tidak ditemukan jalan, maka keluarkan "INFINITY".

#### Input Format
Pada baris pertama, masukkan V. Kemudian baris selanjutnya masukkan E.

Untuk E baris berikutnya, masukkan Vi, Vj, dan W.

Pada baris terakhir, masukkan X dan L. 

#### Sample Input 1
```
8 
9 
0 1 1 
0 3 6 
0 4 7 
1 3 4 
1 5 3 
2 4 7 
2 5 6 
2 6 5 
5 7 3 
0 2 
```

#### Sample Input 2
```
8 
9 
0 1 1 
0 3 6 
0 4 7 
1 3 4 
1 5 3 
2 4 7 
2 5 6 
2 6 5 
5 7 3 
0 3
```

#### Constraints
* 1 < V <= 32
* 1 < E <= V*V / 2
* L <= V

#### Output Format
Output berupa daftar Vertex dan jaraknya dari titik X diakhiri dengan endline. 

#### Sample Output 1
```
0 0 
1 1 
2 14 
3 5 
4 7 
5 4 
6 INFINITY 
7 INFINITY 
```

#### Sample Output 2
```
0 0 
1 1 
2 10 
3 5 
4 7 
5 4 
6 INFINITY 
7 7
```

## Berkeliling Perumahan Syeky
Yaisyeky akan mengunjungi semua rumah dalam kompleks perumahannya. Namun, ada beberapa aturan yang harus dia tepati:
1. Yaisyeky hanya dapat bergerak dari satu rumah ke rumah yang lain jika terdapat jalan di antaranya.
2. Apabila jalan tersebut tidak memperbolehkan Yaisyeky untuk menyeberang, maka Yaisyeki tidak dapat mengambil jalan tersebut.
3. Yaisyeky harus mengunjungi semua tetangga rumah yang sedang ia tempati sebelum berkunjung ke tetangga dari tetangga rumah tersebut. Sehingga ia perlu berjalan kembali ke rumah sebelumnya ketika dia bergerak ke rumah baru
4. Aturan 3 tidak mempedulikan aturan 2.

Bila dalam kompleks rumah tersebut terdapat V rumah dan E jalan, tampilkan urutan perjalanan Yaisyeki dari titik X ke semua titik V selain X jika memungkinkan.

#### Input Format
Pada baris pertama, masukkan V (banyak kota).

Pada baris kedua, masukkan E (banyak jalan).

Untuk E baris berikutnya, masukan Vi dan Vj.

Pada baris terakhir, masukkan X (titik start). 

#### Sample Input 1
```
8 
8 
0 1 
0 2 
1 2 
1 3 
2 3 
2 5 
3 4 
7 6 
0 
```

#### Sample input 2
```
8 
8 
0 1 
0 2 
1 2 
1 3 
2 3 
2 5 
3 4 
7 6 
6
```

#### Constraints
* 1 < V < 20
* 0 < E < V*V

#### Output Format
Keluarkan urutan perjalanan berupa index dari V dimulai dari index X. Tiap index dihubungkan dengan "->" dan index terakhir dihubungkan dengan "-> END" beserta endline. 

#### Sample Output 1
```
0 -> 1 -> 2 -> 3 -> 5 -> 4 -> END 
```

#### Sample Output 2
```
6 -> END
```

## Flow Free
![FF](img/FF.png)

Flow free adalah sebuah game puzzle yang tersedia di berbagai platform mobile. Maryo sebagai seorang gamer idaman nan sejati ingin menjadi master dalam game ini. Dalam perjalanannya menamatkan game ini, maryo yang gabut pun menyadari bahwa game ini bisa ditamatkan secara otomatis menggunakan sebuah program. Bantu maryo membuat program untuk menamatkan game ini!

#### Input Format
Array berukuran 5x5 berupa puzzle yang harus diselesaikan berisi  warna.

#### Constraints
* 1 < n <=5

#### Output Format
Array berisi puzzle yang sudah diselesaikan

#### Sample Input 0
```
XXX12 
X342X 
XXXXX 
XXXX4 
XX1X3
```

#### Sample Output 0
```
11112 
13422 
13444 
13334 
11133
```

#### Explanation 0
1,2,3,4 Merupakan titik-titik awal masing-masing warna. X merupakan ruang kosong pada puzzle.

## Jarak Terjauh
Luzi sangat suka sekali berlari. Untuk mengisi waktu luangnya dia pun mencari rute terjauh untuk latihan larinya. Dia akan memberikan titik-titik jalan yang kemungkinan akan dia lewati. Bantulah dia untuk mencari rute dengan jarak tempuh terjauh.

#### Input Format
Baris Pertama adalah T

T adalah banyaknya jumlah vertex yang ada.

Kemudian berikutnya adalah vertex dan tetangganya.

#### Constraints
* 0 < T < 100

#### Output Format
```
2
```

#### Sample Input 0
```
3 
1 2 
2 3
```

#### Sample Output 0
```
2
```
