# Soal Praktikum 2 Kelas C
## Daftar Isi
- [Ayah dan Anak - AA](#ayah-dan-anak)
- [Mainan Ardi - Auto A](#mainan-ardi)
- [Depth Pohon - DP](#depth-pohon)
- [Tinggal Copas Aja II - TCA2](#tinggal-copas-aja-ii)

## Ayah dan Anak

Time Limit 1 seconds
Memory Limit 64 MB

Phan sedang mempelajari tentang Binary Search Tree tetapi ia masih sering tertukar Antara parent dan child. Bantulah phan mengidentifikasi mana parent dan mana child dari suatu node pada sebuah BST 

#### Format Masukan 
Baris pertama berisi sebuah bilangan Q yang merupakan banyak query. 

Q baris selanjutnya berisi salah satu dari 2 tipe query yaitu: 

“1 K” yang berarti bilangan K dimasukkan ke dalam BST
 
“2 s X” jika s adalah pertanyaan yang seperti dijelaskan di deskripsi. Nilai X pasti ada di dalam BST

#### Format Keluaran 
Untuk setiap query tipe 2, jika s adalah “child” keluarkan 2 buah bilangan yang dipisahkan spasi “A B” dengan A adalah nilai yang menjadi anak kiri dan B adalah nilai yang menjadi anak kanan, jika tidak ada keluarkan “NULL”. Jika s adalah “parent”, keluarkan parent dari node dengan nilai X. Jika X merupakan root, keluarkan -1. 

#### Contoh Masukan 
```c
6 
1 2 
1 1 
1 3 
2 child 1 
2 child 2 
2 parent 3 
```

#### Contoh Keluaran 
```c
NULL NULL 
1 3 
2 
```

#### Constraints 
1 ≤ Q ≤ 1000 \
1 ≤ K ≤ 10^5

## Mainan Ardi

Time Limit 1 seconds
Memory Limit 64 MB

Ardi memiliki N buah mainan. Setiap mainannya diletakkan dalam setiap kotak yang diberi nomor 1 sampai N yang dia susun dari kiri ke kanan. Setiap kali ia ingin bermain bersama temantemannya, ardi akan memilih mainan yang berada di Antara kotak L sampai R yang memiliki harga tertinggi.
 
Tetapi, terkadang terjadi perubahan harga untuk mainan-mainan tersebut. Bantulah Ardi memilih mainan mana yang harus ia bawa. 

#### Input Format 
Baris pertama berisi dua buah bilangan N dan Q yang merupakan banyaknya mainan serta query. 

Baris berikutnya berisi N buah bilangan Ai dimana Ai merupakan harga dari mainan ke-i 

Q baris berikutnya berisi salah satu dari 2 tipe query:

“1 X K” yang berarti harga mainan yang berada pada kotak ke-X berubah menjadi K
 
“2 L R” yang berarti Ardi akan memilih mainan yang berada pada rentang L sampai R 

#### Output Format 
Untuk setiap query tipe 2, keluarkan sebuah bilangan yang merupakan harga maksimal dari mainan yang berada pada rentang L sampai R 

#### Sample Input 
```c
5 3 
1 2 3 4 5 
2 2 4 
1 3 5 
2 2 4 
```

#### Sample Output 
```c
4
5
```

#### Constraints 
1 ≤ N,Q ≤ 10^5 \
1 ≤ L ≤ R ≤ 10^5

## Depth Pohon

Time Limit 1 seconds
Memory Limit 64 MB

Diberikan sebuah Binary Search Tree, tentukan jumlah dari kedalaman 2 node dengan kedalaman terbesar pada tree tersebut tersebut setiap kali sebuah data dimasukkan.
 
Kedalaman sebuah node adalah jarak node tersebut dari root. 

#### Input Format 
Baris pertama berisi sebuah bilangan Q yang merupakan banyaknya data yang akan dimasukkan
 
Q baris selanjutnya berisi sebuah bilangan X yang akan dimasukkan ke dalam BST. 

Proses memasukan bilangan berurut sesuai urutan masukan 

#### Output Format
Keluarkan Q baris bilangan dimana baris ke-i merupakan jumlah dari kedalaman 2 node dengan kedalaman maksimal setelah data ke-i dimasukkan. Jika hanya terdapat 1 node, keluarkan 0. 

#### Sample Input 
```c
5 
3 
1 
2 
4 
5 
```

#### Sample Output 
```c
0 
1 
2 
3
4
```

#### Constraints 
1 ≤ Q ≤ 100 \
1 ≤ X ≤ 10^5

## Tinggal Copas Aja II

Time Limit 1 seconds
Memory Limit 64 MB
Phan saat ini sedang belajar tentang Binary Search Tree. Lalu ia menemukan artikel tentang metode traversal pada sebuah BST yaitu PreOrder Traversal,PostOrder Traversal dan InOrder Traversal. Karena penasaran, ia pun mencoba membuat program untuk mengetahui urutan ke-x untuk suatu traversal.
 
Tapi, karena ia belum lancer ngoding, ia selalu gagal untuk menghasilkan output yang diinginkan. Bantulah Phan untuk membuat program tersebut 

#### Format Masukan 
Baris pertama berisi sebuah bilangan Q yang merupakan banyaknya query 

Q baris selanjutnya berisi salah satu dari 2 tipe query yaitu : 

“1 K” yang berarti bilangan K dimasukkan kedalam BST
 
“2 s X” yang berarti program harus mencetak bilangan pada urutan ke X dalam traversal s. Dijamin ukuran tree pada saat itu <= X 

#### Format 
Keluaran Untuk setiap query dengan tipe 2, keluarkan sebuah bilangan sesuai dengan deskripsi soal. 

#### Contoh Input 
```c
6 
1 2 
1 1 
1 3 
2 inorder 2 
2 preorder 3 
2 postorder 1 
```

#### Contoh Output
```c
2 3 1 
```

#### Constraints 
1 ≤ Q ≤ 1000 \
1 ≤ K ≤ 10^5
