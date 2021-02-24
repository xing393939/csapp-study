<link rel="stylesheet" href="../extra/ideal-image-slider.css">
<link rel="stylesheet" href="../extra/ideal-default-theme.css">
<script src="../extra/ideal-image-slider.js"></script>
<script src="../extra/ideal-iis-bullet-nav.js"></script>
<script>
let gitbook = gitbook || [];
gitbook.push(function() {
    let slider = new IdealImageSlider.Slider('.IdealImageSlider');
    slider.addBulletNav();
});
</script>

### 汇编指令对应的十六进制表示

#### 参考资料
1. [Intel Pentium Instruction Set Reference](https://eun.github.io/Intel-Pentium-Instruction-Set-Reference)

#### CSAPP上p482的代码示例
```c
00000000004004d0 <main>:
4004d0: 48 83 ec 08     sub $0x8,%rsp
4004d4: be 02 00 00 00  mov $0x2,%esi
4004d9: bf 18 10 60 00  mov $0x601018,%edi
4004de: e8 05 00 00 00  callq 4004e8 <sum>
4004e3: 48 83 c4 08     add $0x8,%rsp
4004e7: c3              retq
00000000004004e8 <sum>:
4004e8: b8 00 00 00 00  mov $0x0,%eax
4004ed: ba 00 00 00 00  mov $0x0,%edx
4004f2: eb 09           jmp 4004fd <sum+0x15>
4004f4: 48 63 ca        movslq %edx,%rcx
4004f7: 03 04 8f        add (%rdi,%rcx,4),%eax
4004fa: 83 c2 01        add $0x1,%edx
4004fd: 39 f2           cmp %esi,%edx
4004ff: 7c f3           jl 4004f4 <sum+0xc>
400501: f3 c3           repz retq
```

#### 常见的汇编命令
| 描述 | 指令 |
| ---  | --- |
|jmp + 32位立即数 |E9 + Imm|
|jmp + 内存地址   |FF25 + 0x8d8d3a| 
|call + 32位立即数|E8 + Imm|
|push + 32位立即数|68 + Imm|
|push %rbp       |55      |
|retq            |C3      |




