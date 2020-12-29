### CSAPP深入理解计算机系统·CSDN

#### 第二章：信息的表示和处理
1. 三种最常用的表示数字的方法：
  * unsigned无符号整型
  * two's-complement，2的补码
    1. 1的补码——反码，例如+1是0000 0001，-1就是1111 1110。这种表示法，0有两个形式：0000 0000和1111 1111。范围是（-127~127）
    1. 2的补码——补码，在1的补码的基础上，把-0的位置给-1，多了一个位置给-128。范围是（-128~127）
  * 浮点型：2为基的科学记数法，用以表示实数
1. bit-level operations in C：
  * 与 &
  * 或 |
  * 非 ~
  * 异或 ^：两个一真一假时为真
1. logical operations in C:
  * 与 &&
  * 或 ||
  * 非 ! 
1. shift operations in C：
  * 左移时右边补0
  * 右移分为两种情况：
    1. 逻辑右移：即右移时左边补零；
    1. 算数右移：即右移时左边补最高位的值。

#### 第三章：机器级的代码表示
1. leaq，类似mov，但是不引用源操作数寄存器的值
1. 位的运算
  * addq Src, Dest	//Dest = Dest + Src
  * subq Src, Dest	//Dest = Dest - Src
  * imulq Src, Dest //Dest = Dest * Src
  * salq Src, Dest	//Dest = Dest<<Src 也称为shlq
  * sarq Src, Dest  //Dest = Dest>>Src 算数右移
  * shrq Src, Dest	//Dest = Dest<<Src 逻辑右移
  * xorq Src, Dest  //Dest = Dest ^ Src
  * andq Src, Dest  //Dest = Dest & Src
  * orq Src, Dest	  //Dest = Dest | Src
1. 特殊算术运算：
  * imull S //有符号全64位乘法
  * mull S //无符号全64位乘法
  * cltd //convert long to double转为4字
  * idivl S //有符号除法
  * divl S //无符号除法
1. 跳转指令
  * jmp	Always jump	
  * ja	Jump if above(unsigned >)
  * je/jz	Jump if eq / zero	
  * jae	Jump if above / equal
  * jne/jnz	Jump if !eq / !zero	
  * jb	Jump if below(unsigned <)
  * jg	Jump if greater	
  * jbe	Jump if below / equal
  * jge	Jump if greater / eq	
  * js	Jump if sign bits is 1(neg)
  * jl	Jump if less	
  * jns	Jump if sign bit is 0 (pos)
  * jle	Jump if less / eq

#### 第三章 栈帧
1. pushq Src 指令：
  * 获取Src处的操作数
  * 将%rsp值减8
  * 在%rsp指向的地址处写入操作数
1. popq Dest 指令：
  * 读取%rsp指向的地址处的值
  * 将%rsp值加8
  * 将读取的值存入Dest（通常是个寄存器）

```
int add(int a, int b)
{
    int result = a + b;
    return result;
}
int main(int argc)
{
    int answer;
    answer = add(40, 2);
}
```

<div class="IdealImageSlider">
    <img src="../images/call_stack/01.png" />
    <img src="../images/call_stack/02.png" />
    <img src="../images/call_stack/03.png" />
    <img src="../images/call_stack/04.png" />
    <img src="../images/call_stack/05.png" />
    <img src="../images/call_stack/06.png" />
    <img src="../images/call_stack/07.png" />
    <img src="../images/call_stack/08.png" />
    <img src="../images/call_stack/09.png" />
    <img src="../images/call_stack/10.png" />
    <img src="../images/call_stack/11.png" />
</div>
