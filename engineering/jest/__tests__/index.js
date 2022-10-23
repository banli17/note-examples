describe("test 1", () => {
  it("add 1 + 1", () => {
    expect(1 + 1).toBe(2);
  });

  it("object is same ", () => {
    const a = {
      name: "zs",
      age: 12,
    };
    const b = {
      age: 12,
      name: "zs",
    };
    expect(a).toEqual(b);
  });
});
