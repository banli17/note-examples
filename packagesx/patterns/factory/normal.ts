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

class KeyboardFactory {
    create(type, color) {
        if (type === 'hp') {
            return new HpKeyboard(color)
        }
        if (type === 'dell') {
            return new DellKeyboard(color)
        }
        throw new Error(`没有生产 ${type} 的键盘`)
    }
}

let creator = new KeyboardFactory()

let p1 = creator.create('hp', '绿色')
p1.showColor()

let p2 = creator.create('dell', '红色')
p2.showColor()


export { }