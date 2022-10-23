class HpKeyboard {
    color: string
    constructor(color: string) {
        this.color = color
    }

    showColor() {
        console.log('color', this.color)
    }
}

class KeyboardFactory {
    create(name) {
        return new HpKeyboard(name)
    }
}

let creator = new KeyboardFactory()

let p1 = creator.create('绿色')
p1.showColor()

let p2 = creator.create('红色')
p2.showColor()

export { }