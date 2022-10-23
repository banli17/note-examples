import { fork } from "child_process";

console.time("hi");
let k = 0;
for (let i = 1; i < 5; i++) {
  const f = fork("pack.js");

  f.on("message", (data) => {
    console.log("test", data);
    k++;
    if (k === 4) {
      console.timeEnd("hi");
    }
  });

  f.send({
    index: i,
    input: `./src/index${i}.js`,
    output: {
      dir: `./dist`,
      format: "es",
      // name: "aa",
    },
  });
}
