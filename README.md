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

#### Epoll相关
* [普通文件为什么不能使用epoll](http://jialeicui.github.io/blog/epoll_does_not_work_with_file.html)，内核源码搜索grep -r '\.poll\s' fs/ | uniq
* [go的线程何时会阻塞](https://www.chaochaogege.com/2019/09/16/15/)，Linux用epoll，BSD/Drawin用kqueue，Windows用IOCP
* [golang 系统调用与阻塞处理](https://qiankunli.github.io/2020/11/21/goroutine_system_call.html)，用户态和内核打交道2种方案：自己封装或依赖glibc等运行库
* Epoll的lt、et模式和惊群
  * [epoll惊群效应深度剖析](https://segmentfault.com/a/1190000039676522)
  * [劫起|再谈Linux epoll惊群问题的原因和解决方案](https://mp.weixin.qq.com/s/zoY4PGDs7voe3HM4QRWEDg)
  * lt水平触发：读写事件没有结束就一直触发；et边缘触发：只触发一次
  * 以tcpServer建立了listenFd等待connectFd事件为例（A、B两个进程试用同一个epoll）：
    * lt的问题是A在epoll_wait到accept的时间间隔内，可能会继续给B发触发事件
    * et没有这个问题，但是epoll_wait到accept的时间间隔内有新的客户端进来就被忽略了，解决办法是每次都要循环处理完
  * 惊群效应：nginx多进程监听epollFd，事件会触发所有的进程，nginx 1.11 之前采用et+锁
  * linux 3.9 解决方案：socket提供SO_REUSEPORT标志，允许多个进程监听同一个ip+port
  * linux 4.5 解决方案：epoll提供EPOLLEXCLUSIVE标志，这样事件只会触发一个进程





