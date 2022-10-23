## 优点

- 简单上手快
- 快，开发效率高
- 生态丰富，基于 rollup

为什么快

传统的 webpack 是一次性全部编译，打成 bundle。

- vite 是动态编译，在加载 html 时，看到引入的 js，才会去查找文件进行编译
- esbuild

```sh
// 创建项目
npm create vite@latest
```

vite 开发 vue jsx，用 `@vitejs/plugin-vue-jsx`

vite 支持 vue2

https://cn.vitejs.dev/guide/features.html#vue

1. 按照依赖包 [@vite/plugin-vue2](https://cn.vitejs.dev/guide/features.html#vue)。

```sh
// 和 vitejs/vite-plugin-vue2 是同一个包
npm i vite @vite/plugin-vue2 -D
```

2. 升级 vue 到 2.7 版本，vitejs/vite-plugin-vue2 只支持 2.7+。

3. 将 public/index.html 移动到跟目录。[index.html 与项目根目录](https://cn.vitejs.dev/guide/#index-html-and-project-root)

4. 新增 `vite.config.js` 文件

```js
// vite.config.js
import vue from "@vitejs/plugin-vue2";
import path from "node:path";

export default {
  resolve: {
    alias: {
      "@": path.resolve(__dirname, "./src"),
    },
  },
  define: {
    "process.env": {},
  },
  server: { hmr: { overlay: false } },
  plugins: [vue()],
};
```

## 基础使用

css 支持

vite 集成了 postcss，自动支持 css。推荐使用原生 css variable。

- postcss: 添加 postcss.config.js 即可。
- css module: 文件名命名为 `.module.css`
- css 预处理器 less/sass/stylus：只需要安装对应的预处理器就可以。
- @import alias: stylus 由于 api 限制，不支持内部使用 alias。

```ts
{
  resolve: {
    alias: {
      '@': '/src', // 路径前面需要加 /
    }
  }
}
```

## 静态资源的处理

### 图片

直接 import 即可。

types

- url: 作为 url 引入
- raw: 作为源代码文本引入
- worker/inline-worker

引用 json
引用 wasm

```ts
import init from "./init.wasm";
init().then();
```

## 集成 eslint 和 prettier

增加 .eslintrc.js

```sh
npm i eslint-config-standard eslint-plugin-promise eslint-plugin-import eslint-plugin-
promise
```

husky 和 lint

```js
npm i husky -D
```

环境变量

https://cn.vitejs.dev/guide/env-and-mode.html#env-files

import.meta.env
vite 内置的环境变量：

- MODE
- BASE_URL
- PROD
- DEV
- SSR

自定义环境变量，可以在 .env 文件中定义，必须以 VITE\_ 开头。

```sh
.env                # 所有情况下都会加载
.env.local          # 所有情况下都会加载，但会被 git 忽略
.env.[mode]         # 只在指定模式下加载
.env.[mode].local   # 只在指定模式下加载，但会被 git 忽略
```

指定 mode

```sh
vite --mode test
vite --mode development
```

vscode 智能提示

### 热更新

热更新原理和实现

glob import

```ts
import.meta.glob("./api/*.js");
```

会返回一个对象，key 是路径，值是一个函数 ()=>import(url)

### 预编译

- 可以将第三方包编译后，放在缓存 node_modules/.vite 目录里，后面直接获取。
- 主要用于将非 esmodule 转为 esmodule，dev 下全是 esmodule 工作的。

默认会把所有依赖都加进去预编译。可以通过 optimizeDeps 设置。

有时候插件会添加一些非 es 文件，vite 可能刚开始扫描不到，导致编译时报错。这时可以将文件加入到预编译中。

```ts
export default defineConfig({
  optimizeDeps: {
    include: ["react"],
    // exclude: ['react']
  },
});
```

bundle file together

如果一个包里有很多文件，如 lodash 里函数文件，被 exclude 后，会导致 vite 将所有文件都加载进行。所以不要随便 exclude。

## esbuild

esbuild 只能命令行执行，没有配置文件。

```
esbuild index.js --outfile=output.js
esbuild index.js --outfile=output.js --bundle
```

--target=esnext // es5 支持不完整
--plantform=node
--format=cjs
--define=TEST=12

## vite 插件

vite 插件是受限制的 rollup 插件，但是也有一些扩展。

如果想在 rollup 中使用，命名为 rollup-plugin-xxx
如果只想在 vite 中使用，命名为 vite-plugin-xxx

服务启动时，只会调用一次

- options
- buildStart

每个模块

- resolveId: 找文件
- load: 加载文件
- transform: 转换文件

服务关闭时

- buildEnd
- closeBundle

配置插件的方法有两种：

```ts
export default defineConfig({
  plugins: [a()], // vite 的插件，受限版
  build: {
    rollupOptions: {
      plugins: [], // 完整的 rollup 插件
    },
  },
});
```

条件

- moduleParsed 钩子不会被调用。parse 是放在 esbuild 中做的。
- 打包钩子和输出钩子之间没有强耦合

vite 特有钩子

- config
- configResolved
- configServer
- transformIndexHtml: 转换入口 html
- handleHotUpdate
