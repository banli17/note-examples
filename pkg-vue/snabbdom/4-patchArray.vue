<template>
  <div>模仿 acorn updateChildren, 一个 updateArray 方法</div>
  <div>a: {{ a }}</div>
  <div>b: {{ b }}</div>
  <div>result: {{ result }}</div>
</template>
<script setup>
import { ref } from "vue";

function updateArray(a, b) {
  let newStartIdx = 0;
  let oldStartIdx = 0;
  let newEndIdx = b.length - 1;
  let oldEndIdx = a.length - 1;
  let newStartValue = b[newStartIdx];
  let oldStartValue = a[newStartIdx];
  let newEndValue = b[newEndIdx];
  let oldEndValue = a[oldEndIdx];

  let oldValueMap;
  const diffLog = [];

  while (newStartIdx <= newEndIdx && oldStartIdx <= oldEndIdx) {
    if (newStartValue == null) {
      newStartValue = b[++newStartIdx];
    } else if (oldStartValue == null) {
      oldStartValue = a[++oldStartIdx];
    } else if (oldEndValue == null) {
      oldEndValue = a[--oldEndIdx];
    } else if (newEndValue == null) {
      newEndValue = b[--newEndIdx];
    } else if (isSame(newStartValue, oldStartValue)) {
      newStartValue = b[++newStartIdx];
      oldStartValue = a[++oldStartIdx];
    } else if (isSame(newEndValue, oldEndValue)) {
      newEndValue = b[--newEndIdx];
      oldEndValue = a[--oldEndIdx];
    } else if (isSame(newStartValue, oldEndValue)) {
      a[oldEndIdx] = null;
      a.splice(oldStartIdx, 0, oldEndValue);
      oldStartIdx++;
      oldEndIdx++;
      newStartValue = b[++newStartIdx];
      // 插入到 oldStartIdx 之前
    } else if (isSame(newEndValue, oldStartValue)) {
      a[oldStartValue] = null;
      a.splice(oldEndIdx, 0, oldStartValue);
      newEndValue = a[--newEndIdx];
      oldStartValue = a[++oldStartIdx];
    } else {
      if (!oldValueMap) {
        oldValueMap = createMap(a, oldStartIdx, oldEndIdx);
      }
      // 找到了, 将值移动到 newStartIdx 前面
      const idx = oldValueMap[newStartValue];
      if (idx !== undefined) {
        diffLog.push(`移动 ${a[idx]} 到 oldStartIdx`);
        a.splice(oldStartIdx, 0, a[idx]);
        a[idx] = undefined;
        delete oldValueMap[newStartValue];
        oldStartValue = a[oldStartIdx];
        oldEndValue = a[oldEndIdx];
      } else {
        diffLog.push(`插入 ${newStartValue}`);
        // 新增
        a.splice(oldStartIdx, 0, newStartValue);
        ++oldEndIdx;
        ++oldStartIdx;
      }
      newStartValue = b[++newStartIdx];
    }
    console.log(diffLog);
  }

  if (newStartIdx <= newEndIdx) {
    a.splice(oldEndIdx, 0, ...b.slice(newStartIdx, newEndIdx + 1));
  }

  if (oldStartIdx <= oldEndIdx) {
    a.splice(oldStartIdx, oldEndIdx - oldStartIdx + 1);
  }
  return b;
}
function createMap(val, start, end) {
  const map = {};
  for (let i = start; i <= end; i++) {
    map[val[i]] = i;
  }
  return map;
}
function isSame(a, b) {
  return a == b;
}

// const a = [1, 6]; //
// const b = [1, "b"]; // , "b"
const a = ref([1, 2, 8, "a", 3, 6]); //
const b = ref([1, 7, 3, 5, 6]); // , "b"
const result = updateArray(a, b);
</script>
