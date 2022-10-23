import { createApp } from 'vue'

import '@styles/style.css'
import '@styles/style.less'
import App from './App.vue'

import a from '@styles/style.less?url'
import b from '@styles/style.less?raw'
console.log(a) // /src/styles/style.less
console.log(b)
/**
@red: red;
body {
  border: 1px solid @red;
}
*/
import Worker from './worker?worker'

const worker = new Worker()

worker.onmessage = (e) => {
  console.log('worker data', e)
}

import { version } from '../package.json'
console.log('version12', version)

console.log('imort.meta.env', import.meta.env.VITE_TITLE)
console.log('imort.meta', import.meta)

createApp(App).mount('#app')

import { throttle } from 'lodash-es'

console.log(throttle)

export function render() {
  console.log('重新渲染了')
}

if (import.meta.hot) {
  import.meta.hot.on('test', (val) => {
    console.log('hot update', val)
  })

  // import.meta.hot.accept() 后就不会刷新页面，同时会接受到子模块的更新
  // import.meta.hot.accept(deps, (modules)=>{}) 只会接受到 deps 模块的更新，其它模块会进行页面刷新
  import.meta.hot.accept((newModule) => {
    // hmr 会重新加载模块
    // 不能直接调用 render，因为闭包，还是调用的之前的 render 内容
    newModule.render() // 这里的 render 是新模块的 render
  })
}
