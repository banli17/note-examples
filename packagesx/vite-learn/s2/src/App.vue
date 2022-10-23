<script setup>
// This starter template is using Vue 3 <script setup> SFCs
// Check out https://vuejs.org/api/sfc-script-setup.html#script-setup
import HelloWorld from "./components/HelloWorld.vue";

import styleModule from "./styles/style.module.less";
console.log("styleModule", styleModule);
</script>

<template>
  <div>
    <div>hello world</div>
    <div :class="styleModule.box">
      <div :class="styleModule.span">box</div>
    </div>
  </div>
</template>
