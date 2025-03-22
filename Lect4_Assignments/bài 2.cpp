/* 
 h(i) = (2i+5) mod 11; 
 a, Sử dụng Chaining 

 h(12) = (2*12+5) mod 11 = 29 mod11 = 7 ;
 ->Khóa 12 sẽ được băm vào vị trí 7.

 h(44) = (2*44+5) mod 11= 93 mod 11 = 5;
  ->Khóa 44 sẽ được băm vào vị trí 5.

 h(13) = (2*13+5) mod 11= 31 mod 11 = 9;
 ->Khóa 13 sẽ được băm vào vị trí 9.

 h(88) = (2*88+5) mod 11= 181 mod 11 = 5;
  ->Khóa 88 sẽ được băm vào vị trí 5 (va chạm với 44).

 h(23) = (2*23+5) mod 11= 51 mod 11 =  7;
 ->Khóa 23 sẽ được băm vào vị trí 7 (va chạm với 12).

 h(94) = (2*94+5) mod 11= 193 mod 11 = 6;
 ->Khóa 94 sẽ được băm vào vị trí 6.

 h(11) = (2*11+5) mod 11= 27 mod 11 = 5;
  ->Khóa 11 sẽ được băm vào vị trí 5 (va chạm với 44 và 88).

 h(39) = (2*39+5) mod 11= 83 mod 11 = 6;
 ->Khóa 39 sẽ được băm vào vị trí 6 (va chạm với 94).

 h(20) = (2*20+5) mod 11= 45 mod 11 = 1;
 ->Khóa 20 sẽ được băm vào vị trí 1

 h(16) = (2*16+5) mod 11= 37 mod 11 = 4;
 -> Khóa 16 sẽ được băm vào vị trí 4.

 h(5) = (2*5+5) mod 11= 15 mod 11 = 4;
 -> Khóa 5 sẽ được băm vào vị trí 4 (va chạm với 16).
 
  Bảng băm:
Vị trí 0: Rỗng
Vị trí 1: 20
Vị trí 2: Rỗng
Vị trí 3: Rỗng
Vị trí 4: 16 → 5
Vị trí 5: 44 → 88 → 11
Vị trí 6: 94 → 39
Vị trí 7: 12 → 23
Vị trí 8: Rỗng
Vị trí 9: 13
Vị trí 10: Rỗng


b,Sử dụng linear probing

h(12) = (2*12+5) mod 11 = 29 mod11 = 7 ;
 ->Vị trí 7 trống, khóa 12 vào vị trí 7.

 h(44) = (2*44+5) mod 11= 93 mod 11 = 5;
  ->Vị trí 5 trống, khóa 44 vào vị trí 5.

 h(13) = (2*13+5) mod 11= 31 mod 11 = 9;
 ->Vị trí 9 trống, khóa 13 vào vị trí 9.

 h(88) = (2*88+5) mod 11= 181 mod 11 = 5;
  ->Vị trí 5 đã có khóa, kiểm tra vị trí 6, vị trí 6 trống, khóa 88 vào vị trí 6.

 h(23) = (2*23+5) mod 11= 51 mod 11 =  7;
 ->Vị trí 7 đã có khóa, kiểm tra vị trí 8, vị trí 8 trống, khóa 23 vào vị trí 8.

 h(94) = (2*94+5) mod 11= 193 mod 11 = 6;
 ->Vị trí 6 đã có khóa, kiểm tra vị trí 7, vị trí 7 đã có khóa, kiểm tra vị trí 8, vị trí 8 đã có khóa,
 kiểm tra vị trí 9, vị trí 9 đã có khóa, kiểm tra vị trí 10 vị trí 10 trống, khóa 88 vào vị trí 10.

 h(11) = (2*11+5) mod 11= 27 mod 11 = 5;
  ->Vị trí 5 đã có khóa, kiểm tra vị trí 6, vị trí 6 đã có khóa, kiểm tra tiếp vị trí 7, vị trí 7 đã có khóa, kiểm tra tiếp vị trí 8,
  vị trí 8 đã có khóa, kiểm tra tiếp vị trí 9. Vị trí 9 đã có khóa, kiểm tra tiếp vị trí 10. Vị trí 10 đã có khóa, kiểm tra tiếp vị trí 0.
  Vị trí 0 trống, khóa 11 vào vị trí 0.

 h(39) = (2*39+5) mod 11= 83 mod 11 = 6;
 ->Vị trí 6 đã có khóa, kiểm tra tiếp vị trí 7. Vị trí 7 đã có khóa, kiểm tra tiếp vị trí 8. 
 Vị trí 8 đã có khóa, kiểm tra tiếp vị trí 9. Vị trí 9 đã có khóa, kiểm tra tiếp vị trí 10. 
 Vị trí 10 đã có khóa, kiểm tra tiếp vị trí 0. Vị trí 0 đã có khóa, kiểm tra tiếp vị trí 1. 
 Vị trí 1 trống, khóa 39 vào vị trí 1.

 h(20) = (2*20+5) mod 11= 45 mod 11 = 1;
 ->Vị trí 1 đã có khóa, kiểm tra tiếp vị trí 2. Vị trí 2 trống, khóa 20 vào vị trí 2.

 h(16) = (2*16+5) mod 11= 37 mod 11 = 4;
 -> Vị trí 4 trống, khóa 16 vào vị trí 4.

 h(5) = (2*5+5) mod 11= 15 mod 11 = 4;
 ->Vị trí 4 đã có khóa, kiểm tra tiếp vị trí 5. Vị trí 5 đã có khóa, kiểm tra tiếp vị trí 6.
 Vị trí 6 đã có khóa, kiểm tra tiếp vị trí 7. Vị trí 7 đã có khóa, kiểm tra tiếp vị trí 8.
 Vị trí 8 đã có khóa, kiểm tra tiếp vị trí 9. Vị trí 9 đã có khóa, kiểm tra tiếp vị trí 10.
 Vị trí 10 đã có khóa, kiểm tra tiếp vị trí 0. Vị trí 0 đã có khóa, kiểm tra tiếp vị trí 1.
 Vị trí 1 đã có khóa, kiểm tra tiếp vị trí 2. Vị trí 3 trống, khóa 5 vào vị trí 3.

  Bảng băm:
Vị trí 0: 11
Vị trí 1: 39
Vị trí 2: 20
Vị trí 3: 5
Vị trí 4: 16
Vị trí 5: 44
Vị trí 6: 88
Vị trí 7: 12
Vị trí 8: 23
Vị trí 9: 13
Vị trí 10: 94
*/