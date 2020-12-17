<?php
$fp = fopen("../cmake-build-debug/CMakeFiles/readelf.dir/elf/hello.c.o", "rb");

fseek($fp, 40, SEEK_SET);
$sh_off = fread($fp, 8);
$sh_off = unpack("P", $sh_off);
var_dump("section header offset in file: ". $sh_off[1]);

fseek($fp, 10, SEEK_CUR);
$sh_ent_size = fread($fp, 2);
$sh_ent_size = unpack("v", $sh_ent_size);
var_dump("section header entry size: ". $sh_ent_size[1]);

$sh_num = fread($fp, 2);
$sh_num = unpack("v", $sh_num);
var_dump("section header number: ". $sh_num[1]);

$sh_strtab_index = fread($fp, 2);
$sh_strtab_index = unpack("v", $sh_strtab_index);
var_dump("section header string table index: ". $sh_strtab_index[1]);

fseek($fp, $sh_off[1] + $sh_strtab_index[1] * $sh_ent_size[1], SEEK_SET);
fseek($fp, 24, SEEK_CUR); //sh_name(4) + sh_type(4) + sh_flags(8) + sh_addr(8) = 24
$str_table_off = fread($fp, 8);
$str_table_off = unpack("P", $str_table_off);
var_dump("section name string table offset: ". $str_table_off[1]);

$str_table_size = fread($fp, 8);
$str_table_size = unpack("P", $str_table_size);
var_dump("section name string table size: ". $str_table_size[1]);

fseek($fp, $str_table_off[1], SEEK_SET);
$str = fread($fp, $str_table_size[1]);
var_dump(explode(".", $str));
?>