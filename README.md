### CSAPP 学习

#### 学习建议
* [2015 CMU（卡内基梅隆大学）CSAPP 深入理解计算机系统](https://www.bilibili.com/video/BV1iW411d7hd)，视频课
* 本书的必读章节：1，2，3，5，7；选读章节：8，9；第4，5，6章会感到稍许吃力，因为涉及很多硬件东西可能缺少铺垫，读的时候也可以先跳过
* 2-3章对应“汇编语言”；4-6章对应“计算机系统要素”；7-8章对应“程序员的自我修养”；9-12章对应“现代操作系统”

#### 参考资料
* [【读薄 CSAPP】](https://wdxtub.com/csapp/thin-csapp-0/2016/04/16/)
* [读书推荐 - 博主16年毕业](https://zhenbianshu.github.io/book_list.html)
* [读书推荐 - 学习资源推荐](https://hanfeng.ink/books/)
* [读书推荐 - 操作系统的学习顺序](https://hanfeng.ink/post/os_compiler_map/)
* [读书推荐 - 开发内功修炼公众号推荐](https://mp.weixin.qq.com/s/OQyGEi0rvJRS0HJstaPWKQ)

#### Unix风格和Posix风格
```
# Unix风格的函数返回值可以包含正确的值，也可以是错误代码
if (pid = wait(NULL)) < 0) {
    fprintf(stderr, "wait error: %s\n", strerror(errno));
    exit(0);
}

# Posix风格返回值表示成功（0）或失败（非0），结果存在传入参数中
if (retcode = pthread_create(&tid, NULL, thread, NULL) != 0) {
    fprintf(stderr, "pthread_create error: %s\n", strerror(retcode));
    exit(0);
}

总结read函数返回值（Unix风格）：https://www.jianshu.com/p/b0b52e3d7ce8
返回 =0：读到文件末尾
返回 >0：实际read到的字节数
返回 -1：
1）：errno != EAGAIN (或!=EWOULDBLOCK) read出错
2）：errno == EAGAIN (或==EWOULDBLOCK) 设置了非阻塞读，并且没有数据到达
```






