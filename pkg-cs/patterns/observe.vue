<template>
  <div class="container">
    <div>hi <span>xx</span></div>
    <div>boy</div>
  </div>
</template>
<script setup>
import { onMounted } from "vue";

class Subject {
  constructor() {
    this.observers = [];
    this.state = 0;
  }

  getState() {
    return this.state;
  }

  setState(newState) {
    this.state = newState;
    this.notify();
  }

  // 添加观察者
  attach(observer) {
    this.observers.push(observer);
  }

  // 通知观察者
  notify() {
    this.observers.forEach((observer) => observer.update(this.state));
  }
}

class Observer {
  constructor(name) {
    this.name = name;
  }
  update(state) {
    console.log(`${this.name} updated ${state}`);
  }
}

const o1 = new Observer("o1");
const o2 = new Observer("o2");
const s = new Subject();
s.attach(o1);
s.attach(o2);
s.setState(3);

function Event() {
  this.callbacks = [];
}

Event.prototype.on = function (fn) {
  this.callbacks.push(fn);
};

Event.prototype.emit = function () {
  this.callbacks.forEach((callback) => {
    callback.apply(this, arguments);
  });
};

var e = new Event();
e.on(function (a) {
  console.log(1, a);
});
e.on(function (a, b) {
  console.log(2, a, b);
});
e.emit("hi", "zhangsan");
// 1 'hi'
// 2 'hi' 'zhangsan'

onMounted(() => {
  const el = document.querySelector(".container");
  const callback = (mutationList, observer) => {
    console.log("record", mutationList);
  };

  const mutationObserve = new MutationObserver(callback);

  // childList、attributes 和 characterData 中，必须有一个参数为 true。否则会抛出 TypeError 异常
  mutationObserve.observe(el, {
    attributes: true, // 观察所有监听节点属性值的变化
    // attributeFilter: [], // 哪些属性名会被监听
    // attributeOldValue: true, // 记录上一次被监听的节点的属性变化
    childList: true, // 监听 target 节点中发生的节点的新增和删除
    characterData: true, // 文本内容
    characterDataOldValue: true, // 记录上一个被监听节点中发生的文本变化
    subtree: true, // 将监听 el 为根节点的整个子树
  });
});
</script>
