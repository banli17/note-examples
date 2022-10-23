import { defineConfig } from 'vite'
import vue from '@vitejs/plugin-vue'
import testPlugin from './plugins/test-plugin'

// https://vitejs.dev/config/
export default defineConfig({
  plugins: [vue(), testPlugin()],
  resolve: {
    alias: {
      '@styles': '/src/styles',
    },
  },
  // optimizeDeps: { // exclude: ['lodash-es'], },
  server: {},
})
