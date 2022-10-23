interface Keyboard {
    color: string
    showColor: () => void
}
class HpKeyboard implements Keyboard {
    color: string
    constructor(color: string) {
        this.color = color
    }

    showColor() {
        console.log('hp 键盘, color 是', this.color)
    }
}

class DellKeyboard implements Keyboard {
    color: string
    constructor(color: string) {
        this.color = color
    }

    showColor() {
        console.log('dell 键盘, color 是', this.color)
    }
}

class HpKeyboardFactory {
    create(color) {
        return new HpKeyboard(color)
    }
}

class DellKeyboardFactory {
    create(color) {
        return new HpKeyboard(color)
    }
}

let hpCreator = new HpKeyboardFactory()
let dellCreator = new DellKeyboardFactory()

let p1 = hpCreator.create('绿色')
p1.showColor()

let p2 = dellCreator.create('红色')
p2.showColor()


export { }