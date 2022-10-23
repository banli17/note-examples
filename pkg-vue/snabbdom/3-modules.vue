<template>
  <div>
    <div id="snabbdom-3"></div>
  </div>
</template>
<script setup>
import { onMounted } from "vue";
import { init } from "snabbdom/build/init.js";
import { h } from "snabbdom/build/h.js";
import { styleModule } from "snabbdom/build/modules/style";
import { eventListenersModule } from "snabbdom/build/modules/eventlisteners";

onMounted(() => {
  const patch = init([styleModule, eventListenersModule]);

  // 子元素可以是一个数组， 每个元素又是一个 vnode, 用 h 函数创建
  let vnode = h("div#container.cls", [
    h(
      "h1",
      {
        style: {
          backgroundColor: "red",
        },
      },
      "hello world"
    ),
    h(
      "p",
      {
        on: {
          click: clickHandler,
        },
      },
      "this is a p"
    ),
  ]);

  let app = document.querySelector("#snabbdom-3");

  setTimeout(() => {
    patch(app, vnode);
  }, 1000);

  function clickHandler() {
    console.log("click p");
  }
});
</script>
