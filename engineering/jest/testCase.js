function testCase(message, tests) {
  let total = 0;
  let success = 0;
  for (let test in tests) {
    total += 1;
    let ret = tests[test](test);

    if (ret) {
      success += 1;
    }
  }
  console.log(success + "/" + total);
}

function assert(expression, message) {
  console.log(expression, message);
  return expression;
}

// 业务代码
function add(a, b) {
  return a + b;
}

// 测试用例
testCase("query", {
  "test 1 + 1 = 2"(message) {
    return assert(add(1, 1) === 2, message);
  },
  "test 1 + 3 = 5 "(message) {
    return assert(add(1, 3) === 5, message);
  },
});
