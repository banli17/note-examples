<template>
  <div></div>
</template>
<script setup>
import Tokenizer from "./tokenizer";

let sources = [
  //   `
  //   age >= 45
  // `,
  //   `
  //   int age = 45
  // `,
  `
    int age = 45 * 8
  `,
];

sources.forEach((source) => {
  const tokens = Tokenizer.parse(source);

  console.log(tokens);
});
</script>
