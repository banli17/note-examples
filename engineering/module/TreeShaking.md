# Tree-Shaking

## 什么是Tree-Shaking


Tree-Shaking在前端界由rollup首先提出并实现，后续webpack在2.x版本也借助于UglifyJS实现了。它能帮助我们删除掉没有使用的代码，将会大大缩减打包后的代码量。

## 原理

- ES6的模块引入是静态分析的，故而可以在编译时正确判断到底加载了什么代码。
- 分析程序流，判断哪些变量未被使用、引用，进而删除此代码。
