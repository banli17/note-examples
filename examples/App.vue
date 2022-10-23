<script setup></script>

<template>
  <div id="app-content">
    <div id="app-menu">
      <ul>
        <RouterLink
          v-for="r in $router.options.routes"
          :key="r.path"
          :to="r.path"
          v-slot="{ navigate, href, route }"
          custom
        >
          <li v-show="route.meta.h2" class="h2">{{ route.meta.h2 }}</li>
          <li v-show="route.meta.h3" class="h3">{{ route.meta.h3 }}</li>
          <li class="file">
            <a :href="href" @click="navigate"> {{ route.name }}</a>
          </li>
        </RouterLink>
      </ul>
    </div>
    <div id="app-content-main">
      <RouterView />
    </div>
  </div>
</template>

<style scoped lang="less">
* {
  padding: 0;
  margin: 0;
}
#app-content {
  display: flex;
  #app-menu {
    width: 280px;
    background: #999;
    height: 100vh;
    overflow-y: scroll;
    font-size: 12px;
    padding: 20px;
  }
  ul {
    list-style: none;
  }
  .h2 {
    font-size: 18px;
    font-weight: bold;
  }
  .h3 {
    padding-left: 10px;
    font-size: 16px;
  }
  .file {
    padding-left: 20px;
  }
}
</style>
