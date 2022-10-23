interface Mouse { }
class HpMouse implements Mouse { }
class DellMouse implements Mouse { }

interface Keyboard { }
class HpKeyboard implements Keyboard { }
class DellKeyboard implements Keyboard { }

// 工厂基础类
class Factory {
    createPC() {
        const mouse = this.createMouse()
        const keyboard = this.createKeyboard()
        return { mouse, keyboard }
    }

    createMouse() { }
    createKeyboard() { }
}

class HpFactory extends Factory {
    createMouse() {
        return new HpMouse()

    }
    createKeyboard() {
        return new HpKeyboard()
    }
}

class DellFactory extends Factory {
    createMouse() {
        return new DellKeyboard()

    }
    createKeyboard() {
        return new DellKeyboard()
    }
}

class MixFactory extends Factory {
    createMouse() {
        return new DellKeyboard()

    }
    createKeyboard() {
        return new HpKeyboard()
    }
}

const hpfactory = new HpFactory()
hpfactory.createMouse()