<template></template>
<script setup>
class Singleton {
  static instance;

  // private 无法在实例外 new
  constructor(name) {
    if (Singleton.instance) {
      return Singleton.getInstance();
    }

    this.name = name;
    // js 可以判断 new.target
  }
  static getInstance(name) {
    if (!Singleton.instance) {
      Singleton.instance = new Singleton(name);
    }
    return Singleton.instance;
  }
}

class LoginForm {
  static instance = null;
  constructor() {
    if (LoginForm.instance) {
      return LoginForm.instance;
    }

    LoginForm.instance = this;
  }
  show() {
    console.log("show");
  }

  hide() {
    console.log("hide");
  }

  static getInstance() {
    if (this.instance) {
      return this.instance;
    }
    console.log("ggg");
    return (this.instance = new LoginForm());
  }
}

const lf1 = new LoginForm();
const lf2 = new LoginForm();
const lf3 = LoginForm.getInstance();
const lf4 = LoginForm.getInstance();
console.log(lf1 === lf2); // true
console.log(lf3 === lf4); // true
console.log(lf1 === lf3); // true
</script>
