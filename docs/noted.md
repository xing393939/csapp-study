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

### 虚拟内存和内存分配

#### 存储模型
1. [操作系统原理](http://jennica.space/2017/03/21/os-principle/)
1. 物理内存管理：数据结构（位图、空闲+已分配区表、空闲块链表）；分配算法（首次适配、下次适配、最佳适配、最差适配）
1. 段式：用户地址空间按自身逻辑划分为若干段，内存空间划分为若干个长度不同的区域（可变分区），分配单位是段
1. 页式：用户地址空间划分为大小相等的页，内存空间按页大小划分为多个页框，分配单位是页
1. 段页式：用户程序地址空间是段式，每段内含有多页，内存空间是页式，分配单位是页
1. 内存映射文件：用系统调用将文件映射到虚拟地址空间，访问文件就像访问大数组

#### 伙伴分配器算法
1. [buddy-system-内核物理页管理的实现](https://ggaaooppeenngg.github.io/zh-CN/2016/08/31/buddy-system-%E5%86%85%E6%A0%B8%E7%89%A9%E7%90%86%E9%A1%B5%E5%88%86%E9%85%8D%E7%9A%84%E5%AE%9E%E7%8E%B0/)
1. 内存分配流程：
  1. 申请2^k的块
  1. 如果找到了直接分配
  1. 如果没有找到，就拆分一个比2^k更大的块，如果大小满足2^k则直接分配
  1. 重复步骤Ⅱ
1. 内存释放流程：
  1. 释放2^k的块
  1. 查看分配之后的另一半2^k的块释放也free了，如果是就合并
 
#### 堆的空间利用率问题
1. 内部碎片：由于对齐要求产生的
1. 外部碎片：当空闲内存合计起来足够满足一个分配请求，但是没有一个单独的空闲块足够大到满足这个请求时
1. 分配器关联分配块的链表：
  1. 隐式空闲链表，是一个单向链表
  1. 显式空闲链表，是一个双向链表，在每个空闲块中，都包含一个前驱节点的指针与后继节点的指针
1. 查找一个空闲块的策略：
  1. 首次适应算法(First Fit)
  1. 循环首次适应算法(Next Fit)
  1. 最佳适应算法(Best Fit)
  1. 最坏适应算法(Worst Fit)
  1. 快速适应算法(Quick Fit)
  
#### Linux内存管理
1. [面试问了解Linux内存管理吗？10张图给你安排的明明白白](https://segmentfault.com/a/1190000022429378)
1. [面试官：你谈谈对物理内存和虚拟内存的理解，一文彻底搞懂](https://segmentfault.com/a/1190000022506020)
1. slab分配器：伙伴分配器有效解决了外部碎片的问题，slab分配器解决频繁申请小内存(小于一个页)的问题，主要应用于内核对象的缓存
  1. 将内存按使用对象不同再划分成不同大小的空间，比如task_struct、file_struct等都有slab缓存池
  1. 当要申请这种类型的对象时，就从缓存池的slab 列表中分配一个出去；
  1. 而当要释放时，将其重新保存在该列表中
1. 用户空间内存分配：
  1. malloc 当申请小于 128KB时，使用 sbrk或brk 分配内存；当申请大于 128KB 的内存时，使用 mmap 函数申请内存
  1. vm_area_struct——进程页表——伙伴系统——空闲页框
1. 内核空间内存分配
  1. 直接映射区：kmalloc——slab分配器——伙伴系统——空闲页框
  1. 动态内存映射区：vmalloc——vm_struct——内核页表——伙伴系统——空闲页框
  
