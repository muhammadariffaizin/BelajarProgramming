# Soal Praktikum 2
## Daftar Isi
- [Boboiboy Bangkrut](#boboiboy-bangkrut)
- [Gaboleh Sama](#gaboleh-sama)
- [Kampina Kombinasi](#kampina-kombinasi)
- [Sultan Arif](#sultan-arif)

## Boboiboy Bangkrut
| Time Limit | Memory Limit |
|---|:---|
| 0.001 seconds	| 8 MB |

Kokoa Tok Aba sudah aman dari Adudu karena sudah bisa diorder lewat grab. Sekarang,  setelah menghabiskan waktunya sibuk melawan alien berkepala kotak, Boboiboy berada pada kondisi dimana dia tidak memiliki pendidikan dan skill penting yang bisa dipakai untuk mencari kerja. Akhirnya, setelah putus asa mencari pekerjaan, Boboiboy memilih untuk menggunakan kekuatan gempanya untuk menjadi kontraktor. 

Karena kelaparan tidak bisa makan karena nggak punya kerja, Boboiboy hanya bisa melakukan kekuatan gempanya sebanyak N kali dalam sehari. Selain jumlahnya terbatas, Boboiboy juga terbatas dalam pengendaliannya. Ketika kekuatannya berjalan, dia hanya bisa menaikkan tanah setinggi C, dari tanah meter ke A, sampai tanah meter ke B. Bayangkan tanah merupakan garis dalam bidang dua dimensi dimana sebagian garis dari A sampai B ini bisa bertambah tinggi tergantung oleh C. 
Sebagai kontraktor, klien akan menanyakan apakah Boboiboy bisa membuat tanah setinggi X sepanjang Y pada hari itu. 
Jangan lupa set isi array jadi 0. 

#### Input Format 
Baris pertama merupakan T, menentukan banyaknya testcase. pada setiap T,
baris pertama berisikan N, X, dan Y.
pada setiap N, akan diberikan A, B dan C. 

#### Output Format 
"Akhirnya makan" ketika permintaan klien terpenuhi 
"Sial kelaparan" ketika tidak. (semua output tanpa tanda ") 
#### Sample Input
```c
2 
3 5 3 
1 5 2 
2 9 3 
1 5 0 
3 5 3 
1 5 2 
2 9 3 
1 5 1 
```

#### Sample Output
```c
Akhirnya makan 
Sial kelaparan
```

#### Explanation 

Testcase 1 
awalnya tanah berbentuk seperti ini 
```c
0_ _ _ _ _ _ _ _ _ ... _ 
 0 1 2 3 4 5 6 7 9 ... 10^5 -1   
lalu menjadi seperti ini 
5      _ _ _ 
4 
3    _       _ _ _ 
2  _ 
1       
0_                 ... _ 
 0 1 2 3 4 5 6 7 9 ... 10^5 -1 
```
karena ada tanah setinggi 5 dan sepanjang 3, Boboiboy bisa makan 

Testcase 2 
awalnya tanah berbentuk seperti ini 
```c
0_ _ _ _ _ _ _ _ _ ... _ 
 0 1 2 3 4 5 6 7 9 ... 10^5 - 1   
lalu menjadi seperti ini 
6      _ _ _
5        
4    _ 
3            _ _ _ 
2  
1       
0_                 ... _ 
 0 1 2 3 4 5 6 7 9 ... 10^5 - 1 
```
karena tidak ada tanah setinggi 5 dan sepanjang 3, Boboiboy kelaparan 

#### Constraints 
1 ≤ T ≤ 20 
1 ≤ N ≤ 100 
0<=A<B<10^5 - 1 
0<=X,Y,C<=10^3

## Gaboleh Sama

## Kampina Kombinasi

## Sultan Arif
