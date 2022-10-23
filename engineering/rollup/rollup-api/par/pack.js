import { rollup } from "rollup";
import commonjs from "@rollup/plugin-commonjs";
import { nodeResolve } from "@rollup/plugin-node-resolve";

async function pack(config) {
  const bundle = await rollup({
    input: config.input,
    plugins: [nodeResolve()],
  });
  await bundle.write(config.output);
}

process.on("message", async (data) => {
  if (data) {
    console.log("pack", data);
    await pack(data);
  }
  process.send("完成了");
});
