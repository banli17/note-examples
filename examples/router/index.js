import { createRouter, createWebHistory } from "vue-router";
import HomeView from "../views/HomeView.vue";

const pkgs = import.meta.glob("../../pkg-*/*/*.vue");

const cache = {};

const pkgPages = Object.entries(pkgs).map(([key, value]) => {
  const matched = key.match(/((\/(pkg-.+?)\/(.+?))\/(.+?))\.vue/);
  const h2 = matched[3];
  const h3 = matched[4];
  const filename = matched[5];
  const meta = {};
  if (!cache[h2]) {
    cache[h2] = true;
    meta.h2 = h2;
  }
  if (!cache[matched[2]]) {
    cache[matched[2]] = true;
    meta.h3 = h3;
  }
  return {
    path: matched[1],
    name: filename,
    component: value,
    meta,
  };
});

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: "/",
      name: "home",
      component: HomeView,
    },
    {
      path: "/about",
      name: "about",
      component: () => import("../views/AboutView.vue"),
    },
  ].concat(pkgPages),
});

export default router;
