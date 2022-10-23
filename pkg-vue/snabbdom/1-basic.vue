<template>
  <div>
    <div id="snabbdom-1"></div>
  </div>
</template>
<script setup>
// 使用 webpack 5 打包才能使用下面路径写法, snabbdom 里 package.json 有 exports 字段
// import { init } from "snabbdom/init";
// import { h } from "snabbdom/h";

// import { init } from "snabbdom/build/init.js";
// import { h } from "snabbdom/build/h.js";

import { onMounted } from "vue";
import { init, h } from "snabbdom";

onMounted(() => {
  const patch = init([]);
  // 第一个参数：标签 + 选择器
  // 第二个参数：如果是字符串就是标签中的文本内容
  let vnode = h("div#container.cls", "hello world12345");
  let app = document.querySelector("#snabbdom-1");

  // 第一个参数，旧 vnode
  // 第二个参数，新 vnode
  // 会使用新的 vnode 替换旧的 vnode
  let oldVnode = patch(app, vnode);

  setTimeout(() => {
    vnode = h("div#container.xxx", "hello snabbdom");
    patch(oldVnode, vnode);
  }, 3000);
});
</script>
