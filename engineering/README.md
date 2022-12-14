# webpack

v4.0.0 开始支持零配置，默认打包是： `src/index.js` -> `dist/main.js`

## 是什么

webpack 是一个模块打包工具，它将所有资源(如图片、js文件、css文件、字体等)统一当作 js 模块进行打包。

webpack 打包时，它会根据一个或多个入口点构建一个依赖关系图，然后将项目所需的模块组合成一个或多个 bundles。

## 为什么

1、模块化，将所有资源当作 js 模块统一处理。
2、支持多种模块化方式，CommonJS、ESM。
3、功能强大

## 应用场景

前端应用开发，用于开发环境，和打包。

## 历史

打包器出现之前，有两种方式运行 js，一种是每个功能一个脚本，这样加载太多脚本会导致网络问题。第二种是将代码全部写到一起，这导致可读性、可维护性变差，文件太大等问题。

使用 IIFE 可以很好的隔离脚本，能使脚本安全的组合在一起。它催生了 Grunt、Gulp 等工具，这些工具叫做任务运行器。

但是更改一个文件就需要重新打包整个文件。这种模式下，重用脚本很容易，但是构建和优化很困难。

即使只使用了 lodash 一个函数，也必须添加整个库。无法 treeshake。

## 怎么做

- entry: 入口文件
- output
  - filename 输出文件
  - path 输出目录，必须是绝对路径
- mode:  默认是 production

## 需求

- 编译 ES6
- 将模块化文件进行打包成一个文件

## 打包文件分析

## 原理
