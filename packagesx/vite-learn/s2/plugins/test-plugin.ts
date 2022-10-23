export default (force?: 'pre' | 'post') => {

  return {
    name: 'test-plugin',

    force,

    resolveId() {
      console.log('resolveId') // 不会被执行，因为 vue() 插件中已经执行了 resolveId
    },

    buildStart() {
      console.log('buildStart')
    },

    load() {
      console.log('load', force)
    },

    // 返回值会和 userConfig 合并
    config(userConfig) {
      console.log('config', userConfig.resolve)

      return {
        resolve: {
          alias: {
            '@xxx': './src/styles'
          }
        }
      }
    },

    configResolved(config) {
      console.log('lastConfig', config.resolve)
    },

    configureServer(server) {
      // console.log(server); // server.ws

      // express 中间件
      // 会在 vite 中间件之前执行
      server.middlewares.use((req, res, next) => {
        if (req.url === '/test') {
          res.end('hello vite test')
        } else {
          next()
        }
      })

      // 如果返回函数，会放在 vite 中间件后面执行
      // return () => { server.middlewares.use() }
    },

    transformIndexHtml(html) {
      // console.log('html content', html);
      return html.replace('Vite', 'what')
    },

    handleHotUpdate(ctx) {
      // console.log('ctx', ctx);
      // ctx.file
      // ctx.modules
      ctx.server.ws.send({
        type: 'custom',
        event: 'test',
        data: {
          name: 'zhangsan'
        }
      })
      // 在页面中通过 import.meta.hot 接收
    }
  }
}
