// 扩展 window.$ 
declare interface Window {
  $: (selector: string) => JQuery
}

class JQuery {
  selector: string
  length: number
  constructor(selector: string) {
    const domList = Array.prototype.slice.call(document.querySelectorAll(selector))
    const length = domList.length
    for (let i = 0; i < length; i++) {
      this[i] = domList[0]
    }
    this.selector = selector
    this.length = length
  }
  append(elem: HTMLElement): JQuery {
    return this
  }
  addClass(key: string, value: string): JQuery {
    return this
  }
  html(htmlStr: string): JQuery | string {
    if (htmlStr) {
      // set html 
      return this
    } else { // get html 
      const html = 'xxx'
      return html
    }
  }
}

window.$ = (selector) => {
  return new JQuery(selector)
}