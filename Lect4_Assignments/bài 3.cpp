/*
 h(i) = (i+3) mod 17;
 a, Sử dụng Chaining

 h(1) = (1+3) mod 17 = 4 mod 17 = 4 ;
 ->Khóa 1 sẽ được băm vào vị trí 4.

 h(3) = (3+3) mod 17 = 6 mod 17 = 6;
  ->Khóa 3 sẽ được băm vào vị trí 6.

 h(18) = (18+3) mod 17 = 21 mod 17 = 4;
 ->Khóa 18 sẽ được băm vào vị trí 4(va chạm với 1).

 h(8) = (8+3) mod 17 = 11 mod 17 = 11 ;
  ->Khóa 8 sẽ được băm vào vị trí 11.

 h(23) = (23+3) mod 17 = 26 mod 17 =  9;
 ->Khóa 23 sẽ được băm vào vị trí 9.

 h(35) = (35+3) mod 17 = 38 mod 17 = 4;
 ->Khóa 35 sẽ được băm vào vị trí 4 (va chạm với 1 và 18).

 h(11) = (11+3) mod 17 = 14 mod 17 = 3;
  ->Khóa 11 sẽ được băm vào vị trí 3.

 h(36) = (36+3) mod 17 = 39 mod 17 = 5;
 ->Khóa 36 sẽ được băm vào vị trí 5.

 h(20) = (20+3) mod 17 = 23 mod 17 = 6;
 ->Khóa 20 sẽ được băm vào vị trí 6 (va chạm với 3).

 h(16) = (16+3) mod 17 = 19 mod 17 = 2;
 -> Khóa 16 sẽ được băm vào vị trí 2.

  Bảng băm:
Vị trí 0: Rỗng
Vị trí 1: Rỗng
Vị trí 2: 16
Vị trí 3: 11
Vị trí 4: 1 → 18 → 35
Vị trí 5: 36
Vị trí 6: 3 → 20
Vị trí 7: Rỗng
Vị trí 8: Rỗng
Vị trí 9: 23
Vị trí 10: Rỗng
Vị trí 11: 8
Vị trí 12: Rỗng
Vị trí 13: Rỗng
Vị trí 14: Rỗng
Vị trí 15: Rỗng
Vị trí 16: Rỗng

b,Sử dụng linear probing
 h(1) = (1+3) mod 17 = 4 mod 17 = 4 ;
 ->Vị trí 4 trống, khóa 1 vào vị trí 4.

 h(3) = (3+3) mod 17 = 6 mod 17 = 6;
  ->Vị trí 6 trống, khóa 3 vào vị trí 6.

 h(18) = (18+3) mod 17 = 21 mod 17 = 4;
 ->Vị trí 6 đã có khóa, kiểm tra vị trí 7. Vị trí 7 trống, khóa 18 vào vị trí 7. 

 h(8) = (8+3) mod 17 = 11 mod 17 = 11 ;
  ->Vị trí 11 trống, khóa 8 vào vị trí 11.

 h(23) = (23+3) mod 17 = 26 mod 17 =  9;
 ->Vị trí 9 trống, khóa 23 vào vị trí 9.

 h(35) = (35+3) mod 17 = 38 mod 17 = 4;
 ->Vị trí 4 đã có khóa, kiểm tra vị trí 5. Vị trí 5 trống, khóa 35 vào vị trí 5.

 h(11) = (11+3) mod 17 = 14 mod 17 = 3;
 ->Vị trí 3 trống, khóa 11 vào vị trí 3.

 h(36) = (36+3) mod 17 = 39 mod 17 = 5;
 ->Vị trí 5 đã có khóa, kiểm tra vị trí 6.Vị trí 6 đã có khóa, kiểm tra vị trí 7.
Vị trí 7 đã có khóa, kiểm tra vị trí 8. Vị trí 8 trống, khóa 36 vào vị trí 8.

 h(20) = (20+3) mod 17 = 23 mod 17 = 6;
 ->Vị trí 6 đã có khóa, kiểm tra vị trí 7.Vị trí 7 đã có khóa, kiểm tra vị trí 8.
Vị trí 8 đã có khóa, kiểm tra vị trí 9. Vị trí 9 đã có khóa, kiểm tra vị trí 10.
Vị trí 10 trống, khóa 20 vào vị trí 10.

 h(16) = (16+3) mod 17 = 19 mod 17 = 2;
 -> Vị trí 2 trống, khóa 16 vào vị trí 2.
  Bảng băm:
Vị trí 0: Trống 
Vị trí 1: Trống 
Vị trí 2: 16
Vị trí 3: 11
Vị trí 4: 1
Vị trí 5: 35
Vị trí 6: 3
Vị trí 7: 18
Vị trí 8: 36
Vị trí 9: 23
Vị trí 10: 20
Vị trí 12: Trống 
Vị trí 13: Trống 
Vị trí 14: Trống 
Vị trí 15: Trống 
Vị trí 16: Trống 

*/