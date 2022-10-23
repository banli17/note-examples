import { fork } from "child_process";

import { rollup } from "rollup";
import commonjs from "@rollup/plugin-commonjs";
import { nodeResolve } from "@rollup/plugin-node-resolve";

console.time("hi");
let k = 0;
for (let i = 1; i < 5; i++) {
  async function pack() {
    const bundle = await rollup({
      input: `./src/index${i}.js`,
      plugins: [nodeResolve()],
    });
    await bundle.write({
      dir: `./dist`,
      format: "es",
      // name: "aa",
    });
    k++;
    console.log('kk', k)
    if (k === 4) {
      console.timeEnd("hi");
    }
  }

  pack();
}
