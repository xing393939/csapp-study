<?php
$file = fopen("../cmake-build-debug/CMakeFiles/readelf.dir/elf/hello.c.o", "rb");

fseek($file, 40);

$sh_off = fread($file, 8);
$sh_off = unpack("P", $sh_off);
var_dump("section header offset in file: ", $sh_off);

?>